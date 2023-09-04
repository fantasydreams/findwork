#include <cstddef>
#include <memory>
#include <vector>
#include <unordered_set>

class Context {
    public:
        Context(int value) : m_iValue(value), m_iHandlerValue(-1) {};
        Context() : m_iValue(0), m_iHandlerValue(-1) {};
        int m_iValue;
        int m_iHandlerValue;
};

class BaseChain {
    public:
        BaseChain() = default;
        virtual ~BaseChain() {};
        virtual int Handle(const Context* poCtx, BaseChain* poChain, BaseChain* poChainHandler = nullptr) = 0;
};


class Chain : public BaseChain {
    public:
        Chain() = default;
        virtual ~Chain() {
            for(int i = 0; i < m_vecContaioner.size(); ++i) {
                delete m_vecContaioner[i];
                m_vecContaioner[i] = nullptr;
            }
        };

        inline Chain& AddChain(BaseChain* poChainHandler)  {
            m_vecContaioner.push_back(poChainHandler);
            m_IdxHash.insert({poChainHandler, m_vecContaioner.size() - 1});
            return *this;
        };
        
        virtual int Handle(const Context* poCtx, BaseChain* poChain, BaseChain* poChainHandler = nullptr) override {
            if(m_vecContaioner.empty()) {
                return 0;
            }
            if(poChainHandler == nullptr ) {
                return m_vecContaioner[0]->Handle(poCtx, this, m_vecContaioner[0]);
            }
            auto pIter = m_IdxHash.find(poChainHandler);
            if(pIter == m_IdxHash.end()) {
                return 0;
            }

            size_t iIdx = pIter->second + 1;
            if(iIdx >= m_vecContaioner.size()) {
                return 0;
            }

            return m_vecContaioner[iIdx]->Handle(poCtx, this, m_vecContaioner[iIdx]);
            return 0;
        };
    private:
        std::vector<BaseChain*> m_vecContaioner;
        std::unordered_map<BaseChain*, size_t> m_IdxHash;
};


class BaseHandlerExample : public BaseChain{
    public:
        BaseHandlerExample() = delete;
        explicit BaseHandlerExample(int condi) : m_iCondtion(condi){};
        virtual ~BaseHandlerExample(){};
        virtual int Handle(const Context* poCtx, BaseChain* poChain, BaseChain* poChainHandler = nullptr) override{
            if(m_iCondtion >= poCtx->m_iValue){
                const_cast<Context*>(poCtx)->m_iHandlerValue = m_iCondtion;
                return 0;
            }

            return poChain->Handle(poCtx, poChain, this); // 这里要暴露this，一个不好的设计！！！
        };
    
    private:
        int m_iCondtion;
};


class BaseChainHandler {
    public:
       BaseChainHandler() = default;
        virtual ~BaseChainHandler() {};
        virtual int Handle(const Context* poCtx, BaseChainHandler* poChain){return 0;};
};

class ChainHandler : public BaseChainHandler {
    public:
        explicit ChainHandler(int condi) : m_iCondi(condi) {};
        virtual ~ChainHandler(){};
        virtual int Handle(const Context* poCtx, BaseChainHandler* poChain) {
            if(m_iCondi >= poCtx->m_iValue) {
                // process;
                const_cast<Context*>(poCtx)->m_iHandlerValue = m_iCondi;
                return 0;
            }

            return poChain->Handle(poCtx, poChain);
        };
    private:
        int m_iCondi;
};

// shared_ptr + 局部变量
class ChaninManager : public BaseChainHandler {
    public:
        ChaninManager() : m_idx(0){};
        virtual ~ChaninManager() {};

        inline ChaninManager& AddChain(BaseChainHandler* poChainHandler)  {
            std::shared_ptr<BaseChainHandler> p(poChainHandler);
            m_vecContaioner.push_back(p);
            return *this;
        };
        
        virtual int Handle(const Context* poCtx, BaseChainHandler* poChain) override {
            if(m_vecContaioner.empty() || m_idx >= m_vecContaioner.size()) {
                return 0;
            }

            size_t iIdx = m_idx++;
            int iRet = m_vecContaioner[iIdx]->Handle(poCtx, &(*this)); // 这种如果链比较长的话开销感觉还是蛮大的
            --m_idx;
            return iRet;
        };
    private:
        std::vector<std::shared_ptr<BaseChainHandler> > m_vecContaioner;
        size_t m_idx;
};



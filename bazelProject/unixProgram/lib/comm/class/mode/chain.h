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
#include <memory>
#include <string>
#include <list>

class AbstractComponent {
    public:
        AbstractComponent() = default;
        virtual ~AbstractComponent() {};
        virtual AbstractComponent& Add(std::shared_ptr<AbstractComponent>) = 0;
        virtual AbstractComponent& Remove(std::shared_ptr<AbstractComponent>) = 0;
        virtual std::list<std::shared_ptr<AbstractComponent> > GetChildrens() = 0;
        virtual std::string Handle() = 0;
};

class Composite : public AbstractComponent {
    public:
        Composite(std::string sNodeName) : m_sNodeName(sNodeName){};
        virtual ~Composite() override {};
        virtual AbstractComponent& Add(std::shared_ptr<AbstractComponent> poNode) override {
            m_oListChild.push_back(poNode);
            return *this;
        }
        virtual AbstractComponent& Remove(std::shared_ptr<AbstractComponent> poNode) override {
            m_oListChild.remove(poNode);
            return *this;
        };

        virtual std::list<std::shared_ptr<AbstractComponent> > GetChildrens() override {
            return m_oListChild;
        };

        virtual std::string Handle() override {
            std::string sRes = "<" + m_sNodeName + ">\n";
            for(auto poChild : m_oListChild) {
                sRes += poChild->Handle();
            }
            sRes += "</" + m_sNodeName + ">\n";
            return sRes;
        };
    private:
        std::string m_sNodeName;
        std::list<std::shared_ptr<AbstractComponent> > m_oListChild;
};

class Leaf : public AbstractComponent {
    public:
        explicit Leaf(std::string sNodeName) : m_sNodeName(sNodeName){};
        virtual ~Leaf() override {};
        virtual std::string Handle() override{
            return m_sNodeName;
        }; 
    private:
        virtual AbstractComponent& Add(std::shared_ptr<AbstractComponent>) override {return *this;};
        virtual AbstractComponent& Remove(std::shared_ptr<AbstractComponent>) override {return *this;};
        virtual std::list<std::shared_ptr<AbstractComponent> > GetChildrens() override {
            return std::list<std::shared_ptr<AbstractComponent> >();   
        }
        std::string m_sNodeName;
};




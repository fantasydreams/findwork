
#include <cassert>
#include <memory>
#include <vector>


//可变参数的工厂模式实现
class Object {
    public:
        virtual Object* clone() = 0;
        // virtual ~Object() = 0; 析构函数不能为纯虚函数
        virtual ~Object(){};
};

class Interger : public Object {
    public:
        Interger(): m_iValue(0){};
        Interger(int value) : m_iValue(value){};
        virtual Object* clone() override{
            return new Interger(m_iValue);
        }

        int GetValue() {
            return m_iValue;
        }
        ~Interger(){}
    private:
        int m_iValue;
};

class Boolean : public Object {
    public:
        Boolean() : m_bValue(false){} 
        ~Boolean(){}
        Boolean(bool bValue) : m_bValue(bValue){}
        virtual Object* clone() override {
            return new Boolean(m_bValue);
        }

        bool GetValue() {
            return m_bValue;
        }
    private:
        bool m_bValue;
};


enum class SimpleFactoryType {
    Type_Example = 0,
};

// 方式1 静态成员函数根据类型创建实例。通过多态完成实例方法的处理过程


// 简单工厂模式，每个实例由工厂来创造实例
// 特点：扩展性较差，扩展时需要去修改工厂
class SimpleFactory {
    public:
        SimpleFactory() = default;
        virtual ~SimpleFactory(){};
        static std::shared_ptr<SimpleFactory> GetFactoryInstance(SimpleFactoryType, const std::vector<Object*>& args);
        
        virtual int DoMethod(){return 0;};
    private:
}; 

class SimpleFactoryExample : public SimpleFactory {
    public:
        SimpleFactoryExample() : m_num(0), m_bool(false){};  
        virtual ~SimpleFactoryExample() {}
        SimpleFactoryExample(int num, bool bBoolean) : m_num(num), m_bool(bBoolean) {};
        virtual int DoMethod() override{
            return m_num + m_bool;
        }
    private:
        int m_num;
        bool m_bool;
};

std::shared_ptr<SimpleFactory> SimpleFactory::GetFactoryInstance(SimpleFactoryType Type, const std::vector<Object*>& args) {

    if(Type == SimpleFactoryType::Type_Example) {
        assert(args.size() == 2);
        int a = (dynamic_cast<Interger*>(args[0]))->GetValue();
        bool b = (dynamic_cast<Boolean*>(args[1]))->GetValue();
        return std::make_shared<SimpleFactoryExample>(a, b);
    }
    
    return std::make_shared<SimpleFactory>();
}


// factory mode

class Instance {
public:
    Instance() = default;
    virtual ~Instance(){};
    virtual int DoMethod() {
        return 0;
    };
};

class InstanceExample : public Instance{
    public:
        InstanceExample() = default;
        InstanceExample(int a, bool b): m_num(a), m_bool(b){};
        virtual ~InstanceExample(){};
        virtual int DoMethod() {
            return m_num + m_bool;
        };
    private:
        int m_num;
        bool m_bool;
};

class InstanceExample1: public Instance{
    public:
        InstanceExample1() = default;
        InstanceExample1(int a): m_num(a){};
        virtual ~InstanceExample1(){};
        virtual int DoMethod() {
            return m_num;
        };
    private:
        int m_num;
};

class Factory {
    public:
        Factory() = default;
        virtual ~Factory(){};
        virtual std::shared_ptr<Instance> GetInstance(std::vector<Object*>& args) {
            return std::make_shared<Instance>();
        };
    private:
};

class FactoryExample : public Factory {
    public:
        FactoryExample() = default;
        virtual ~FactoryExample() {};
        virtual std::shared_ptr<Instance> GetInstance(std::vector<Object*>& args) override {
            assert(args.size() == 2);
            int a = (dynamic_cast<Interger*>(args[0]))->GetValue();
            bool b = (dynamic_cast<Boolean*>(args[1]))->GetValue();
            return std::make_shared<InstanceExample>(a, b);
        };
};



// abstract factory
class AbstractFactory {
    public:
        AbstractFactory() = default;
        virtual ~AbstractFactory(){};
        virtual std::shared_ptr<Instance> GetInstanceFirst(std::vector<Object*>& args) {
            return std::make_shared<Instance>();
        };

        virtual std::shared_ptr<Instance> GetInstanceScond(std::vector<Object*>& args) {
            return std::make_shared<Instance>();
        };
};

class AbstractFactoryExample : public AbstractFactory {
    public:
        AbstractFactoryExample() = default;
        virtual ~AbstractFactoryExample() {};
        virtual std::shared_ptr<Instance> GetInstanceFirst(std::vector<Object*>& args) override {
            assert(args.size() == 2);
            int a = (dynamic_cast<Interger*>(args[0]))->GetValue();
            bool b = (dynamic_cast<Boolean*>(args[1]))->GetValue();
            return std::make_shared<InstanceExample>(a, b);
        };

        virtual std::shared_ptr<Instance> GetInstanceScond(std::vector<Object*>& args) override {
            assert(args.size() == 1);
            int a = (dynamic_cast<Interger*>(args[0]))->GetValue();
            return std::make_shared<InstanceExample1>(a);
        };
};

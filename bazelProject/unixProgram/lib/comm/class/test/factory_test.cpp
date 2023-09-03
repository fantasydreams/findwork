#include "lib/comm/class/mode/factory.h"
#include "gtest/gtest.h"
#include <memory>
#include <type_traits>
#include <vector>
#include <cstdlib>
#include <cmath>
#include "lib/comm/class/scopeguard.h"

TEST(case_1, content)
{
    std::vector<Object*> args;
    args.resize(2);
    args[0] = new Interger(5);
    args[1] = new Boolean(true);

    std::shared_ptr<SimpleFactory> pOject = SimpleFactory::GetFactoryInstance(SimpleFactoryType::Type_Example, args);
    EXPECT_EQ(pOject.get()->DoMethod(), 6);
    delete args[0];
    delete args[1];
}

TEST(case_2, content)
{
    std::vector<Object*> args;
    args.resize(2);
    args[0] = new Interger(5);
    args[1] = new Boolean(true);

    ON_SCOPT_EXIT{
        for(int i = 0; i < args.size(); ++i) {
            delete args[i];
            args[i] = nullptr;
        }
    }; 


    std::shared_ptr<Instance> poInstance = FactoryExample().GetInstance(args);
    EXPECT_EQ(poInstance.get()->DoMethod(), 6);
}


TEST(case_3, content)
{
    std::vector<Object*> args, args1;
    args.resize(2);
    args[0] = new Interger(5);
    args[1] = new Boolean(true);

    args1.resize(1);
    args1[0] = new Interger(5); 

    ON_SCOPT_EXIT{
        for(int i = 0; i < args.size(); ++i) {
            delete args[i];
            args[i] = nullptr;
        }
        for(int i = 0; i < args1.size(); ++i) {
            delete args1[i];
            args1[i] = nullptr;
        }
    }; 


    std::shared_ptr<Instance> poInstance = AbstractFactoryExample().GetInstanceFirst(args);
    EXPECT_EQ(poInstance.get()->DoMethod(), 6);

    std::shared_ptr<Instance> poInstance1 = AbstractFactoryExample().GetInstanceScond(args1); 
    EXPECT_EQ(poInstance1.get()->DoMethod(), 5); 
}
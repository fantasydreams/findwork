#include "gtest/gtest.h"
#include <memory>
#include "lib/comm/class/mode/composite.h"


TEST(case_1, content)
{
    Composite oRoot("root");
    std::shared_ptr<AbstractComponent> poBook = std::make_shared<Composite>("author");
    std::shared_ptr<AbstractComponent> poAuther = std::make_shared<Leaf>("sharwenluo"); 
    poBook->Add(poAuther);

    std::shared_ptr<AbstractComponent> poName = std::make_shared<Composite>("name");
    std::shared_ptr<AbstractComponent> poBookName = std::make_shared<Leaf>("happy work");
    poName->Add(poBookName);
    oRoot.Add(poBook).Add(poName);

    std::shared_ptr<AbstractComponent> poTags = std::make_shared<Composite>("tags");
    std::shared_ptr<AbstractComponent> poTag1 = std::make_shared<Composite>("tag");
    std::shared_ptr<Leaf> poTag1Real1 = std::make_shared<Leaf>("c++");
    poTag1->Add(poTag1Real1);

    std::shared_ptr<AbstractComponent> poTag2 = std::make_shared<Composite>("tag");
    std::shared_ptr<AbstractComponent> poTag1Real2 = std::make_shared<Leaf>("mode");
    poTag2->Add(poTag1Real2);

    poTags->Add(poTag1).Add(poTag2);

    oRoot.Add(poTags);

    std::string sAns = "<root>\n<author>\nsharwenluo</author>\n<name>\nhappy work</name>\n<tags>\n<tag>\nc++</tag>\n<tag>\nmode</tag>\n</tags>\n</root>\n";
    EXPECT_EQ(oRoot.Handle(), sAns);
}



#include <gtest/gtest.h>

#include <dr_runner/factories/entity_factory.h>



TEST(EntityFactoryTest, can_be_created)
{
   EntityFactory entity_factory(nullptr);
}



TEST(EntityFactoryTest, creates_a_base_entity_type)
{
   EntityFactory entity_factory(nullptr);

   std::shared_ptr<Entity::Base> expected_entity = entity_factory.create_entity("base");
}



int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}




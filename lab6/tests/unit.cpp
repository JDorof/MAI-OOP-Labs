#include "npc.hpp"
#include "point.hpp"
#include "npc.hpp"
#include <gtest/gtest.h>
#include <sstream>

// Тест: Создание NPC через фабрику
TEST(NPCFactoryTest, CreateNPC) {
    NPCFactory factory;

    auto elf = factory.create_npc(NPCType::Elf, "Legolas", {10, 20});
    ASSERT_EQ(elf->get_name(), "Legolas");
    ASSERT_EQ(elf->get_type(), NPCType::Elf);
    ASSERT_EQ(elf->get_position().getX(), 10);
    ASSERT_EQ(elf->get_position().getY(), 20);
    ASSERT_TRUE(elf->is_alive());

    auto rogue = factory.create_npc(NPCType::Rogue, "Garrett", {5, 5});
    ASSERT_EQ(rogue->get_name(), "Garrett");
    ASSERT_EQ(rogue->get_type(), NPCType::Rogue);
    ASSERT_EQ(rogue->get_position().getX(), 5);
    ASSERT_EQ(rogue->get_position().getY(), 5);
    ASSERT_TRUE(rogue->is_alive());
}

// Тест: Сериализация NPC
TEST(NPCFactoryTest, DumpToStream) {
    NPCFactory factory;

    auto squirrel = factory.create_npc(NPCType::Squirrel, "Chippy", {15, 25});
    std::ostringstream out;
    factory.DumpToStream(out, squirrel);

    std::string expected = "Squirrel Chippy 15 25 1\n"; // 1 означает alive = true
    ASSERT_EQ(out.str(), expected);
}

// Тест: Десериализация NPC
TEST(NPCFactoryTest, LoadFromStream) {
    NPCFactory factory;

    std::istringstream in("Elf Elrond 3 7 1\n");
    auto npc = factory.LoadFromStream(in);

    ASSERT_EQ(npc->get_type(), NPCType::Elf);
    ASSERT_EQ(npc->get_name(), "Elrond");
    ASSERT_EQ(npc->get_position().getX(), 3);
    ASSERT_EQ(npc->get_position().getY(), 7);
    ASSERT_TRUE(npc->is_alive());
}

// Тест: Базовая логика боя
TEST(NPCLogicTest, FightRules) {
    NPCFactory factory;

    auto elf = factory.create_npc(NPCType::Elf, "Tyrande", {0, 0});
    auto rogue = factory.create_npc(NPCType::Rogue, "Valeera", {1, 1});
    auto squirrel = factory.create_npc(NPCType::Squirrel, "Nutty", {2, 2});

    // Эльф убивает разбойника
    ASSERT_TRUE(elf->lets_fight(rogue.get()));
    ASSERT_FALSE(rogue->is_alive());

    // Разбойник убивает белку
    rogue = factory.create_npc(NPCType::Rogue, "Valeera", {1, 1}); // Новый разбойник
    ASSERT_TRUE(rogue->lets_fight(squirrel.get()));
    ASSERT_FALSE(squirrel->is_alive());

    // Белка убивает эльфа
    squirrel = factory.create_npc(NPCType::Squirrel, "Nutty", {2, 2}); // Новая белка
    ASSERT_TRUE(squirrel->lets_fight(elf.get()));
    ASSERT_FALSE(elf->is_alive());
}

// Тест: Сохранение и восстановление нескольких NPC
TEST(NPCFactoryTest, MultipleNPCSerialization) {
    NPCFactory factory;

    auto npc1 = factory.create_npc(NPCType::Elf, "Thranduil", {5, 5});
    auto npc2 = factory.create_npc(NPCType::Rogue, "Garona", {1, 1});

    std::ostringstream out;
    factory.DumpToStream(out, npc1);
    factory.DumpToStream(out, npc2);

    std::istringstream in(out.str());
    auto loaded_npc1 = factory.LoadFromStream(in);
    auto loaded_npc2 = factory.LoadFromStream(in);

    ASSERT_EQ(loaded_npc1->get_name(), "Thranduil");
    ASSERT_EQ(loaded_npc1->get_type(), NPCType::Elf);
    ASSERT_EQ(loaded_npc1->get_position().getX(), 5);
    ASSERT_EQ(loaded_npc1->get_position().getY(), 5);

    ASSERT_EQ(loaded_npc2->get_name(), "Garona");
    ASSERT_EQ(loaded_npc2->get_type(), NPCType::Rogue);
    ASSERT_EQ(loaded_npc2->get_position().getX(), 1);
    ASSERT_EQ(loaded_npc2->get_position().getY(), 1);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

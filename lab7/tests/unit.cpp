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

    auto elf = factory.create_npc(NPCType::Elf, "Elrond", {15, 25});
    std::ostringstream out;
    factory.DumpToStream(out, elf);

    std::string expected = "elf Elrond 15 25 1\n"; // 1 означает alive = true
    ASSERT_EQ(out.str(), expected);
}

// Тест: Десериализация NPC
TEST(NPCFactoryTest, LoadFromStream) {
    NPCFactory factory;

    std::istringstream in("Squirrel Chippy 3 7 1\n");
    auto npc = factory.LoadFromStream(in);

    ASSERT_EQ(npc->get_type(), NPCType::Squirrel);
    ASSERT_EQ(npc->get_name(), "Chippy");
    ASSERT_EQ(npc->get_position().getX(), 3);
    ASSERT_EQ(npc->get_position().getY(), 7);
    ASSERT_TRUE(npc->is_alive());
}

// Тест: Базовая логика боя
TEST(NPCLogicTest, Fight) {
    NPCFactory factory;

    auto rogue = factory.create_npc(NPCType::Rogue, "Valeera", {0, 0});
    auto elf = factory.create_npc(NPCType::Elf, "Tyrande", {1, 1});

    ASSERT_FALSE(rogue->lets_fight(elf.get())); // Друид атакует орка
    ASSERT_TRUE(elf->is_alive());             // Орк должен остаться жив

    auto squirrel = factory.create_npc(NPCType::Squirrel, "Fluffy", {2, 2});
    ASSERT_FALSE(squirrel->lets_fight(rogue.get())); // Белка атакует друида
    ASSERT_TRUE(rogue->is_alive());
}

// Тест: Сохранение и восстановление нескольких NPC
TEST(NPCFactoryTest, MultipleNPCSerialization) {
    NPCFactory factory;

    auto npc1 = factory.create_npc(NPCType::Elf, "Thranduil", {5, 5});
    auto npc2 = factory.create_npc(NPCType::Squirrel, "Nutty", {1, 1});

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

    ASSERT_EQ(loaded_npc2->get_name(), "Nutty");
    ASSERT_EQ(loaded_npc2->get_type(), NPCType::Squirrel);
    ASSERT_EQ(loaded_npc2->get_position().getX(), 1);
    ASSERT_EQ(loaded_npc2->get_position().getY(), 1);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
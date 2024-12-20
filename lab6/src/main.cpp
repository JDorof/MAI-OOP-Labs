#include "game.hpp"
#include "npc.hpp"
#include "observer.hpp"

int main() {
    auto elf1 = NPCFactory::create_npc(NPCType::Elf, "lolka", {1, 12});
    auto elf2 = NPCFactory::create_npc(NPCType::Elf, "meme", {3, 0});
    auto elf3 = NPCFactory::create_npc(NPCType::Elf, "solana", {12, 12});
    auto sq1 = NPCFactory::create_npc(NPCType::Squirrel, "chain", {0, 0});
    auto sq2 = NPCFactory::create_npc(NPCType::Squirrel, "diddy", {15, 3});
    auto sq3 = NPCFactory::create_npc(NPCType::Squirrel, "mango", {100, 12});
    auto rogue1 = NPCFactory::create_npc(NPCType::Rogue, "hihi", {0, 3});
    auto rogue2 = NPCFactory::create_npc(NPCType::Rogue, "kek", {6, 20});

    auto log_obs = std::make_shared<LogEntityObserver>("./log.txt");
    auto print_obs = std::make_shared<PrintEntityObserver>();

    Game game;
    game.attach_observer(log_obs);
    game.attach_observer(print_obs);

    game.add_object(std::move(elf1));
    game.add_object(std::move(elf2));
    game.add_object(std::move(elf3));
    game.add_object(std::move(sq1 ));
    game.add_object(std::move(sq2 ));
    game.add_object(std::move(sq3 ));
    game.add_object(std::move(rogue1 ));
    game.add_object(std::move(rogue2 ));

    game.run(15);
}
add_test( NPCFactoryTest.CreateNPC /home/justdema/OOP/MAI-OOP-Labs/lab6/build/runTests [==[--gtest_filter=NPCFactoryTest.CreateNPC]==] --gtest_also_run_disabled_tests)
set_tests_properties( NPCFactoryTest.CreateNPC PROPERTIES WORKING_DIRECTORY /home/justdema/OOP/MAI-OOP-Labs/lab6/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( NPCFactoryTest.DumpToStream /home/justdema/OOP/MAI-OOP-Labs/lab6/build/runTests [==[--gtest_filter=NPCFactoryTest.DumpToStream]==] --gtest_also_run_disabled_tests)
set_tests_properties( NPCFactoryTest.DumpToStream PROPERTIES WORKING_DIRECTORY /home/justdema/OOP/MAI-OOP-Labs/lab6/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( NPCFactoryTest.LoadFromStream /home/justdema/OOP/MAI-OOP-Labs/lab6/build/runTests [==[--gtest_filter=NPCFactoryTest.LoadFromStream]==] --gtest_also_run_disabled_tests)
set_tests_properties( NPCFactoryTest.LoadFromStream PROPERTIES WORKING_DIRECTORY /home/justdema/OOP/MAI-OOP-Labs/lab6/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( NPCFactoryTest.MultipleNPCSerialization /home/justdema/OOP/MAI-OOP-Labs/lab6/build/runTests [==[--gtest_filter=NPCFactoryTest.MultipleNPCSerialization]==] --gtest_also_run_disabled_tests)
set_tests_properties( NPCFactoryTest.MultipleNPCSerialization PROPERTIES WORKING_DIRECTORY /home/justdema/OOP/MAI-OOP-Labs/lab6/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( NPCLogicTest.FightRules /home/justdema/OOP/MAI-OOP-Labs/lab6/build/runTests [==[--gtest_filter=NPCLogicTest.FightRules]==] --gtest_also_run_disabled_tests)
set_tests_properties( NPCLogicTest.FightRules PROPERTIES WORKING_DIRECTORY /home/justdema/OOP/MAI-OOP-Labs/lab6/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( runTests_TESTS NPCFactoryTest.CreateNPC NPCFactoryTest.DumpToStream NPCFactoryTest.LoadFromStream NPCFactoryTest.MultipleNPCSerialization NPCLogicTest.FightRules)
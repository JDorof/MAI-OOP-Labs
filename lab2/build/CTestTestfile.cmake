# CMake generated Testfile for 
# Source directory: /home/justdema/OOP/MAI-OOP-Labs/lab2
# Build directory: /home/justdema/OOP/MAI-OOP-Labs/lab2/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(unit_tests "/home/justdema/OOP/MAI-OOP-Labs/lab2/build/unit_tests")
set_tests_properties(unit_tests PROPERTIES  _BACKTRACE_TRIPLES "/home/justdema/OOP/MAI-OOP-Labs/lab2/CMakeLists.txt;38;add_test;/home/justdema/OOP/MAI-OOP-Labs/lab2/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")

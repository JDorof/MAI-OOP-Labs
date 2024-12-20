# CMake generated Testfile for 
# Source directory: /home/justdema/OOP/MAI-OOP-Labs/lab5
# Build directory: /home/justdema/OOP/MAI-OOP-Labs/lab5/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[oop_tests]=] "/home/justdema/OOP/MAI-OOP-Labs/lab5/build/oop_tests")
set_tests_properties([=[oop_tests]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/justdema/OOP/MAI-OOP-Labs/lab5/CMakeLists.txt;31;add_test;/home/justdema/OOP/MAI-OOP-Labs/lab5/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")

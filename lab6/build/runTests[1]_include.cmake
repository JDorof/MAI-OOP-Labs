if(EXISTS "/home/justdema/OOP/MAI-OOP-Labs/lab6/build/runTests[1]_tests.cmake")
  include("/home/justdema/OOP/MAI-OOP-Labs/lab6/build/runTests[1]_tests.cmake")
else()
  add_test(runTests_NOT_BUILT runTests_NOT_BUILT)
endif()

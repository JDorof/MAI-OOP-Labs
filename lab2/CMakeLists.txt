# Минимальная версия CMake
cmake_minimum_required(VERSION 3.10)

# Название проекта
project(EluminateUnsetBits)

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Включаем поддержку тестирования
enable_testing()

# Пути к исходникам и тестам
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(TEST_DIR "${CMAKE_SOURCE_DIR}/tests")

# Добавляем исполняемый файл для основной программы
add_executable(main src/main.cpp ${SRC_DIR}/solution.cpp)

# Подключаем библиотеку Google Test через FetchContent (она автоматически загрузит и соберет Google Test)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.11.0.zip
)
# Принудительное использование статических библиотек
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Добавляем исполняемый файл для тестов
add_executable(unit_tests ${TEST_DIR}/unit_tests.cpp ${SRC_DIR}/solution.cpp)

# Линкуем тесты с библиотекой Google Test и основным решением
target_link_libraries(unit_tests gtest_main)

# Добавляем тесты для CTest
add_test(NAME unit_tests COMMAND unit_tests)


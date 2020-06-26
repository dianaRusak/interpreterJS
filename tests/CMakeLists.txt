project(unit_tests)

set(CMAKE_CXX_STANDARD 17)

SET(TEST_SOURCES
        test_test.cpp)

add_executable(interpreter_tests ${TEST_SOURCES})
target_link_libraries(interpreter_tests PRIVATE interpreter_lib catch)

add_executable(interpreter_coverage ${TEST_SOURCES})
target_link_libraries(interpreter_coverage PRIVATE interpreter_lib catch)
target_compile_options(interpreter_coverage PRIVATE -g -O0 -Wall -fprofile-arcs -ftest-coverage)
set_target_properties(interpreter_coverage PROPERTIES LINK_FLAGS "${LINK_FLAGS} -fprofile-arcs")
project(unit_tests)

SET(TEST_SOURCES
        test_test.cpp
        data/additive/test_test.cpp
        data/array/test_test.cpp
        data/assignment/test_test.cpp
        data/binary/test_test.cpp
        data/binary-bitwise/test_test.cpp
        data/binary-logical/test_test.cpp
        data/bitwise-shift/test_test.cpp
        data/complex/test_test.cpp
        data/conditional/test_test.cpp
        data/equality/test_test.cpp
        data/grouping/test_test.cpp
        data/left-hand-side/test_test.cpp
        data/multiplicative/test_test.cpp
        data/numeric-literal/test_test.cpp
        data/object/test_test.cpp
        data/other/test_test.cpp
        data/postfix/test_test.cpp)

add_executable(interpreter_tests ${TEST_SOURCES})
target_link_libraries(interpreter_tests PRIVATE interpreter_lib catch)

add_executable(interpreter_coverage ${TEST_SOURCES})
target_link_libraries(interpreter_coverage PRIVATE interpreter_lib catch)
target_compile_options(interpreter_coverage PRIVATE -g -O0 -Wall -fprofile-arcs -ftest-coverage)
set_target_properties(interpreter_coverage PROPERTIES LINK_FLAGS "${LINK_FLAGS} -fprofile-arcs")
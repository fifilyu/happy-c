enable_testing()

SET(OUTPUT_DIR ${CMAKE_BINARY_DIR}/bin)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})

ADD_EXECUTABLE(log_test ${CMAKE_CURRENT_SOURCE_DIR}/test/log_test.c)
TARGET_LINK_LIBRARIES(log_test happyc ${CHECK_LIBRARIES})
ADD_TEST(NAME log_test COMMAND log_test)
ADD_CUSTOM_TARGET(valgrind_log_test
        COMMAND ${VALGRIND_PROGRAM} --leak-check=full $<TARGET_FILE:log_test>
        DEPENDS log_test)
#ADD_CUSTOM_COMMAND(TARGET log_test
#        POST_BUILD
#        COMMAND make valgrind_log_test)
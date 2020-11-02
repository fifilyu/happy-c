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

ADD_EXECUTABLE(base64_test ${CMAKE_CURRENT_SOURCE_DIR}/test/base64_test.c)
TARGET_LINK_LIBRARIES(base64_test happyc ${CHECK_LIBRARIES})
ADD_TEST(NAME base64_test COMMAND base64_test)
ADD_CUSTOM_TARGET(valgrind_base64_test
        COMMAND ${VALGRIND_PROGRAM} --leak-check=full $<TARGET_FILE:base64_test>
        DEPENDS base64_test)
#ADD_CUSTOM_COMMAND(TARGET base64_test
#        POST_BUILD
#        COMMAND make valgrind_base64_test)

ADD_EXECUTABLE(list_test ${CMAKE_CURRENT_SOURCE_DIR}/test/list_test.c)
TARGET_LINK_LIBRARIES(list_test happyc ${CHECK_LIBRARIES})
ADD_TEST(NAME list_test COMMAND list_test)
ADD_CUSTOM_TARGET(valgrind_list_test
        COMMAND ${VALGRIND_PROGRAM} --leak-check=full $<TARGET_FILE:list_test>
        DEPENDS list_test)
#ADD_CUSTOM_COMMAND(TARGET list_test
#        POST_BUILD
#        COMMAND make valgrind_list_test)

ADD_EXECUTABLE(csv_test ${CMAKE_CURRENT_SOURCE_DIR}/test/csv_test.c)
TARGET_LINK_LIBRARIES(csv_test happyc ${CHECK_LIBRARIES})
ADD_TEST(NAME csv_test COMMAND csv_test)
ADD_CUSTOM_TARGET(valgrind_csv_test
        COMMAND ${VALGRIND_PROGRAM} --leak-check=full $<TARGET_FILE:csv_test>
        DEPENDS csv_test)
#ADD_CUSTOM_COMMAND(TARGET csv_test
#        POST_BUILD
#        COMMAND make valgrind_csv_test)

ADD_EXECUTABLE(map_test ${CMAKE_CURRENT_SOURCE_DIR}/test/map_test.c)
TARGET_LINK_LIBRARIES(map_test happyc ${CHECK_LIBRARIES})
ADD_TEST(NAME map_test COMMAND map_test)
ADD_CUSTOM_TARGET(valgrind_map_test
        COMMAND ${VALGRIND_PROGRAM} --leak-check=full $<TARGET_FILE:map_test>
        DEPENDS map_test)
#ADD_CUSTOM_COMMAND(TARGET map_test
#        POST_BUILD
#        COMMAND make valgrind_map_test)
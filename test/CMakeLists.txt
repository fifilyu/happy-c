SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

IF (CMAKE_COMPILER_IS_GNUCC)
    include_directories(${CHECK_INCLUDE_DIR})
    SET(DEP_LIBS ${CHECK_LIBRARIES})
ENDIF ()

FUNCTION(ADD_UNITTEST unittest_name src_files)
    ADD_EXECUTABLE(${unittest_name} ${src_files})
    TARGET_LINK_LIBRARIES(${unittest_name} happyc ${DEP_LIBS})

    ADD_TEST(NAME ${unittest_name} COMMAND ${unittest_name})

    IF (CMAKE_COMPILER_IS_GNUCC)
        ADD_CUSTOM_TARGET(valgrind_${unittest_name}
                COMMAND ${VALGRIND_PROGRAM} --leak-check=full $<TARGET_FILE:${unittest_name}>
                DEPENDS ${unittest_name})
        #ADD_CUSTOM_COMMAND(TARGET ${unittest_name}
        #        POST_BUILD
        #        COMMAND make valgrind_${unittest_name})
    ENDIF ()
ENDFUNCTION(ADD_UNITTEST)

ADD_UNITTEST(log_test log_test.c)

IF (CMAKE_COMPILER_IS_GNUCC)
    ADD_UNITTEST(base64_test base64_test.c)
    ADD_UNITTEST(list_test list_test.c)
    ADD_UNITTEST(csv_test csv_test.c)
    ADD_UNITTEST(map_test map_test.c)
    ADD_UNITTEST(byte_test byte_test.c)
    ADD_UNITTEST(date_test date_test.c)
ENDIF ()

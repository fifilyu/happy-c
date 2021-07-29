IF (MSVC)
    #省略默认库，生成的库文件中不包含libcmt.lib这样的默认库
    SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} /Zl")
    SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} /Zl")
ENDIF ()

SET(SRC_LIST
        csv.c
        log.c
        filesys.c
        date.c
        list.c
        base64/buffer.c
        base64/decode.c
        base64/encode.c
        map.c
        byte.c)

IF (MSVC)
    ADD_LIBRARY(happyc STATIC ${SRC_LIST})
    TARGET_LINK_LIBRARIES(happyc)
ELSE ()
    ADD_LIBRARY(happyc SHARED ${SRC_LIST})
    TARGET_LINK_LIBRARIES(happyc)
ENDIF ()

INSTALL(TARGETS happyc LIBRARY DESTINATION lib)
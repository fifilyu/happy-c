IF (MSVC)
    SET(CMAKE_C_FLAGS_RELEASE "/MT /O2 /Ob2")
    # /Z7 将pdb合并到库文件
    # /Zi 生成单独的pdb文件
    SET(CMAKE_C_FLAGS_DEBUG "/MTd /Z7 /Ob0 /Od")
    # /Za 启用MSVC的C99支持
    # By default, when code is compiled as C, the MSVC compiler doesn't conform to a particular C standard.
    # It implements ANSI C89 with several Microsoft extensions, some of which are part of ISO C99. Some
    # Microsoft extensions can be disabled by using the /Za compiler option, but others remain in effect.
    # It isn't possible to specify strict C89 conformance.
    SET(CMAKE_C_FLAGS "/Za")
ENDIF ()


IF (CMAKE_COMPILER_IS_GNUCC)
    SET(CMAKE_C_FLAGS "-std=c99 -fPIC -Wall -Wno-deprecated-declarations")
    SET(CMAKE_C_FLAGS_DEBUG "-Wall -Wextra -pedantic -Werror -O0 -g -ggdb")
ENDIF ()

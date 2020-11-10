CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(happy-c C)

SET(CMAKE_C_STANDARD 99)

IF(MSVC)
    SET(BUILD_MODE STATIC)
ELSE()
    SET(BUILD_MODE SHARED)
ENDIF()

# 设置默认 CMAKE_BUILD_TYPE 为 release
IF(NOT CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE Release
            CACHE STRING
            "Choose the type of build, options are: Debug Release \
          RelWithDebInfo MinSizeRel."
            FORCE)
ENDIF(NOT CMAKE_BUILD_TYPE)

INCLUDE(cmake/FindPackage.cmake)
INCLUDE(cmake/CompilerFlags.cmake)

SET(HAPPYC_VERSION_MAJOR 0)
SET(HAPPYC_VERSION_MINOR 1)
SET(HAPPYC_VERSION_PATCH 0)
SET(HAPPYC_VERSION "${HAPPYC_VERSION_MAJOR}.${HAPPYC_VERSION_MINOR}.${HAPPYC_VERSION_PATCH}")

INCLUDE_DIRECTORIES(include)

IF(MSVC)
    SET(HAPPYC_SHAREDLIB OFF CACHE BOOL
            "如果值为 ON，HAPPYC 将构建为共享库, 反之为静态库。")
ELSE()
    SET(HAPPYC_SHAREDLIB ON CACHE BOOL
            "如果值为 ON，HAPPYC 将构建为共享库, 反之为静态库。")
ENDIF()

# 所有使用 happy-c 静态库的项目都必须定义 HAPPYC_STATICLIB 宏
IF(NOT HAPPYC_SHAREDLIB)
    ADD_DEFINITIONS("-DHAPPYC_STATICLIB")
ENDIF()

# 设置安装路径（CMAKE_INSTALL_PREFIX 只能在主 CMake 配置中生效，不能在包含的其它目录设置）
IF(MSVC)
# 在 64 位系统上，32 位程序会安装到 C:/Program Files (x86)
# 在 64 位系统上，64 位程序会安装到 C:/Program Files
# 在 32 位系统上，程序会安装到 C:/Program Files
    string(REPLACE
            "happy-c"
            "happyc"
            NEW_INSTALL_PREFIX
            ${CMAKE_INSTALL_PREFIX})
    SET(CMAKE_INSTALL_PREFIX ${NEW_INSTALL_PREFIX})
ELSE()
    SET(CMAKE_INSTALL_PREFIX /usr/local/happyc)
ENDIF()

INSTALL(DIRECTORY include/happyc DESTINATION include)

# ENABLE_TESTING 只能在主 CMake 配置中设置或INCLUDE，不能在ADD_SUBDIRECTORY的其它目录设置
ENABLE_TESTING()

ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(test)


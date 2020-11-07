//
// Created by lyuqiang on 2020/11/3.
//

#ifndef HAPPY_C_PLATFORM_H
#define HAPPY_C_PLATFORM_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__unix__) || defined(unix)
#   define PLATFORM_LINUX 1
#elif defined(__arm__)
#   define PLATFORM_ARM 1
#else
#   error Unsupported platform
#endif

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
}
#endif

#endif //HAPPY_C_PLATFORM_H

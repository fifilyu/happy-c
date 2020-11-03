//
// Created by lyuqiang on 2020/11/3.
//

#ifndef HAPPY_C_PLATFORM_H
#define HAPPY_C_PLATFORM_H

#if defined(__unix__) || defined(unix)
#   define PLATFORM_LINUX 1
#elif defined(__arm__)
#   define PLATFORM_ARM 1
#else
#   error Unsupported platform
#endif

#endif //HAPPY_C_PLATFORM_H

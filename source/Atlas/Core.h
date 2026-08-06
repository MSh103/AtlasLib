#pragma once

#ifdef AT_PLATFORM_WINDOWS
#include <print>
#else
#error Atlas currently only supports Windows
#endif


#ifdef AT_DEBUG
#define AT_ENABLE_ASSERTS
#endif

#ifdef AT_ENABLE_ASSERTS
#define AT_ASSERT(x, ...) { if(!(x)) { std::println("Assertion Failed: {}", __VA_ARGS__); __debugbreak(); }}
#else
#define AT_ASSERT(x, ...)
#endif

// clang-format off
#ifndef GRIMOIRE_COMMON_H
#define GRIMOIRE_COMMON_H

#if !defined(_WIN32) && (defined(__WIN32__) || defined(WIN32) || defined(__MINGW32__))
    #define _WIN32
#endif

#ifdef _WIN32
    #ifdef _GRIMOIRE_BUILD
        #define GRIMOIRE_API __declspec(dllexport)
    #else
        #define GRIMOIRE_API __declspec(dllimport)
    #endif
#elif (defined(__GNUC__) && __GNUC__ >= 4) || defined(__clang__)
    #define GRIMOIRE_API __attribute__ ((visibility("default")))
#endif

#ifndef GRIMOIRE_API
    #define GRIMOIRE_API
#endif

#ifdef _MSC_VER
    #define GRIMOIRE_DEPRECATED(msg) __declspec(deprecated(msg))
#elif defined(__GNUC__) || defined(__clang__)
    #define GRIMOIRE_DEPRECATED(msg) __attribute__((deprecated(msg)))
#else
    #define GRIMOIRE_DEPRECATED(msg)
#endif

#ifdef __cplusplus
    #define GRIMOIRE_BEGIN extern "C" {
    #define GRIMOIRE_END }
#else
    #define GRIMOIRE_BEGIN
    #define GRIMOIRE_END
#endif

#include <stdbool.h>
#include <stdint.h>

/**
 * @typedef hash_t
 * @brief 32-bit signed integer used as a deterministic seed.
 *
 * Can be used for RNGs, noise generation, or any system requiring a reproducible
 * pseudo-random value. Ensures consistent output given the same seed.
 */
typedef int32_t hash_t;

#endif // GRIMOIRE_COMMON_H
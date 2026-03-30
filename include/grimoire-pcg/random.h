/**
 * @file random.h
 * @brief Knuth‑derived pseudo-random number generator (RNG)
 *
 * Provides an opaque RNG API based on algorithms derived from Donald Knuth’s work.
 * Supports creation, seeding, destruction, generating integers/floats, filling buffers,
 * and serializing/deserializing state for reproducible sequences.
 *
 * The internal implementation is hidden to allow future changes without breaking
 * compatibility.
 *
 * @author Stellar Wolf Entertainment
 * @version 1.0.0
 * @date 2026‑02‑14
 */
#ifndef GRIMOIRE_RANDOM_H
#define GRIMOIRE_RANDOM_H

#include "common.h"

GRIMOIRE_BEGIN

/**
 * @typedef GrimoireRandom_t
 * @brief Opaque RNG instance structure.
 *
 * Users interact with this only through the `GrimoireRandom` handle.
 */
typedef struct GrimoireRandom_t GrimoireRandom_t;

/**
 * @def GrimoireRandom
 * @brief Pointer type to an opaque RNG instance.
 */
#define GrimoireRandom GrimoireRandom_t*

/**
 * @brief Creates a new RNG with a non-deterministic seed.
 *
 * @return A new RNG instance, or `NULL` on failure.
 */
GRIMOIRE_API GrimoireRandom GrimoireRandom_CreateNew();

/**
 * @brief Creates a new RNG with a specific 32-bit seed.
 *
 * @param seed Seed value for deterministic sequences.
 * @return A new RNG instance, or `NULL` on failure.
 */
GRIMOIRE_API GrimoireRandom GrimoireRandom_CreateSeed(hash_t seed);

/**
 * @brief Destroys an RNG instance, freeing all associated memory.
 *
 * Safe to pass `NULL`.
 *
 * @param random RNG instance to destroy.
 */
GRIMOIRE_API void GrimoireRandom_Destroy(GrimoireRandom random);

/**
 * @brief Generates a 32-bit pseudo-random integer.
 *
 * @param random RNG instance.
 * @return Signed 32-bit integer.
 */
GRIMOIRE_API int32_t GrimoireRandom_Next(GrimoireRandom random);

/**
 * @brief Generates a random integer within [min, max].
 *
 * Behavior undefined if min > max.
 *
 * @param random RNG instance.
 * @param min Minimum value (inclusive).
 * @param max Maximum value (inclusive).
 * @return Random integer in [min, max].
 */
GRIMOIRE_API int32_t GrimoireRandom_NextRange(GrimoireRandom random, int32_t min, int32_t max);

/**
 * @brief Generates a random integer within [0, max].
 *
 * Equivalent to `GrimoireRandom_NextRange(random, 0, max)`.
 *
 * @param random RNG instance.
 * @param max Maximum value (inclusive, must be >= 0).
 * @return Random integer in [0, max].
 */
GRIMOIRE_API int32_t GrimoireRandom_NextMax(GrimoireRandom random, int32_t max);

/**
 * @brief Generates a uniform double in [0.0, 1.0).
 *
 * @param random RNG instance.
 * @return Double in [0.0, 1.0).
 */
GRIMOIRE_API double GrimoireRandom_NextDouble(GrimoireRandom random);

/**
 * @brief Fills a buffer with random bytes.
 *
 * Example:
 * @code
 * int32_t values[16];
 * GrimoireRandom_NextBytes(random, values, sizeof(values));
 * @endcode
 *
 * @param random RNG instance.
 * @param buffer Pointer to buffer to fill.
 * @param length Number of bytes to write.
 */
GRIMOIRE_API void GrimoireRandom_NextBytes(GrimoireRandom random, void* buffer, size_t length);

/**
 * @brief Serializes RNG state into a buffer (>= 228 bytes).
 *
 * Layout is implementation-defined but size is fixed in this release.
 *
 * @param random RNG instance.
 * @param buffer Output buffer.
 */
GRIMOIRE_API void GrimoireRandom_Serialize(GrimoireRandom random, uint8_t* buffer);

/**
 * @brief Restores an RNG from serialized state (>= 228 bytes).
 *
 * @param buffer Input buffer produced by `GrimoireRandom_Serialize`.
 * @return New RNG instance, or `NULL` on failure.
 */
GRIMOIRE_API GrimoireRandom GrimoireRandom_Deserialize(const uint8_t* buffer);

/**
 * @brief Clones an RNG into an existing instance.
 *
 * The new instance has identical state and produces the same sequence.
 *
 * @param source Source RNG.
 * @param destination Pointer to store the new instance.
 */
GRIMOIRE_API void GrimoireRandom_CloneInto(const GrimoireRandom source, GrimoireRandom destination);

/**
 * @brief Clones an RNG and returns the new instance.
 *
 * Allocates a new instance. Caller must destroy it when done.
 *
 * @param source Source RNG.
 * @return New RNG instance with identical state, or `NULL` on failure.
 */
GRIMOIRE_API GrimoireRandom GrimoireRandom_Clone(const GrimoireRandom source);

GRIMOIRE_END

#endif // GRIMOIRE_RANDOM_H
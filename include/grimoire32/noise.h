/**
 * @file noise.h
 * @brief Noise generation functions and fractal settings
 *
 * This header defines the interface for various noise generation functions, including value noise and Perlin noise in
 * 1D, 2D, and 3D. It also defines a structure for fractal noise settings and a function to compute fractal noise based
 * on a given noise function. The noise functions take a seed value to allow for deterministic noise generation, and the
 * fractal function allows for combining multiple octaves of noise with configurable parameters. The implementation of
 * these functions is expected to be in a corresponding source file (e.g., `noise.c`), where the actual algorithms for
 * noise generation will be defined.
 *
 * @author Stellar Wolf Entertainment
 * @version 1.0.0
 * @date 2026‑03-01
 */
#ifndef GRIMOIRE_NOISE_H
#define GRIMOIRE_NOISE_H

#include "common.h"

GRIMOIRE_BEGIN

/**
 * @typedef hash_t
 * @brief Type used for noise hashing and seeding.
 *
 * This type is used as the seed for noise generation functions and for hashing coordinates to produce pseudo-random
 * gradients or values. It is defined as a 32-bit signed integer, which provides a large range of possible seeds while
 * maintaining efficient storage and computation. The choice of a signed integer allows for both positive and negative
 * seed values, which can be useful for certain applications or to provide a wider variety of noise patterns. The actual
 * noise generation algorithms will use this type to compute hash values based on the input coordinates and the seed,
 * ensuring that the same seed produces the same noise pattern consistently.
 */
typedef int32_t hash_t;

/**
 * @struct GrimoireFractalSettings
 * @brief Configuration settings for fractal noise generation.
 *
 * This structure encapsulates the parameters used to control the behavior of fractal noise generation. The `frequency`
 * parameter determines the base frequency of the noise, which affects the scale of the noise features. The `octaves`
 * parameter specifies the number of layers of noise to combine, with each octave adding finer details to the noise
 * pattern. The `lacunarity` parameter controls the frequency multiplier for each successive octave, typically set
 * to 2.0 for standard fractal noise. The `persistence` parameter determines how much each octave contributes to the
 * final noise, with lower values resulting in smoother noise and higher values creating more roughness. Finally, the
 * `staticSeed` boolean flag indicates whether to use a static seed for each octave (true) or a shifting seed (false),
 * which affects the continuity and variation of the fractal noise pattern.
 */
typedef struct GrimoireFractalSettings
{
    float frequency;   //< Base frequency of the noise.
    uint32_t octaves;  //< Number of noise layers to combine.
    float lacunarity;  //< Frequency multiplier for each octave (commonly 2.0).
    float persistence; //< Amplitude multiplier for each octave (commonly 0.5).
    bool staticSeed;   //< Whether to use a static seed for each octave (true) or a shifting seed (false).
} GrimoireFractalSettings;

/**
 * @typedef GrimoireNoiseFunction
 * @brief Function pointer type for noise generation functions.
 *
 * This type defines a pointer to a noise generation function that takes three float parameters (x, y, z) representing
 * the coordinates at which to evaluate the noise, and a `hash_t` seed for deterministic noise generation. The function
 * returns a float value representing the noise at the given coordinates, typically in the range [0.0, 1.0]. This
 * function pointer type allows for flexible use of different noise generation algorithms (e.g., value noise, Perlin
 * noise) in a consistent manner, enabling the fractal noise function to accept any compatible noise function as an
 * argument.
 *
 * @param x The x-coordinate for noise evaluation.
 * @param y The y-coordinate for noise evaluation.
 * @param z The z-coordinate for noise evaluation.
 * @param seed The seed value for deterministic noise generation.
 * @return The noise value at the given coordinates, typically in the range [0.0, 1.0].
 */
typedef float (*GrimoireNoiseFunction)(float x, float y, float z, hash_t seed);

/**
 * @brief Generates 1D value noise with sharp transitions.
 *
 * This function computes value noise in one dimension, producing a noise pattern with sharp transitions between values.
 * The noise is generated based on the input coordinates (x, y, z) and a seed value for deterministic output. The
 * resulting noise value is typically in the range [0.0, 1.0], where the sharp transitions create a more blocky or
 * pixelated appearance compared to smooth noise.
 *
 * @param x The x-coordinate for noise evaluation.
 * @param y The y-coordinate for noise evaluation (ignored in 1D noise).
 * @param z The z-coordinate for noise evaluation (ignored in 1D noise).
 * @param seed The seed value for deterministic noise generation.
 * @return The 1D value noise at the given coordinates, with sharp transitions.
 */
GRIMOIRE_API float Grimoire_ValueSharp1D(float x, float y, float z, hash_t seed);

/**
 * @brief Generates 2D value noise with sharp transitions.
 *
 * This function computes value noise in two dimensions, producing a noise pattern with sharp transitions between
 * values. The noise is generated based on the input coordinates (x, y) and a seed value for deterministic output. The
 * resulting noise value is typically in the range [0.0, 1.0], where the sharp transitions create a more blocky or
 * pixelated appearance compared to smooth noise.
 *
 * @param x The x-coordinate for noise evaluation.
 * @param y The y-coordinate for noise evaluation.
 * @param z The z-coordinate for noise evaluation (ignored in 2D noise).
 * @param seed The seed value for deterministic noise generation.
 * @return The 2D value noise at the given coordinates, with sharp transitions.
 */
GRIMOIRE_API float Grimoire_ValueSharp2D(float x, float y, float z, hash_t seed);

/**
 * @brief Generates 3D value noise with sharp transitions.
 *
 * This function computes value noise in three dimensions, producing a noise pattern with sharp transitions between
 * values. The noise is generated based on the input coordinates (x, y, z) and a seed value for deterministic output.
 * The resulting noise value is typically in the range [0.0, 1.0], where the sharp transitions create a more blocky or
 * pixelated appearance compared to smooth noise.
 *
 * @param x The x-coordinate for noise evaluation.
 * @param y The y-coordinate for noise evaluation.
 * @param z The z-coordinate for noise evaluation.
 * @param seed The seed value for deterministic noise generation.
 * @return The 3D value noise at the given coordinates, with sharp transitions.
 */
GRIMOIRE_API float Grimoire_ValueSharp3D(float x, float y, float z, hash_t seed);

/**
 * @brief Generates 1D value noise with smooth transitions.
 *
 * This function computes value noise in one dimension, producing a noise pattern with smooth transitions between
 * values. The noise is generated based on the input coordinates (x, y, z) and a seed value for deterministic output.
 * The resulting noise value is typically in the range [0.0, 1.0], where the smooth transitions create a more natural
 * and continuous appearance compared to sharp noise.
 *
 * @param x The x-coordinate for noise evaluation.
 * @param y The y-coordinate for noise evaluation (ignored in 1D noise).
 * @param z The z-coordinate for noise evaluation (ignored in 1D noise).
 * @param seed The seed value for deterministic noise generation.
 * @return The 1D value noise at the given coordinates, with smooth transitions.
 */
GRIMOIRE_API float Grimoire_ValueSmooth1D(float x, float y, float z, hash_t seed);

/**
 * @brief Generates 2D value noise with smooth transitions.
 *
 * This function computes value noise in two dimensions, producing a noise pattern with smooth transitions between
 * values. The noise is generated based on the input coordinates (x, y) and a seed value for deterministic output. The
 * resulting noise value is typically in the range [0.0, 1.0], where the smooth transitions create a more natural and
 * continuous appearance compared to sharp noise.
 *
 * @param x The x-coordinate for noise evaluation.
 * @param y The y-coordinate for noise evaluation.
 * @param z The z-coordinate for noise evaluation (ignored in 2D noise).
 * @param seed The seed value for deterministic noise generation.
 * @return The 2D value noise at the given coordinates, with smooth transitions.
 */
GRIMOIRE_API float Grimoire_ValueSmooth2D(float x, float y, float z, hash_t seed);

/**
 * @brief Generates 3D value noise with smooth transitions.
 *
 * This function computes value noise in three dimensions, producing a noise pattern with smooth transitions between
 * values. The noise is generated based on the input coordinates (x, y, z) and a seed value for deterministic output.
 * The resulting noise value is typically in the range [0.0, 1.0], where the smooth transitions create a more natural
 * and continuous appearance compared to sharp noise.
 *
 * @param x The x-coordinate for noise evaluation.
 * @param y The y-coordinate for noise evaluation.
 * @param z The z-coordinate for noise evaluation.
 * @param seed The seed value for deterministic noise generation.
 * @return The 3D value noise at the given coordinates, with smooth transitions.
 */
GRIMOIRE_API float Grimoire_ValueSmooth3D(float x, float y, float z, hash_t seed);

/**
 * @brief Generates 1D Perlin noise.
 *
 * This function computes Perlin noise in one dimension, producing a noise pattern with smooth gradients and natural
 * variations. The noise is generated based on the input coordinates (x, y, z) and a seed value for deterministic
 * output. The resulting noise value is typically in the range [0.0, 1.0], where the smooth gradients create a more
 * natural and continuous appearance compared to value noise.
 *
 * @param x The x-coordinate for noise evaluation.
 * @param y The y-coordinate for noise evaluation (ignored in 1D noise).
 * @param z The z-coordinate for noise evaluation (ignored in 1D noise).
 * @param seed The seed value for deterministic noise generation.
 * @return The 1D Perlin noise at the given coordinates.
 */
GRIMOIRE_API float Grimoire_Perlin1D(float x, float y, float z, hash_t seed);

/**
 * @brief Generates 2D Perlin noise.
 *
 * This function computes Perlin noise in two dimensions, producing a noise pattern with smooth gradients and natural
 * variations. The noise is generated based on the input coordinates (x, y) and a seed value for deterministic output.
 * The resulting noise value is typically in the range [0.0, 1.0], where the smooth gradients create a more natural and
 * continuous appearance compared to value noise.
 *
 * @param x The x-coordinate for noise evaluation.
 * @param y The y-coordinate for noise evaluation.
 * @param z The z-coordinate for noise evaluation (ignored in 2D noise).
 * @param seed The seed value for deterministic noise generation.
 * @return The 2D Perlin noise at the given coordinates.
 */
GRIMOIRE_API float Grimoire_Perlin2D(float x, float y, float z, hash_t seed);

/**
 * @brief Generates 3D Perlin noise.
 *
 * This function computes Perlin noise in three dimensions, producing a noise pattern with smooth gradients and natural
 * variations. The noise is generated based on the input coordinates (x, y, z) and a seed value for deterministic
 * output. The resulting noise value is typically in the range [0.0, 1.0], where the smooth gradients create a more
 * natural and continuous appearance compared to value noise.
 *
 * @param x The x-coordinate for noise evaluation.
 * @param y The y-coordinate for noise evaluation.
 * @param z The z-coordinate for noise evaluation.
 * @param seed The seed value for deterministic noise generation.
 * @return The 3D Perlin noise at the given coordinates.
 */
GRIMOIRE_API float Grimoire_Perlin3D(float x, float y, float z, hash_t seed);

/**
 * @brief Generates fractal noise by combining multiple octaves of a base noise function.
 *
 * This function computes fractal noise by summing multiple octaves of a given base noise function. The behavior of the
 * fractal noise is controlled by the parameters specified in the `GrimoireFractalSettings` structure, which includes
 * the base frequency, number of octaves, lacunarity, persistence, and whether to use fractional Brownian motion (fBm).
 * The noise is generated based on the input coordinates (x, y, z) and a seed value for deterministic output. The
 * resulting noise value is typically in the range [0.0, 1.0], where the combination of octaves creates a more complex
 * and natural appearance compared to single-octave noise.
 *
 * @param noiseFunc The base noise function to use for generating each octave (e.g., Perlin or value noise).
 * @param x The x-coordinate for noise evaluation.
 * @param y The y-coordinate for noise evaluation.
 * @param z The z-coordinate for noise evaluation.
 * @param seed The seed value for deterministic noise generation.
 * @param settings Pointer to a `GrimoireFractalSettings` structure that defines the parameters for fractal noise
 * generation.
 * @return The fractal noise value at the given coordinates, based on the specified settings.
 */
GRIMOIRE_API float Grimoire_Fractal(GrimoireNoiseFunction noiseFunc, float x, float y, float z, hash_t seed,
                                    const GrimoireFractalSettings* settings);

/**
 * @brief Generates billow noise by combining multiple octaves of a base noise function with absolute value.
 *
 * This function computes billow noise by summing multiple octaves of a given base noise function, where each octave's
 * contribution is modified by taking the absolute value of the noise. The behavior of the billow noise is controlled by
 * the parameters specified in the `GrimoireFractalSettings` structure, which includes the base frequency, number of
 * octaves, lacunarity, persistence, and whether to use fractional Brownian motion (fBm). The noise is generated based
 * on the input coordinates (x, y, z) and a seed value for deterministic output. The resulting noise value is typically
 * in the range [0.0, 1.0], where the combination of octaves and the absolute value operation creates a more billowy and
 * cloud-like appearance compared to standard fractal noise.
 *
 * @param noiseFunc The base noise function to use for generating each octave (e.g., Perlin or value noise).
 * @param x The x-coordinate for noise evaluation.
 * @param y The y-coordinate for noise evaluation.
 * @param z The z-coordinate for noise evaluation.
 * @param seed The seed value for deterministic noise generation.
 * @param settings Pointer to a `GrimoireFractalSettings` structure that defines the
 * parameters for billow noise generation.
 * @return The billow noise value at the given coordinates, based on the specified settings.
 */
GRIMOIRE_API float Grimoire_Billow(GrimoireNoiseFunction noiseFunc, float x, float y, float z, hash_t seed,
                                   const GrimoireFractalSettings* settings);

GRIMOIRE_END

#endif // !GRIMOIRE_NOISE_H
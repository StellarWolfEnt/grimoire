#include <grimoire32/internal/noise.h>
#include <grimoire32/noise.h>

static uint32_t Grimoire_WangHash(uint32_t x);

GRIMOIRE_API float Grimoire_Fractal(GrimoireNoiseFunction noiseFunc, float x, float y, float z, hash_t seed,
                                    const GrimoireFractalSettings* settings)
{
    x *= settings->frequency;
    y *= settings->frequency;
    z *= settings->frequency;

    float v = 0.0f;
    float a = 1.0f;
    float r = 0.0f;

    for (uint32_t i = 0; i < settings->octaves; ++i)
    {
        v += noiseFunc(x, y, z, seed) * a;
        r += a;

        x *= settings->lacunarity;
        y *= settings->lacunarity;
        z *= settings->lacunarity;

        a *= settings->persistence;
        seed += !settings->staticSeed;
    }

    return v / r;
}

GRIMOIRE_API float Grimoire_Billow(GrimoireNoiseFunction noiseFunc, float x, float y, float z, hash_t seed,
                                   const GrimoireFractalSettings* settings)
{
    x *= settings->frequency;
    y *= settings->frequency;
    z *= settings->frequency;

    float v = 0.0f;
    float a = 1.0f;
    float r = 0.0f;

    for (uint32_t i = 0; i < settings->octaves; ++i)
    {
        float s = noiseFunc(x, y, z, seed) * 2.0f - 1.0f;
        s = fabsf(s);
        v += s * a;
        r += a;

        x *= settings->lacunarity;
        y *= settings->lacunarity;
        z *= settings->lacunarity;

        a *= settings->persistence;
        seed += !settings->staticSeed;
    }

    return v / r;
}

uint8_t Grimoire_NoiseHash(hash_t seed, int32_t x, int32_t y, int32_t z)
{
    uint32_t h = seed;

    h ^= Grimoire_WangHash(x);
    h *= 0x27d4eb2d;

    h ^= Grimoire_WangHash(y);
    h *= 0x165667b1;

    h ^= Grimoire_WangHash(z);
    h *= 0x9e3779b9;

    return Grimoire_WangHash(h);
}

float Grimoire_NoiseSmooth(float t)
{
    return t * t * t * (t * (t * 6.0f - 15.0f) + 10.0f);
}

float Grimoire_NoiseLerp(float a, float b, float t)
{
    return a + ((b - a) * t);
}

float Grimoire_Dot2(vec2 a, float x2, float y2)
{
    return (a.x * x2) + (a.y * y2);
}

float Grimoire_Dot3(vec3 a, float x2, float y2, float z2)
{
    return (a.x * x2) + (a.y * y2) + (a.z * z2);
}

uint32_t Grimoire_WangHash(uint32_t x)
{
    x = (x ^ 61) ^ (x >> 16);
    x *= 9;
    x = x ^ (x >> 4);
    x *= 0x27d4eb2d;
    x = x ^ (x >> 15);
    return x;
}
#ifndef GRIMOIRE_INTERNAL_NOISE_H
#define GRIMOIRE_INTERNAL_NOISE_H

#include <grimoire32/noise.h>
#include <math.h>

GRIMOIRE_BEGIN

typedef struct
{
    float x, y;
} vec2;

typedef struct
{
    float x, y, z;
} vec3;

static const float INV_255 = 1.0f / 255.0f;

uint8_t Grimoire_NoiseHash(hash_t seed, int32_t x, int32_t y, int32_t z);
float Grimoire_NoiseSmooth(float t);
float Grimoire_NoiseLerp(float a, float b, float t);

float Grimoire_Dot2(vec2 a, float x2, float y2);
float Grimoire_Dot3(vec3 a, float x2, float y2, float z2);

GRIMOIRE_END

#endif // !GRIMOIRE_INTERNAL_NOISE_H
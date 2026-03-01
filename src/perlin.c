#include <grimoire32/internal/noise.h>
#include <grimoire32/noise.h>

static const float SQRT_2 = 1.41421356237f;

static const float GRAD_1D[2] = {1.0f, -1.0f};
static const vec2 GRAD_2D[8] = {{1.0f, 0.0f},
                                {-1.0f, 0.0f},
                                {0.0f, 1.0f},
                                {0.0f, -1.0f},
                                {0.70710678f, 0.70710678f},
                                {-0.70710678f, 0.70710678f},
                                {0.70710678f, -0.70710678f},
                                {-0.70710678f, -0.70710678f}};

static const vec3 GRAD_3D[16] = {{1.0f, 1.0f, 0.0f}, {-1.0f, 1.0f, 0.0f}, {1.0f, -1.0f, 0.0f}, {-1.0f, -1.0f, 0.0f},
                                 {1.0f, 0.0f, 1.0f}, {-1.0f, 0.0f, 1.0f}, {1.0f, 0.0f, -1.0f}, {-1.0f, 0.0f, -1.0f},
                                 {0.0f, 1.0f, 1.0f}, {0.0f, -1.0f, 1.0f}, {0.0f, 1.0f, -1.0f}, {0.0f, -1.0f, -1.0f},
                                 {1.0f, 1.0f, 0.0f}, {-1.0f, 1.0f, 0.0f}, {0.0f, -1.0f, 1.0f}, {0.0f, -1.0f, -1.0f}};

GRIMOIRE_API float Grimoire_Perlin1D(float x, float y, float z, hash_t seed)
{
    int iX0 = (int) floorf(x);

    int iX1 = iX0 + 1;

    float tX0 = x - iX0;

    float tX1 = tX0 - 1.0f;

    float tX = Grimoire_NoiseSmooth(tX0);

    float h0 = GRAD_1D[Grimoire_NoiseHash(seed, iX0, 0, 0) & 1];
    float h1 = GRAD_1D[Grimoire_NoiseHash(seed, iX1, 0, 0) & 1];

    float v0 = h0 * tX0;
    float v1 = h1 * tX1;

    return Grimoire_NoiseLerp(v0, v1, tX) + 0.5f;
}

GRIMOIRE_API float Grimoire_Perlin2D(float x, float y, float z, hash_t seed)
{
    int iX0 = (int) floorf(x);
    int iY0 = (int) floorf(y);

    int iX1 = iX0 + 1;
    int iY1 = iY0 + 1;

    float tX0 = x - iX0;
    float tY0 = y - iY0;

    float tX1 = tX0 - 1.0f;
    float tY1 = tY0 - 1.0f;

    float tX = Grimoire_NoiseSmooth(tX0);
    float tY = Grimoire_NoiseSmooth(tY0);

    vec2 h00 = GRAD_2D[Grimoire_NoiseHash(seed, iX0, iY0, 0) & 7];
    vec2 h10 = GRAD_2D[Grimoire_NoiseHash(seed, iX1, iY0, 0) & 7];
    vec2 h01 = GRAD_2D[Grimoire_NoiseHash(seed, iX0, iY1, 0) & 7];
    vec2 h11 = GRAD_2D[Grimoire_NoiseHash(seed, iX1, iY1, 0) & 7];

    float v00 = Grimoire_Dot2(h00, tX0, tY0);
    float v10 = Grimoire_Dot2(h10, tX1, tY0);
    float v01 = Grimoire_Dot2(h01, tX0, tY1);
    float v11 = Grimoire_Dot2(h11, tX1, tY1);

    float v0 = Grimoire_NoiseLerp(v00, v10, tX);
    float v1 = Grimoire_NoiseLerp(v01, v11, tX);

    float v = Grimoire_NoiseLerp(v0, v1, tY) * SQRT_2;
    return (v * 0.5f) + 0.5f;
}

GRIMOIRE_API float Grimoire_Perlin3D(float x, float y, float z, hash_t seed)
{
    int iX0 = (int) floorf(x);
    int iY0 = (int) floorf(y);
    int iZ0 = (int) floorf(z);

    int iX1 = iX0 + 1;
    int iY1 = iY0 + 1;
    int iZ1 = iZ0 + 1;

    float tX0 = x - iX0;
    float tY0 = y - iY0;
    float tZ0 = z - iZ0;

    float tX1 = tX0 - 1.0f;
    float tY1 = tY0 - 1.0f;
    float tZ1 = tZ0 - 1.0f;

    float tX = Grimoire_NoiseSmooth(tX0);
    float tY = Grimoire_NoiseSmooth(tY0);
    float tZ = Grimoire_NoiseSmooth(tZ0);

    vec3 h000 = GRAD_3D[Grimoire_NoiseHash(seed, iX0, iY0, iZ0) & 15];
    vec3 h100 = GRAD_3D[Grimoire_NoiseHash(seed, iX1, iY0, iZ0) & 15];
    vec3 h010 = GRAD_3D[Grimoire_NoiseHash(seed, iX0, iY1, iZ0) & 15];
    vec3 h110 = GRAD_3D[Grimoire_NoiseHash(seed, iX1, iY1, iZ0) & 15];
    vec3 h001 = GRAD_3D[Grimoire_NoiseHash(seed, iX0, iY0, iZ1) & 15];
    vec3 h101 = GRAD_3D[Grimoire_NoiseHash(seed, iX1, iY0, iZ1) & 15];
    vec3 h011 = GRAD_3D[Grimoire_NoiseHash(seed, iX0, iY1, iZ1) & 15];
    vec3 h111 = GRAD_3D[Grimoire_NoiseHash(seed, iX1, iY1, iZ1) & 15];

    float v000 = Grimoire_Dot3(h000, tX0, tY0, tZ0);
    float v100 = Grimoire_Dot3(h100, tX1, tY0, tZ0);
    float v010 = Grimoire_Dot3(h010, tX0, tY1, tZ0);
    float v110 = Grimoire_Dot3(h110, tX1, tY1, tZ0);
    float v001 = Grimoire_Dot3(h001, tX0, tY0, tZ1);
    float v101 = Grimoire_Dot3(h101, tX1, tY0, tZ1);
    float v011 = Grimoire_Dot3(h011, tX0, tY1, tZ1);
    float v111 = Grimoire_Dot3(h111, tX1, tY1, tZ1);

    float v00 = Grimoire_NoiseLerp(v000, v100, tX);
    float v10 = Grimoire_NoiseLerp(v010, v110, tX);
    float v01 = Grimoire_NoiseLerp(v001, v101, tX);
    float v11 = Grimoire_NoiseLerp(v011, v111, tX);

    float v0 = Grimoire_NoiseLerp(v00, v10, tY);
    float v1 = Grimoire_NoiseLerp(v01, v11, tY);

    float v = Grimoire_NoiseLerp(v0, v1, tZ);
    return (v * 0.5f) + 0.5f;
}
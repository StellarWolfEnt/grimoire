#include <grimoire32/internal/noise.h>
#include <grimoire32/noise.h>

GRIMOIRE_API float Grimoire_ValueSmooth1D(float x, float y, float z, hash_t seed)
{
    int iX0 = (int) floorf(x);

    int iX1 = iX0 + 1;

    float tX = Grimoire_NoiseSmooth(x - iX0);

    uint8_t v0 = Grimoire_NoiseHash(seed, iX0, 0, 0);
    uint8_t v1 = Grimoire_NoiseHash(seed, iX1, 0, 0);

    return Grimoire_NoiseLerp(v0, v1, tX) * INV_255;
}

GRIMOIRE_API float Grimoire_ValueSmooth2D(float x, float y, float z, hash_t seed)
{
    int iX0 = (int) floorf(x);
    int iY0 = (int) floorf(y);

    int iX1 = iX0 + 1;
    int iY1 = iY0 + 1;

    float tX = Grimoire_NoiseSmooth(x - iX0);
    float tY = Grimoire_NoiseSmooth(y - iY0);

    uint8_t v00 = Grimoire_NoiseHash(seed, iX0, iY0, 0);
    uint8_t v10 = Grimoire_NoiseHash(seed, iX1, iY0, 0);
    uint8_t v01 = Grimoire_NoiseHash(seed, iX0, iY1, 0);
    uint8_t v11 = Grimoire_NoiseHash(seed, iX1, iY1, 0);

    float v0 = Grimoire_NoiseLerp(v00, v10, tX);
    float v1 = Grimoire_NoiseLerp(v01, v11, tX);

    return Grimoire_NoiseLerp(v0, v1, tY) * INV_255;
}

GRIMOIRE_API float Grimoire_ValueSmooth3D(float x, float y, float z, hash_t seed)
{
    int iX0 = (int) floorf(x);
    int iY0 = (int) floorf(y);
    int iZ0 = (int) floorf(z);

    int iX1 = iX0 + 1;
    int iY1 = iY0 + 1;
    int iZ1 = iZ0 + 1;

    float tX = Grimoire_NoiseSmooth(x - iX0);
    float tY = Grimoire_NoiseSmooth(y - iY0);
    float tZ = Grimoire_NoiseSmooth(z - iZ0);

    uint8_t v000 = Grimoire_NoiseHash(seed, iX0, iY0, iZ0);
    uint8_t v100 = Grimoire_NoiseHash(seed, iX1, iY0, iZ0);
    uint8_t v010 = Grimoire_NoiseHash(seed, iX0, iY1, iZ0);
    uint8_t v110 = Grimoire_NoiseHash(seed, iX1, iY1, iZ0);
    uint8_t v001 = Grimoire_NoiseHash(seed, iX0, iY0, iZ1);
    uint8_t v101 = Grimoire_NoiseHash(seed, iX1, iY0, iZ1);
    uint8_t v011 = Grimoire_NoiseHash(seed, iX0, iY1, iZ1);
    uint8_t v111 = Grimoire_NoiseHash(seed, iX1, iY1, iZ1);

    float v00 = Grimoire_NoiseLerp(v000, v100, tX);
    float v10 = Grimoire_NoiseLerp(v010, v110, tX);
    float v01 = Grimoire_NoiseLerp(v001, v101, tX);
    float v11 = Grimoire_NoiseLerp(v011, v111, tX);

    float v0 = Grimoire_NoiseLerp(v00, v10, tY);
    float v1 = Grimoire_NoiseLerp(v01, v11, tY);

    return Grimoire_NoiseLerp(v0, v1, tZ) * INV_255;
}
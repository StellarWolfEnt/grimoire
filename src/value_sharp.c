#include <grimoire32/internal/noise.h>
#include <grimoire32/noise.h>

GRIMOIRE_API float Grimoire_ValueSharp1D(float x, float y, float z, hash_t seed)
{
    int iX = (int) floorf(x);

    return Grimoire_NoiseHash(seed, iX, 0, 0) * INV_255;
}

GRIMOIRE_API float Grimoire_ValueSharp2D(float x, float y, float z, hash_t seed)
{
    int iX = (int) floorf(x);
    int iY = (int) floorf(y);

    return Grimoire_NoiseHash(seed, iX, iY, 0) * INV_255;
}

GRIMOIRE_API float Grimoire_ValueSharp3D(float x, float y, float z, hash_t seed)
{
    int iX = (int) floorf(x);
    int iY = (int) floorf(y);
    int iZ = (int) floorf(z);

    return Grimoire_NoiseHash(seed, iX, iY, iZ) * INV_255;
}
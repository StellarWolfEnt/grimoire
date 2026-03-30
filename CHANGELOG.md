# Changelog

## [1.0.0] - 2026-03-29

- Ported `Grimoire_Noise` API to x86-64 assembly for Windows, improving performance.
- Updated documentation for all noise functions and fractal settings.
- Added version info to `dll.rc` and updated build scripts for MSVC.
- Renamed `Grimoire_Fractal` → `Grimoire_Fbm` (breaking change: update references in dependent projects).
- Changed the license from GNDL to CC-BY-SA 4.0.
- Added `ROADMAP.md` and `SECURITY.md` files for project transparency and future planning.
- Created a new docs site with MkDocs.
- Changed the project name to "Grimoire PCG" to better reflect the focus on procedural content generation.

## [0.0.2] - 2026-03-01

- Added `Grimoire_Noise` API and headers.
- Added `dll.rc` version info.

## [0.0.1] - 2026-02-14

- Initial release.
- Added `GrimoireRandom` API and headers.
# Roadmap

This roadmap reflects the current direction for Grimoire.
It is intentionally practical and platform-focused.

## Guiding Priority

Primary long-term goal: move from Windows-only delivery toward cross-platform support.

## Phase 1: Linux x64 Support (Primary)

Status: planned

Scope:

- Build and validate the core library on Linux x64.
- Establish Linux-compatible build scripts/tooling.
- Confirm exported API compatibility for public headers.
- Verify deterministic behavior parity against Windows for seed-driven workflows.
- Document Linux integration and packaging expectations.

Success criteria:

- Linux x64 build is reproducible in CI or repeatable local workflow.
- Core RNG and noise APIs pass functional and deterministic checks.
- Consumer-facing docs include Linux setup and linking guidance.

## Phase 2: macOS Support (Community-Assisted)

Status: planned, contributor-friendly

Scope:

- Bring up macOS build and validation pipeline.
- Confirm API and behavior parity with existing platforms.
- Document macOS consumption and runtime requirements.

Notes:

- macOS support is expected to be community-assisted unless contributor bandwidth changes.
- PRs and build validation contributions for macOS are especially valuable.

Success criteria:

- Native macOS build path is documented and repeatable.
- Core APIs behave consistently with existing deterministic expectations.

## Phase 3: Post-Platform Expansion

Status: exploratory

After Linux and macOS support are stable, roadmap direction will be reassessed.
Possible next steps may include performance work, tooling improvements, additional platform targets, and API evolution.

## Contributing to the Roadmap

If you can help with Linux/macOS build validation, CI setup, or platform testing, contributions are welcome.
Roadmap updates will be tracked as implementation milestones are completed.

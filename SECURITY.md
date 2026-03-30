# Security Policy

## Supported Versions

Only the most recent stable release branch is supported for security fixes.

| Version | Supported |
| ------- | --------- |
| 1.0.x   | :white_check_mark: |
| < 1.0   | :x: |

## Reporting a Vulnerability

Please do not open public issues for suspected vulnerabilities.

Use one of the following private channels:

- GitHub Security Advisories for this repository (preferred)
- Private contact with the maintainers (if you already have a trusted channel)

When reporting, include:

- A clear description of the issue
- Affected version/commit
- Reproduction steps or proof of concept
- Impact assessment
- Any suggested mitigation

## Response Expectations

- Initial acknowledgement target: within 7 days
- Triage/update target: within 14 days
- Fix timeline: depends on severity and complexity

If a report is accepted, maintainers will coordinate disclosure timing and credit (if desired).

## Scope and Notes

This project is a procedural content generation library and is not intended for cryptographic use.

- `GrimoireRandom` is not cryptographically secure
- Do not use this library for key generation, secure tokens, or other security-critical randomness

## Disclosure Policy

Please allow maintainers reasonable time to investigate and fix before public disclosure.
Coordinated disclosure helps protect downstream users.

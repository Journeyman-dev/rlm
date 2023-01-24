<!--
SPDX-FileCopyrightText: 2023 Daniel Aimé Valcour <fosssweeper@gmail.com>

SPDX-License-Identifier: MIT
-->

<!--
    Copyright (c) 2023 Daniel Aimé Valcour

    Permission is hereby granted, free of charge, to any person obtaining a copy of
    this software and associated documentation files (the "Software"), to deal in
    the Software without restriction, including without limitation the rights to
    use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
    the Software, and to permit persons to whom the Software is furnished to do so,
    subject to the following conditions:
    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
    FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
    COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
    IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
    CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
-->

# RLM Contributing Guidelines

This file explains how to contribute to the RLM project. For standards of behaviour, look at the [Code of Conduct](CODE_OF_CONDUCT.md).

## How to Report a Bug or Suggest a Feature

Report bugs and suggest features in the [issues board](https://www.github.com/Journeyman-dev/rlm/issues). [Create a new issue](https://docs.github.com/en/issues/tracking-your-work-with-issues/creating-an-issue) using the appropriate issue template.
## How to Ask a Question

Ask questions about how to use this library in the [#roguelikedev](https://discord.gg/Y5AVXeWNkf) channel of the roguelikes Discord.

## How to Contribute Code Changes

Browse the [issues board](https://www.github.com/Journeyman-dev/rlm/issues) to find an issue that interests you. If you want to work on an issue, say so by commenting in the issue thread. [Fork the dev branch](https://docs.github.com/en/get-started/quickstart/fork-a-repo#fork-an-example-repository) of the RLM repository and [clone the fork](https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository) to your local machine. [Commit your changes](https://docs.github.com/en/desktop/contributing-and-collaborating-using-github-desktop/making-changes-in-a-branch/committing-and-reviewing-changes-to-your-project) locally and then [push them](https://docs.github.com/en/desktop/contributing-and-collaborating-using-github-desktop/making-changes-in-a-branch/pushing-changes-to-github) to your forked repository. When you are ready, go ahead and [make a pull request](https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/about-pull-requests) in the [rlm pull requests board](https://github.com/Journeyman-dev/rlm/pulls).

### Unit Tests with Catch2

Every time you push changes to GitHub, several tests will be run automatically by [GitHub Actions](https://github.com/Journeyman-dev/rlm/actions). [Unit tests](https://en.wikipedia.org/wiki/Unit_testing) are code snipets used to verify that the library code works as expected. For testing, RLM uses the [Catch2 framework](https://github.com/catchorg/Catch2). Before your pull request can be merged into RLM, all unit tests must pass. Depending on what code you added or modified, you may be required to add more unit tests or change existing ones. If you are not sure what you need to do, ask for guidance in your pull request thread.

### Licensing with REUSE

The RLM project is a propoenent of the [REUSE Specification](https://reuse.software/spec/). This means that all files in the repository must be adequatly licensed for the your fork to be considered [REUSE-compliant](https://reuse.software/tutorial/). If you have the [REUSE Tool](https://github.com/fsfe/reuse-tool) installed on your computer, you can check your fork to see if it is compliant using the bash command `reuse lint`.

## Project Versioning

RLM uses [Semantic Versioning 2.0.0](https://semver.org/). Bugs can be patched quickly with patch releases, and non-breaking changes can be made during minor releases. API breaking changes to the library must only be made during major releases.

Version commits have git tags written in the style of "v1.2.3.4".

### Workflow

The latest release of RLM can always be found on the head of the `main` branch. Work in progress code for future releases should be pulled into the `dev` branch. The `dev` branch should be pulled into the main branch when the next major release is ready. Patches should be pulled into their own branch forked from the `main` branch. When a patch is ready for release, it should be pulled directly into both the `main` and `dev` branches.

### Depreciation Warnings

If it is planned for a function or type to be removed or replaced in an upcoming major release, it should be marked with the C++ `[[deprecated]]` attribute to warn users of the upcoming change.

### Tweak Versions

Tweak versions use a fourth version number, and are only intended for testing purposes. Tweak versions are more likely to contain bugs than normal versions of the library.

## Credits

If you report a bug, make a pull request that is approved, or help with the development of RLM in some other way, you can be added to the credits. The credits are located in a [text file](CREDITS) in the root directory of the repository. You may choose the name that is shown. Your entry will also include a reference to your GitHub username.

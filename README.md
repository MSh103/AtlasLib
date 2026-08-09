# AtlasLib

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-26-blue?style=for-the-badge&logo=cplusplus" alt="C++26">
  <img src="https://img.shields.io/badge/OpenGL-4.6-blue?style=for-the-badge&logo=opengl" alt="OpenGL">
  <img src="https://img.shields.io/badge/GLFW-Windowing-lightgrey?style=for-the-badge" alt="GLFW">
  <img src="https://img.shields.io/badge/ImGui-UI-orange?style=for-the-badge" alt="Dear ImGui">
  <img src="https://img.shields.io/badge/Premake5-Build-orange?style=for-the-badge" alt="Premake5">
</p>

> ⚠️ **Work in Progress**

AtlasLib is a modern C++ core library designed to make creating and setting up new C++ applications easier. It provides the core application structure, window management, event handling, layers, input, logging, and ImGui integration while keeping rendering functionality separate for future projects.

## Features

* Application lifecycle and main loop
* GLFW window management
* OpenGL context initialization through GLAD
* Event system and event dispatcher
* Keyboard and mouse events
* Input abstraction
* Layer and LayerStack system
* TimeStep utilities
* Logging through spdlog
* Dear ImGui integration with docking and multi-viewport support
* C++26 support

## Dependencies

AtlasLib currently uses:

* [GLFW](https://github.com/MSh103/glfw) — Window and input handling
* [GLAD](https://github.com/Dav1dde/glad) — OpenGL function loading
* [spdlog](https://github.com/gabime/spdlog) — Logging
* [Dear ImGui](https://github.com/ocornut/imgui) — Immediate-mode UI

Dependencies are included through Git submodules where applicable.

## Requirements

### Windows

* Windows 10 or newer
* Visual Studio 2022 or newer
* C++26-compatible compiler
* Git
* Premake5

AtlasLib currently targets **x64**.

## Workspace Requirement

AtlasLib's `build.lua` is intended to be included by a **Premake workspace** rather than being used as a standalone Premake script.

For example, a workspace can include AtlasLib with:

```lua
workspace "MyWorkspace"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release"
    }

include "AtlasLib/build.lua"
include "MyProject/build.lua"
```

This allows AtlasLib to be used alongside an application or sandbox project within the same Premake workspace.

## Building

Clone the repository and initialize its dependencies:

```bash
git clone https://github.com/MSh103/AtlasLib.git
cd AtlasLib

git submodule update --init --recursive
```

Generate the Visual Studio project files using Premake:

```bash
premake5 --file=build.lua vs2022
```

Then open the generated solution and build the desired configuration.

Available configurations:

```text
Debug
Release
```

AtlasLib is currently developed and tested primarily on Windows with Visual Studio.

## Usage

AtlasLib is intended to be used as a core framework for applications built on top of it.

A separate sandbox/application project can link against AtlasLib and use its public API without needing to implement the underlying windowing, event, input, layer, or logging infrastructure itself.

## License

AtlasLib is licensed under the MIT License. See [LICENSE](LICENSE) for more information.

# COSC345

[![CMake](https://github.com/wpframe/cosc345/actions/workflows/cmake.yml/badge.svg)](https://github.com/wpframe/cosc345/actions/workflows/cmake.yml)


Team members:
- Ben Knox
- Shamen Kumar
- Vincent Lee
- Will Frame

[Our report](docs/assignment1.md)

To build, simply run [build.sh](build.sh) with ``./build.sh`` with CMake installed.

If you run into issues with that, here is a breakdown:

1. Install [CMake](https://cmake.org/install/)
2. Make a /build/ directory in terminal (``mkdir build``)
3. Open the build directory (``cd build``)
4. Run ``cmake ..``
5. Run ``cmake --build . --config Release``

To open the application, run [build/MyApp](build/MyApp) with ``./MyApp``

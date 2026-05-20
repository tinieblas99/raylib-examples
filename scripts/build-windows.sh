#!/usr/bin/env bash
# build-windows.sh — Cross-compile raylib for Windows x86_64 (mingw-w64).
# Usage: ./scripts/build-windows.sh [INSTALL_PREFIX]
set -e

PARENT="$(cd "$(dirname "$0")/../.." && pwd)"
PREFIX="${1:-$PARENT/raylib-win64}"
JOBS="$(nproc)"
RAYLIB_SRC="$PARENT/raylib"
TOOLCHAIN="$RAYLIB_SRC/src/external/glfw/CMake/x86_64-w64-mingw32.cmake"

if ! command -v x86_64-w64-mingw32-gcc &>/dev/null; then
    echo "ERROR: mingw-w64 not found. Install with: sudo apt install mingw-w64"
    exit 1
fi

echo "==> Building raylib for Windows -> $PREFIX"
cmake -S "$RAYLIB_SRC" -B "$RAYLIB_SRC/build-win64" \
    -DCMAKE_TOOLCHAIN_FILE="$TOOLCHAIN" \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_PREFIX="$PREFIX" \
    -DBUILD_SHARED_LIBS=OFF \
    -DBUILD_EXAMPLES=OFF
cmake --build "$RAYLIB_SRC/build-win64" -j"$JOBS"
cmake --install "$RAYLIB_SRC/build-win64"

echo "==> Done. raylib installed to: $PREFIX"
find "$PREFIX" -name "*.a" -o -name "*.dll" | sort

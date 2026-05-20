#!/usr/bin/env bash
# build-linux.sh — Build raylib and install to ../raylib-install
# Usage: ./scripts/build-linux.sh [INSTALL_PREFIX]
set -e

PARENT="$(cd "$(dirname "$0")/../.." && pwd)"
PREFIX="${1:-$PARENT/raylib-install}"
JOBS="$(nproc)"
RAYLIB_SRC="$PARENT/raylib"

echo "==> Building raylib -> $PREFIX"
cmake -S "$RAYLIB_SRC" -B "$RAYLIB_SRC/build" \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_PREFIX="$PREFIX" \
    -DBUILD_SHARED_LIBS=OFF \
    -DBUILD_EXAMPLES=OFF
cmake --build "$RAYLIB_SRC/build" -j"$JOBS"
cmake --install "$RAYLIB_SRC/build"

echo "==> Done. raylib installed to: $PREFIX"
find "$PREFIX" -name "*.a" -o -name "*.so*" | sort

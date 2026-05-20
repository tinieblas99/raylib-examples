#!/usr/bin/env bash
# setup.sh — Clone raylib, rlImGui (with imgui docking) next to this repo.
# Run once before building.
set -e

PARENT="$(cd "$(dirname "$0")/../.." && pwd)"

clone_or_skip() {
    local url="$1" dest="$2" extra="${3:-}"
    if [ -d "$dest/.git" ]; then
        echo "==> Already exists, skipping: $dest"
    else
        echo "==> Cloning $url"
        git clone --depth=1 $extra "$url" "$dest"
    fi
}

clone_or_skip "https://github.com/raysan5/raylib.git"         "$PARENT/raylib"
clone_or_skip "https://github.com/raylib-extras/rlImGui.git"  "$PARENT/rlImGui"

# rlImGui bundles imgui as a subdirectory — clone docking branch there
clone_or_skip "https://github.com/ocornut/imgui.git" "$PARENT/rlImGui/imgui" "-b docking"

echo ""
echo "==> All sources ready under $PARENT"
echo "==> Next: run scripts/build-linux.sh"

#!/usr/bin/env bash
# install-deps-linux.sh — Install build dependencies on Ubuntu/Debian.
set -e

sudo apt-get update -qq
sudo apt-get install -y \
    cmake gcc g++ make \
    libgl1-mesa-dev libgles2-mesa-dev \
    libx11-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev \
    libasound2-dev

echo "==> Dependencies installed."

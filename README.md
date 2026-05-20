# Raylib Examples

Raylib examples with Dear ImGui integration via [rlImGui](https://github.com/raylib-extras/rlImGui) (docking branch).

## Examples

| Directory | Description |
|-----------|-------------|
| `raylib-basic` | Raylib + rlImGui docking. Moveable circle with ImGui controls panel, color picker, and demo window. |

---

## Full setup from a fresh machine (Ubuntu/Debian)

### 1. Clone this repository
```bash
git clone https://github.com/tinieblas99/raylib-examples
cd raylib-examples
```

### 2. Install system build dependencies
```bash
./scripts/install-deps-linux.sh
```

### 3. Clone raylib and rlImGui
```bash
./scripts/setup.sh
```
Clones the following repos **as siblings** of this repository:
- `../raylib` — raylib source
- `../rlImGui` — rlImGui source (with `../rlImGui/imgui` as the Dear ImGui docking branch)

### 4. Build raylib
```bash
./scripts/build-linux.sh
```
Compiles raylib (static) and installs it to `../raylib-install/`.

### 5. Build and run an example
```bash
cd raylib-basic
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
./build/raylib_example
```

---

## Directory layout after setup

```
parent/
├── raylib-examples/    ← this repo
│   ├── scripts/
│   └── raylib-basic/
├── raylib/             ← cloned by setup.sh
├── rlImGui/            ← cloned by setup.sh (includes imgui/docking)
└── raylib-install/     ← built by build-linux.sh
```

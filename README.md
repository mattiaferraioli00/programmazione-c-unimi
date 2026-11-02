# C Programming – UniMi

Exercises completed during the **C Programming** course of the Cybersecurity and Artificial Intelligence degree program at the University of Milan.

## 🛠 Tech stack

- **Language:** C (C17)
- **Compiler:** GCC
- **Build system:** CMake
- **IDE:** CLion

## 📂 Repository structure

Exercises are grouped by teaching unit and numbered sequentially within each unit. Every exercise is self-contained: its own folder, its own `main.c` and its own CMake target.

```text
programmazione-c-unimi/
├── CMakeLists.txt          # root project, includes every exercise
├── scripts/
│   └── exercise/
│       └── create.sh       # creates a new exercise
├── unit2/
│   ├── es1/
│   │   ├── CMakeLists.txt
│   │   └── main.c
│   ├── es2/
│   └── ...
└── unitN/
    └── esM/
```

## 🚀 Build and run

### CLion

Open the repository folder. CLion loads the root `CMakeLists.txt` and creates a run configuration for each exercise: pick one from the run configuration selector and run it.

### Command line

```bash
cmake -S . -B build                     # configure
cmake --build build --target help       # list the available targets
cmake --build build --target <target>   # build a single exercise
cmake --build build                     # build everything
```

Executables are placed in `build/unitN/esM/`.

## ➕ Creating a new exercise

`scripts/exercise/create.sh` creates the folder, `main.c` and `CMakeLists.txt` of a new exercise and registers it in the root project, so you never have to write them by hand.

### Usage

```bash
./scripts/exercise/create.sh [-u UNIT] [-e EXERCISE]
```

| Option        | Description                          | Default                              |
|---------------|--------------------------------------|--------------------------------------|
| `-u UNIT`     | Unit number (`3` or `unit3`)         | The highest existing unit            |
| `-e EXERCISE` | Exercise number (`7` or `es7`)       | The one after the highest in the unit |
| `-h`          | Show the help                        |                                      |

The script can be run from any directory: it finds the project root from its own location.

### Examples

Assuming the highest existing exercise is `unit2/es6`:

| Command                                  | Creates                            |
|------------------------------------------|------------------------------------|
| `./scripts/exercise/create.sh`           | `unit2/es7`                        |
| `./scripts/exercise/create.sh -u 3`      | `unit3/es1` (and the `unit3` folder) |
| `./scripts/exercise/create.sh -u 2 -e 10`| `unit2/es10`                       |
| `./scripts/exercise/create.sh -e 9`      | `unit2/es9`                        |

### What it does

1. Creates `unitN/esM/`, and `unitN/` if it doesn't exist yet.
2. Writes a `main.c` containing an empty `main` function.
3. Writes a `CMakeLists.txt` defining the target `unitN_esM`. The unit prefix is required because CMake target names must be unique across the whole project.
4. Adds `add_subdirectory(unitN/esM)` to the root `CMakeLists.txt`, right after the last existing one.

Then reload the CMake project in CLion (*Tools → CMake → Reload CMake Project*) or run `cmake -S . -B build` again.

### Safety checks

- **No overwrites:** if `unitN/esM` already exists, the script stops with an error and changes nothing.
- **Input validation:** invalid values (`-u abc`, `-e 0`, an option without a value) are rejected.
- **Root project untouched if unsupported:** if the root `CMakeLists.txt` doesn't use `add_subdirectory`, it is left as is and a warning is printed.

> If you get `Permission denied`, make the script executable with `chmod +x scripts/exercise/create.sh`.

## 🎯 Goals

- Master the fundamentals of C programming.
- Develop algorithmic thinking and problem-solving skills.
- Apply theoretical concepts through practical exercises.

## 🎓 Course information

- **University:** University of Milan (UniMi)
- **Degree program:** Cybersecurity and Artificial Intelligence

---

*This repository is intended for educational and personal purposes.*
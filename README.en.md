<div align="center">

# student-simulator

**A console student-life simulator: 10 days until the exam, three resources, random dreams and a dozen endings.**

[![Build](https://github.com/Ilya0107/student-simulator/actions/workflows/build.yml/badge.svg)](https://github.com/Ilya0107/student-simulator/actions/workflows/build.yml)
![Platform](https://img.shields.io/badge/platform-Windows-0078D6?logo=windows&logoColor=white)
![C++](https://img.shields.io/badge/C%2B%2B-17-00599C?logo=cplusplus&logoColor=white)
![Build](https://img.shields.io/badge/build-MSBuild%20%7C%20CMake-success)
![License](https://img.shields.io/badge/license-MIT-green)

[Русская версия](README.md) | **English**

</div>

![Gameplay](screenshots/gameplay.svg)

## About

`student-simulator` is a text-based game for the **Windows console**, written in
**C++17**. You have **10 days** before the exam and must balance studying, working,
sleeping and resting to survive the session with acceptable health, money and
knowledge. Every day offers three choices that shift three stats. At night a dream may
come, and the ending depends on what you bring to the exam — including running a
business, going pro in sports, or a secret ending.

The project started at a hackathon and was then rebalanced: content separated from logic,
a warning-free build, and a clear code structure.

## Features

- **Three stats** — health, knowledge, money — with a daily 20 ₽ expense and the risk of going negative.
- **10 days × 3 unique choices**, each with different stat trade-offs.
- **Random dreams** with an adaptive chance — an extra layer of risk.
- **Branching finale**: grades 2–5, bribing the professor, expulsion, death, leaving for
  business or sports, and a secret ending.
- **Colored output** and ASCII art right in the console.
- **Data-driven content** — days and dreams live in `DAYS` / `DREAMS` tables, not in control flow.
- **CI** — the solution is built by GitHub Actions on every push.

## Controls

- Type `1`–`3` and press `Enter`.
- Invalid input never crashes the game: the input stream is cleared and the prompt repeats.
- After a dream, press `Enter` to continue.

Sample session:

```text
------------------------------День 1. Будильник в общаге------------------------------
--------------------------------------------------------------------------------
Текущее состояние:
| Здоровье: 50| | Знания: 52| | Деньги: 300
--------------------------------------------------------------------------------
Локация: Общежитие
Ты просыпаешься от будильника. Первая мысль — хочется выключить его и спать дальше.
    1.Пойти на пары. День проходит тяжело, но полезно.
    2.Спать дальше. Ты высыпаешься, но пропускаешь важную тему.
    3.Пойти на работу вместо пар.
Ваш выбор:
```

> The game itself is in Russian; the code and this document are in English.

## Getting started

Requires **Windows** (the game uses the Windows console API) and **Visual Studio 2022**
with the "Desktop development with C++" workload.

### Visual Studio

1. Open `student-simulator.sln`.
2. Select `Release` / `x64` and build (`Ctrl+Shift+B`).
3. Run `x64\Release\student-simulator.exe`.

### Command line (MSBuild)

```powershell
msbuild student-simulator.sln /p:Configuration=Release /p:Platform=x64
```

### CMake

```powershell
cmake -B build -A x64
cmake --build build --config Release
```

## Project layout

```
student-simulator/
├── src/
│   ├── main.cpp          # entry point, game loop, dreams
│   ├── player.h/.cpp     # Player class, output, exam and endings
│   ├── text_data.h/.cpp  # all content: days, dreams, texts, ASCII art
│   └── color.h/.cpp      # console color (WinAPI wrapper)
├── docs/                 # documentation (Russian)
├── screenshots/          # README image
├── .github/workflows/    # CI build
├── student-simulator.sln
├── CMakeLists.txt
└── LICENSE
```

## Documentation

Russian-language docs live in [`docs/`](docs/):

- `GAMEPLAY.md` — how to play, characters, resources, mechanics.
- `BALANCE.md` — day/dream effects, grade and bribe formulas.
- `ENDINGS.md` — every ending and how to reach it.
- `ARCHITECTURE.md` — architecture, modules and technical decisions.
- `ROADMAP.md` — planned architecture improvements.

## Tech stack

`C++17` · `WinAPI (console)` · `Visual Studio 2022 / MSBuild` · `CMake` · `GitHub Actions`

## License

Released under the **MIT** license — see [`LICENSE`](LICENSE).

## Author

**Ilya** — [github.com/Ilya0107](https://github.com/Ilya0107)

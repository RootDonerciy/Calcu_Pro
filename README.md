# CALCU_PRO

A feature-rich command-line calculator written in C, covering arithmetic, trigonometric, and geometric operations with a clean terminal interface.

---

## Features

- **Arithmetic Operations** — Addition, Subtraction, Multiplication, Division, Factorial, GCD, LCM, Power, Prime check, Sum of digits
- **Trigonometric Operations** — Sine, Cosine, Tangent, Cotangent, Secant, Cosecant, and their inverses (Arcsin, Arccos, Arctan, Arccot), Degree/Radian conversion
- **2D Geometry** — Triangle, Circle, Square, Rectangle, Rhombus, Parallelogram, Trapezoid
- **3D Geometry** — Cone, Cube, Cylinder, Sphere
- **Calculation History** — All results are saved to `history.txt` with timestamps

---

## Project Structure

```
Calcu_Pro/
├── include/
│   ├── arithmetic.h
│   ├── trigono.h
│   ├── math_utils.h
│   └── geometric/
│       ├── 2D/
│       └── 3D/
├── src/
│   ├── arithmetic.c
│   ├── trigono.c
│   ├── math_utils.c
│   └── geometric/
│       ├── 2D/
│       └── 3D/
├── main_simplified.c
├── build.bat
└── README.md
```

---

## Requirements

- GCC compiler (MinGW recommended for Windows)
- Windows OS (ANSI color support required)

---

## How to Build and Run

**1. Clone the repository:**
```bash
git clone https://github.com/RootDonerciy/Calcu_Pro.git
cd Calcu_Pro
```

**2. Build the project:**
```bash
build.bat
```

**3. Run the program:**
```bash
.\main_simplified.exe
```

---

## Calculation History

Every calculation is automatically saved to `history.txt` in the project directory with a timestamp:

```
[Wed Mar 25 23:10:10 2026] Addition = 57.00
[Wed Mar 25 23:10:45 2026] Sine = 0.5000
```

You can view the history directly from the main menu by selecting **"Show File History"**.

---

## Notes

> This is the **first version (v1)** of CALCU_PRO. There may be some incomplete features or minor issues. I will work to address these in future versions.

### Planned for future versions:
- Fix any bugs found in v1
- Matrix operations
- Advanced mathematical operations (derivatives, integrals, complex numbers)
- ncurses-based TUI (Terminal User Interface)
- 3D geometry expansion (Pyramid, Ellipsoid, Prism)
- Cross-platform support (Linux/Mac)

---

## Author

**Omer Bagirzade** — [@RootDonerciy](https://github.com/RootDonerciy)

*C/C++ system programmer wannabe* 🚀

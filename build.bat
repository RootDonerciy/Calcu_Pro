@echo off
gcc main_simplified.c src/arithmetic.c src/trigono.c src/math_utils.c src/geometric/2D/circle.c src/geometric/2D/triangle.c src/geometric/2D/square.c src/geometric/2D/rectangle.c src/geometric/2D/rhombus.c src/geometric/2D/paralelogram.c src/geometric/2D/trapesoid.c src/geometric/3D/cone.c src/geometric/3D/cube.c src/geometric/3D/cylinder.c src/geometric/3D/spher.c -o main_simplified.exe -I. -lm
echo Build complete!

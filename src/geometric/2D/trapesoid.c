#include "include/geometric/2D/trapesoid.h"
#include "include/trigono.h"
#include <stdio.h>
#include <math.h>

double midline(double a, double b) {
    return (a + b) / 2.0;
}

double trap_per(double a, double b, double c) {
    return a + b + (2.0 * c);
}

double trap_area_1(double a, double b, double h) {
    return midline(a, b) * h;
}

double trap_area_2(double a, double b, double c, double angle) {
    double h = c * sine(angle);
    return (a + b) / 2.0 * h;
}

double trap_height(double c, double angle) {
    return c  * sine(angle);
}


#include "include/geometric/2D/rectangle.h"
#include "include/trigono.h"
#include <stdlib.h>
#include <math.h>

double rec_per(double a, double b) {
    return (a + b) * 2;
}

double rec_diagonal(double a, double b) {
    return sqrt(pow(a, 2) + pow(b, 2));
}

double rec_area_1(double a, double b) {
    return a * b;
}

double rec_area_2(double d, double angle) {
    return (pow(d, 2) * sine(angle)) / 2.0;
}

double rec_area_3(double d, double h) {
    return d * h;
}
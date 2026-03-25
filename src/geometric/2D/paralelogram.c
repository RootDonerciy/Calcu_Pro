#include "include/geometric/2D/paralelogram.h"
#include "include/trigono.h"
#include <stdio.h>
#include <math.h>


double par_per(double a, double b) {
    return (a + b) * 2;
}

double par_diagonal_1(double a, double b, double angle) {
    return sqrt(pow(a, 2) + pow(b, 2) - (2*a*b*cosine(angle)));
}

double par_area_1(double d_1, double d_2, double angle) {
    return (1.0/2.0) * (d_1 * d_2) *sine(angle);
}

double par_area_2(double a, double b, double angle) {
    return a * b * sine(angle);
}

double par_area_3(double a, double h) {
    return a * h;
}

double par_diagonal_2(double a, double b, double d_curr) {
    return sqrt(2 * (pow(a, 2) + pow(b, 2)) - pow(d_curr, 2));
}
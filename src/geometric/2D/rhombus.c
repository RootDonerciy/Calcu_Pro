#include "include/geometric/2D/rhombus.h"
#include "include/trigono.h"
#include <stdio.h>
#include <math.h>

double rhomb_per(double a) {
    return 4.0*a;
}

double rhomb_diagonal_1(double A, double d) {
    return 2.0*A/d;
}

double rhomb_diagonal_2(double a, double d_ot) {
    return sqrt(4.0*(pow(a, 2)) - pow(d_ot, 2));
}

double rhomb_diagonal_3(double a, double angle) {
    return a * sqrt(2 - 2*cosine(angle));
}

double rhomb_height(double a, double angle) {
    return a * sine(angle);
}

double rhomb_area_1(double a, double h) {
    return a * h;
}

double rhomb_area_2(double d_1, double d_2) {
    return (d_1 * d_2) / 2.0;
}

double rhomb_area_3(double a, double angle) {
    return pow(a, 2) * sine(angle);
}


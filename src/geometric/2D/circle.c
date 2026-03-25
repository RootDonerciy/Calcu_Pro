#include "include/geometric/2D/circle.h"
#include "include/trigono.h"
#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

double circ_diameter(double r) {
    return 2.0 * r;
}

double circum(double r) {
    return 2.0 * PI * r;
}

double circ_area(double r) {
    return PI * pow(r, 2);
}

double arc(double r, double angle) {
    return (PI * r * angle) / 180.0;
}

double circ_sector_area(double r, double angle) {
    return (PI * pow(r, 2) * angle) / 360.0;
}

double chord(double r, double angle) {
    return 2 * r * sine(angle/2.0);
}

double circ_tangent(double d, double r) {
    return sqrt(pow(d, 2) - pow(r, 2));
}
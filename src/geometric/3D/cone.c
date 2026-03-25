#include "include/geometric/3D/cone.h"
#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

double cone_later_area(double r, double l) {
    return r * PI * l;
}

double cone_total_area(double r, double l) {
    return PI * r * (r + l);
}

double cone_volume(double r, double h) {
    return (1.0/3.0) * PI * pow(r, 2) * h;
}

double slant_height(double r, double h) {
    return sqrt(pow(r, 2) + pow(h, 2));
}

double frustum_later_area(double r, double R, double l) {
    return PI * (R + r) * l;
}

double frustum_slant_height(double r, double R, double h) {
    return sqrt(pow(h, 2) + pow(R - r, 2));
}

double frustum_volume(double r, double R, double h) {
    return (PI * h / 3.0) * (pow(R, 2) + (R * r) + pow(r, 2));
}
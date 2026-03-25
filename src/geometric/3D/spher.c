#include "include/geometric/3D/spher.h"
#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

double spher_volume(double r) {
    return (4.0 / 3.0) * PI * pow(r, 3);
}

double spher_area(double r) {
    return 4.0 * PI * pow(r, 2);
}

double spher_diameter(double r) {
    return 2.0 * r;
}

double big_circle_area(double r) {
    return PI * pow(r, 2);
}

double big_circle_per(double r) {
    return 2.0 * PI * r;
}

double segment_volume(double r, double h) {
    return (PI * (pow(h, 2) / 3.0)) * ((3 * r) - h);
}

double segment_area(double r, double h) {
    return 2.0 * PI * h * r;
}

double sector_volume(double r, double h) {
    return (2.0/3.0) * PI * pow(r, 2) * h;
}
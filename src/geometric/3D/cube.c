#include "include/geometric/3D/cube.h"
#include <stdio.h>
#include <math.h>

double cube_volume(double a) {
    return pow(a, 3);
}

double cube_total_area(double a) {
    return 6 * pow(a, 2);
}

double cube_later_area(double a) {
    return 4 * pow(a, 2);
}

double diagonal_own(double a) {
    return a * sqrt(3.0);
}

double diagonal_face(double a) {
    return a * sqrt(2.0);
}

double cube_per(double a) {
    return 12 * a;
}
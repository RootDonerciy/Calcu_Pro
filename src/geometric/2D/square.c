#include "include/geometric/2D/square.h"
#include <stdlib.h>
#include <math.h>

double sqr_diagonal(double a) {
    return a * sqrt(2);
}

double sqr_per(double a) {
    return 4 * a;
}

double sqr_area_1(double a) {
    return pow(a, 2);
}

double sqr_area_2(double d) {
    return pow(d, 2) / 2.0;
}
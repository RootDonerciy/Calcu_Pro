#include "include/geometric/3D/cylinder.h"
#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

double cylin_later_area(double r, double h) {
    return 2 * PI * r * h;
}

double cylin_total_area(double r, double h) {
    return 2 * PI * r * (r + h);
}

double cylin_volume(double r, double h) {
    return PI * pow(r, 2) * h;
}

double cylin_diagonal(double r, double h) {
    return sqrt((4.0 * pow(r, 2)) + pow(h, 2));
}

double axial_select_area(double r, double h) {
    return 2*r*h;
}

/*Diagonal is same with cyliner*/

double axial_select_per(double r, double h) {
    return 2 * ((2 * r) + h);
}

double oblique_volume(double r, double h_mid) {
    return PI * pow(r, 2) * h_mid;
}

double oblique_later_area(double r, double h_min, double h_max) {
    return PI * r * (h_min + h_max);
}
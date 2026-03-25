#include "include/trigono.h"
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

double sine(double angle) {
    return sin(angle) * PI / 180.0;
}

double cosine(double angle) {
    return cos(angle) * PI / 180.0;
}

double tang(double angle) {
    return sine(angle) / cosine(angle);
}

double cot(double angle) {
    return cosine(angle) / sine(angle);
}

double sec(double angle) {
    return 1 / cosine(angle);
}

double cosec(double angle) {
    return 1 / sine(angle);
}

double arcsin(double radian) {
    double result = asin(radian);
    return result * (180.0 / PI);
}

double arccos(double radian) {
    double result = acos(radian);
    return result * (180.0 / PI);
}

double arctan(double radian) {
    double result = atan(radian);
    return result * (180.0 / PI);
}

double arccot(double radian) {
    double result = (PI / 2) - atan(radian);
    return result * (180.0 / PI);
}

double deg_to_rad(double angle) {
    return angle * (PI / 180.0);
}

double rad_to_deg(double radian) {
    return radian * (180.0 / PI);
}

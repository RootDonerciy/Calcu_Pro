#include "include/geometric/2D/triangle.h"
#include "include/trigono.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

char* triang_type(double a, double b, double c) {
    if(a == b && a == c) {
        return "It's a equilateral triangle.";   
    }

    if((pow(a, 2) + pow(b, 2) == pow(c, 2)) || (pow(a, 2) + pow(c, 2) == pow(b, 2)) 
    || pow(b, 2) + pow(c, 2) == pow(a, 2)) {
        return "It's a right-angled triangle.";  
    }

    if(a == b || a == c || b == c) {
        return "It's a isoscales triangle.";     
    }

    return "It's a scalene triangle.";           
}

double triang_perim(double a, double b, double c) {
    return a + b + c;
}

double triang_area_1(double side, double h) {
    return (1.0/2.0) * side * h;
}

double triang_area_2(double side_1, double side_2, double angle) {
    return (1.0/2.0) * side_1 * side_2 * sine(angle);
}

double triang_area_3(double a, double b, double c) {
    double half_per = triang_perim(a, b, c) / 2.0;
    return sqrt(half_per * (half_per - a) * (half_per - b) * (half_per - c));
}

char* check_triangle(double a, double b, double c) {
    if((a+b) > c && (a+c) > b && (b+c) > a) {
        return "It's a trinagle.\n";
    }
    return "It's not a triangle\n";
}

double triang_altit(double a, double b, double c) {
    double area = triang_area_3(a, b, c);
    return (2.0 * area) / c;
}


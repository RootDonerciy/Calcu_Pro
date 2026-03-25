#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <stdbool.h>

char* triang_type(double a, double b, double c); 
double triang_perim(double a, double b, double c); 
double triang_area_1(double side, double h); 
double triang_area_2(double side_1, double side_2, double angle); 
double triang_area_3(double a, double b, double c); 
char* check_triangle(double a, double b, double c); 
double triang_altit(double a, double b, double c);

#endif 
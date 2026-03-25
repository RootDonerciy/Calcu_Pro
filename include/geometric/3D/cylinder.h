#ifndef CYLINDER_H
#define CYLINDER_H

double cylin_later_area(double r, double h);
double cylin_total_area(double r, double h);
double cylin_volume(double r, double h);
double cylin_diagonal(double r, double h);
double axial_select_area(double r, double h);
double axial_select_per(double r, double h);
double oblique_volume(double r, double h_mid);
double oblique_later_area(double r, double h_min, double h_max);

#endif
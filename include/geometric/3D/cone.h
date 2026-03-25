#ifndef CONE_H
#define CONE_H

double cone_later_area(double r, double l);
double cone_total_area(double r, double l);
double cone_volume(double r, double h);
double slant_height(double r, double h);
double frustum_later_area(double r, double R, double l);
double frustum_slant_height(double r, double R, double h);
double frustum_volume(double r, double R, double h);

#endif
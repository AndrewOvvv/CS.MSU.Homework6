#ifndef ROOT_H
#define ROOT_H

#include <stdio.h>


typedef double(*function)(double);
const double eps = 1e-7;
const double dx = 1e-2;


extern function get_f1_value_fun;
extern function get_f2_value_fun;
extern function get_f3_value_fun;


int sgn(double val) {
    return (val > eps) ? 1 : ((val > -eps) ? 0 : -1);
}


double get_derivative_1(function f1, function f2, double point);


double sgn_derivative_2(function f1, function f2, double point) {
    return sgn((get_derivative_1(f1, f2, point + dx) - get_derivative_1(f1, f2, point)) / dx);
}


double find_root(function f1, function f2, double left, double right);


#endif //ROOT_H
#ifndef INTEGRAL_H
#define INTEGRAL_H

#include <stdio.h>


typedef double(*function)(double);
const double eps = 1e-7;
const double p = 1 / 15;
const double INF = 1e9;


extern function get_f1_value_fun;
extern function get_f2_value_fun;
extern function get_f3_value_fun;



double integral(function f, double left, double right);


#endif //INTEGRAL_H
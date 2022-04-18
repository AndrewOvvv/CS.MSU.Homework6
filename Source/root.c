#include "./../headers/root.h"

double get_derivative_1(function f1, function f2, double point) {
    double dx = 1e-2;
    double loc_eps = 1e-4;

    double derivative_value = 0;
    double current_value = 1e9;

    while (abs(derivative_value - current_value) > loc_eps) {
        derivative_value = current_value;
        current_value = (f1(point + dx) - f1(point) - f2(point + dx) + f2(point)) / dx;
        dx /= 2;
    }

    return current_value;
}


double find_root(function f1, function f2, double left, double right)
{
    double local_eps = 1e-5;    

    while (abs(left - right) > 2 * local_eps)
    {
        if ((f1(left) - f2(left)) * sgn_derivative_2(f1, f2, left) < -eps) {
            left = left - ((f1(left) - f2(left)) * (left - right)) / ((f1(left) - f2(left)) - (f1(right) - f2(right)));
        } else if ((f1(left) - f2(left)) * sgn_derivative_2(f1, f2, left) > eps) {
            left = left - ((f1(left) - f2(left)) / get_derivative_1(f1, f2, left));
        }


        if ((f1(right) - f2(right)) * sgn_derivative_2(f1, f2, right) < -eps) {
            right = right - ((f1(right) - f2(right)) * (right - left)) / ((f1(right) - f2(right)) - (f1(left) - f2(left)));
        } else if ((f1(right) - f2(right)) * sgn_derivative_2(f1, f2, right) > eps) {
            right = right - ((f1(right) - f2(right)) / get_derivative_1(f1, f2, right));
        }
    }

    return (left + right) / 2;
}
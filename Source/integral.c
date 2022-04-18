#include "./../headers/integral.h"

double integral(function f, double left, double right) {
    double sum_border = f(left) + f(right);
    double sum_previous_step = 0;
    double sum_current_step = 0;

    double previous_integral = 0;
    double current_integral = INF;


    int n = 10;
    for (int i = 1; i < n; i++) {
        sum_previous_step += f(left + (right - left) * i / n);
    }


    while (p * abs(previous_integral - current_integral) > eps) {
        previous_integral = current_integral;
        sum_previous_step += sum_current_step;
        current_integral = 0;
        sum_current_step  = 0;
        
        for (int i = 1; i < n; i+=2) {
            sum_current_step += f(left + (right - left) * i / n);
        }

        current_integral = (sum_border + 4 * sum_current_step + 2 * sum_previous_step) * (right - left) / (3 * n);
        
        n *= 2;
    }

    return previous_integral;
}
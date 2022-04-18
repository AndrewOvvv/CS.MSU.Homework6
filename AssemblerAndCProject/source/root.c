#include "./../headers/root.h"


int sgn(double val) { //функция sgn возвращает знак аргумента (-1, 0, 1)
    return (val > eps) ? 1 : ((val > -eps) ? 0 : -1);
}


double get_derivative_1(function f1, function f2, double point) { // вычисляем первую производную разности функций по определению (достаточно малый dx)
    return ((f1(point + dx) - f2(point + dx) - f1(point) + f2(point)) / dx);
}


double sgn_derivative_2(function f1, function f2, double point) { // вычисляем знак второй производнй разности функции
    return sgn((get_derivative_1(f1, f2, point + dx) - get_derivative_1(f1, f2, point)) / dx);
}


double find_root(function f1, function f2, double left, double right) // находим корень на отрезке комбинированным методом
{
    while (fabs(left - right) > 2 * eps)
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

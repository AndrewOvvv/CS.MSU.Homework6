#ifndef INTEGRAL_H
#define INTEGRAL_H

#include "./root.h" //подключаем заголовок root.h 


static const double P_cnst = 1.0 / 15.0; //бъявляем константу для поиска интеграла методом Симсона
static const double INF = 1e9; //объявляем константу для бесконечности


//объявление функций
double integral(function f, double left, double right);


#endif //INTEGRAL_H

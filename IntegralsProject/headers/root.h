#ifndef ROOT_H
#define ROOT_H

#include <math.h>
#include <stdio.h> //подключаем стандартные библиотеки 
#include <string.h>
#include <stdlib.h> //которые будем использовать во всей программе
#include <stdbool.h>
#include <float.h>


typedef double(*function)(double); //объявляем новый тип - функция
static const double eps = 1e-7; //константа определяющая точность для нуля 0 == x (-eps < x < eps)
static const double eps2 = 1e-5; //константа определяющая точность для вычисления интеграла
static const double feps = 1e-3; //константа для проверки точности ответов на тестовую часть
static const double dx = 1e-2; //дельта икса для вычислений производных первого или второго порядка
static const int cnt_functions = 9; //колиество тестируемых функций


extern double get_f1_values_fun(double); //экстёрним функции из ассемблера
extern double get_f2_values_fun(double);
extern double get_f3_values_fun(double);


extern bool pprf;
extern bool pcif;

//объявление функции
bool equal(double val1, double val2, double eps);


int sgn(double val); 


double get_derivative_1(function f1, function f2, double point);


double sgn_derivative_2(function f1, function f2, double point);


double find_root(function f1, function f2, double left, double right, double eps1);


#endif //ROOT_H
#include "./../headers/get_area.h"

double get_area(function f1, function f2, function f3) {
	double border_1 = -1.875, border_2 = -1, border_3 = 0, border_4 = 0.5; //выставляем границы для поиска корней

	double root_1 = find_root(f1, f2, border_3, border_4); //ищем корни
	double root_2 = find_root(f2, f3, border_2, border_3); 
	double root_3 = find_root(f1, f3, border_1, border_2);
	

	double integral_1 = integral(f1, root_3, root_1); //ищем интегралы на заданных отрезках
	double integral_2 = integral(f2, root_2, root_1);
	double integral_3 = integral(f3, root_3, root_2);
	
	return integral_1 - integral_2 - integral_3; //возвращаем итоговое значение
}
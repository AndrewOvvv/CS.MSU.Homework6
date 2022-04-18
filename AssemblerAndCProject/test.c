#include <get_area.h>
#include <assert.h>

//additional functions
double sqr(double x) {
	return x * x; //x^2
}

double polynom(double x) {
	return 3 * sqr(x) * x + 4 * sqr(x) + 2; //3x^3 + 4x^2 + 2
}

double combine(double x) {
	return exp(x + 2) + 3 * sqr(x) - 10; //e^(x + 2) + 3x^2 - 10
}

double trigonomery(double x) {
	return cos(x) + sin(x); //cos(x) + sin(x)
}

double zero(double x) {
	return 0 * x; //0
}
//additional functions


int main(void )
{
	double test_result = 0;
	//test derivative
	printf("start of derivative test\n");
	test_result = get_derivative_1(sqr, zero, 3); //6
	printf("%f\n", test_result);

	test_result = get_derivative_1(polynom, zero, 3);
	printf("%f\n", test_result);

	test_result = get_derivative_1(combine, zero, 3);
	printf("%f\n", test_result);

	test_result = get_derivative_1(trigonomery, zero, 3);
	printf("%f\n", test_result);
	printf("end of derivative test\n\n");
	//test derivative	


	//test sign of second derivative
	printf("start of second derivative test\n");
	test_result = sgn_derivative_2(sqr, zero, 3); //+
	printf("%f\n", test_result);

	test_result = sgn_derivative_2(polynom, zero, 3); //+
	printf("%f\n", test_result);

	test_result = sgn_derivative_2(combine, zero, 3); //+
	printf("%f\n", test_result);

	test_result = sgn_derivative_2(trigonomery, zero, 3); //+
	printf("%f\n", test_result);
	printf("end of second derivative test\n\n");
	//test sign of second derivative


	//test find_root
	printf("start of find_root test\n");
	test_result = find_root(sqr, polynom, -2, -1); //-1.36028....
	printf("%f\n", test_result);

	test_result = find_root(sqr, trigonomery, -2, 0); //-0.56098....
	printf("%f\n", test_result);

	test_result = find_root(sqr, combine, 0, 1); //0.28608....
	printf("%f\n", test_result);

	test_result = find_root(trigonomery, combine, 0, 2); //0.38489...
	printf("%f\n", test_result);
	printf("end of find_root test\n\n");
	//test find_root


	//test integral
	printf("start of integral test\n");
	test_result = integral(sqr, 0, 1); //0.3333333....
	printf("%f\n", test_result);

	test_result = integral(polynom, 0, 1); //4.083333333333...
	printf("%f\n", test_result);

	test_result = integral(combine, 0, 1); //3.6964808242...
	printf("%f\n", test_result);

	test_result = integral(trigonomery, 0, 1); //1.30116867...
	printf("%f\n", test_result);
	printf("end of integral test\n\n");
	//test integral


	//compute final result
	printf("start of final test\n");
	test_result = get_area(get_f1_values_fun, get_f2_values_fun, get_f3_values_fun); //5.120194...
	printf("%f\n", test_result);
	printf("end of final test\n\n");
	//compute final result
	return 0;
}
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

double lin(double x) {
	return x + 2;
}
//additional functions


int main(int argc, char* argv[])
{
	bool phif = false; //print help info flag
	bool ptif = false; //print test info flag

	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-help") == 0) {
			phif = true;
		} else if (strcmp(argv[i], "-pprf") == 0) {
			pprf = true;
		} else if (strcmp(argv[i], "-pcif") == 0) {
			pcif = true;
		} else if (strcmp(argv[i], "-test") == 0) {
			ptif = true;
		} else {
			printf("Error: use undefined flag\nUse '-help' to get info about flags\n\n");
		}
	}

	if (phif) {
		printf("-test - flag which swows additional test info\n");
		printf("-pprf - flag which shows coordinates of intersection points\n");
		printf("-pcif - flag which shows number of itterations of find_root functions\n\n");
	}


	if (ptif) {
		printf("begin of test section\n");
		function all_functions[] = {get_f1_values_fun, get_f2_values_fun, get_f3_values_fun, sqr, lin, polynom, combine, trigonomery, zero};
		double integral_ans_array[] = {16.2083, 42.5, 1.2527, 41.6666, 22.5, 645.4166, 1164.2441, -0.2426};
		double root_ans_array[] = {0.4481, -0.1528, 0.6180, 2, 0.2152, 0.5493, 0.3848};

		double left = 0, right = 5;

		//integral test
		for (int i = 0; i < cnt_functions; i++) {
			double result = integral(all_functions[i], left, right, eps2);
			assert(equal(result, integral_ans_array[i], feps));
			printf("integral of %i function: %f\n", i + 1, result);
		}
		printf("\n");
		//integral test


		//root test
		left = 0.1;
		right = 1;
		for (int i = 0; i < cnt_functions - 2; i+=2) {
			double result = find_root(all_functions[i], all_functions[i + 1], left, right, eps);
			assert(equal(result, root_ans_array[i], feps));
			printf("point if intersection %i function and %i function has %f - x-coord\n", i + 1, i + 2, result);
		}
		printf("\n");
		//root test
		printf("end of test section\n\n");
	}


	printf("start of final test\n");
	double test_result = get_area(get_f1_values_fun, get_f2_values_fun, get_f3_values_fun); //5.120194...
	printf("%f\n", test_result);
	printf("end of final test\n\n");


	return 0;
}

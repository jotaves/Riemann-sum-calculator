double ftest(double x){
	return 1 - pow (x, 2);
}

double f1(double x){
	return - (pow (x, 2)) + 25;
}

double f2(double x){
	return sin (2 * x);
}

double f3(double x){
	return sin (x) + pow ((M_E), x);
}

void RiemannSum (double a, double b, double n, double (&summation)[4], double (&f)(double)){
	double delta_x = (b-a)/n;
	/* Right sum */
	summation[0] = 0;
	for (double x(a+delta_x); x <= b; x += delta_x){
		summation[0] += f(x)*delta_x;
	}

	/* Middle sum */
	summation[1] = 0;
	for (double x(a+(delta_x/2)); x < b; x += delta_x){
		summation[1] += f(x)*delta_x;
	}

	/* Left sum */
	summation[2] = 0;
	for (double x(a); x < b; x += delta_x){
		summation[2] += f(x)*delta_x;
	}

	/* Trapezoidal Rule */
	summation[3] = 0;
	for (double x(a); x <= b; x += delta_x){
		/* summation = ((f(a) + f(b)) * (delta_x))/2 */
		summation[3] += (f(x)+f(x+delta_x))*delta_x;
	}
	summation[3] /= 2;	
}
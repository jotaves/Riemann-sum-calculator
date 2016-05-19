// g++ -Wall -std=c++11 src/calculator.cpp -I include/ -o bin/calculator
// ./bin/calculator

#include <iostream>
#include <cmath>

#include "calculator.h"

int main (void){
	/* 'a' é o primeiro elemento da integral (início) */
	/* 'b' é o segundo elemento da integral (fim) */
	/* 'n' é a quantidade de partições no período fechado */
	double a, b, n;
	/* summation é um arranjo com 4 elementos, sendo eles:
	** summation[0] -> Somatório de Riemann com soma à direita
	** summation[1] -> Somatório de Riemann com regra do ponto médio
	** summation[2] -> Somatório de Riemann com soma à esquerda
	** summation[3] -> Somatório com Regra do Trapézio
	*/
	double summation[4];

	/* Intervalo a ser calculado */
	a = 0; b = 1;
	/* Calculando na função teste */
	std::cout << "\n### Function Test: 1-x^2 ###\n\n";
	for(n = 2; n < 4096; n *= 2){
		RiemannSum(a, b, n, summation, ftest);
		std::cout << "Number of partitions = " << n << "\n";
		printf("%lf -> Right\n", summation[0]);
		printf("%lf -> Middle\n", summation[1]);
		printf("%lf -> Left\n", summation[2]);
		printf("%lf -> Trapezoidal\n\n", summation[3]);
	}

	/* Intervalo a ser calculado */
	a = -5; b = 5;
	/* Calculando na função 1 */
	std::cout << "\n### Function 1: -x^2+25 ### \n\n";	
	for(n = 2; n < 4096; n *= 2){
		RiemannSum(a, b, n, summation, f1);
		std::cout << "Number of partitions = " << n << "\n";
		printf("%lf -> Right\n", summation[0]);
		printf("%lf -> Middle\n", summation[1]);
		printf("%lf -> Left\n", summation[2]);
		printf("%lf -> Trapezoidal\n\n", summation[3]);
	}

	/* Intervalo a ser calculado */
	a = 0; b = M_PI_4;
	/* Calculando na função 2 */
	std::cout << "\n### Function 2: sin(2*x) ###\n\n";
	for(n = 2; n < 4096; n *= 2){
		RiemannSum(a, b, n, summation, f2);
		std::cout << "Number of partitions = " << n << "\n";
		printf("%lf -> Right\n", summation[0]);
		printf("%lf -> Middle\n", summation[1]);
		printf("%lf -> Left\n", summation[2]);
		printf("%lf -> Trapezoidal\n\n", summation[3]);
	}

	/* Intervalo a ser calculado */
	a = 1; b = 2;
	/* Calculando na função 3 */
	std::cout << "\n### Function 3: sin(x)+e^x ###\n\n";
	for(n = 2; n < 4096; n *= 2){
		RiemannSum(a, b, n, summation, f3);
		std::cout << "Number of partitions = " << n << "\n";
		printf("%lf -> Right\n", summation[0]);
		printf("%lf -> Middle\n", summation[1]);
		printf("%lf -> Left\n", summation[2]);
		printf("%lf -> Trapezoidal\n\n", summation[3]);
	}		
	return 0;
}
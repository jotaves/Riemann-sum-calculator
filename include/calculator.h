#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include <cmath>

double ftest(double x);

double f1(double x);

double f2(double x);

double f3(double x);

void RiemannSum (double a, double b, double n, double (&summation)[4], double (&f)(double));

#include "calculator.inl"

#endif
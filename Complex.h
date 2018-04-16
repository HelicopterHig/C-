#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

void menu(void);



	int x;
	int y;

typedef struct Complex_struct* Complex;
Complex_struct* add(Complex_struct complex_number, Complex_struct *complex_old, size_t &size);
Complex_struct* complex_delete(Complex_struct *complex_old, size_t &size, int count);
Complex_struct addition(Complex_struct one, Complex_struct two);
Complex_struct subtraction(Complex_struct one, Complex_struct two);
Complex_struct multiplication(Complex_struct one, Complex_struct two);
void print_complex(Complex_struct complex);

#endif

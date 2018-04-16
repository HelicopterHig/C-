#include "Complex.h"

Complex_struct* add(Complex_struct complex_number, Complex_struct *complex_old, size_t &size)
{
	Complex_struct *complex_new = new Complex_struct[size + 1];

	for (size_t i = 0; i < size; i++)
	{
		complex_new[i].x = complex_old[i].x;
		complex_new[i].y = complex_old[i].y;
	}

	complex_new[size] = complex_number;

	size++;
	delete[] complex_old;

	return complex_new;
}

Complex_struct* complex_delete(Complex_struct *complex_old, size_t &size,int count)
{
	Complex_struct *complex_new = new Complex_struct[size - 1];
	int size1 = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (count == i + 1)
			continue;

		complex_new[size1].x = complex_old[i].x;
		complex_new[size1].y = complex_old[i].y;
		size1++;

	}
	delete[] complex_old;
	complex_old = complex_new;
	size--;

	return complex_old;
}

Complex_struct addition(Complex_struct one, Complex_struct two)
{
	return { one.x + two.x,one.y + two.y };
}

Complex_struct subtraction(Complex_struct one, Complex_struct two)
{
	return { one.x - two.x,one.y - two.y };
}

Complex_struct multiplication(Complex_struct one, Complex_struct two)
{
	return { one.x * two.x,one.y * two.y };
}

void print_complex(Complex_struct complex)
{
	cout << "z =";
	if (complex.x)
		cout << " " << complex.x;

	if(!complex.x && !complex.y)
		cout << " 0";
	if (complex.y > 0)
		if (!complex.x)
			if (!(complex.y == 1))
				cout << " " << complex.y << "i";
			else
				cout << " " << "i";
		else
			if (!(complex.y == 1))
				cout << " + " << complex.y << "i";
			else
				cout << " + " << "i";
	if (complex.y < 0)
		if (!complex.x)
			if (!(complex.y == -1))
				cout << " " << complex.y << "i";
			else
				cout << " " << "-i";
			
		else
			if (!(complex.y == -1))
				cout << " - " << abs(complex.y) << "i";
			else
				cout << " - " << "i";
			
		
	cout << endl;
}

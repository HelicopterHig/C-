#include "Complex.h"

int main()
{
	setlocale(LC_ALL,"Rus");
	int count;
	bool is = true;
	size_t size = 0;
	Complex_struct *complex_arr = new Complex_struct[size];

	complex_arr = add({ 3,1 }, complex_arr, size);
	complex_arr = add({ 6,0 }, complex_arr, size);
	complex_arr = add({ 0,8 }, complex_arr, size);

	Complex_struct(*operation)(Complex_struct, Complex_struct);

	while (is)
	{
		menu();
		cin >> count;
		cout << "\n";
		switch (count)
		{
		case 1:
			if (size)
			{
				for (size_t i = 0; i < size;i++)
				{
					cout << i + 1 << ") ";
					print_complex(complex_arr[i]);
				}
			}
			else
				cout << "Введите x и y комплексного числа: ";
			break;
		case 2:
		{
			cout << "Введите x и y комплексного числа: ";
			int x = 0, y = 0;
			cin >> x >> y;
			complex_arr = add({ x,y }, complex_arr, size);
		}
			break;
		case 3:
			if (size)
			{
				cout << "\nУдалить число под номером: ";
				cin >> count;
				complex_arr = complex_delete(complex_arr,size,count);
			}
			else
				cout << "Список пуст.\n";
			break;
		case 4:
			size = 0;
			{
				Complex_struct *complex_new = new Complex_struct[size];
				delete[] complex_arr;
				complex_arr = complex_new;
			}
			break;
		case 5:
			cout << "Сложить числа под номерами(двумя): ";
			{
				int i1, i2,x,y;
				cin >> i1 >> i2;
				operation = addition;
				complex_arr = add(operation(complex_arr[i1 - 1], complex_arr[i2 - 1]),complex_arr,size);
			}
			break;
		case 6:
			cout << "Введите номер числа из которого нужно вычесть, а следом какое: ";
			{
				int i1, i2, x, y;
				cin >> i1 >> i2;
				operation = subtraction;
				complex_arr = add(operation(complex_arr[i1 - 1], complex_arr[i2 - 1]), complex_arr, size);
			}
			break;
		case 7:
			cout << "Умножить числа под номерами(двумя): ";
			{
				int i1, i2, x, y;
				cin >> i1 >> i2;
				operation = multiplication;
				complex_arr = add(operation(complex_arr[i1 - 1], complex_arr[i2 - 1]), complex_arr, size);
			}
			break;
		case 8:
			is = false;
			break;
		default:
			cout << "Такого пункта не существует!";
			break;
		}

		cout << "\n\n\n\n";
	}



	delete[] complex_arr;
}

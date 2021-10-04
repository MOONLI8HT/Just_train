#include <iostream>
#include <iomanip>
#include <string>
//#include <chrono> //std::this_thread::sleep_for(std::chrono::milliseconds(300));
//#include <thread>
#include <cmath>
//#include <ctime> //for srand(time(NULL)) 
//#include <algorithm>
#define DEBUG


using namespace std;




/*
"switch construct"
switch ("varible")
{
	case "name":
	{
		"body";
		break;
	}
	default:
	{
		"body";
		break
	}
}

	//templets <class T1 or namespace T1>
	//srand(time(NULL));
	//rand();
	//sizeof();
	//inline
	//new - создать объект в дин памяти
	//delete -удалить бъект в дин памяти
	//nullptr - удалить указатель
	//pa = nullptr
*/


void standart()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
}
void fillarray2(int** const arr, const int rows, const int cols, const int max_num)
{

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (max_num + 1);
		}
	}
	
}
void fillarray(int* const arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 20;
	}
}
void showarray(int* const arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << setw(3);
	}
	cout << "\n";
}
void showarray2(int** const arr, const int rows, const int cols, const int max_num)
{
	int distance = 2, maxi = max_num;
	while (maxi > 9)
	{
		distance += 1;
		maxi = maxi / 10;
	}
	cout << setw(distance);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << setw(distance);
		}
		cout << endl;
	}
}
void push_back(int *&arr, int& size, const int value)
{
	int* new_arr = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		new_arr[i] = arr[i];
	}
	delete[] arr;
	new_arr[size] = value;
	size++;
	arr = new_arr;
}
void pop_back(int *&arr, int& size)
{
	size--;
	int* new_arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		new_arr[i] = arr[i];
	}
	delete[] arr;
	arr = new_arr;
}
void add_in_pos(int *&arr, int& size)
{
	int value, id;
	cout << "Add new element\n";
	cout << "Enter new value: "; cin >> value;
	cout << "Enter position number: "; cin >> id;
	if (id > size) { id = size; }
	int* new_arr = new int[size + 1];
	size++;
	for (int i = 0; i < size; i++)
	{
		if (i < id)
		{
			new_arr[i] = arr[i];
		}
		else if (i > id)
		{
			new_arr[i] = arr[i - 1];
		}
		else
		{
			new_arr[i] = value;
		}
	}
	delete[] arr;
	arr = new_arr;
}
void pop_from_pos(int *&arr, int& size) 
{
	cout << "Delete element from position\n";
	int id; cout << "Enter position number: "; cin >> id;

	size--;  int* new_arr = new int[size];

	for (int i = 0; i <= size; i++)
	{
		if (i < id)
		{
			new_arr[i] = arr[i];
		}
		else if (i > id)
		{
			new_arr[i - 1] = arr[i];
		}
	}
	delete[] arr;
	arr = new_arr;
}
void start_cicle()
{
#ifdef DEBUG > 0
	cout << "Начало цикла\n";
#endif
}
void end_cicle()
{
#ifdef DEBUG > 0
	cout << "Конец цикла\n";
#endif
}
void x3_plus_1(int &x)
{
	(x % 2 == 0) ? (x = x / 2) : (x = x * 3 + 1);
}

class MyClass
{	
public:
	
	MyClass(int size)//может быть несколько
	{
		this->Size = size;
		this->data = new int[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = i;
		}
		cout << data << " Конструктор\n";
	}
	~MyClass()//параметров быть не может, только один
	{
		delete[] data;
		cout << data << " Деструктор\n";
	}
	MyClass(const MyClass &other) //конструкция копирования
	{
		this->Size = other.Size;
		this->data = new int[other.Size];
		for (int i = 0; i < other.Size; i++)
		{
			this->data[i] = other.data[i];
		}
		cout << data << " Копирование\n";
	}
	void print()
	{
		for (int i = 0; i < Size; i++)
		{
			cout << setw(3) << data[i];
		}
		cout << endl;
	}
private:
	int Size;
	int* data;
};
class point
{
	
public:
	int x, y, z;
	point() {
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}
	template <class T1>
	point(T1 x = 0, T1 y = 0, T1 z = 0)//конструктор класса, обязательно в паблик
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	void print(int a = 0)
	{
		cout << "x = " << x << "\ny = " << y << "\nz = " << z << endl;
		print_r(x, y, z);
	}

private:
	template <class T1>
	void print_r(T1 x, T1 y, T1 z)
	{
		double R = pow(pow(x, 2) + pow(y, 2) + pow(z, 2), 0.5);
		cout << "Радиус = " << R << endl;
	}

};

//void main(int argc, char* argv[])
int main()
{
	standart();
	MyClass a(5);
	MyClass b(a);
	
	//system("pause"); пауза для .exe вызова
	return 0;
}



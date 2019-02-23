#include<iostream>
#include<locale.h>
#include<time.h>
#include<Windows.h>


using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void fillArray(int *arr, int n)
{
	for (int *p = arr; p != arr+n; p++)
	{
		*p = 1 + rand() % 55;
	}
}

void printArray(int *arr, int n)
{
	cout << endl;

	for (int *p = arr; p != arr + n; p++)
	{
		cout << *p << "  ";
	}

	cout <<"\n\n";
}

void selectionSort(int *arr, int n)
{
	for (int *p = arr; p != arr + n; p++)
		for (int *c =p; c != 0; c--)
			{
				if (*c < *(c-1))
					swap(*c, *(c - 1));
				else
					break;
			}
}

void seachArray(int arr[], int n, int key)
{
	int sumMore = 0;

	for (int *p = arr; p != arr + n; p++)
	{
		if (*p > key) sumMore++;
	}

	cout << endl << "Кол-во элементов > " << key << " = " << sumMore << endl;
	cout << endl << "Кол-во элементов < " << key << " = " << n - sumMore << endl;
	
	if (sumMore > n - sumMore)
		cout << "\n В массиве кол-во элемнтов со значением > "<<key<<" больше."<<endl<<endl;
	else
		cout << "\n В массиве кол-во элемнтов со значением < " << key << " больше.";
}

void Task1()
{
	/*11. Используя указатели в упорядоченном по возрастанию массиве выяснить, что больше элементов со значением > Р
	или элементов со значением < Р.*/


	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask2\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	int n;
	cout << "Введите размер массива -> ";
	cin >> n;
	int *arr = new int[n];

	int key;
	cout << "Введите отправную точку P для поиска элементов массива по условию -> ";
	cin >> key;

	fillArray(arr, n);
	printArray(arr, n);
	selectionSort(arr, n);
	printArray(arr, n);
	seachArray(arr, n, key);

	delete[]arr;

}

void Task2()
{
	

	


}


int main()
{
	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n Orlov Vladimir HomeWork_19_02_2019_1550591366 \n\n";
	SetConsoleTextAttribute(hConsole, 7);


	setlocale(LC_ALL, "");
	srand(time(NULL));

	int number;
	char flag;

	do
	{
		cout << endl << "Enter number of Task (1) to (2) => ";
		cin >> number;

		switch (number)
		{
		case 1: {Task1(); } break;
		case 2: {Task2(); } break;


		default: cout << "\nEntered number of Task does not exist...\n\n";

		}

		SetConsoleTextAttribute(hConsole, 10);
		cout << "\n--------------------------------------------------------------------------\n\n";
		SetConsoleTextAttribute(hConsole, 7);

		cout << "Do you want to continue? \n\nIf YES press (y) if NO any keys => ";
		cin >> flag;

	} while (flag == 'y');
}

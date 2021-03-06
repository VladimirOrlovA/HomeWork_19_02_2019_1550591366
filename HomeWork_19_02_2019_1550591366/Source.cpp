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

void seachArray(int *arr, int n, int key)
{
	int sumMore = 0;

	for (int *p = arr; p != arr + n; p++)
	{
		if (*p > key) sumMore++;
	}

	cout << endl << "���-�� ��������� > " << key << " = " << sumMore << endl;
	cout << endl << "���-�� ��������� < " << key << " = " << n - sumMore << endl;
	
	if (sumMore > n - sumMore)
		cout << "\n � ������� ���-�� �������� �� ��������� > "<<key<<" ������."<<endl<<endl;
	else
		cout << "\n � ������� ���-�� �������� �� ��������� < " << key << " ������.";
}

void sumArrayPtoK(int *arr, int n, int p, int k)
{
	int pind = 0;
	int kind = 0;
	int sum = 0;
	
	for (int *c = arr; c != arr + n; c++)
	{
		if (*c == p) pind = c-arr;
		if (*c == k) kind = c-arr;
	}
	
	kind++; // �� ������� ����� ��� ����� �� �������� K ������ �� ������� ���, ���� ������, �� ������ ������� ���� ���������  

	for (kind; kind != pind; kind++) 
		sum += arr[kind];

	cout << "����� ��������� ����� ���������� �� ���������� K � P = " << sum << endl;
}

void Task1()
{
	/*11. ��������� ��������� � ������������� �� ����������� ������� ��������, ��� ������ ��������� �� ��������� > �
	��� ��������� �� ��������� < �.*/


	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask1\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	int n;
	cout << "������� ������ ������� -> ";
	cin >> n;
	int *arr = new int[n];

	int key;
	cout << "������� ��������� ����� P ��� ������ ��������� ������� �� ������� -> ";
	cin >> key;

	fillArray(arr, n);
	selectionSort(arr, n);
	printArray(arr, n);
	seachArray(arr, n, key);

	delete[]arr;

}

void Task2()
{
	/*12. ��������� ��������� � ������������� �� ����������� ������� ���������� ����� ���������, 
		������������� �� ��������� �� ��������� � � �� �������� �� ��������� �(� > �).*/
	

	
	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask2\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	int n = 0, p = 0, k=INT_MAX;
	cout << "������� ������ ������� -> ";
	cin >> n;
	int *arr = new int[n];

	fillArray(arr, n);
	selectionSort(arr, n);
	printArray(arr, n);

	cout << "������� �������� P \t -> ";
	cin >> p;

	while (k >= p)
	{
		cout << "������� �������� K < P \t -> ";
		cin >> k;
		if (k >= p) cout << "\n��������� �������� K �� ������������� �������. ���������� ��� ���...\n";
	}

	sumArrayPtoK(arr, n, p, k);


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

#include<iostream>
#include<locale.h>
#include<time.h>
#include<Windows.h>


using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void fillArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = 1 + rand() % 99;
	}
}

void printArray(int arr[], int n)
{
	int count = 1;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
		count++;
	}
}

int minSumTen(int arr[], int n, int start, int step)
{
	static int ind = 0;
	static int sum = 0, sumb = INT_MAX;

	if (step >= n) return ind;

	sum = 0;
	for (int i = start; i < step; i++)
	{
		sum += arr[i];
	}

	if (sum < sumb)
	{
		sumb = sum;
		ind = start;
		minSumTen(arr, n, start + 1, step + 1);
	}
	else minSumTen(arr, n, start + 1, step + 1);
}



void fillArray2Spiral(int arr2[][30], int n, int m)
{
	int count = 1;
	int i, j, k = 0;

	i = k;
	j = k;

	while (k != m / 2)
	{
		for (i = k; i < n - k; i++)
		{
			for (j = k; j < m - k; j++) if (i == k) arr2[i][j] = count++; // верх строка 
			for (j = k; j < m - k; j++)	if (i != k && i < n - k && j == m - k - 1) arr2[i][j] = count++; // верт правый столбец	
			for (j = m - k - 1; j >= k; j--) if (i == n - k - 1 && j != m - k - 1) arr2[i][j] = count++; // нижн строка
		}
		for (i = n - k - 1; i > k; i--) if (i != n - k - 1 && i != j) arr2[i][j = k] = count++; // верт левый столбец
		if (m % 2 != 0) arr2[n / 2][m / 2] = count; // заполнение центра при нечетном размере матрицы
		k++;
	}
	cout << endl;
}

int fillArray2SpiralR(int arr2[][30], int n, int m)
{
	static int count = 1, k = 0;
	int i, j;
	i = k;
	j = k;

	if (k == n / 2 + 1)
	{
		count = 1;
		k = 0;
		cout << endl;
		return 0;
	}

	for (i = k; i < n - k; i++)
	{
		for (j = k; j < m - k; j++) if (i == k) arr2[i][j] = count++; // верх строка 
		for (j = k; j < m - k; j++)	if (i != k && i < n - k && j == m - k - 1) arr2[i][j] = count++; // верт правый столбец	
		for (j = m - k - 1; j >= k; j--) if (i == n - k - 1 && j != m - k - 1) arr2[i][j] = count++; // нижн строка
	}
	for (i = n - k - 1; i > k; i--) if (i != n - k - 1 && i != j) arr2[i][j = k] = count++; // верт левый столбец
	if (m % 2 != 0) arr2[n / 2][m / 2] = count - 1; // заполнение центра при нечетном размере матрицы
	k++;

	fillArray2SpiralR(arr2, n, m);
}

void printArray2(int arr2[][30], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr2[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

void Task1()
{
	/*1.	**Ќапишите рекурсивную функцию, котора€ принимает одномерный массив из 100 целых чисел заполненных случайным образом
		и находит позицию, с которой начинаетс€ последовательность из 10 чисел, сумма которых минимальна.*/

	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask1\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	int n = 0, start = 0, step = 10;
	int arr[100] = { 0 };


	cout << "¬ведите размер одномерного массива -> ";
	cin >> n;
	cout << endl;

	fillArray(arr, n);
	cout << minSumTen(arr, n, start, step);
}

void Task2()
{
	/*2.	Ќапишите рекурсивную функцию, котора€ заполн€ет матрицу по спирали
		ѕример :
		1  2  3   4
		12 13 14  5
		11 16 15  6
		10 9  8   7*/


	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask2\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	int arr2[30][30] = { 0 };
	int n, m;

	cout << "¬ведите размер квадратной матрицы -> ";
	cin >> n;
	cout << endl;
	m = n;

	//printArray2(arr2, n, m);
	//fillArray2Spiral(arr2, n, m);
	fillArray2SpiralR(arr2, n, m);
	printArray2(arr2, n, m);


}


int main()
{
	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n Orlov Vladimir HomeWork_14_02_2019_1550157314 \n\n";
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

#include <iostream>
#include "Sort.h"
#include <fstream>
using namespace std;

int countLines(string filename);
int main() {
	int n = 0;
	n = countLines("data.txt");//文件行数，待排元素个数
	int a = n + 1;
	ifstream textfile;
	textfile.open("data.txt");//读取文件
	int* R = new int[a];
	int i = 1;
	while (!textfile.eof())
	{
		textfile >> R[i];
		i++;
	}
	textfile.close();
	int *R1 = new int[a];
	int *R2 = new int[a];
	int *R3 = new int[a];
	int *R4 = new int[a];
	int *R5 = new int[a];
	int *R6 = new int[a];

	for (int i = 1; i < a; i++)
	{
		R1[i] = R[i];
		R2[i] = R[i];
		R3[i] = R[i];
		R4[i] = R[i];
		R5[i] = R[i];
		R6[i] = R[i];
	}
	Sort sort;
	sort.selectSort(R1, n);
	cout << endl;
	sort.insertSort(R2, n);
	cout << endl;
	sort.bubbleSort(R3, n);
	cout << endl;
	sort.setArray(R4);
	sort.quickSort(1, n);
	cout << endl;
	sort.mergeSort(R5, n);
	cout << endl;
	sort.heapSort(R6, n);
	cout << endl;
	system("pause");
	return 1;
}

int countLines(string filename)
{
	char str[20];
	ifstream ReadFile;
	int n = 0;
	char line[512];
	string temp;
	ReadFile.open(filename, ios::in);
	if (ReadFile.fail())
	{
		return 0;
	}
	else
	{
		while (!ReadFile.eof())
		{
			ReadFile.getline(str,sizeof(str));
			n++;
		}
		return n;
	}

	ReadFile.close();
}
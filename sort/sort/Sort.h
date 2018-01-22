#pragma once
#include<iostream>
#include <list>
using namespace std;
class Sort
{
public:
	Sort();
	~Sort();
	void selectSort(int* R, int n);
	void insertSort(int* R, int n);
	void bubbleSort(int* R, int n);
	void quickSort(int i, int j);
	void setArray(int* R);
	void mergeSort(int* R,int n);
	void heapSort(int* R, int n);
private:
	void partition(int i, int j, int &k);
	void merge(int* R, int* S, int a, int b, int c);
	void mergePass(int* R, int* S, int &m);
	void sift(int* R,int i, int m);
	void quickSortPrivate(int i, int j);
	int* R;//快速排序使用
	int count1 = 0, count2 = 0;//快速、归并排序计数使用
	int n;//归并排序使用
	
};

Sort::Sort()
{
}

Sort::~Sort()
{
}

void Sort::selectSort(int* R, int n)
{
	int i, j, k, count1=0, count2=0;
	for (i = 1; i <= n - 1; i++) {
		k = i;
		for (j = i + 1; j <= n; j++) {
			if (R[j] < R[k]) {
				k = j;
			}
			count1++;
		}
		if (k>i) {
			R[0] = R[k];
			R[k] = R[i];
			R[i] = R[0];
			count2 = count2 + 3;
		}
	}
	cout << "排序结果：";
	for (int i = 1; i <= n; i++)
	{
		cout << R[i] << "\t";
	}
	
	cout << endl << "对于长度为" << n << "的数组使用简单选择排序,元素比较了" << count1 << "次，移动了" << count2 << "次。" << endl;
}

void Sort::insertSort(int* R, int n) {
	int i, j, count1=0, count2=0;
	for (i = 2; i <= n; i++) {
		R[0] = R[i];
		count2++;
		j = i - 1;
		while (R[0] < R[j]) {
			count1++;
			R[j + 1] = R[j];
			count2++;
			j--;
		}
		R[j + 1] = R[0];
		count1++;
	}
	cout << "排序结果：";
	for (int i = 1; i <= n; i++)
	{
		cout << R[i] << "\t";
	}

	cout << endl << "对于长度为" << n << "的数组使用直接插入排序,元素比较了" << count1 << "次，移动了" << count2 << "次。" << endl;
}

void Sort::bubbleSort(int* R, int n) {
	int i, j, swap, count1=0, count2=0;
	i = n+1;
	do
	{
		swap = 0;
		for (j = 1;j < i-1; j++)
		{
			count1++;
			if (R[j] > R[j + 1]) {
				swap = 1;
				R[0] = R[j];
				R[j] = R[j + 1];
				R[j + 1] = R[0];
				count2 ++;
			}
		}
		i--;
	} while ((i>1)&&swap);
	cout << "排序结果：";
	for (int i = 1; i <= n; i++)
	{
		cout << R[i] << "\t";
	}

	cout << endl << "对于长度为" << n << "的数组使用冒泡排序,元素比较了" << count1 << "次，移动了" << count2 << "次。" << endl;
}

void Sort::setArray(int* R) {
	this->R = R;
}

void Sort::quickSort(int i, int n) {
	count1 = count2 = 0;
	quickSortPrivate(i, n);
	cout << "排序结果：";
	for (int i = 1; i <= n; i++)
	{
		cout << R[i] << "\t";
	}

	cout << endl << "对于长度为" << n << "的数组使用快速排序,元素比较了" << count1 << "次，移动了" << count2 << "次。" << endl;


}

void Sort::quickSortPrivate(int i, int j) {
	int k;
	
	if (i < j) {
		partition(i, j, k);
		quickSortPrivate(i, k - 1);
		quickSortPrivate(k + 1, j);
	}
}

void Sort::partition(int i, int j, int &k)
{
	R[0] = R[i];
	count2++;
	while (i<j) {
		while ((i < j) && (R[j] >= R[0])) {
			j--;
			count1++;
		}
		if (i < j) {
			R[i++] = R[j];
			count2++;
		}
		while ((i < j) && (R[i] <= R[0])) {
			i++;
			count1++;
		}
		if (i < j) {
			R[j--] = R[i];
			count2++;
		}
	}
	R[i] = R[0];
	count2++;
	k = i;
}

//两组归并
void Sort::merge(int* R, int* S, int a, int b, int c)
{
	int i, j, k;
	i = a;//第一组起始
	j = b + 1;//第二组起始
	k = a;
	while ((i <= b) && (j <= c)){
		if (R[i] <= R[j]) {
			S[k++] = R[i++];
			count2++;
		}
		else {
			S[k++] = R[j++];
			count2++;
		}
		count1++;
	}
		while (i <= b) {
			S[k++] = R[i++];
			count2++;
		}
		while (j <= c){
			S[k++] = R[j++];
			count2++;
		}
	
}

//一趟归并          
void Sort:: mergePass(int* R, int* S, int &m)
{
	int i = 1, j;
	while (i + 2 * m - 1 <= n) {  //相邻的两个有序表长度都是m
		merge(R, S, i, i + m - 1, i + 2 * m - 1);
		i = i + 2 * m;
	}
	if (i + m - 1<n)//剩下两个有序表，最后一个有序表长度小于m       
		merge(R, S, i, i + m - 1, n);
	else       //剩下一个有序表                         
		for (j = i; j <= n; j++) {
			S[j] = R[j];
			count2++;
		}
	m = 2 * m;
}

//归并排序
void Sort::mergeSort(int* R, int n)
{
	count1 = 0; count2 = 0;
	this->n = n;
	int* S = new int[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		S[i] = R[i];
	}

	int m = 1;
	while (m < n) {
		mergePass(R, S, m);
		mergePass(S, R, m);
	}
	cout << "排序结果：";
	for (int i = 1; i <= n; i++)
	{
		cout << R[i] << "\t";
	}

	cout << endl << "对于长度为" << n << "的数组使用归并排序,元素比较了" << count1 << "次，移动了" << count2 << "次。" << endl;

}


//筛选操作          
void Sort::sift(int* R,int i, int m)
{
	int k;
	R[0] = R[i]; 
	count2++;
	k = 2 * i;
	while (k <= m) {
		if ((k < m) && (R[k] < R[k + 1])) {
			k++;
		}
		count1++;
		if (R[0]<R[k]) {
			R[i] = R[k];
			count2++;
			i = k;
			k = 2 * i;
		}
		else {
			k = m + 1;
		}
		count1++;
	}
	R[i] = R[0];
}

//堆排序
void Sort::heapSort(int* R,int n)
{
	count1 = 0; count2 = 0;
	int j;
	for (j = n / 2; j >= 1; j--){
		sift(R, j, n);
	}

	for (j = n; j >= 2; j--) {
		R[0] = R[1];
		R[1] = R[j];
		R[j] = R[0];
		count2 += 3;
		sift(R,1, j - 1);
	}

	cout << "排序结果：";
	for (int i = 1; i <= n; i++)
	{
		cout << R[i] << "\t";
	}

	cout << endl << "对于长度为" << n << "的数组使用堆排序,元素比较了" << count1 << "次，移动了" << count2 << "次。" << endl;

}



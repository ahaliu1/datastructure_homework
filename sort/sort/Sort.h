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
	int* R;//��������ʹ��
	int count1 = 0, count2 = 0;//���١��鲢�������ʹ��
	int n;//�鲢����ʹ��
	
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
	cout << "��������";
	for (int i = 1; i <= n; i++)
	{
		cout << R[i] << "\t";
	}
	
	cout << endl << "���ڳ���Ϊ" << n << "������ʹ�ü�ѡ������,Ԫ�رȽ���" << count1 << "�Σ��ƶ���" << count2 << "�Ρ�" << endl;
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
	cout << "��������";
	for (int i = 1; i <= n; i++)
	{
		cout << R[i] << "\t";
	}

	cout << endl << "���ڳ���Ϊ" << n << "������ʹ��ֱ�Ӳ�������,Ԫ�رȽ���" << count1 << "�Σ��ƶ���" << count2 << "�Ρ�" << endl;
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
	cout << "��������";
	for (int i = 1; i <= n; i++)
	{
		cout << R[i] << "\t";
	}

	cout << endl << "���ڳ���Ϊ" << n << "������ʹ��ð������,Ԫ�رȽ���" << count1 << "�Σ��ƶ���" << count2 << "�Ρ�" << endl;
}

void Sort::setArray(int* R) {
	this->R = R;
}

void Sort::quickSort(int i, int n) {
	count1 = count2 = 0;
	quickSortPrivate(i, n);
	cout << "��������";
	for (int i = 1; i <= n; i++)
	{
		cout << R[i] << "\t";
	}

	cout << endl << "���ڳ���Ϊ" << n << "������ʹ�ÿ�������,Ԫ�رȽ���" << count1 << "�Σ��ƶ���" << count2 << "�Ρ�" << endl;


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

//����鲢
void Sort::merge(int* R, int* S, int a, int b, int c)
{
	int i, j, k;
	i = a;//��һ����ʼ
	j = b + 1;//�ڶ�����ʼ
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

//һ�˹鲢          
void Sort:: mergePass(int* R, int* S, int &m)
{
	int i = 1, j;
	while (i + 2 * m - 1 <= n) {  //���ڵ�����������ȶ���m
		merge(R, S, i, i + m - 1, i + 2 * m - 1);
		i = i + 2 * m;
	}
	if (i + m - 1<n)//ʣ��������������һ���������С��m       
		merge(R, S, i, i + m - 1, n);
	else       //ʣ��һ�������                         
		for (j = i; j <= n; j++) {
			S[j] = R[j];
			count2++;
		}
	m = 2 * m;
}

//�鲢����
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
	cout << "��������";
	for (int i = 1; i <= n; i++)
	{
		cout << R[i] << "\t";
	}

	cout << endl << "���ڳ���Ϊ" << n << "������ʹ�ù鲢����,Ԫ�رȽ���" << count1 << "�Σ��ƶ���" << count2 << "�Ρ�" << endl;

}


//ɸѡ����          
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

//������
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

	cout << "��������";
	for (int i = 1; i <= n; i++)
	{
		cout << R[i] << "\t";
	}

	cout << endl << "���ڳ���Ϊ" << n << "������ʹ�ö�����,Ԫ�رȽ���" << count1 << "�Σ��ƶ���" << count2 << "�Ρ�" << endl;

}



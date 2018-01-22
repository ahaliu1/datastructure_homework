#include "BinaryTree.h"
using namespace std;
void knap(int c, int t, int i);
void main()
{
	BinaryTree<char>a, b, x, y, z;
	y.MakeTree('E', a, b);
	z.MakeTree('F', a, b);
	x.MakeTree('C', y, z);
	y.MakeTree('D', a, b);
	z.MakeTree('B', y, x);
	y.MakeTree('m', a, b);
	x.MakeTree('j', z, y);
	y.MakeTree('m', a, b);
	z.MakeTree('p', x, y);

	cout << "���ĸ߶ȣ�"<<z.Height(z.root) << endl;
	cout << "��Ҷ������"<<z.Countleves(z.root) << endl;
	z.Swap(z.root);
	knap(29, 0, 1);
	system("pause");
}
const int n = 4;         // ��Ʒ����
int limit = 29;    // ��������
int w[n +1] = {0, 11, 8, 19, 6 };            // �����Ʒ����
int x[n + 1], y[n + 1];     // ���װ������
int total = 0;           // ������Ž����Ʒ������
int a = 0;				//���������˶��ٸ���
void knap(int c, int t, int i) {
	//�ڱ���ʣ������Ϊc����ǰ���Ž���Ʒ������Ϊt������£�
	//�����Ƿ�ѡȡ��i����Ʒ
	if (i > n){ // ��������һ����Ҷ
		if ((t > total) && (t <= limit)) { // ����һ�����ŵĽ�
			total = t;   for (int j = 1; j <= n; j++) x[j] = y[j];
		}
	}
	else {
		// ��չ������
		if (t+w[i] < limit){
			y[i] = 1;  
			knap(c - w[i], t + w[i], i + 1);
			a++;
		}
		int temp = t;
		for (int j = i+1; j < n + 2; j++){
			temp = temp + w[j];
		}
		// ��չ������
		if (temp > total){
			a++;
			y[i] = 0;  
			knap(c, t, i + 1);
		}

	cout <<"��ǰ������" <<a <<endl<<"��ǰ���Ž⣺"<<total<< endl;//��������ı��������Ž�
	}
}
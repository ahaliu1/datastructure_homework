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

	cout << "树的高度："<<z.Height(z.root) << endl;
	cout << "树叶个数："<<z.Countleves(z.root) << endl;
	z.Swap(z.root);
	knap(29, 0, 1);
	system("pause");
}
const int n = 4;         // 物品件数
int limit = 29;    // 背包容量
int w[n +1] = {0, 11, 8, 19, 6 };            // 存放物品质量
int x[n + 1], y[n + 1];     // 存放装包方案
int total = 0;           // 存放最优解的物品总质量
int a = 0;				//计算生成了多少个边
void knap(int c, int t, int i) {
	//在背包剩余容量为c、当前最优解物品总质量为t的情况下，
	//考虑是否选取第i件物品
	if (i > n){ // 遇到的是一个树叶
		if ((t > total) && (t <= limit)) { // 发现一个更优的解
			total = t;   for (int j = 1; j <= n; j++) x[j] = y[j];
		}
	}
	else {
		// 扩展左子树
		if (t+w[i] < limit){
			y[i] = 1;  
			knap(c - w[i], t + w[i], i + 1);
			a++;
		}
		int temp = t;
		for (int j = i+1; j < n + 2; j++){
			temp = temp + w[j];
		}
		// 扩展右子树
		if (temp > total){
			a++;
			y[i] = 0;  
			knap(c, t, i + 1);
		}

	cout <<"当前边数：" <<a <<endl<<"当前最优解："<<total<< endl;//输出创建的边数和最优解
	}
}
#include <iostream>
#include <fstream>
#include "ExTLGraph.h"
#include "MGraph.h"
#include <stack>
using namespace std;
void main()
{
	//有向图 图如ppt中关键路径部分所用图
	ExtLGraph<int>* digraph = new ExtLGraph<int>(9);
	int a,b, c, d, e, f, g;
	a = 9;
	b = 1; c = 2; d = 7; e = 4; f = 5; g = 6;
	digraph->DiInsert(0,1,g);
	digraph->DiInsert(0,2,e);
	digraph->DiInsert(0,3,f);
	digraph->DiInsert(1,4,b);
	digraph->DiInsert(2,4,b);
	digraph->DiInsert(3,5,c);
	digraph->DiInsert(4,6,a);
	digraph->DiInsert(4,7,d);
	digraph->DiInsert(5,7,e);
	digraph->DiInsert(6,8,c);
	digraph->DiInsert(7,8,e);

	cout << "深度优先遍历" << endl;
	digraph->DFS();
	cout << endl;

	cout << "宽度优先遍历" << endl;
	digraph->BFS();
	cout << endl;

	cout << "拓扑排序" << endl;
	int order[9];
	digraph->TopoSort(order);
	cout << endl;

	//无向图 图如ppt最小生成树部分例图
	ExtLGraph<int>* undigraph = new ExtLGraph<int>(6);
	
	b = 1; c = 2; d = 3; e = 4; f = 5; g = 6;

	undigraph->UnDiInsert(0, 1, g);
	undigraph->UnDiInsert(1, 4, d);
	undigraph->UnDiInsert(1, 2, f);
	undigraph->UnDiInsert(0, 2, b);
	undigraph->UnDiInsert(0, 3, f);
	undigraph->UnDiInsert(2, 4, g);
	undigraph->UnDiInsert(2, 3, f);
	undigraph->UnDiInsert(4, 5, g);
	undigraph->UnDiInsert(2, 5, e);
	undigraph->UnDiInsert(3, 5, c);
	int nearest[6];
	int lowcost[6];

	cout << "普林算法最小生成树" << endl;
	undigraph->Prim(0, nearest, lowcost);
	cout << endl;

	//矩阵存储的图
	MGraph<int>* mgraph = new MGraph<int>(4, a);
	b =45; c = 10; d = 15; e = 15; f = 20;
	mgraph->Insert(0, 1,c);
	mgraph->Insert(0,2,b);
	mgraph->Insert(2,3,e);
	mgraph->Insert(3,1,f);
	mgraph->Insert(1,2,d);
	int dis[4], path[4];
	mgraph->Dijkstra(0, dis, path);

	cout << "迪杰斯特拉算法最短路径" << endl;
	for (int i = 0; i < 4; i++){
		cout << dis[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 4; i++){
		cout << path[i] << " ";
	}
	cout << endl;

	cout << "关键事件(从1开始记）" << endl;
	int earliest[9];
	int latest[9];
	digraph->Earliest(earliest, order);
	digraph->Latest(latest, order, 18);
	digraph->OutputKeyEvent(earliest, latest);
	
	cout << endl;

	//实验内容（3）	
	ifstream txtfile;
	txtfile.open("Data.txt");//读取文件

	if (txtfile){
		cout << "找到文件" << endl;
	}
	else
	{
		cout << "未找到文件" << endl;
	}

	int start, end;//起点和终点
	cout << "请输入起点" << endl;
	cin >> start;
	cout << "请输入终点" << endl;
	cin >> end;

	int points, edges, point1, point2;
	//读入
	txtfile >> points >> edges;

	int w = 1;

	MGraph<int>* graphFromFile = new MGraph<int>(points,a);

	//创建图 边的权重全为1，则最短路路径就是边数最少的路径
	while (!txtfile.eof())
	{
		txtfile >> point1>>point2;
		graphFromFile->Insert(point1, point2, w);
		if (graphFromFile->Exist(point1,point2))
		cout << point1<<"到"<<point2 <<"边创建成功" <<endl;
	}
	txtfile.close();

	int *dis1=new int[points], *path1=new int[points];

	graphFromFile->Dijkstra(start, dis1, path1);
	stack<int> route;
	while (path1[end]!=-1)
	{
		route.push(end);
		end = path1[end];
	}
	route.push(start);
	cout << "从" << start << "到" << end << "换乘次数最少路线为" << endl;
	while( route.size()>0)
	{
		cout << route.top()<<",";
		route.pop();
	}

	cout << endl;

	system("pause");

}
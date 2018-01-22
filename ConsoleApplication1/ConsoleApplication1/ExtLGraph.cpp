/*#include "ExtLGraph.h"
template<class T>
void ExtLGraph<T >::DFS(int v, bool* visited)//私有递归函数
{
	cout << " " << v;
	visited[v] = true;
	for (ENode<T> *p = a[v]; p; p = p->nextArc)
		if (!visited[p->adjVex])
			DFS(p->adjVex, visited);
}

template<class T>
void ExtLGraph<T >::DFS()//共有DFS函数
{
	bool* visited = new bool[n];
	for (int i = 0; i<n; i++) visited[i] = false;
	for (i = 0; i<n; i++)
		if (!visited[i]) DFS(i, visited);
	delete[]visited;
}

template<class T>
void ExtLGraph<T >::BFS(int v, bool* visited)
{
	SeqQueue<int> q(QSize);
	cout << " " << v;
	visited[v] = true;
	q.EnQueue(v);
	while (!q.IsEmpty()){
		q.Front(v); q.DeQueue();
		for (ENode<T> *p = a[v]; p; p = p->nextArc)
			if (!visited[p->adjVex]){
				cout << " " << p->adjVex;
				visited[p->adjVex] = true;
				q.EnQueue(p->adjVex);
			}
	}
}

template<class T>
void ExtLGraph<T >::BFS()
{
	bool* visited = new bool[n];
	for (int i = 0; i<n; i++) visited[i] = false;
	for (i = 0; i<n; i++)
		if (!visited[i]) BFS(i, visited);
	delete[]visited;
}

//计算各顶点入度值
template<class T>
void ExtLGraph<T >::CalInDegree(int* InDegree)
{
	for (int i = 0; i<n; i++) InDegree[i] = 0;
	for (i = 0; i<n; i++)
		for (ENode<T>* p = a[i]; p; p = p->nextArc)
			InDegree[p->adjVex]++;
}

//拓扑排序
template<class T>
void ExtLGraph<T >::TopoSort(int* order)
{
	int* InDegree = new int[n];
	int i, j, k;
	int top = -1;                         //设置空栈
	CalInDegree(InDegree);  //计算每个顶点的入度
	//将入度为零的顶点序号串成一个链接栈
	for (i = 0; i<n; i++)
		if (!InDegree[i]){
			InDegree[i] = top;    top = i;
		}
	for (i = 0; i<n; i++) {                       //生成拓扑序列
		if (top == -1) { cout << “有回路”；return; }
		else {
			j = top; top = InDegree[top];   //出栈                         
			order[i] = j; cout << j << ‘ ’;      //输出一个顶点                                 
			for (ENode<T>* p = a[j]; p; p = p->nextArc){
				k = p->adjVex; InDegree[k]--;  //修改入度          
				if (!InDegree[k]){   //入度为零的顶点进栈
					InDegree[k] = top; top = k;
				}
			}//endfor
		}//endelse
	}//endfor
}

//普里姆算法
template<class T>
void ExtLGraph<T>::Prim(int k, int* nearest, T* lowcost){
	int i, j;
	bool* mark = new bool[n];
	ENode<T> *p;
	if (k<0 || k>n - 1) {
		cout << “OutofBounds”;  return;
	}
	for (int i = 0; i < n; i++){
		mark[i] = false;
		lowcost[i] = INFTY;  nearest[i] = -1;
	}
	mark[k] = true;  lowcost[k] = 0;  nearest[k] = k;
	for (i = 1; i < n; i++){
		for (p = a[k]; p; p = p->nextArc){
			j = p->adjVex;  //修改lowcost和nearest的值
			if ((!mark[j]) && (lowcost[j] > p->w)){
				lowcost[j] = p->w;  nearest[j] = k;
			}
		}
		T min = INFTY;    //求下一条最小权值的边
		for (j = 0; j < n; j++){
			if ((!mark[j]) && (lowcost[j] < min)){
				min = lowcost[j]; k = j;
			}
			mark[k] = true;       //将顶点k加到生成树上
		}
	}
}
*/

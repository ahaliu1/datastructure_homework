#include "LGraph.h"
#include <queue>
template <class T>
class ExtLGraph : public LGraph<T>
{
public:
	ExtLGraph(int mSize) :LGraph<T>(mSize){}             //���ø���Ĺ��캯��
	void DFS();
	void BFS();
	void CalInDegree(int* InDegree);
	void TopoSort(int* order);
	void Prim(int k, int* nearest, T* lowcost);
	void Earliest(int* earliest, int* order);
	void Latest(int* latest, int* order, int longest);
	void OutputKeyEvent(int* earliest, int* latest);
private:
	void DFS(int v, bool* visited);
	void BFS(int v, bool* visited);
	
};

template<class T>
void ExtLGraph<T >::DFS(int v, bool* visited)//˽�еݹ麯��
{
	cout << " " << v;
	visited[v] = true;
	for (ENode<T> *p = a[v]; p; p = p->nextArc)
		if (!visited[p->adjVex])
			DFS(p->adjVex, visited);
}

template<class T>
void ExtLGraph<T >::DFS()//����DFS����
{
	bool* visited = new bool[n];
	for (int i = 0; i<n; i++) visited[i] = false;
	for (int i = 0; i<n; i++)
		if (!visited[i]) DFS(i, visited);
	delete[]visited;
}

template<class T>
void ExtLGraph<T >::BFS()//����BFS����
{
	bool* visited = new bool[n];
	for (int i = 0; i<n; i++) visited[i] = false;
	for (int i = 0; i<n; i++)
		if (!visited[i]) BFS(i, visited);
	delete[]visited;
}

template<class T>
void ExtLGraph<T >::BFS(int v, bool* visited)
{
	queue<int> q;
	cout << " " << v;
	visited[v] = true;
	q.push(v);
	while (!q.empty()){
		v=q.front(); q.pop();
		for (ENode<T> *p = a[v]; p; p = p->nextArc){
			if (!visited[p->adjVex]){
				cout << " " << p->adjVex;
				visited[p->adjVex] = true;
				q.push(p->adjVex);
			}
		}
	}
}


//������������ֵ
template<class T>
void ExtLGraph<T >::CalInDegree(int* InDegree)
{
	for (int i = 0; i<n; i++) InDegree[i] = 0;
	for (int i = 0; i<n; i++)
		for (ENode<T>* p = a[i]; p; p = p->nextArc)
			InDegree[p->adjVex]++;
}

//��������
template<class T>
void ExtLGraph<T >::TopoSort(int* order)
{
	int* InDegree = new int[n];
	int i, j, k;
	int top = -1;                         //���ÿ�ջ
	CalInDegree(InDegree);  //����ÿ����������
	//�����Ϊ��Ķ�����Ŵ���һ������ջ
	for (i = 0; i<n; i++)
		if (!InDegree[i]){
			InDegree[i] = top;    top = i;
		}
	for (i = 0; i<n; i++) {                       //������������
		if (top == -1) { 
			cout << "�л�·";
			return; 
		}
		else {
			j = top; top = InDegree[top];   //��ջ                         
			order[i] = j; 
			cout << j << " ";      //���һ������                                 
			for (ENode<T>* p = a[j]; p; p = p->nextArc){
				k = p->adjVex; InDegree[k]--;  //�޸����          
				if (!InDegree[k]){   //���Ϊ��Ķ����ջ
					InDegree[k] = top; top = k;
				}
			}//endfor
		}//endelse
	}//endfor
}

//����ķ�㷨
template<class T>
void ExtLGraph<T>::Prim(int k, int* nearest, T* lowcost){
	const int INFTY = 9999;
	int i, j;
	bool* mark = new bool[n];
	ENode<T> *p;
	if (k<0 || k>n - 1) {
		cout << "OutofBounds";  return;
	}
	for (int i = 0; i < n; i++){
		mark[i] = false;
		lowcost[i] = INFTY;  nearest[i] = -1;
	}
	mark[k] = true;  lowcost[k] = 0;  nearest[k] = k;
	for (i = 1; i < n; i++){
		for (p = a[k]; p; p = p->nextArc){
			j = p->adjVex;  //�޸�lowcost��nearest��ֵ
			if ((!mark[j]) && (lowcost[j] > p->w)){
				lowcost[j] = p->w;  nearest[j] = k;
			}
		}
		T min = INFTY;    //����һ����СȨֵ�ı�
		for (j = 0; j < n; j++){
			if ((!mark[j]) && (lowcost[j] < min)){
				min = lowcost[j]; k = j;
			}
		}
			mark[k] = true;       //������k�ӵ���������
	}
	for (int i = 0; i < n; i++){
		cout << nearest[i] << " ";
	}
}

//����ÿ���¼����ܵ����緢��ʱ��
template<class T>
void ExtLGraph<T>::Earliest(int* earliest, int* order)
{
	for (int i = 0; i<n; i++)  earliest[i] = 0;
	for (int i = 0; i<n; i++){
		int k = order[i];
		for (ENode<T>* p = a[k]; p; p = p->nextArc){
			int  j = p->adjVex;
			if (earliest[j]<earliest[k] + p->w)
				earliest[j] = earliest[k] + p->w;
		}
	}
}



//����ÿ���¼��������ٷ���ʱ��
template<class T>
void ExtLGraph<T >::Latest(int* latest, int* order, int longest)
{
	for (int i = 0; i<n; i++) latest[i] = longest;
	for (int i = n - 2; i>-1; i--){
		int j = order[i];
		for (ENode<T>* p = a[j]; p; p = p->nextArc) {
			int  k = p->adjVex;
			if (latest[j]>latest[k] - p->w)
				latest[j] = latest[k] - p->w;
		}
	}
}

template<class T>
void ExtLGraph<T >::OutputKeyEvent(int* earliest, int* latest){
	for (int i = 0; i <9; i++){
		if (earliest[i] == latest[i]){
			cout << i + 1 << ",";
		}
	}
}


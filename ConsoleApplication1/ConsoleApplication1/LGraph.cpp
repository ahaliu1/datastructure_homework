/*#include "LGraph.h"
template<class T>
LGraph<T>::LGraph(int mSize)
{
	n = mSize; e = 0;
	a = new ENode<T>*[n];
	for (int i = 0; i<n; i++) a[i] = NULL;
}

template<class T>
LGraph<T>::~LGraph()
{
	ENode<T>* p, *q;
	for (int i = 0; i<n; i++){
		p = a[i]; q = p;
		while (p) {
			p = p->nextArc;
			delete q;
			q = p;
		}
	}
	delete[] a;
}

template<class T>
bool LGraph<T >::Exist(int u, int v)const
{
	if (u<0 || v<0 || u>n - 1 || v>n - 1 || u == v)
		return false;
	ENode<T>* p = a[u];
	while (p&& p->adjVex != v)
		p = p->nextArc;
	if (!p) return false;
	else return true;
}

template<class T>
ResultCode LGraph<T>::Insert(int u, int v, T& w)
{
	if (u<0 || v<0 || u>n - 1 || v>n - 1 || u == v)
		return Failure;
	if (Exist(u, v))
		return Duplicate;
	ENode<T>* p = new ENode<T>(v, w, a[]);
	a[u] = p;  //新结点插在最前面
	e++;
	return Success;
}

template<class T>
ResultCode LGraph<T>::Remove(int u, int v)
{
	if (u<0 || v<0 || u>n - 1 || v>n - 1 || u == v) return Failure;
	ENode<T>* p = a[u], *q = NULL;
	while (p&& p->adjVex != v){
		q = p; p = p->nextArc;
	}
	if (!p) 
		return NotPresent;
	if (q) 
		q->nextArc = p->nextArc;
	else a[u] = p->nextArc;
	delete p; e--;
	return Success;
}
*/
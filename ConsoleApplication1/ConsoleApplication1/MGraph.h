
template<class T>
class MGraph
{
public:
	MGraph(int mSize, const T& noedg);
	~MGraph();
	ResultCode Insert(int u, int v, T&w);
	ResultCode Remove(int u, int v);
	bool Exist(int u, int v) const;
	void Dijkstra(int v, T* d, int* path);
	int Choose(int* d, bool* s);
protected:
	T**a;
	T noEdge;
	int n, e;
private:
	
	const int INFTY = 9999;
};
template <class T>
MGraph<T>::MGraph(int mSize, const T& noedge){
	n = mSize;
	e = 0;
	noEdge = noedge;
	a = new T*[n];
	for (int i = 0; i < n; i++){
		a[i] = new T[n];
		for (int j = 0; j < n; j++){
			a[i][j] = noEdge;
		}
		a[i][i] = 0;
	}
}
template<class T>
MGraph<T>::~MGraph()
{
	for (int i = 0; i < n; i++){
		delete []a[i];
	}
	delete []a;
}

template<class T>
bool MGraph<T>::Exist(int u, int v)const{
	if (u<0 || v<0 || u>n - 1 || v>n - 1 || u == v || a[u][v] == noEdge){
		return false;
	}
	return true;
}

template<class T>
ResultCode MGraph<T>::Insert(int u, int v, T&w){
	if (u<0 || v<0 || u>n - 1 || v>n - 1 || u == v){
		return Failure;
	}
	if (a[u][v] != noEdge){
		return Duplicate;
	}
	a[u][v] = w;
	e++;
	return Success;
}
template<class T>
ResultCode MGraph<T>::Remove(int u, int v){
	if (u<0 || v<0 || u>n - 1 || v>n - 1 || u == v){
		return false;
	}
	if (a[u][v] == noEdge){
		return NotPresent;
	}
	a[u][v] == noEdge;
	e--;
	return Success;
}

//迪杰斯特拉算法
template <class T>
void MGraph<T>::Dijkstra(int v, T* d, int* path)
{
	int i, k, w;
	if (v<0 || v>n - 1) {
		cout << "OutOfBounds";  return;
	}
	bool *s = new bool[n];
	for (i = 0; i<n; i++){
		s[i] = false; d[i] = a[v][i];
		if (i != v && d[i]<INFTY) path[i] = v;
		else path[i] = -1;
	}
	s[v] = true; //d[v]=0; 
	for (i = 1; i < n; i++){
		//确定第i条最短路径的终点序号k
		k = Choose(d, s);
		if (k == -1) return;
		s[k] = true;
		//修正源点到其余各顶点的最短路径      
		for (w = 0; w < n; w++){
			if (!s[w] && d[k] + a[k][w] < d[w]){
				d[w] = d[k] + a[k][w];
				path[w] = k;
			}
		}
	}
	
}
template <class T>
int MGraph<T>::Choose(int* d, bool* s)
{
	int i, minpos; T min;
	min = INFTY;
	minpos = -1;
	for (i = 1; i < n; i++){
		if (d[i] < min &&!s[i]){
			min = d[i];
			minpos = i;
		}
	}
	return minpos;
}
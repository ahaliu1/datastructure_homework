template<class T >
struct ENode
{
	ENode()  { nextArc = NULL; }
	ENode(int vertex, T weight, ENode* next)
	{
		adjVex = vertex; w = weight; nextArc = next;
	}
	int adjVex;
	T w;
	ENode* nextArc;
};
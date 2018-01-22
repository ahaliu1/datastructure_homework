#include <iostream>
template<class T>
class BTNode
{
public:
	BTNode(){ lChild = rChild = NULL; }
	BTNode(const T& x){
		element = x; lChild = rChild = NULL;
	}
	BTNode(const T& x, BTNode<T>* l, BTNode<T>* r){
		element = x; lChild = l; rChild = r;
	}
	T element;
	BTNode<T> *lChild, *rChild;
};

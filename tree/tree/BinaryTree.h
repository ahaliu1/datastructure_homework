//��������
#include "BTNode.h"
template<class T>
class BinaryTree :public BTNode<T>
{
public:
	BinaryTree(){ root = NULL; }
	~BinaryTree(){ Clear(); }
	bool IsEmpty()const;
	void Clear();
	int Size();
	bool Root(T& x)const;
	void MakeTree(const T& e, BinaryTree<T>& left, BinaryTree<T>& right);

	void BreakTree(T& e, BinaryTree<T>& left,
		BinaryTree<T>& right);
	int Height(BTNode<T>* node);
	int Countleves(BTNode<T>* node);
	void Swap(BTNode<T>* node);
	BTNode<T>* root;
private:
	void Clear(BTNode<T>* t);
	int  Size(BTNode<T>* t);
	void PreOrder(void(*Visit)(T& x), BTNode<T>*t);
	void InOrder(void(*Visit)(T& x), BTNode<T>*t);
	void PostOrder(void(*Visit)(T& x), BTNode<T>*t);
	BTNode<T>* Copy(BTNode<T>* t);
};
//��ȡ������ֵ
template <class T>
bool BinaryTree<T>::Root(T &x)const
{
	if (root){
		x = root->element; return true;
	}
	else return false;
}

//�ж��������Ƿ�Ϊ��
template <class T>
bool BinaryTree<T>::IsEmpty()const
{
	return(!root);
}
//����
template <class T>
void BinaryTree<T>::Clear()
{
	Clear(root); root = NULL;
}

template <class T>
void BinaryTree<T>::Clear(BTNode<T>* t)
{
	if (t){
		Clear(t->lChild);
		Clear(t->rChild);
		delete t;
	}
}
//����
template <class T>
void BinaryTree<T>::MakeTree(const T& x, BinaryTree<T>& left, BinaryTree<T>& right)
{
	if (root || &left == &right) return;
	root = new BTNode<T>(x, left.root, right.root);
	left.root = right.root = NULL;
}

//���
template <class T>
void BinaryTree<T>::BreakTree(T& x,BinaryTree<T>& left,BinaryTree<T>& right)
{
	if (!root || &left == &right || left.root || right.root)
		return;
	x = root->element;
	left.root = root->lChild;
	right.root = root->rChild;
	delete root;
	root = NULL;
}
//ͳ�ƽ�����
template <class T>
int BinaryTree<T>::Size()
{
	return Size(root);
}

template <class T>
int BinaryTree<T>::Size(BTNode<T> * t)
{
	if (!t)  return 0;
	else  return Size(t->lChild) + Size(t->rChild) + 1;
}
//�������߶�
template<class T>
int BinaryTree<T>::Height(BTNode<T>* node){
	if (node->lChild == NULL&&node->rChild ==NULL){
		return 1;
	}
	int lchild = Height(node->lChild)+1;
	int rchild = Height(node->rChild)+1;
	return lchild > rchild ? lchild : rchild;
}
//������Ҷ�ڵ�ĸ���
template<class T>
int BinaryTree<T>::Countleves(BTNode<T>* node){
	if (node->lChild == NULL&&node->rChild == NULL){
		return 0;
	}
	
	int lchild = Countleves(node->lChild);
	int rchild = Countleves(node->rChild);
	int leves = lchild + rchild;
	if (lchild == 0)
	{
		leves++;
	}
	if (rchild == 0)
	{
		leves++;
	}
	return leves;
}
//����
template<class T>
void BinaryTree<T>::Swap(BTNode<T>* node){
	if (node->lChild == NULL&&node->rChild == NULL){
		return;
	}
	Swap(node->lChild);
	Swap(node->rChild);
	BTNode<T>* temp;
	temp = node->lChild;
	node->lChild = node->rChild;
	node->rChild = temp;
	return;
}
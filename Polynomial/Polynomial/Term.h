#include<iostream>
using namespace std;

class Term{
public:
	Term(int c, int e);
	Term(int c, int e, Term* nxt);
	Term* InsertAfter(int c, int e);
private:
	int coef;
	int exp;
	Term *link;
	friend ostream & operator<<(ostream &, const Term &); //����<<,�������ʽ��һ��
	friend class Polynominal;//����ʽ
};
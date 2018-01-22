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
	friend ostream & operator<<(ostream &, const Term &); //重载<<,输出多项式的一项
	friend class Polynominal;//多项式
};
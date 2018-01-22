#include<iostream>
#include"Polynomial.h"


Polynominal::Polynominal()
{
	theList = new Term(0, -1);//分配头结点的存储单元
	theList->link = theList;//构成循环链表
}
Polynominal::~Polynominal()
{
	Term* p = theList->link;
	while (p != theList){
		theList->link = p->link;
		delete p;
		p = theList->link;
	}
	delete theList;
}
void Polynominal::AddTerms(istream & in)
{
	Term*q = theList;
	int c[20], e[20];
	for (int i = 0; i < 19; i++){
		c[i] = 0;
		e[i] = 0;
	}
	for (int i = 0; i < 19; i++){
			cout << "Input a term(coef,exp):\n" << endl;
			cin >> c[i] >> e[i];
			if (e[i] < 0)break;
	}
	for (int i = 0; i <19; i++){
		for (int j = 0; j <18-i; j++){
			int etemp = 0, ctemp = 0;
			if (e[j] < e[j+1]){
				etemp = e[j+1];
				e[j+1] = e[j];
				e[j] = etemp;
				ctemp = c[j+1];
				c[j+1] = c[j];
				c[j] = ctemp;
			}
		}
	}
	for (int i = 0; i < 19; i++){
		if (e[i] < 0)break;
		int a = c[i], b = e[i];
		q = q->InsertAfter(a,b);
	}
}

void Polynominal::OutPut(ostream& out)const
{
	int first = 1;
	Term *p = theList->link;
	cout << "The polynominal is:\n" << endl;
	for (; p != theList; p = p->link){
		if (!first && (p->coef > 0)) out << "+";
		first = 0;
		out << *p;
	}
	cout << "\n" << endl;
}
void Polynominal::PolyAdd(Polynominal& r)
{
	Term* q, *q1 = theList, *p;
	p = r.theList->link; //p指向r第一个要处理的节点
	q = q1->link;//q指向this多项式第一个要处理的节点
	while (p->exp>=0){
		while (p->exp < q->exp){
			q1 = q;
			q = q->link;
		}
		if (p->exp == q->exp){
			q->coef = q->coef + p->coef;
			if (q->coef==0){
				q1->link = q->link;
				delete(q);
				q = q1->link;
			}
			else{
				q1 = q; 
				q = q->link;
			}
		}
		else{
			q1 = q1->InsertAfter(p->coef, p->exp);
		}
			p = p->link;
		
	}
}
void Polynominal::Deribation(){
	Term*p; 
	p = this->theList->link;
	for (;;){
		p->coef = p->coef*p->exp;
		p->exp -= 1;
		p = p->link;
		if (p->exp < 0) break;
	}
}

ostream& operator <<(ostream &out, const Polynominal &x)
{
	x.OutPut(out);
	return out;
}
istream& operator >>(istream& in, Polynominal &x)
{
	x.AddTerms(in);
	return in;
}
Polynominal& operator +(Polynominal &a, Polynominal &b)
{
	a.PolyAdd(b);
	return a;
}

#include<iostream>
#include"Term.h"
using namespace std;

class Polynominal
{
public:
	Polynominal();
	~Polynominal();
	void AddTerms(istream& in);
	void OutPut(ostream& out)const;
	void PolyAdd(Polynominal& r);
	void Deribation();
private:
	Term* theList;//±ÌÕ∑÷∏’Î
	friend ostream & operator <<(ostream &, const Polynominal &);
	friend istream& operator >>(istream&, Polynominal &);
	friend Polynominal& operator +(Polynominal &, Polynominal &);
};
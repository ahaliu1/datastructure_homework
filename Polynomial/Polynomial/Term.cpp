#include"Term.h"
Term::Term(int c, int e) :coef(c), exp(e)//ָ�� ϵ�� һ�ָ�ֵд��
{
	link = 0;
}
Term::Term(int c, int e, Term *nxt) : coef(c), exp(e)
{
	link = nxt;
}
Term* Term::InsertAfter(int c, int e)
{
	link = new Term(c, e, link);//c,e this->link ��ֵ�����½ڵ����Ӧ��
	return link;
}
ostream &operator <<(ostream & out, const Term& val)
{
	if (val.coef == 0) return out;
	out << val.coef;
	switch (val.exp){
		case 0:break;
		case 1:out << "X"; break;
		default:out << "X^" << val.exp; break;
	}
	return out;
}


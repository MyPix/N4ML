#include <iostream>
#include <deque>
#include "Lexer.h"
#include "Token.h"
int main(char *argv[], int argc)
{
	Lexer lex;
	deque<Token>* dq = lex.returnTkDqPtr();
	lex.eatChar("-->DQ @",0);
	lex.identifity();
	cout << "dqsize " << dq->size() << endl;
	for (int x(0); x < dq->size(); x++)
	{
		cout << " = " << (*dq)[x].getContent() << " = "  << (*dq)[x].getLiteralCategory()<< endl;
	}
	lex.clearDq();
	if (lex.readFromFile("C:\\Users\\Pierre v\\Documents\\Visual Studio 2013\\Projects\\N4ML\\N4ML\\Foo.txt", nBUFFER_XS))
	{
		lex.identifity();
		cout << "dqsize " << dq->size() << endl;
		for (int x(0); x < dq->size(); x++)
		{
			cout << " = " << (*dq)[x].getContent() << " = " << (*dq)[x].getLiteralCategory() << endl;
		}
	}
	else
	{
		cout << "Unable to open file";
	}
	cin.get();
}
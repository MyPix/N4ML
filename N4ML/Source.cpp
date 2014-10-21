#include <iostream>
#include <deque>
#include <windows.h>
#include <sstream>
#include "Lexer.h"
#include "Token.h"
#include "TreeParser.h"
int main(char *argv[], int argc)
{
	Lexer lex;
	deque<Token>* dq = lex.returnTkDqPtr();
	if (argc == 1)
	{
		if (lex.readFromFile(argv[0],nBUFFER_M))
		{
			try{
				lex.identifity();
			}
			catch (exception e)
			{
				cout << e.what();
			}
			cout << "Taille de la Deque : " << dq->size() << endl;
			for (int x(0); x < dq->size(); x++)
			{
				cout << " JETON > '" << (*dq)[x].getContent() << "' > TYPE > '" << (*dq)[x].getLiteralCategory() << "';" << endl;
			}
		}
		else
		{
			cout << "Impossible d'ouvrir le fichier :c";
		}
	}
	else
	{
		if (lex.readFromFile("Foo.txt", 24250))
		{
			lex.identifity();
			cout << "Taille de la Deque : " << dq->size() << endl;
			for (int x(0); x < dq->size(); x++)
			{
				cout << " JETON > '" << (*dq)[x].getContent() << "' > TYPE > '" << (*dq)[x].getLiteralCategory() << "';" << endl;
			}
			TreeParser p(dq);
		}
		else
		{
			cout << "Impossible d'ouvrir le fichier :c";
		}
	}
	cin.get();
}
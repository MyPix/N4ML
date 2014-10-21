#include "TreeParser.h"
#include <algorithm>

TreeParser::TreeParser(deque<Token> *toks)
{
	_toks = toks;
}
TreeParser::~TreeParser()
{
	delete _toks;
	_toks = 0;
}
bool TreeParser::checkForTree()
{
	if (((*_toks)[0].getCategory() == nToken::lowthan) && ((*_toks)[1].getCategory() == nToken::word) && ((*_toks)[2].getCategory() == nToken::grethan))
	{
		string data = (*_toks)[1].getContent();
		transform(data.begin(), data.end(), data.begin(), ::tolower);
		cout << endl << "DATA : " << data << endl;
		if (data == "tree")
			return 1;
		else
			return 0;
	}
	else
	{
		return 0;
	}
}
void TreeParser::parseTree(bool doIt)
{

}

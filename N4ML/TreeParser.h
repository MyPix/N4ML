#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <type_traits>
#include "Token.h"
using namespace std;
class TreeParser
{
public:
	TreeParser(deque<Token> *toks);
	~TreeParser();
	bool checkForTree();
	void parseTree(bool doIt); // Usually, to use this, Make parseTree(checkForTree()); So it's easier to use, not a lot of IFs ;) 
private:
	deque<Token> *_toks = 0;
};


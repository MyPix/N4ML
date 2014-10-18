#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <stack>
#include <ostream>
#include "Globals.h"
using namespace std;
using namespace nCodes;
class Token
{
public:
	Token();
	Token(string fragment);
	Token(string fragment,nToken::tTypes cat);

	void setCategory(nToken::tTypes cat);
	void setContent(string fragment);

	nToken::tTypes getCategory();
	string getContent();
	string getLiteralCategory();

//	friend std::ostream& operator<< (std::ostream& stream, const Token& tok) {
	//	cout << tok.getContent() << "[" << tok.getCategory() << "]";
	//	return stream;
	//}

	~Token();
private:
	string m_tcontent = ""; // Content
	nToken::tTypes m_tcat = nToken::tTypes::undefined; // Category
};


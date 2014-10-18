#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <fstream>>
#include <type_traits>
#include "Globals.h"
#include "Token.h"
// Help tools
#define nBUFFER_XXL 16384
#define nBUFFER_XL 8192
#define nBUFFER_L 4096
#define nBUFFER_M 2048
#define nBUFFER_S 1024
#define nBUFFER_XS 512
#define nBUFFER_XXS 256
using namespace std;
using namespace nCodes;
class Lexer
{
public:
	Lexer();
	~Lexer();
	deque<Token>* Tokenize(string const& str);
	bool eatChar(string const& str, int  const& pos);
	void identifity();
	deque<Token>* returnTkDqPtr();
	bool readFromFile(string const& filepath, unsigned int const& buffsize);
	void clearDq();
private:
	bool isAlphanum(char const& c);
	bool isalph(string const& s);
	void flushToken();
	void flushToken(nToken::tTypes const& type);

	nToken::tTypes idTok(string tok);

	Token makeToken(string const& fragment, nToken::tTypes const& category);

	bool isWord(string const& str);

	cTypes nGettype(char const& c);

	//string seperators = " ,;:!?&@_-()[]{}~#";
	//string alphaNum = "azertyuiopqsdfghjklmwxcvbnAZERTYUIOPQSDFGHJKLMWXCVBN1234567890"; // Alternative

	string curtok;
	deque<Token> *toks = new deque<Token>;

	bool isInStr;
};

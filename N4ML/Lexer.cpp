#include "Lexer.h"
#include <Windows.h>
int tour;
bool is_digit(string s)
{
	for (int x(0); x < s.length();x++)
	{
		if (isdigit(s[x]))
			continue;
		else
			return 0;
	}
	return 1;
}
bool Lexer::isAlphanum(char const& c)
{
	if (isalpha(c) || isdigit(c))
		return 0;
	return 1;
}
bool Lexer::isalph(string const& s)
{
	for (int x(0); x < s.length(); x++)
	{
		if (isalpha(s[x]))
			continue;
		else
			return 0;
	}
	return 1;
}

Lexer::Lexer()
{
}
Lexer::~Lexer()
{
}
deque<Token>* Lexer::Tokenize(string const& str)
{
	eatChar(str, 0);
	return toks;
}
deque<Token>* Lexer::returnTkDqPtr()
{
	return toks;
}
Token Lexer::makeToken(string const& fragment, nToken::tTypes const& category)
{ 
	Token rtr(fragment, category);
	return rtr; 
}
void Lexer::flushToken()
{
	Token push(curtok, nToken::tTypes::undefined);
	if (NAML_DEBUG_MSG)
		cout << "pushed " << push.getContent() << endl;
	toks->push_back(push);
	curtok = "";
}
void Lexer::flushToken(nToken::tTypes const& type)
{
	Token push(curtok,type);
	if (NAML_DEBUG_MSG)
		cout << "pushed " << push.getContent() << endl;
	toks->push_back(push);
	curtok = "";
}
bool Lexer:: eatChar(string const& str, int const& pos)
{
	if (NAML_DEBUG_MSG)
	{
		tour++;
		cout << "@" << tour << endl;
	}
	int npos = (pos + 1);
	char _now = str[pos];
	if (pos == str.length())
	{
		if (curtok != "")
			flushToken();
		return 1;
	}
	switch (nGettype(_now))
	{
			//
			case cTypes::quote:
			case cTypes::apos:
				try{
					
					if ((pos - 1) >= 0)
					{
						if (str[pos - 1] == '\\')
						{
							curtok.pop_back();
							curtok += _now;
							return eatChar(str, npos);
						}
					}
					
				}
				catch (exception e)
				{
					//Nothing
				}
				if (isInStr)
					{
						curtok += '"';
						isInStr = false;
						flushToken(nToken::tTypes::nstring);
					}
				else
					{
						curtok += '"';
						isInStr = true;
						return eatChar(str, npos);
					}
				break;
			//
			case cTypes::alpha:
				if (curtok == "")
				{
					curtok += _now;
					return eatChar(str, npos);
				}
				else
				{
					if (isWord(curtok))
					{
						curtok += _now;
						return eatChar(str, npos);
					}
					else if (isInStr)
					{
						curtok += _now;
						return eatChar(str, npos);
					}
					else
					{
						flushToken();
						return eatChar(str, pos);
					}
				}
				break;
			case cTypes::num:
				curtok += _now;
				return eatChar(str, npos);
				break;
			case cTypes::op_bracket:
			case cTypes::cls_bracket:
			case cTypes::op_par:
			case cTypes::cls_par:
			case cTypes::op_cbrack:
			case cTypes::cls_cbrack:
			case cTypes::semicolon:
			case cTypes::underscore:
			case cTypes::dollarsign:
			case cTypes::andsign:
			case cTypes::asterisk:
			case cTypes::div:
			case cTypes::idiv:
			case cTypes::tiret:
			case cTypes::plus:
			case cTypes::equal:
			case cTypes::exp:
			case cTypes::dash:
			case cTypes::tilde:
			case cTypes::imp:
			case cTypes::interr:
			case cTypes::virg:
			case cTypes::dpoint:
			case cTypes::point:
			case cTypes::modulo:
			case cTypes::lowthan:
			case cTypes::grethan:
			case cTypes::arobase:
				if (curtok != "")
				{
					if (isInStr)
					{
						curtok += _now;
						return eatChar(str, npos);
					}
					else
					{
						flushToken();
						return eatChar(str, pos);
					}
				}
				else
				{
					curtok += _now;
					flushToken();
					return eatChar(str,npos);
				}
				break;
			case cTypes::space:
				if (curtok != "")
				{
					if (isInStr)
					{
						curtok += ' ';
						return eatChar(str, npos);
					}
					else
					{
						flushToken();
						return eatChar(str, npos);
					}
				}
				else
				{
					try{
						if (isspace(str[npos]))
							return eatChar(str, npos + 1);
						else
							return eatChar(str, npos);
					}
					catch (const std::out_of_range& oor)
					{
						return 1;
					}
				}
			case cTypes::unknown:
				cout << "Unknown token " << _now << " , skipping" << endl;
				return eatChar(str,npos);
				break;
			default:
				cout << "Unknown token " << _now << " , skipping" << endl;
				return eatChar(str,npos);
				break;
	}
	return 1;
}
bool Lexer::isWord(string const& str)
{
	for (int j(0); j < str.length(); j++)
	{
		if (isalpha(str[j]))
			continue;
		else
			return 0;
	}
	return 1;
}
cTypes Lexer::nGettype(char const& c)
{

		if (isalpha(c))
			return cTypes::alpha;
		else if (isdigit(c))
			return cTypes::num;
		else if (isspace(c))
			return cTypes::space;
	switch (c)
	{
			case '[':
				return cTypes::op_bracket;
				break;
			case ']':
				return cTypes::cls_bracket;
				break;
				///////////////////////
			case '(':
				return cTypes::op_par;
				break;
			case ')':
				return cTypes::cls_par;
				break;
				///////////////////////
			case '{':
				return cTypes::op_cbrack;
				break;
			case '}':
				return cTypes::cls_cbrack;
				break;
				///////////////////////
			case '>':
				return cTypes::grethan;
				break;
			case '<':
				return cTypes::lowthan;
				break;
				///////////////////////
			case '-':
				return cTypes::tiret; // Also considered as minus
				break;
			case '_':
				return cTypes::underscore;
				break;
			case '~':
				return cTypes::tilde;
				break;
				///////////////////////
			case '.':
				return cTypes::point;
				break;
			case ':':
				return cTypes::dpoint;
				break;
			case ',':
				return cTypes::virg;
				break;
			case ';':
				return cTypes::semicolon;
				break;
			case '!':
				return cTypes::imp;
				break;
			case '?':
				return cTypes::interr;
				break;
			case '#':
				return cTypes::dash;
				break;
			case '$':
				return cTypes::dollarsign;
				break;
			case '&':
				return cTypes::andsign;
				break;
				///////////////////////
			case '/':
				return cTypes::div;
				break;
			case '+':
				return cTypes::plus;
				break;
			case '^':
				return cTypes::exp;
				break;
			case '=':
				return cTypes::equal;
				break;
			case '*':
				return cTypes::asterisk;
				break;
			case '%':
				return cTypes::modulo;
				break;
			case '\\':
				return cTypes::idiv;
				break;
			case '"':
				return cTypes::quote;
				break;
			case ' ':
				return cTypes::space;
				break;
			case '\'':
				return cTypes::apos;
				break;
			case '@':
				return cTypes::arobase;
				break;
				///////////////////////idk
			default:
				return cTypes::unknown;
				break;
	}
}

nToken::tTypes Lexer::idTok(string tok)
{
	return nToken::tTypes::undefined;
}
void Lexer::identifity()
{
	for (int x(0); x < toks->size(); x++)
	{
		if ((*toks)[x].getCategory() == nToken::undefined)
		{
			string alias = (*toks)[x].getContent();
			if (isalph(alias))
			{
				(*toks)[x].setCategory(nToken::word);
				continue;
			}
			else if (is_digit(alias))
			{
				(*toks)[x].setCategory(nToken::number);
				continue;
			}
			else if ((alias[0] == '"') && (alias[alias.length()] == '"'))
			{
				(*toks)[x].setCategory(nToken::nstring);
				continue;
			}
			else if (alias == "-")
			{
				(*toks)[x].setCategory(nToken::tiret);
				continue;
			}
			else if (alias == "+")
			{
				(*toks)[x].setCategory(nToken::plus);
				continue;
			}
			else if (alias == "*")
			{
				(*toks)[x].setCategory(nToken::asterisk);
				continue;
			}
			else if (alias == "/")
			{
				(*toks)[x].setCategory(nToken::div);
				continue;
			}
			else if (alias == "\\")
			{
				(*toks)[x].setCategory(nToken::idiv);
				continue;
			}
			else if (alias == "^")
			{
				(*toks)[x].setCategory(nToken::exp);
				continue;
			}
			else if (alias == ">")
			{
				(*toks)[x].setCategory(nToken::grethan);
				continue;
			}
			else if (alias == "<")
			{
				(*toks)[x].setCategory(nToken::lowthan);
				continue;
			}
			else if (alias == "=")
			{
				(*toks)[x].setCategory(nToken::equal);
				continue;
			}
			else if (alias == "#")
			{
				(*toks)[x].setCategory(nToken::dash);
				continue;
			}
			else if (alias == "~")
			{
				(*toks)[x].setCategory(nToken::tilde);
				continue;
			}
			else if (alias == "$")
			{
				(*toks)[x].setCategory(nToken::dollarsign);
				continue;
			}
			else if (alias == "&")
			{
				(*toks)[x].setCategory(nToken::andsign);
				continue;
			}
			else if (alias == "_")
			{
				(*toks)[x].setCategory(nToken::underscore);
				continue;
			}
			else if (alias == "!")
			{
				(*toks)[x].setCategory(nToken::imp);
				continue;
			}
			else if (alias == "?")
			{
				(*toks)[x].setCategory(nToken::interr);
				continue;
			}
			else if (alias == ".")
			{
				(*toks)[x].setCategory(nToken::point);
				continue;
			}
			else if (alias == ";")
			{
				(*toks)[x].setCategory(nToken::semicolon);
				continue;
			}
			else if (alias == ",")
			{
				(*toks)[x].setCategory(nToken::virg);
				continue;
			}
			else if (alias == ":")
			{
				(*toks)[x].setCategory(nToken::dpoint);
				continue;
			}
			else if (alias == "%")
			{
				(*toks)[x].setCategory(nToken::modulo);
				continue;
			}
			else if (alias == "}")
			{
				(*toks)[x].setCategory(nToken::cls_cbrack);
				continue;
			}
			else if (alias == "{")
			{
				(*toks)[x].setCategory(nToken::op_cbrack);
				continue;
			}
			else if (alias == "[")
			{
				(*toks)[x].setCategory(nToken::op_bracket);
				continue;
			}
			else if (alias == "]")
			{
				(*toks)[x].setCategory(nToken::cls_bracket);
				continue;
			}
			else if (alias == "(")
			{
				(*toks)[x].setCategory(nToken::op_par);
				continue;
			}
			else if (alias == ")")
			{
				(*toks)[x].setCategory(nToken::cls_par);
				continue;
			}
			else if (alias == "@")
			{
				(*toks)[x].setCategory(nToken::arobase);
				continue;
			}

		}
		else
		{
			// Nothing to do !
		}
	}
	if (((*toks)[0].getCategory() == nToken::tilde) && ((*toks)[1].getCategory() != nToken::word))
	{
		string x = (*toks)[1].getContent();
		if (x[0] == '"')
			x = (*toks)[1].getContent().substr(1, (x.length() - 1));
		if (x[x.length()] == '"')
			x = (*toks)[1].getContent().substr(0, (x.length() - 1));
		size_t kz = x.find('V');
		size_t mz = x.find('v');
		string substr;
		if (x.substr(0,4) == "NAML")
		{

			if (kz != string::npos)
			{
				substr = x.substr(kz, (x.length() - kz -1));
				cout << "Current document is validated ! Recognized NAML Version is: " << substr << endl;
				toks->pop_front(); // ~
				toks->pop_front(); // "NAML V**"
			}
			else if (mz != string::npos)
			{
				substr = x.substr(mz, (x.length() - mz -1));
				cout << "Current document is validated ! Recognized NAML Version is: " << substr << endl;
				toks->pop_front(); // ~
				toks->pop_front(); // "NAML v**"
			}
			else
			{
				cout << "Current document is validated ! No NAML Version recognized :/" << endl;
			}
		}
		else
		{
			cout << x.substr(0, 4) << endl;
			cout << "A NAML DOCUMENT MUST BEGIN WITH ~\"NAML V(version)\"!!";
			Sleep(2000);
			exit(-1);
		}
			
	}
	else
	{
		cout << "---" << endl;
		cout << (*toks)[0].getLiteralCategory() << endl;
		cout << (*toks)[1].getLiteralCategory() << endl;
		cout << "A NAML DOCUMENT MUST BEGIN WITH ~\"NAML V(version)\"!!";
		Sleep(2000);
		exit(-1);
	}
}
bool Lexer::readFromFile(string const& filepath,unsigned int const& buffsize) 
{
	ifstream stream;
	char *buffer = new char[buffsize];
	stream.rdbuf()->pubsetbuf(buffer, buffsize);
	stream.open(filepath);
	
	if(stream)
	{

		string code, temp;
		while (getline(stream,temp))
		{
			eatChar(temp, 0);
		}
		return 1;

	}
	else
	{
		return 0;
	}
}
void Lexer::clearDq()
{
	delete toks;
	toks = new deque<Token>;
}
/*

*/
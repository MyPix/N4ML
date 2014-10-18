#include "Token.h"

////
//CONSTRUCTORS & DESTRUCTORS
////
Token::Token()
{
}
Token::~Token()
{
}
Token::Token(string fragment)
{
	m_tcontent = fragment;
}
Token::Token(string fragment, nToken::tTypes cat)
{
	m_tcontent = fragment;
	m_tcat = cat;
}
////
//MUTATORS
////
void Token::setCategory(nToken::tTypes cat)
{
	m_tcat = cat;
}
void Token::setContent(string fragment)
{
	m_tcontent = fragment;
}
////
//ACCESSORS
////
nToken::tTypes

Token::getCategory()
{
	return m_tcat;
}
string Token::getContent()
{
	return m_tcontent;
}
/////
// SPECIFIC
////
string Token::getLiteralCategory()
{
	switch (m_tcat)
	{
		case nToken::word:
			return "WORD";
			break;
		case nToken::number:
			return "CONSTANT";
			break;
		case nToken::arobase:
			return "AROBASE";
			break;
		case nToken::op_bracket:
			return "BRACKET OPEN";
			break;
		case nToken::cls_bracket:
			return "BRACKET CLOSE";
			break;
		case nToken::op_cbrack:
			return "CURLY BRACKET OPEN";
			break;
		case nToken::cls_cbrack:
			return "CURLY BRACKET CLOSE";
			break;
		case nToken::op_par:
			return "PARENTHESIS OPEN";
			break;
		case nToken::cls_par:
			return "PARENTHESIS CLOSE";
			break;
		case nToken::tiret:
			return "MINUS";
			break;
		case nToken::lowthan:
			return "LOWER THAN";
			break;
		case nToken::grethan:
			return "GREATER THAN";
			break;
		case nToken::semicolon:
			return "SEMICOLON";
			break;
		case nToken::underscore:
			return "UNDERSCORE";
			break;
		case nToken::dollarsign:
			return "DOLLARSIGN";
			break;
		case nToken::andsign:
			return "AND SIGN";
			break;
		case nToken::asterisk:
			return "ASTERISK";
			break;
		case nToken::div:
			return "DIVISION";
			break;
		case nToken::idiv:
			return "INVERTED DIVISION SIGN";
			break;
		case nToken::plus:
			return "PLUS";
			break;
		case nToken::equal:
			return "EQUAL";
			break;
		case nToken::exp:
			return "EXPONENT";
			break;
		case nToken::dash:
			return "DASH";
			break;
		case nToken::tilde:
			return "TILDE";
			break;
		case nToken::imp:
			return "EXCLAMATION MARK";
			break;
		case nToken::interr:
			return "INTERROGATION MARK";
			break;
		case nToken::virg:
			return "COMMA";
			break;
		case nToken::dpoint:
			return "DOUBLE POINT";
			break;
		case nToken::point:
			return "POINT";
			break;
		case nToken::modulo:
			return "MODULO/PERCENT";
			break;
		case nToken::nstring:
			return "STRING";
			break;
		case nToken::arrow:
			return "ARROW";
			break;
		default:
			return "UNKNOWN";
			break;
	}
	return "null";
}
////    ////
//  END   //
////   ////
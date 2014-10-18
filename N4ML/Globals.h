/* IF YOUR CLASS IS NOT A N4ML CLASS JUST DONT USE THIS (srlsy) */
#pragma once
#include <exception>
#include <map>
#define NAML_DEBUG_MSG 1
namespace nCodes // N4ML CODES
{
	enum cTypes // Characters types
	{
		alpha, num, //a-Z or 0-9
		op_bracket, cls_bracket, // []
		op_par, cls_par, // ()
		op_cbrack, cls_cbrack, // {}
		semicolon //;
		, underscore//_
		, dollarsign // $
		, andsign // &
		, asterisk // *
		, div // /
		, idiv // \,
		, tiret // -
		, plus // +
		, equal // =
		, exp // ^ 
		, dash // #
		, tilde // ~
		, imp // !
		, interr // ?
		, virg // ,
		, dpoint // :
		, point // .
		, modulo // % 
		, lowthan // < 
		, grethan // >
		, quote // "
		, space // a space
		, apos // '
		, arobase
		, unknown // Whoops !
	};
	typedef cTypes cTypes;
}
namespace nToken
{
	enum tTypes // Token types
	{
		word, number,
		op_bracket, cls_bracket, // []
		op_par, cls_par, // ()
		op_cbrack, cls_cbrack, // {}
		semicolon //;
		, underscore//_
		, dollarsign // $
		, andsign // &
		, asterisk // *
		, div // /
		, idiv // \,
		, tiret // -
		, plus // +
		, equal // =
		, exp // ^ 
		, dash // #
		, tilde // ~
		, imp // !
		, interr // ?
		, virg // ,
		, dpoint // :
		, point // .
		, modulo // % 
		, lowthan // < 
		, grethan, // >
		 arobase
		,arrow,nstring,
		undefined // Whoops !
	};
	typedef tTypes tTypes;
}
using namespace std;
class NAML_ERR : public std::exception
{
public:
	NAML_ERR(std::string what, int line, int carpos, char car) // Character error
	{
		err += "Something bad happened :(. [ERROR] ";
		err += what;
		err += " [AT (";
		err += line;
		err += ",";
		err += carpos;
		err += ") token '";
		err += car;
		err += "'";
		
	}
	NAML_ERR(std::string what, int line, int carpos) // Other type of char error (missing char,..)
	{
		err += "Something bad happened :(. [ERROR] ";
		err += what;
		err += " [AT (";
		err += line;
		err += ",";
		err += carpos;
		err += ")";
	}
	NAML_ERR(std::string what, int line) // Error in line (syntax,grammar)
	{
		err += "Something bad happened :(. [ERROR] ";
		err += what;
		err += " [AT LINE";
		err += line;
		err += ']';
	} 
	NAML_ERR(std::string what, char car) // Global sheit
	{
		err += "Something bad happened :(. [ERROR] ";
		err += what;
		err += " [character concerned is ";
		err += car;
		err += "]";
	}
	NAML_ERR(std::string what) // Global sheit
	{
		err += "Something bad happened :(. [ERROR] ";
		err += what;
	}
	virtual char const * what() const {
		return err.c_str();
	}
private:
	std::string err;
};
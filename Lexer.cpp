#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include "lexer.h"
#include "evalex.h"

using namespace std;

Lexer::Lexer(string strFileName)
{
	fileScanner.open(strFileName, fstream::in);
	table.push_back(Token(PROGRAM, "program"));
	table.push_back(Token(ENDPROGRAM, "endprogram"));
	table.push_back(Token(DEF, "def"));
	table.push_back(Token(ENDDEF, "enddef"));
	table.push_back(Token(IF, "if"));
	table.push_back(Token(ELSE, "else"));
	table.push_back(Token(ENDIF, "endif"));
	table.push_back(Token(VARIABLE, "variable"));
	table.push_back(Token(CONSTANT, "constante"));
	table.push_back(Token(EQUALS, "=="));
	table.push_back(Token(LPAREN, "("));
	table.push_back(Token(RPAREN, ")"));
	table.push_back(Token(INT, "int"));
	table.push_back(Token(READ, "read"));
	table.push_back(Token(PRINT, "print"));
	table.push_back(Token(CALL, "call"));
	table.push_back(Token(RETURN, "return"));
  table.push_back(Token(THEN, "then"));
	table.push_back(Token(TEOF, "TEOF"));
  table.push_back(Token(ADICION, "+"));
  table.push_back(Token(SUSTRACCION, "-"));
  table.push_back(Token(DIVISION, "/"));
  table.push_back(Token(MULTIPLICATION, "*"));
  table.push_back(Token(OR, "||"));
  table.push_back(Token(AND, "&&"));
  table.push_back(Token(NELPASTEL, "~"));
  table.push_back(Token(DIFFERENT, "!="));
  table.push_back(Token(EQUALS, "=="));
}

Lexer::~Lexer()
{
	table.clear();
	lineScanner.clear();
}

string Lexer::nextText()
{ 
	string text;
	string temp;
	do {
		text = "";
		
		if(lineScanner.length() == 0)
		{
			if(!fileScanner.eof())
			{
				getline(fileScanner,lineScanner, '\n');
			}
			else {
				text = "TEOF";
			}
		}
		else
		{
			if(lineScanner.find(" ") != string::npos)
			{
				text = lineScanner.substr(0, lineScanner.find(" "));
				lineScanner = lineScanner.substr(lineScanner.find(" ")+1, lineScanner.length()-1);
			}
			else
			{
				text = lineScanner.substr(0,lineScanner.length()-1);
				lineScanner.clear();
			}
		}
	} while (text.length() == 0);
	return text;
}

Token* Lexer::nextToken()
{
	string text = nextText();
	for(auto t: table)
	{
		string comparar = t.getToken();

		if(comparar.compare(text) == 0) {
			return new Token(t.getCode(), "");
		}
	}
	
	if(validVariableName(text)) return new Token(VARIABLE, text);
	if(validIntConstant(text)) return new Token(CONSTANT, text);
  
	return new Token(INVALIDTOKEN, text);
}

bool isLetter(char c) {
   return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int isdigit(int a){
  switch(a){
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      return true;
    default:
      return false;
  }
}

bool isSigno(char s){
  return((s == '/')||(s=='*')||(s=='+')||(s=='-'));
}
//Analiza si es un signo condicional
bool isCondicion(string r){
  return((r=="&&")||(r=="||")||(r=="~")||(r=="!=")||(r=="=="));
}

bool Lexer::validVariableName(string text)
{
	if (!isLetter(text.at(0))||(!isSigno(text.at(0))))
		return false;
	for(int i = 1; i < text.length(); i++) {
		if(!isLetter(text.at(i)) && !isdigit(text.at(i))) return false;
    if(!isSigno(text.at(i)) && !isdigit(text.at(i))) return false;
	return true;
  }
}

bool Lexer::validIntConstant(string text)
{
	for(int i = 0; i < text.length(); i++) {
		if(!isdigit(text.at(i))) return false;
	}
	return true;
}


string Lexer::getTokenText(int code)
{
	for(auto t: table) {
		if(t.getCode() == code) return t.getToken();
	}
	return "";
}

#ifndef lexer_h
#define lexer_h

#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Lexer
{
	private:
	    vector<Token> table;
    
		fstream fileScanner;
		string lineScanner;
		bool validVariableName(string text);
		bool validIntConstant(string text);
		
	public:
		Lexer(string strFileName);
		virtual ~Lexer();
		string nextText();
		Token* nextToken();
		string getTokenText(int code);
//    bool validVariableName(string text);
//    bool validIntConstant(string text);
    };

const int PROGRAM = 1;
const int ENDPROGRAM = 2;
const int DEF = 3;
const int ENDDEF = 4;
const int IF = 5;
const int ELSE = 6;
const int ENDIF = 7;
const int VARIABLE = 8;
const int CONSTANT = 9;
const int EQUALS = 10;
const int WHILE = 11;
const int ENDWHILE = 12;
const int ASSIGN = 13;
const int LPAREN = 14;
const int RPAREN = 15;
const int INT = 16;
const int READ = 17;
const int PRINT = 18;
const int CALL = 19;
const int RETURN = 20;
const int THEN = 21;
const int ADICION = 22;
const int SUSTRACCION = 23;
const int MULTIPLICATION = 24;
const int DIVISION = 25;
const int OR = 26;
const int AND = 27;
const int NELPASTEL = 28;
const int DIFFERENT = 29;
const int EXPRESSION = 30;
const int INVALIDTOKEN = 98;
const int TEOF = 99;

#endif

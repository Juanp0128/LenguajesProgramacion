#include <string>
#include "parser.h"
#include "lexer.h"
#include "token.h"
#include <list>


using namespace std;

Parser::~Parser()
{
	delete token;
	delete lexer;
#ifdef debug
	cout << "DEBUG: Parser destroyed" << "\n";
#endif
}

void Parser::recognize(int expected)
{
	if (token->getCode() == expected)
	{
		token = lexer->nextToken();
	}
	else
	{
		cout << "Syntax Error. " 
		     << "Expected: " << lexer->getTokenText(expected) 
			 << " found: " << lexer->getTokenText(token->getCode())
			 << " " << token->getToken()
			 << endl;
		exit(2);
	}
}
string Parser::recognizeVariable()
{
	string text;
	if (token->getCode() == VARIABLE) {
		text = token->getToken();
		token = lexer->nextToken();
	}
	else {
		cout << "Syntax Error. "
			 << "Expected: variable found: "
			 << token->getToken() << endl;
		text = "";
		exit(2);
	}
	return text;
}

void Parser::recognizeConstante()
{
	string text;
	if (token->getCode() == CONSTANT) {
		text = token->getToken();
		token = lexer->nextToken();
	}
	else {
		cout << "Syntax Error. "
			 << "Expected: constante found: "
			 << token->getToken() << endl;
		text = "";
		exit(2);
	}
}

void Parser::asignar(){
  string text;
  text= token->getToken();
  if(token->getCode()==VARIABLE){
    recognizeVariable();
    if(token->getCode()== ADICION|| token->getCode()== SUSTRACCION||token->getCode()==MULTIPLICATION || token->getCode()== DIVISION){
      exp();
      recognizeVariable();
    }
  }
}

void Parser::program()
{
	recognize(PROGRAM);
	funDefinitionList();
	recognize(ENDPROGRAM);
	if (token->getCode() == TEOF)
		cout << "No errors found" << endl;
}

void Parser::funDefinitionList()
{
	if(token->getCode() == DEF) {
		funDefinition();
		funDefinitionList();
	}
}


#include <string>
#include "token.h"

using namespace std;

Token::Token(int code, string text)
{
	this->code = code;
	this->text = text;
}

Token::~Token()
{
	text.clear();
}

string Token::toString() {
	return "" + to_string(code) + " " + text;
}

string Token::getToken() {
	return text;
}

int Token::getCode() {
	return code;
}

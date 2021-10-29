#ifndef token_h
#define token_h

#include <string>

using namespace std;

class Token
{
	private:
		int code;
		string text;
	
	public:
		Token(int code, string text);
		virtual ~Token();
		string toString();
		string getToken();
		int getCode();
};

#endif

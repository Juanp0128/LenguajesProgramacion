compilador: parser.o lexer.o token.o
	g++ -g -o compilador parser.o lexer.o token.o
  
parser.o: parser.cpp parser.h lexer.o
	g++ -g -c parser.cpp

lexer.o: lexer.cpp lexer.h token.o token.h
	g++ -g -c lexer.cpp

token.o: token.cpp token.h
	g++ -g -c token.cpp

clean:
	rm -f *.o *.exe

all: ErrorHandler.o ErrorItem.o LexicalError.o CompilerSettings.o main_test.o
	g++ ErrorHandler.o ErrorItem.o LexicalError.o CompilerSettings.o main_test.o -o main --std=c++11

ErrorHandler.o: ErrorHandler.cpp ../settings/CompilerSettings.hpp
	g++ -c ErrorHandler.cpp --std=c++11

ErrorItem.o: ErrorItem.cpp
	g++ -c ErrorItem.cpp --std=c++11

LexicalError.o: LexicalError.cpp
	g++ -c LexicalError.cpp --std=c++11

CompilerSettings.o: ../settings/CompilerSettings.cpp
	g++ -c ../settings/CompilerSettings.cpp --std=c++11

main_test.o: main_test.cpp ErrorHandler.hpp ErrorItem.hpp ../settings/CompilerSettings.hpp
	g++ -c main_test.cpp --std=c++11

clean: 
	rm *.o
	rm main
list : list.o list_function.o filinghtml.o dump.o
	g++ list.o list_function.o filinghtml.o dump.o -o result

list.o : list.cpp
	g++ -c list.cpp

list_function.o : list_function.cpp list_function.h
	g++ -c list_function.cpp

filinghtml.o : filinghtml.cpp filinghtml.h
	g++ -c filinghtml.cpp

dump.o : dump.cpp dump.h
	g++ -c dump.cpp

clean:
	del list.o list_function.o filinghtml.o dump.o dump.html result.exe
    
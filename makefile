Proyecto1:	Main.o Object.o Person.o VSArrayList.o ADTList.o
		g++ Main.o Object.o Person.o VSArrayList.o ADTList.o -o Proyecto1

Main.o: Main.cpp Object.o Person.o VSArrayList.o ADTList.o
	g++ -c Main.cpp

Object.o:	Object.cpp Object.h
	g++ -c Object.cpp

Person.o: Person.cpp Object.h Person.h
	g++ -c Person.cpp

ADTList.o:	ADTList.cpp ADTList.h
	g++ -c ADTList.cpp

VSArrayList.o:	VSArrayList.cpp ADTList.h VSArrayList.h
	g++ -c VSArrayList.cpp					

clean:	
	rm *.o Proyecto1
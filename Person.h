#include "Object.h"
using namespace std;
#include <string>
#include <sstream>
class Person: public Object
{
protected:	
	string name;
	int age;
public:
	Person(string,int);//Constructor que asignara el String Nombre y int Edad
	~Person();
	virtual string toString() const;//toString que imprimira toda la informacion de la Persona
	virtual bool equals(Object*);//Equals que comparara si un "Objeto"  es una Persona (sea de la clase persona) 
	
};
#include "Person.h"
#include <sstream>
#include <string>
using namespace std;

Person::Person(string name,int age):name(name),age(age){//Contructor de la clase Person asignara el Name->Nombre de la persona y su Age->Edad de la persona

}

Person::~Person(){
	
}
string Person::toString() const{//toString que retornara la informacion de la Persona
	stringstream ss;
	ss<<"Name:"<<name<<" Age:"<<age;
	return ss.str();
}

bool Person::equals(Object* Other){//Compara si el "Objeto" es una Persona
	if (dynamic_cast<Person*>(Other))
	{
		return false;
	}
	Person* TemporalPersona=dynamic_cast<Person*>(Other);
	return TemporalPersona->name==name;
}

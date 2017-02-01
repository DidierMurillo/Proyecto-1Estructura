
#include <string>
#pragma once 
using std::string;
class Object
{

public:
	Object();
	virtual~Object();
	virtual string toString()const;
	virtual bool equals(Object*);//Metodo equals que compara los diferentes "Objetos"
};
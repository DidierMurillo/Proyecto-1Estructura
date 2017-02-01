#include "Object.h"
#include <sstream>
using namespace std;

//Object es la clase que estandarizara la creacion de nuevos "objetos" al heredarse 
Object::Object(){

}

Object::~Object(){
	
}

string Object::toString() const{
	stringstream ss;
	ss<<"Esto es un objeto toString del padre \n";
	return ss.str();
}

bool Object::equals(Object* Other){
	return Other==this;
}
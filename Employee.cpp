#include "Employee.h"
#include <string>
#include <sstream>

Employee::Employee(string Domicilio,string name,int Sueldo,int age):Person(name,age),Domicilio(Domicilio),Sueldo(Sueldo){

}

Employee::Employee(string name,int age):Person(name,age){

}

Employee::~Employee(){

}

string Employee::getDomicilio(){//Accesor de  Domicilio
	return this->Domicilio;
}

int Employee::getSueldo(){//Accesor de Sueldo
	return this->Sueldo;
}

void Employee::setSueldo(int Sueldo){//Modificador de Sueldo
	this->Sueldo=Sueldo;
}

void Employee::setDomicilio(string Domicilio){//Modificador de Domocilio
	this->Domicilio=Domicilio;
}


void Employee::aumentarSueldo(int DeltaAumentoSueldo){//Modifica el sueldo de un empleado segun un deltaAumentoSueldo
	if (DeltaAumentoSueldo>=100)
	{
		setSueldo(this->Sueldo*(1+DeltaAumentoSueldo/100));
	}else if (DeltaAumentoSueldo<100&&DeltaAumentoSueldo>11){
		setSueldo(this->Sueldo*(DeltaAumentoSueldo)/100+this->Sueldo);
	}else{
		setSueldo((this->Sueldo*(DeltaAumentoSueldo))/100+this->Sueldo);
	}
	
}

string Employee::toString()const{//Imprime los atributos de Employee
	stringstream ss;
	ss<<Person::toString()<<" Domicilio:"<<Domicilio<<" Sueldo:"<<Sueldo;
	return ss.str();
}
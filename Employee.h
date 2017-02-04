#include <string>
#include "Person.h"
using namespace std;

class Employee: public Person
{
		
public:
	int Sueldo;
	string Domicilio;
	Employee(string,string,int,int);//Constructor propio de Employee(Nombre,Domicilio,Edad,Sueldo)
	Employee(string,int);
	~Employee();
	string getDomicilio();//Accesor de Domicilio
	void setDomicilio(string);//Modificador de Domicilio
	int getSueldo();//Accesor de Sueldo
	void setSueldo(int);//Modificador de Sueldo
	void aumentarSueldo(int);//Modificador de sueldo que lo aumentara dependiendo de un delta que sea el porcentaje que se aumentara
	virtual string toString() const;
};
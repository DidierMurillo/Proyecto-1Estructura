#include "VSArrayList.h"
using namespace std;
#include <sstream>
#include <iostream>

bool VSArrayList::insert(Object* e,int p){
	if (p<0||p>size)//Validara la posicion dada por el usuario
	{
		return false;
	}
	if (size==currentcapacity)//Si el tamaño es igual a la capacidad que tiene la VSArrayList llamara al metodo que resize que aumentara el tamño del la lista
	{
		resize();
	}
	for (int i = size; i > p; --i)
	{
		array[i]=array[i-1];
	}
	array[p]=e;
	size++;
	return true;
}

void VSArrayList::resize(){//Metodo de la clase VSArrayList que incrementara el tamaño de la lista segun el delta definido, dependiendo del constructor
	Object** temp=NULL;
	temp=new Object*[currentcapacity+delta];
	//validar memoria
	for (int i = 0; i < currentcapacity; ++i)
	{
		temp[i]=array[i];
	}
	delete[] array;
	array=temp;
	currentcapacity+=delta;
}

VSArrayList::VSArrayList(int currentcapacity){//Constructor que inicializa el VSArrayList y delta se le asigna la capacidad(aumento del 100% de su tamaño)
	this->currentcapacity=currentcapacity;
	array=new Object*[currentcapacity];
	delta=currentcapacity;//delta es el numero de espacios libres que se incrementaran en la lista
	if (!array)
	{
		cout<<"OUT OF MEMORY "<<"\n";
		
	}
}

VSArrayList::VSArrayList(int currentcapacity,int delta){//Constructor que inicializa el VSArrayList y delta se le asigna un tamaño definido por el usuario
	this->currentcapacity=currentcapacity;
	array=new Object*[currentcapacity];
	this->delta=delta;//delta es el numero de espacios libres que se incrementaran en la lista
	if (!array)
	{
		cout<<"OUT OF MEMORY "<<"\n";
		
	}
}

VSArrayList::~VSArrayList(){//Destructor de VSArrayList
	for (int i = 0; i <size; ++i)
	{
		if (array[i])
		{
			delete array[i];
		}
	delete[] array;	
	}
}


Object* VSArrayList::remove(int p){//Remueve un objeto en una posicion dada por el usuario(El size no decremena) mientras la posicion sea validad
	if (p<0||p>size)
	{
		cout<<"El tamaño que ingreso no fue valido ---->explode()";
		return NULL;
	}
	Object* e=array[p];
	array[p]=NULL;
	return e;
	
}

Object* VSArrayList::get(int p){//Regresa la referencia del "objeto" en una posicion dada por el usuario mientras la posicion sea validad
	if(p<0||p>size){
		cout<<"El tamaño que ingreso no fue valido ---->explode()";
		return NULL;
	}
	return array[p];
}

Object* VSArrayList::first()const{//Regresa refeferencia del primer objeto que se encuentra en la lista
	return array[0];	
}

Object* VSArrayList::last(){//Regresa referencia del ultimo objeto que se encuentra en la lista
	return array[size-1];	
}

void VSArrayList::clear(){//Elimina el contenido de cada posicion de la lista y borra la lista como tal
	for (int i = 0; i < size; ++i)
	{
		if (array[i])
		{
			delete array[i];
			array[i]=NULL;
		}
	}
}

int VSArrayList::indexof(Object* e){//Regresa la posicion de un "objeto" que el usuario da a buscar, sino lo encuentra regresa -1 
	for (int i = 0; i < size; ++i)
	{
		if (array[i]==e)
		{
			return i;
		}
	}
	return -1;
}

bool VSArrayList::isFull(){//Evalua si la lista esta llena 
	for (int i = 0; i < size; ++i)
	{
		if (array[i]==NULL)
		{
			return true;
		}
	}
	return false;
}

bool VSArrayList::isEmpty(){//Evalua si la lista esta vacia
	for (int i = 0; i < size; ++i)
	{
		if (array[i]!=NULL)
		{
			return false;
		}
	}
	return true;
}

int VSArrayList::capacity()const{//Retorna la capacidad de la lista(VSArrayList su tamaño incrementrara por lo tanto regresa -1)
	return -1;
}
#include "Object.h"
#pragma once
class ADTList : public Object
{
protected://Size es protected para que toda clase que herede de esta pueda acceder al size
	int size;

public:
	ADTList();
	~ADTList();
	//Metodos virtuales puros que son los que las TDA List que hereden de ADTList tendran que implementar 
	virtual bool insert(Object*,int)=0;
	virtual Object* remove(int)=0;
	virtual Object* first()const=0;
	virtual Object* last()=0;
	virtual void clear()=0;
	virtual int indexof(Object*)=0;
	virtual Object* get(int)=0;
	virtual int capacity()const=0;
	virtual bool isFull()=0;
	virtual bool isEmpty()=0;
};
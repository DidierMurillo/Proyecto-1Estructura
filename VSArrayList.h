#include "ADTList.h"
# pragma once
class VSArrayList: public ADTList
{
public:
	VSArrayList(int);//Constructor que incia el VSArrayList y su amuento(delta) sera su mismo tamaño
	VSArrayList(int,int);//Contructor que incia el VSArrayList y su aumento(delta) lo ingresara tambien el usuario
	virtual ~VSArrayList();//Destructor de VSArrayList que borrara completamente la Lista
	virtual bool insert(Object*,int);//Insertara un objeto en la posicion deseada por el usuario (Mientras sea valida)
	virtual Object* remove(int);//Remueve un objeto en la posicion deseada por el usuario (Mientras sea valida) y retorna el objeto borrado
	virtual Object* first()const;//Retornara el primer objeto que se encuentra en la lista (si hay objeto)
	virtual Object* last();//Retornara el ultima objeto que se encuentra en la lista (si hay objeto)
	virtual void clear();//Limpia toda la lista 
	virtual int indexof(Object*);//Buscara un objeto en la lista y retornara la posicion en la que se encuentra
	virtual Object* get(int);//Retorna una referencia del objeto en una posicion dada
	virtual int capacity()const;//Retorna la capacidad que tendra la lista en este caso siempre sera -1 ya que el tamaño es variable
	virtual bool isFull();//Retornara 1 si la lista esta llena 0 si no lo esta
	virtual bool isEmpty();////Retornara 0 si la lista esta vacia 0 si no esta vacia


private:
	int currentcapacity;//
	int delta;//El el tamaño que aumentara la lista al estar llena 
	void resize();//El metodo que incrementara la capacidad de la lista 
	Object** array;
};


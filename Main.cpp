#include "Object.h"
#include "Person.h"
#include "ADTList.h"
#include "VSArrayList.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
	Person* P=new Person("Juana",15);
	Person* P1=new Person("Sancho",18);
	Object* O=new Object();
	ADTList* List=new VSArrayList(5);
	cout<<P->toString()<<"\n";
	cout<<List->isFull()<<"\n";
	cout<<List->isEmpty()<<"\n";
	cout<<List->insert(P,0)<<"\n";
	cout<<List->get(0)->toString()<<"\n";
	cout<<List->indexof(P)<<"\n";
	cout<<List->insert(P1,0)<<"\n";
	cout<<List->first()->toString()<<"\n";
	cout<<List->last()->toString()<<"\n";
	cout<<List->isEmpty()<<"\n";
	cout<<List->remove(0)->toString()<<"\n";
	List->clear();
	cout<<List->isEmpty()<<"\n";

}	

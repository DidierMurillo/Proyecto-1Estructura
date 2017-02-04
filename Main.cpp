#include "Object.h"
#include "ADTList.h"
#include "VSArrayList.h"
#include "Employee.h"
#include <iostream>
#include <sstream>
#include <stdio.h>
using namespace std;

int main(int argc, char* argv[]){
	int OpcionIngresada,ContadorSizeList=0;
	ADTList* ListaEmpleados;
	printf("Opciones de creacion de la lista:\n1- Lista con aumento de 100");
	printf("%c",37 );
	cout<<"\n2- Lista con aumento pre-establecido\n3-Salir\n Ingrese su opcion:";
	cin>>OpcionIngresada;
	while(OpcionIngresada==1||OpcionIngresada==2){
		int TamanoLista=0,DeltaCambioLista=0;
		cout<<"Ingrese el tamaño que tendra la lista:";
		cin>>TamanoLista;
		if (OpcionIngresada==1)
		{
			ListaEmpleados=new VSArrayList(TamanoLista);//Crea la lista y el aumento sera del 100%
		}else{
			cout<<"Ingrese el delta (tamaño que incrementara al llenarse la lista):";
			cin>>DeltaCambioLista;
			ListaEmpleados=new VSArrayList(TamanoLista,DeltaCambioLista);//Crea la lista pero tendra un aumento de delta
		}
		cout<<"Se creo la lista con exito!";
		
		while(OpcionIngresada>0&&OpcionIngresada<8){
			cout<<"\n\n\n\n\n----Bienvenido al Menu ----\n";
			cout<<"Ingrese la opcion que desea:\n1-Insertar Empleado\n2-Listar Empleado\n3-Borrar Empleado\n4-Calcular Salario Promedio\n5-Ver Salario Maximo\n6-Ver Salario Minimo\n7-Dar Incremento por Inflación\n8-Salir\nIngrese su opcion:";
			cin>>OpcionIngresada;
			if (OpcionIngresada==1)//Se ingresan todos los datos de el empleado se crea y luego se agrega en la posion cero de la lista
			{	
				string NombreEmpleado,DomicilioEmpleado;
				int EdadEmpleado,SueldoEmpleado;
				cout<<"Ingrese el nombre del empleado:";
				cin>>NombreEmpleado;
				cout<<"Ingrese el domicilio del empleado:";
				cin>>DomicilioEmpleado;
				cout<<"Ingrese la edad del empleado:";
				cin>>EdadEmpleado;
				cout<<"Ingrese el sueldo del empleado: ";
				cin>>SueldoEmpleado;
				ListaEmpleados->insert( new Employee(DomicilioEmpleado,NombreEmpleado,SueldoEmpleado,EdadEmpleado),0);
				cout<<"Se ingreso el empleado con exito!\n";
				ContadorSizeList++;
			}else if(OpcionIngresada==2){//Imprimira los datos del empleado mientras las posicion no este vacia y sea valida
				int PosiconLista;
				cout<<"Ingrese la posicion del empleado para imprimir su informacion:";
				cin>>PosiconLista;
				if (ListaEmpleados->get(PosiconLista)!=NULL)
				{
					cout<<static_cast<Employee*>(ListaEmpleados->get(PosiconLista))->toString();
				}else{
					cout<<"\nLa posicon ingresada no fue valida\n";
				}
				
			}else if(OpcionIngresada==3){//Se borra el empleado y se imprimen los datos de ese mismo empleado
				int PosiconBorrar;
				cout<<"Ingrese la posicion del empleado a borrar:";
				cin>>PosiconBorrar;
				cout<<"Se borro con exito a--->"<<ListaEmpleados->remove(PosiconBorrar)->toString();
			}else if(OpcionIngresada==4){//Se suman todos los sueldos en un acumulador, para luego obtener un promedio
				int ContadorPromedio=0,AcumuladorPromedio=0;
				for (int i = 0; i < ContadorSizeList; ++i)
				{
					if (ListaEmpleados->get(i)!=NULL)
					{
						AcumuladorPromedio+=static_cast<Employee*>(ListaEmpleados->get(i))->getSueldo();
						ContadorPromedio++;
					}

				}
				cout<<"El Sueldo Promedio es:"<<AcumuladorPromedio/ContadorPromedio<<"\n";
			}else if(OpcionIngresada==5){//Primero se busca el sueldo maximo, luego se agrega la informacion de aquellos empleados con el mismo sueldo a un stringstream y se imprimen
				stringstream EmpleadoSueldoMaximo;
				int TemporalSueldoMaximo=0;
				for (int i = 0; i < ContadorSizeList; ++i)
				{
					if (ListaEmpleados->get(i)!=NULL)
					{
						if (TemporalSueldoMaximo<static_cast<Employee*>(ListaEmpleados->get(i))->getSueldo())
						{
							TemporalSueldoMaximo=static_cast<Employee*>(ListaEmpleados->get(i))->getSueldo();
						}
					}

				}
				for (int i = 0; i < ContadorSizeList; ++i)
				{
					if(ListaEmpleados->get(i)!=NULL)
					{
						if (static_cast<Employee*>(ListaEmpleados->get(i))->getSueldo()==TemporalSueldoMaximo)
						{
							EmpleadoSueldoMaximo<<static_cast<Employee*>(ListaEmpleados->get(i))->toString()<<"\n";
						}
					}	
				}
				cout<<"Empleado(s) con sueldo maximo:\n"<<EmpleadoSueldoMaximo.str();

			}else if(OpcionIngresada==6){//Primero se busca el sueldo minimo, luego se agrega la informacion de aquellos empleados con el mismo sueldo a un stringstream y se imprimen
				stringstream EmpleadoSueldoMinimo;
				int TemporalSueldoMinimo=static_cast<Employee*>(ListaEmpleados->get(0))->getSueldo();
				for (int i = 0; i < ContadorSizeList; ++i)
				{
					if (ListaEmpleados->get(i)!=NULL)
					{
						if (ListaEmpleados->get(i)!=NULL)
						{
							if (TemporalSueldoMinimo>static_cast<Employee*>(ListaEmpleados->get(i))->getSueldo())
							{
								TemporalSueldoMinimo=static_cast<Employee*>(ListaEmpleados->get(i))->getSueldo();
							}
						}	
					}

				}
				for (int i = 0; i < ContadorSizeList; ++i)
				{
					if (static_cast<Employee*>(ListaEmpleados->get(i))->getSueldo()==TemporalSueldoMinimo)
					{
						EmpleadoSueldoMinimo<<static_cast<Employee*>(ListaEmpleados->get(i))->toString()<<"\n";
					}
				}
				cout<<"Empleado(s) con sueldo minimo:\n"<<EmpleadoSueldoMinimo.str();
			}else if(OpcionIngresada==7){//Aumenta el sueldo de todos los empleados llamando la funcion aumentar sueldo que es propia de la clase Employee
				int DeltaAumento;
				cout<<"Ingrese el incremento por inflacion(Un numero entero y sin signo de porcentaje): ";
				cin>>DeltaAumento;
				for (int i = 0; i < ContadorSizeList; ++i)
				{
					if(ListaEmpleados->get(i)!=NULL)
					{
						static_cast<Employee*>(ListaEmpleados->get(i))->aumentarSueldo(DeltaAumento);
					}	
				}
				cout<<"Se aumento el sueldo con exito\n";	
			}//Llave de cierre de la ultima opcion del menu

		}//Llave de cierre del segundo while que contrala la repeticion del menu mientras sea un numero mayor que cero y menor que 8
	}//Llave de cierre del primer while que controla que se ingrese 1 o 2 al momento de decidir que tipo de lista crear
}//Llave que cierra el main
	

#ifndef MIEMBROA_H_INCLUDED
#define MIEMBROA_H_INCLUDED
#include "string.h"


typedef struct{
    string nombre;
    fecha nacimiento;
    boolean miembroInicial;
    string progenitor;
} miembroA;


/*Carga miembroA A*/
void cargarMiembroA (miembroA &A, string nombre, fecha nacimiento, boolean miembroInicial, string progenitor);

/*Despliega por pantalla los datos de un miembro A*/
void mostrarMiembroA (miembroA A);

/*Copia los datos de un miembro A a otro nuevo*/
void copiarMiembroA (miembroA &B, miembroA A);

/*Devuelve nombre*/
void darNombre (miembroA A, string &nombre);

/*Devuelve boolean miembro inicial*/
boolean darMiembroInicial (miembroA A);

/*Devuelve la fecha de nacimiento*/
fecha darFechaNac (miembroA A);

/*Devuelve nombre de progenitor*/
//Precondici�n: Que no sea miembro inicial
void darProgenitor (miembroA A, string &progenitor);

/*Escribe en el archivo los datos del miembroA A*/
//Precondici�n: El archivo viene abierto para escritura
void bajarMiembroA (miembroA A, FILE * f);

/*Lee desde el archivo los datos del miembroA A*/
//Precondici�n: El archivo viene abierto para lectura
void subirMiembroA (miembroA &A, FILE * f);

/*Llama al procedimiento destruirString del m�dulo de string*/
void destruirMiembroA (miembroA &A);



#endif // MIEMBROA_H_INCLUDED

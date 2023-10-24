#ifndef ABBMONARQUIA_H_INCLUDED
#define ABBMONARQUIA_H_INCLUDED
#include "miembroA.h"



typedef struct nodoM{
    miembroA m;
    nodoM * hizq;
    nodoM * hder;
}nodoMie;
typedef nodoMie * ABBMonarquia;


/*Crea un �rbol vac�o*/
void crearABB (ABBMonarquia &a);

/*Devuelve TRUE si el �rbol es vac�o*/
boolean ABBVacio (ABBMonarquia a);

/*Inserta un miembroA m en el ABB*/
//Precondici�n: el miembro no existe en el ABB
void insertABB (ABBMonarquia &a, miembroA m);

/*Devuelve TRUE si un nombre existe en el ABB*/
boolean existeMiembro (ABBMonarquia a, string nombre);

/*Recorre el ABB en orden listando sus nodos por pantalla*/
void listarOrdenado (ABBMonarquia a);

/*Escribe en el archivo los datos de todos los enteros del �rbol*/
//Precondici�n: el archivo viene abierto para escritura
void bajarABBAux (ABBMonarquia a, FILE * f);

/*Abre el archivo para escritura y escribe los datos de todos los miembrosA del �rbol*/
void bajarABB (ABBMonarquia a, string nomArch);

/*Abre el archivo para lectura e inserta en el �rbol todos los enteros est�n en el archivo*/
//Precondicion: el archivo existe
void levantarABB (ABBMonarquia &a, string nomArch);

/*Devuelve TRUE si el archivo de respaldo ABB es vac�o*/
boolean archivoVacioABB (string nomArch);

/*Devuelve TRUE si existe el archivo de respaldo ABB*/
boolean existeArchivoABB (string nomArch);

/*Elimina todos los nodos del ABB y lo deja vac�o*/
//Precondicion: El ABB no esta vacio
void eliminarArbol (ABBMonarquia &a);


#endif // ABBMONARQUIA_H_INCLUDED

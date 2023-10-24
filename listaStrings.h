#ifndef LISTASTRINGS_H_INCLUDED
#define LISTASTRINGS_H_INCLUDED
#include "string.h"


typedef struct nodoString {
    string info;
	nodoString * sig;
 } NodoST;
typedef NodoST * listaStrings;


/*Divide un string en una lista de strings*/
void partirString (string s, listaStrings &LS);

/*Dada una posición devuelve un string de una lista de strings*/
void obtenerString (listaStrings LS, int pos, string &s);

/*Devuelve la cantidad de strings que tiene una lista de strings*/
int cantidadStrings (listaStrings LS);

/*Crea una lista de strings*/
void crearListaString (listaStrings &LS);

/*Elimina los nodos de una lista de strings y la deja vacía*/
void eliminarListaString (listaStrings &LS);

/*Agregar un string al final de una lista de strings*/
void insBackListaString (listaStrings &LS, string s);

//Devuelve el ultimo string de una lista de strings
void ultimo (listaStrings LS, string &s);

//Devuelve TRUE si existe un nombre en una lista de strings
boolean existeNombre (listaStrings LS, string s);

#endif // LISTASTRINGS_H_INCLUDED

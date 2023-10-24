#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include "boolean.h"
#include "fecha.h"


const int MAX = 80;
typedef char * string;

/*Crear un string vacío*/
void strCrear (string &s);

/*Libera la memoria usada por el string*/
void strDestruir (string &s);

/*Copia el contenido de s2 en s1*/
void strCop (string &s1, string s2);

/*Lee el string s desde teclado*/
void scan (string &s);

/*Imprime el string s por pantalla*/
void print (string s);

/*Determina si los strings s1 y s2 son iguales*/
boolean strEq (string s1, string s2);

/*Escribe en el archivo los caracteres del string s (incluido '\0')*/
//Precondición: El archivo viene abierto para escritura.
void bajarString (string s, FILE * f);

/*Lee desde el archivo los caracteres del string s*/
//Precondición: El archivo viene abierto para lectura.
void levantarString (string &s, FILE * f);

/*Determina si el string solo tiene letras*/
boolean soloLetras (string s);

/*Convierte un string a letras mayúsculas. Precondición: el string solo tiene letras*/
void convertirMayus (string &s);

/*Determina si el string tiene el formato dd/mm/yyyy*/
boolean validarFormatoFecha (string s);

/*Convierte un string en una fecha*/
//Precondición: el string tiene el formato dd/mm/yyyy
int convertirNumero (string s);

/*Determina si s1 es alfabéticamente menor que s2*/
boolean strMenor (string s1, string s2);

/*Devuelve el largo del string s*/
int strLargo (string s);

/*Devuelve TRUE si el string solo contiene los caracteres “->”*/
boolean soloFlecha (string s);

void dividirStringFecha(string fecha, string &dia, string &mes, string &anio);

//Copia hacia sb los caracteres de s, pero sin blancos que s pueda tener al principio
//Precondicion: s no es vacio
void eliminarBlancosPrincipio (string s, string &sb);

//Divide el string s en otros dos; en primero guarda la primer palabra de s y en resto todo lo demas
//Precondicion: s no es vacio
void dividirString (string s, string &primero, string &resto);

fecha convertirFecha(string s);

#endif // STRING_H_INCLUDED

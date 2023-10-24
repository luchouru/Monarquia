#ifndef RESPALDOFECHA_H_INCLUDED
#define RESPALDOFECHA_H_INCLUDED
#include "fecha.h"
#include "string.h"

/*Abre el archivo para escritura y escribe la última fecha global ingresada*/
void bajarFecGlobal (fecha fec, string nomArch);

/*Abre el archivo para lectura e inserta la última fecha global ingresada*/
//Precondicion: el archivo existe
void levantarFecGlobal (fecha &fec, string nomArch);

/*Devuelve TRUE si existe el archivo de respaldo ABB*/
boolean existeArchivoFecha (string nomArch);

#endif // RESPALDOFECHA_H_INCLUDED

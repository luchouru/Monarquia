#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include "boolean.h"
#include "stdio.h"

typedef struct {
    int dia;
    int mes;
    int anio;
}fecha;


/*Carga día, mes y año*/
void cargarFecha(fecha &f, int dia, int mes, int anio);

/*Despliega la fecha por pantalla*/
void desplegarFecha(fecha f);

/*Devuelve el día*/
int darDia(fecha f);

/*Devuelve el mes*/
int darMes(fecha f);

/*Devuelve el año*/
int darAnio(fecha f);

/*Comprueba que la fecha sea válida*/
boolean validarFecha (fecha f);

/*Compara dos fechas, devuelve TRUE si f1 es posterior o igual a f2*/
boolean compararFecha (fecha f1, fecha f2);

/*Bajar fecha global*/
void bajarFecha (fecha fec, FILE * f);

/*Subir fecha global*/
void subirFecha (fecha &fec, FILE * f);

#endif // FECHA_H_INCLUDED

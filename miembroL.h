#ifndef MIEMBROL_H_INCLUDED
#define MIEMBROL_H_INCLUDED
#include "miembroA.h"

typedef struct{
    miembroA m;
    boolean monarcaActual;
    boolean fueMonarca;
    boolean aspiranteAlTrono;
    boolean abdico;
    boolean estaVivo;
    fecha ascencion;
    fecha abdicacion;
    fecha fallecimiento;
} miembroL;


/*carga miembroL L*/
void cargarMiembroL (miembroL &L, boolean monarcaActual, boolean fueMonarca, boolean aspiranteAlTrono, boolean abdico, boolean estaVivo, fecha ascencion, fecha abdicacion, fecha fallecimiento, miembroA m);

/*Despliega por pantalla los datos de un miembro L*/
void mostrarMiembroL (miembroL L);

/*Devuelve boolean monarca actual*/
boolean darMonarcaActual (miembroL L);

/*Devuelve boolean fue monarca*/
boolean darFueMonarca (miembroL L);

/*Devuelve boolean aspirante al trono*/
boolean darAspiranteAlTrono (miembroL L);

/*Devuelve boolean abdico*/
boolean darAbdico (miembroL L);

/*Devuelve boolean est� vivo*/
boolean darEstaVivo (miembroL L);

/*Devuelve fecha de ascensi�n*/
//Precondici�n: darAspiranteAlTrono =FALSE
fecha darFechaAscencion (miembroL L);

/*Devuelve fecha de abdicaci�n*/
//Precondici�n: darAbdico =FALSE
fecha darFechaAbdicacion (miembroL L);

/*Devuelve fecha de fallecimiento*/
//Precondici�n: estavivo=FALSE
fecha darFechaFallecimiento (miembroL L);

void darNombreL (miembroL L, string &nom);

void darProgenitorL (miembroL L, string &prog);

/*Escribe en el archivo los datos del miembroL L*/
//Precondici�n: El archivo viene abierto para escritura
void bajarMiembroL (miembroL L, FILE * f);

/*Lee desde el archivo los datos del miembroL L*/
//Precondici�n: El archivo viene abierto para escritura
void subirMiembroL (miembroL &L, FILE * f);

/*Despliega por pantalla el nombre y el de su progenitor*/
void listarDatosAspirantes (miembroL L);

/*Destruye miembro L, invocando destruirMiembroA*/
void destruirMiembroL (miembroL &L);

//Operacion auxiliar para desplegar aspirantes
void mostrarSoloAspirantes (miembroL L);

//Operacion auxiliar para desplegar monarcas
/*Despliega por pantalla, nombre, ascensi�n, finalizaci�n del reinado y causa*/
void mostrarSoloMonarcas (miembroL L);

//Modifica boolean monarca actual, puede pasar de TRUE a FALSE o de FALSE a TRUE
void modificarMonarcaActual (miembroL &L, boolean mActual);

//Modifica boolean fue monarca de FALSE a TRUE
void modificarFueMonarca (miembroL &L);

//Modifica boolean aspirante al trono de TRUE a FALSE
void modificarAspiranteAlTrono (miembroL &L);

//Modifica boolean abdico de FALSE a TRUE
void modificarAbdico (miembroL &L);

//Modifica boolean esta vivo de TRUE a FALSE
void modificarEstaVivo (miembroL &L);

//Modifica la fecha de ascension al trono
void modificarFechaAscencion (miembroL &L, fecha asc);

//Mofifica la fecha de abdicacion al trono
void modificarFechaAbdicacion (miembroL &L, fecha abd);

//Modifica la fecha de fallecimiento
void modificarFechaFallecimiento (miembroL &L, fecha fall);
#endif // MIEMBROL_H_INCLUDED

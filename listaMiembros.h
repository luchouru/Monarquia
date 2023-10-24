#ifndef LISTAMIEMBROS_H_INCLUDED
#define LISTAMIEMBROS_H_INCLUDED
#include "miembroL.h"
#include "listaStrings.h"


typedef struct nodoL{
    miembroL miembro;
    nodoL * sig;
} nodo;
typedef nodo * listaMiembros;


/*Crea una lista de miembrosL*/
void crearLista (listaMiembros &L);

/*Devuelve TRUE si la lista es vacía*/
boolean listaVacia (listaMiembros L);

/*Inserta un miembro al inicio de la lista*/
//Precondición: la lista está vacía
void insFront (listaMiembros &L, miembroL mL);

/*Inserta un miembro al final de la lista. */
void insBack (listaMiembros &L, miembroL mL);

//Operacion auxiliar de nacimiento, inserta un miembro en la lista despues del nombre recibido
void insertarNacimiento (listaMiembros &L, miembroL mL, string nom);

/*Dado un nombre devuelve un miembroL*/
//Precondición: el nombre existe
miembroL buscarMiembro (listaMiembros L, string nombre);

/*Abre el archivo para lectura y carga en la lista los datos de todos los miembrosL que están almacenadas en el archivo*/
void levantarLista (listaMiembros &L, string nomArch);

/*Abre el archivo para escritura y escribe los datos de todos los miembrosL que están almacenadas en la lista */
void bajarLista (listaMiembros L, string nomArch);

/*Devuelve TRUE si el archivo de respaldo lista se encuentra vacío*/
boolean vacioArchivoLista (string nomArch);

/*Devuelve TRUE si existe el archivo de respaldo lista*/
boolean existeArchivoLista (string nomArch);

/*Recorre la lista eliminando sus nodos y la deja vacía*/
//Precondicion: la lista no esta vacia
void eliminarLista (listaMiembros &L);

/*Lista por pantalla todos los miembrosL de la lista de sucesión al trono*/
void desplegarHistorial (listaMiembros L);

/*Lista por pantalla todos aspirantes al trono de la lista de sucesión*/
void desplegarAspirantes(listaMiembros L);

/*Lista por pantalla todos los miembrosL que fueron monarcas*/
void desplegarMonarcas (listaMiembros L);

/*Devuelve según un nombre si el miembroL está vivo*/
//Precondición: el miembro existe
boolean estaVivo (listaMiembros L, string s);

/*Devuelve TRUE si existe un miembro con la capacidad de acceder al trono*/
boolean existeSucesion (listaMiembros L);

/*Actualiza el estado monarca de un miembroL*/
//Precondicion: Existe miembro
void fallecimientoMonarca (listaMiembros &L, string nombre);

/*Devuelve TRUE si existe un miembroL como monarca actual*/
boolean existeMonarca (listaMiembros L);

/*Compara la posición de un miembroL con el monarca actual*/
//Precondición: Existe monarca actual
//Precondicion: Existe miembro
boolean compararPosicion (listaMiembros L, string nombre);

/*Actualiza el estado abdico de un miembroL*/
//Precondicion: Existe miembro
//Precondicion: El miembro no es el monarca actual
void abdicacionAspirante (listaMiembros &L, string nombre, fecha fecAbd);

/*Registra el fallecimiento de un miembroL*/
//Precondicion: Existe miembro
void registrarFallecimiento (listaMiembros &L, string nombre, fecha fallecimiento);

/*Registra la abdicación de un miembroL*/
//Precondicion: Existe miembro
//Precondicion: El miembro es el monarca actual
void abdicacionMonarca (listaMiembros &L, string nombre, fecha abdica);

/*Devuelve el nombre del miembro con la capacidad de acceder al trono*/
//Precondición: existe miembro con la capacidad de acceder al trono
void sucesor (listaMiembros L, string &nombre);

//Inserta un miembro mL en la listaMiembros
//Precondicion:La lista no esta vacia
//Precondicion:El nombre del miembro mL no existe
//Precondicion:El nombre del progenitor existe
void nacimiento (listaMiembros &L, miembroL mL);

//Operacion auxiliar de nacimiento, encuentra el lugar donde se inserta el miembro mL en la lista
void lugarNacimiento (listaMiembros L, miembroL mL, string &lugar);

void deAspiranteAMonarca (listaMiembros &L, string nombre, fecha ascencion);

void abdicarAlNacer (listaMiembros &L, string nombre, fecha abd);

void fallecimientoAspirante (listaMiembros &L, string nombre);

#endif // LISTAMIEMBROS_H_INCLUDED

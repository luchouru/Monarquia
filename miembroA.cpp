#include "miembroA.h"

//CARGA

void cargarMiembroA (miembroA &A, string nombre, fecha nacimiento, boolean miembroInicial, string progenitor){
    strCrear(A.nombre);
    strCop(A.nombre, nombre);
    A.nacimiento = nacimiento;
    A.miembroInicial = miembroInicial;
    strCrear(A.progenitor);
    strCop(A.progenitor, progenitor);
}

void copiarMiembroA (miembroA &B, miembroA A){
    strCrear(B.nombre);
    strCop(B.nombre, A.nombre);
    B.nacimiento = A.nacimiento;
    B.miembroInicial = A.miembroInicial;
    strCrear(B.progenitor);
    strCop(B.progenitor, A.progenitor);
}

//DESPLEGAR

void mostrarMiembroA (miembroA A){
   string progenitor, nombre;
   strCrear(nombre);
   strCrear(progenitor);
   darNombre(A,nombre);
   darProgenitor(A,progenitor);

   printf("\t");
   print(nombre);
   printf(" ");
    if(!darMiembroInicial(A)){
        printf("hijo/a de ");
        print(progenitor);
        printf(" ");
    }else printf("primer monarca ");

    printf("Nacio el ");
    desplegarFecha(darFechaNac(A));

    printf("\n");
}

//SELECTORAS

void darNombre (miembroA A, string &nombre){
    strCop(nombre,A.nombre);
}

boolean darMiembroInicial (miembroA A){
    return A.miembroInicial;
}

fecha darFechaNac (miembroA A){
    return A.nacimiento;
}

void darProgenitor (miembroA A, string &progenitor){
    strCop(progenitor,A.progenitor);
}

//LEVANTAR; BAJAR Y DESTRUIR

void bajarMiembroA (miembroA A, FILE * f){
    bajarString(A.nombre, f);
    fwrite(&A.nacimiento, sizeof(fecha), 1, f);
    fwrite(&A.miembroInicial, sizeof(boolean), 1, f);
    bajarString(A.progenitor, f);
}

void subirMiembroA (miembroA &A, FILE * f){
    strCrear(A.nombre);
    levantarString(A.nombre, f);
    fread(&A.nacimiento, sizeof(fecha), 1, f);
    fread(&A.miembroInicial, sizeof(boolean), 1, f);
    strCrear(A.progenitor);
    levantarString(A.progenitor, f);
}

void destruirMiembroA (miembroA &A){
    strDestruir(A.nombre);
    strDestruir(A.progenitor);
}

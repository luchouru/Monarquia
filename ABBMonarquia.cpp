#include "ABBMonarquia.h"


void crearABB (ABBMonarquia &a){
    a = NULL;
}

boolean ABBVacio (ABBMonarquia a){
    return (boolean) (a == NULL);
}

//INSERTAR

void insertABB (ABBMonarquia &a, miembroA m){
    string nomAux,nomAux2;
    strCrear(nomAux);
    strCrear(nomAux2);

    if (a == NULL)    {
        a = new nodoMie;
        a -> m = m;
        a -> hizq = NULL;
        a -> hder = NULL;
    }
    else    {
        darNombre(a->m,nomAux);
        darNombre(m,nomAux2);
        if(strMenor(nomAux2,nomAux))
            insertABB (a -> hizq, m);
        else
            insertABB (a -> hder, m);
    }
}

//BUSQUEDA

boolean existeMiembro (ABBMonarquia a, string nombre){
    string nomaux;
    strCrear(nomaux);
    boolean encontre = FALSE;

    while (a != NULL && !encontre)
    {
        darNombre(a->m, nomaux);
        if (strEq(nombre,nomaux))
            encontre = TRUE;
        else
            if(strMenor(nombre,nomaux))
                a = a -> hizq;
            else
                a = a -> hder;
    }
    return encontre;
}

//DESPLEGAR

void listarOrdenado (ABBMonarquia a){
    if (a != NULL)
    {
        listarOrdenado(a -> hizq);
        mostrarMiembroA(a->m);
        listarOrdenado(a -> hder);
    }
}

//LEVANTAR, BAJAR y BUSQUEDA

void bajarABBAux (ABBMonarquia a, FILE * f){
    if (a != NULL){
        bajarMiembroA(a->m,f);
        bajarABBAux(a -> hizq, f);
        bajarABBAux(a -> hder, f);
    }
}

void bajarABB (ABBMonarquia a, string nomArch){
    FILE * f = fopen (nomArch, "wb");
    bajarABBAux (a, f);
    fclose (f);
}

void levantarABB (ABBMonarquia &a, string nomArch){
    FILE * f = fopen (nomArch, "rb");
    miembroA buffer;
    crearABB (a);
    subirMiembroA(buffer,f);
    while (!feof(f)){
        insertABB (a, buffer);
        subirMiembroA(buffer,f);
    }
    fclose (f);
}

boolean archivoVacioABB (string nomArch){
    boolean vacio = FALSE;
    FILE * f = fopen(nomArch,"rb");
    int buffer;
    fread(&buffer,sizeof(int),1,f);
    if(feof(f))
        vacio = TRUE;
    fclose(f);
    return vacio;
}

boolean existeArchivoABB (string nomArch){
    boolean existeArchivo = TRUE;
    FILE * f = fopen (nomArch, "rb");
    if (f == NULL)
        existeArchivo = FALSE;
    else
        fclose (f);
    return existeArchivo;
}

void eliminarArbol (ABBMonarquia &a){
    if (a != NULL){
        eliminarArbol(a -> hizq);
        eliminarArbol(a -> hder);
        destruirMiembroA(a->m);
        delete a;
        a = NULL;
    }
}

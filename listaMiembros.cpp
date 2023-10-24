#include "listaMiembros.h"

void crearLista (listaMiembros &L){
    L = NULL;
}

boolean listaVacia (listaMiembros L){
    boolean es = FALSE;
    if (L == NULL)
        es = TRUE;
    return es;
}

//INSERTAR

void insFront (listaMiembros &L, miembroL mL){
    listaMiembros aux = new nodo;
    aux -> miembro = mL;
    aux -> sig = L;
    L = aux;
}

void insBack (listaMiembros &L, miembroL mL){
     if(L == NULL){
        L = new nodo;
        L -> miembro = mL;
        L -> sig = NULL;
    }else insBack(L -> sig, mL);
}

void nacimiento (listaMiembros &L, miembroL mL){
    string aux;
    strCrear(aux);
    lugarNacimiento(L,mL,aux);
    insertarNacimiento(L,mL,aux);
}

void lugarNacimiento (listaMiembros L, miembroL mL, string &lugar){
    listaMiembros lmAux = L;
    listaStrings lsAux;
    crearListaString(lsAux);
    boolean progenitor = FALSE, parar = FALSE;
    string aux1, aux2, aux3, aux4;
    strCrear(aux1);
    strCrear(aux2);
    strCrear(aux3);
    strCrear(aux4);
    //recorre la lista, busca al progenitor y lo agrega a lista string aux
    darProgenitor(mL.m,aux1);
    while(!progenitor && lmAux != NULL){
        darNombreL(lmAux->miembro,aux2);
        if(strEq(aux1,aux2)){
            insBackListaString(lsAux,aux2);
            progenitor = TRUE;
        }else
            lmAux = lmAux->sig;
    }
    lmAux = lmAux->sig;
    //recorre la lista y agrega los nombres a la lista strings aux si sus progenitores esten en la lista de strings aux
    while(lmAux != NULL && !parar){
        darProgenitorL(lmAux->miembro,aux3);
        if(existeNombre(lsAux,aux3)){
            darNombreL(lmAux->miembro,aux4);
            insBackListaString(lsAux,aux4);
        }else parar = TRUE;
        lmAux = lmAux->sig;
    }
    //devuelve el ultimo nombre de la lista string aux
    ultimo(lsAux,lugar);

    //elimina lista strings aux
    eliminarListaString(lsAux);
}

void insertarNacimiento (listaMiembros &L, miembroL mL, string nom){
    string aux6;
    strCrear(aux6);

    //inserta nuevo miembro despues del nombre recibido
    listaMiembros nuevo = new nodoL;
    nuevo->miembro = mL;
    nuevo->sig = NULL;

    listaMiembros aux = L;
    darNombreL(aux->miembro,aux6);
    while(aux != NULL && !strEq(nom,aux6)){
        aux = aux->sig;
        darNombreL(aux->miembro,aux6);
    }
    if(aux->sig != NULL)
        nuevo->sig = aux->sig;
    aux->sig = nuevo;
}

//LEVANTAR, BAJAR Y DESTRUIR

void levantarLista (listaMiembros &L, string nomArch){
    FILE * f = fopen (nomArch, "rb");
    miembroL buffer;
    crearLista (L);
    subirMiembroL (buffer, f);
    while (!feof(f)) {
        insBack (L, buffer);
        subirMiembroL(buffer, f);
    }
    fclose (f);
}

void bajarLista (listaMiembros L, string nomArch){
    FILE * f = fopen (nomArch, "wb");
    while (L != NULL)
    {
        bajarMiembroL(L -> miembro, f);
        L  = L -> sig;
    }
    fclose (f);
}

boolean vacioArchivoLista (string nomArch){
    boolean archivoVacio = FALSE;
    FILE * f = fopen (nomArch, "rb");
    int buffer;
    fread (&buffer, sizeof(int), 1, f);
    if (feof(f))
        archivoVacio = TRUE;
    fclose (f);
    return archivoVacio;
}

boolean existeArchivoLista (string nomArch){
    boolean existeArchivo = TRUE;
    FILE * f = fopen (nomArch, "rb");
    if (f == NULL)
        existeArchivo = FALSE;
    else
        fclose (f);
    return existeArchivo;
}

void eliminarLista (listaMiembros &L){
    if(L->sig != NULL)
        eliminarLista(L->sig);
    else
        if(L->sig == NULL){
            destruirMiembroL(L->miembro);
            delete L;
            L = NULL;
        }
}

//DESPLEGAR

void desplegarHistorial (listaMiembros L){
    int ordinal = 1;
    listaMiembros aux = L;
    while(aux != NULL){
            printf("\n\t%d - ",ordinal);
            mostrarMiembroL(aux->miembro);
            ordinal++;
            aux = aux -> sig;
    }
    printf("\n");
}

void desplegarAspirantes(listaMiembros L){
    int ordinal = 1;
    listaMiembros aux = L;
    while (aux != NULL){
        if (darAspiranteAlTrono(aux->miembro)){
            printf("\n\t%d - ",ordinal);
            mostrarSoloAspirantes(aux->miembro);
            ordinal++;
        }
         aux = aux -> sig;
        }
         printf("\n");
    }

void desplegarMonarcas (listaMiembros L){
    int ordinal = 1;
    listaMiembros aux = L;
    while (aux != NULL){
        if (darFueMonarca(aux->miembro) || darMonarcaActual(aux->miembro)){
            printf("\n\t%d -",ordinal);
            mostrarSoloMonarcas(aux->miembro);
            ordinal++;
        }
        aux = aux -> sig;
    }
    printf("\n");
}

//BUSQUEDAS

boolean existeSucesion (listaMiembros L){
    boolean existe = FALSE;
    while(L != NULL && !existe){
        if (darAspiranteAlTrono(L->miembro) == TRUE)
            existe = TRUE;
        else
            L = L->sig;
    }
    return existe;
}

boolean existeMonarca (listaMiembros L){
    boolean existe = FALSE;
    while (L != NULL && !existe){
        if (darMonarcaActual(L->miembro) == TRUE)
            existe = TRUE;
        else
            L = L -> sig;
    }
    return existe;
}

boolean compararPosicion (listaMiembros L, string nombre){
    boolean esMenor = FALSE, encontre = FALSE;
    listaMiembros aux = L;
    int posMon =0, posMiem =0;
    string nomMiembro;
    strCrear(nomMiembro);
    while (L != NULL && !encontre){
        if (darMonarcaActual(L->miembro) == TRUE){
            encontre= TRUE;
        }else{
            posMon ++;
            L = L -> sig;
        }
    }
    encontre = FALSE;
    while (aux != NULL && !encontre){
        darNombreL(aux->miembro,nomMiembro);
        if (strEq(nomMiembro,nombre)){
            encontre= TRUE;
        }else{
            posMiem ++;
            aux = aux -> sig;
        }
    }
    if (posMiem<posMon){
        esMenor = TRUE;
    }
    return esMenor;
}

miembroL buscarMiembro (listaMiembros L, string nombre){
    boolean encontre = FALSE;
    string nomAux;
    strCrear(nomAux);
    while (L != NULL && !encontre){
        darNombreL(L->miembro,nomAux);
        if(strEq(nombre,nomAux))
            encontre = TRUE;
        else
            L = L->sig;
    }
    return L->miembro;
}

boolean estaVivo (listaMiembros L, string s){
    boolean esta = FALSE;
    if (darEstaVivo(buscarMiembro(L,s))== TRUE){
        esta = TRUE;
    }
    return esta;
}

void sucesor (listaMiembros L, string &nombre){
    boolean encontre = FALSE;
    while((L !=NULL) & (!encontre)){
        if (darAspiranteAlTrono(L->miembro) == TRUE){
            darNombreL(L->miembro,nombre);
            encontre = TRUE;
        }else{
            L = L->sig;
        }
    }
}

//MODIFICACIONES

void fallecimientoAspirante (listaMiembros &L, string nombre){
    boolean encontre = FALSE;
    string nomAux;
    strCrear(nomAux);
    listaMiembros aux = L;

    while(aux != NULL && !encontre){
        darNombreL(aux->miembro,nomAux);
        if(strEq(nombre,nomAux)){
            modificarAspiranteAlTrono(aux->miembro);
            encontre = TRUE;
        }else
            aux = aux ->sig;
    }
}

void abdicarAlNacer (listaMiembros &L, string nombre, fecha abd){
    boolean encontre = FALSE;
    string nomAux;
    strCrear(nomAux);
    listaMiembros aux = L;

    while(aux != NULL && !encontre){
        darNombreL(aux->miembro,nomAux);
        if(strEq(nombre,nomAux)){
            modificarAspiranteAlTrono(aux->miembro);
            modificarAbdico(aux->miembro);
            modificarFechaAbdicacion(aux->miembro,abd);
            encontre = TRUE;
        }else
            aux = aux ->sig;
    }
}

void fallecimientoMonarca (listaMiembros &L, string nombre){
 boolean encontre = FALSE;
    string nomAux;
    strCrear(nomAux);
    listaMiembros aux = L;

    while(aux != NULL && !encontre){
        darNombreL(aux->miembro,nomAux);
        if(strEq(nombre,nomAux)){
            modificarFueMonarca(aux->miembro);
            modificarMonarcaActual(aux->miembro,FALSE);
            encontre = TRUE;
        }else
            aux = aux ->sig;
    }
}

void abdicacionMonarca (listaMiembros &L, string nombre, fecha fecAbd){
    boolean encontre = FALSE;
    string nomAux;
    strCrear(nomAux);
    listaMiembros aux = L;

    while(aux != NULL && !encontre){
        darNombreL(aux->miembro,nomAux);
        if(strEq(nombre,nomAux)){
            modificarAbdico(aux->miembro);
            modificarFechaAbdicacion(aux->miembro,fecAbd);
            modificarFueMonarca(aux->miembro);
            modificarMonarcaActual(aux->miembro,FALSE);
            encontre = TRUE;
        }else
            aux = aux ->sig;
    }
}

void registrarFallecimiento (listaMiembros &L, string nombre, fecha fallecimiento){
    boolean encontre = FALSE;
    string nomAux;
    strCrear(nomAux);
    listaMiembros aux = L;

    while(aux != NULL && !encontre){
        darNombreL(aux->miembro,nomAux);
        if(strEq(nombre,nomAux)){
            modificarFechaFallecimiento(aux->miembro,fallecimiento);
            modificarEstaVivo(aux->miembro);
            encontre = TRUE;
        }else
            aux = aux ->sig;
    }
}

void abdicacionAspirante (listaMiembros &L, string nombre, fecha abdica){
    boolean encontre = FALSE;
    string nomAux;
    strCrear(nomAux);
    listaMiembros aux = L;

    while(aux != NULL && !encontre){
        darNombreL(aux->miembro,nomAux);
        if(strEq(nombre,nomAux)){
            modificarFechaAbdicacion(aux->miembro,abdica);
            modificarAspiranteAlTrono(aux->miembro);
            modificarAbdico(aux->miembro);
            encontre = TRUE;
        }else
            aux = aux ->sig;
    }
}

void deAspiranteAMonarca (listaMiembros &L, string nombre, fecha ascencion){
    boolean encontre = FALSE;
    string nomAux;
    strCrear(nomAux);
    listaMiembros aux = L;

    while(aux != NULL && !encontre){
        darNombreL(aux->miembro,nomAux);
        if(strEq(nombre,nomAux)){
            modificarAspiranteAlTrono(aux->miembro);
            modificarMonarcaActual(aux->miembro,TRUE);
            modificarFechaAscencion(aux->miembro,ascencion);
            encontre = TRUE;
        }else
            aux = aux ->sig;
    }
}

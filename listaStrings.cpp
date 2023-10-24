#include "listaStrings.h"


void crearListaString (listaStrings &LS){
    LS = NULL;
}

void eliminarListaString (listaStrings &LS){
    if(LS->sig != NULL)
        eliminarListaString(LS->sig);
    else
        if(LS->sig == NULL){
            strDestruir(LS->info);
            delete LS;
            LS = NULL;
        }
}

void insBackListaString (listaStrings &LS, string s){
    if (LS == NULL) {
        LS = new NodoST;
        strCrear(LS->info);
        strCop(LS->info,s);
        LS -> sig = NULL;
    } else insBackListaString(LS -> sig, s);
}

int cantidadStrings (listaStrings LS){
    if(LS == NULL)
        return 0;
    else return 1 + cantidadStrings(LS->sig);
}

void obtenerString (listaStrings LS, int pos, string &s){
    int contar = 1;
    listaStrings aux = LS;
    while(contar != pos){
        aux = aux->sig;
        contar++;
    }
    strCop(s,aux->info);
}

void partirString (string s, listaStrings &LS){
    string sb,primero,resto;
    strCrear(sb);
    strCrear(primero);
    strCrear(resto);
    if(s[0] != '\0'){
        eliminarBlancosPrincipio(s,sb);
        dividirString(sb,primero,resto);
        insBackListaString(LS,primero);
        strCop(s,resto);
        partirString(s,LS->sig);
    }
}

void ultimo (listaStrings LS, string &s){
    if(LS->sig == NULL)
        strCop(s,LS->info);
    else return ultimo(LS->sig,s);
}

boolean existeNombre (listaStrings LS, string s){
    if(LS == NULL)
        return FALSE;
    else if(strEq(s,LS->info))
        return TRUE;
    else return existeNombre(LS->sig, s);
}


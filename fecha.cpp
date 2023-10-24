#include "fecha.h"

void cargarFecha(fecha &f, int dia, int mes, int anio){
    f.dia = dia;
    f.mes = mes;
    f.anio = anio;
}

void desplegarFecha(fecha f){
    printf("%d/%d/%d", f.dia, f.mes, f.anio);
}

int darDia(fecha f){
    return f.dia;
}

int darMes(fecha f){
    return f.mes;
}

int darAnio(fecha f){
    return f.anio;
}

boolean validarFecha (fecha f){
    boolean valido = FALSE;
switch(f.mes){
        case 1:
        if(f.dia >= 1 && f.dia <=31){
            valido = TRUE;
        } else valido = FALSE;
        break;
        case 2:
        if((f.dia >= 1 && f.dia <=28) || ((f.dia >= 1 && f.dia <= 29) && f.anio%4==0)){
            valido = TRUE;
        } else valido = FALSE;
        break;
        case 3:
        if(f.dia >= 1 && f.dia <=31){
            valido = TRUE;
        } else valido = FALSE;
        break;
        case 4:
        if(f.dia >= 1 && f.dia <=30){
            valido = TRUE;
        } else valido = FALSE;
        break;
        case 5:
        if(f.dia >= 1 && f.dia <=31){
            valido = TRUE;
        } else valido = FALSE;
        break;
        case 6:
        if(f.dia >= 1 && f.dia <=30){
            valido = TRUE;
        } else valido = FALSE;
        break;
        case 7:
        if(f.dia >= 1 && f.dia <=31){
            valido = TRUE;
        } else valido = FALSE;
        break;
        case 8:
        if(f.dia >= 1 && f.dia <=31){
            valido = TRUE;
        } else valido = FALSE;
        break;
        case 9:
        if(f.dia >= 1 && f.dia <=30){
            valido = TRUE;
        } else (valido = FALSE);
        break;
        case 10:
        if(f.dia >= 1 && f.dia <=31){
            valido = TRUE;
        } else valido = FALSE;
        break;
        case 11:
        if(f.dia >= 1 && f.dia <=30){
            valido = TRUE;
        } else valido = FALSE;
        break;
        case 12:
        if(f.dia >= 1 && f.dia <=31){
            valido = TRUE;
        } else valido = FALSE;
        break;
        default: valido = FALSE; break;
    }

    return valido;
}

boolean compararFecha (fecha f1, fecha f2){
    boolean mayor = FALSE;

    int fec1 = f1.anio*365 + f1.mes*30 + f1.dia;
    int fec2 = f2.anio*365 + f2.mes*30 + f2.dia;

    if(fec1 >= fec2)
        mayor = TRUE;

    return mayor;
}

void bajarFecha (fecha fec, FILE * f){
    fwrite(&fec, sizeof(fecha), 1, f);
}

void subirFecha (fecha &fec, FILE * f){
    fread(&fec, sizeof(fecha), 1, f);
}

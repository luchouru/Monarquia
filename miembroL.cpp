#include "miembroL.h"

//CARGA

void cargarMiembroL (miembroL &L, boolean monarcaActual, boolean fueMonarca, boolean aspiranteAlTrono, boolean abdico, boolean estaVivo, fecha ascencion, fecha abdicacion, fecha fallecimiento, miembroA m){
    copiarMiembroA(L.m, m);
    L.monarcaActual = monarcaActual;
    L.fueMonarca = fueMonarca;
    L.aspiranteAlTrono = aspiranteAlTrono;
    L.abdico = abdico;
    L.estaVivo = estaVivo;
    L.ascencion = ascencion;
    L.abdicacion = abdicacion;
    L.fallecimiento = fallecimiento;
}

//DESPLEGAR

void mostrarMiembroL (miembroL L){
    string nombre, progenitor;
    strCrear(nombre);
    strCrear(progenitor);
    darNombre(L.m,nombre);
    darProgenitor(L.m,progenitor);

    print(nombre);
    printf(", ");

    if(darMiembroInicial(L.m))
		printf("primer monarca");
    else{
		printf("hijo/a de ");
        print(progenitor);
	}

    if(darMonarcaActual(L)){
        printf("\n\t    Monarca desde ");
        desplegarFecha(darFechaAscencion(L));
        printf(" hasta la actualidad");
    }

    if(darFueMonarca(L)){
        printf("\n\t    Monarca desde el ");
        desplegarFecha(darFechaAscencion(L));
        printf(" hasta el ");
        if(darAbdico(L))
            desplegarFecha(darFechaAbdicacion(L));
        else desplegarFecha(darFechaFallecimiento(L));
    }

    if(darAspiranteAlTrono(L))
        printf("\n\t    Aspirante al trono");

    if(darAbdico(L)){
        printf("\n\t    Abdico el ");
        desplegarFecha(darFechaAbdicacion(L));
    }

    if(!darEstaVivo(L)){
        printf("\n\t    Fallecio el ");
        desplegarFecha(darFechaFallecimiento(L));
    }
}

void listarDatosAspirantes (miembroL L){
    string nombre, progenitor;
    strCrear(nombre);
    strCrear(progenitor);
    darNombre(L.m,nombre);
    darProgenitor(L.m,progenitor);

    print(nombre);
    printf(", ");
    print(progenitor);
}

void mostrarSoloMonarcas (miembroL L){
    string nombre;
    strCrear(nombre);
    darNombre(L.m,nombre);

    print(nombre);

    if(darFueMonarca(L)){
        printf(" fue monarca desde ");
        desplegarFecha(darFechaAscencion(L));
        printf(" hasta ");
        if(darAbdico(L)){
            desplegarFecha(darFechaAbdicacion(L));
            printf(" (abdico)");
        }else{
            desplegarFecha(darFechaFallecimiento(L));
            printf(" (fallecio)");
        }
    }
    else if(darMonarcaActual(L)){
        printf(" monarca desde ");
        desplegarFecha(darFechaAscencion(L));
        printf(" hasta la actualidad");
    }
}

void mostrarSoloAspirantes (miembroL L){
        string nombre, progenitor;
        strCrear(nombre);
        strCrear(progenitor);
        darNombre(L.m,nombre);
        darProgenitor(L.m,progenitor);

        print(nombre);
        printf(" hijo/a de ");
        print(progenitor);
}

//SELECTORAS

boolean darMonarcaActual (miembroL L){
    return L.monarcaActual;
}

boolean darFueMonarca (miembroL L){
    return L.fueMonarca;
}

boolean darAspiranteAlTrono (miembroL L){
    return L.aspiranteAlTrono;
}

boolean darAbdico (miembroL L){
    return L.abdico;
}

boolean darEstaVivo (miembroL L){
    return L.estaVivo;
}

fecha darFechaAscencion (miembroL L){
    return L.ascencion;
}

fecha darFechaAbdicacion (miembroL L){
    return L.abdicacion;
}

fecha darFechaFallecimiento (miembroL L){
    return L.fallecimiento;
}

void darNombreL (miembroL L, string &nom){
    darNombre(L.m,nom);
}

void darProgenitorL (miembroL L, string &prog){
    darProgenitor(L.m,prog);
}

//LEVANTAR, BAJAR Y DESTRUIR

void bajarMiembroL (miembroL L, FILE * f){
    bajarMiembroA(L.m, f);
    fwrite(&L.monarcaActual, sizeof(boolean), 1, f);
    fwrite(&L.fueMonarca, sizeof(boolean), 1, f);
    fwrite(&L.aspiranteAlTrono, sizeof(boolean), 1, f);
    fwrite(&L.abdico, sizeof(boolean), 1, f);
    fwrite(&L.estaVivo, sizeof(boolean), 1, f);
    fwrite(&L.ascencion, sizeof(fecha), 1, f);
    fwrite(&L.abdicacion, sizeof(fecha), 1, f);
    fwrite(&L.fallecimiento, sizeof(fecha), 1, f);
}

void subirMiembroL (miembroL &L, FILE * f){
    subirMiembroA(L.m, f);
    fread(&L.monarcaActual, sizeof(boolean), 1, f);
    fread(&L.fueMonarca, sizeof(boolean), 1, f);
    fread(&L.aspiranteAlTrono, sizeof(boolean), 1, f);
    fread(&L.abdico, sizeof(boolean), 1, f);
    fread(&L.estaVivo, sizeof(boolean), 1, f);
    fread(&L.ascencion, sizeof(fecha), 1, f);
    fread(&L.abdicacion, sizeof(fecha), 1, f);
    fread(&L.fallecimiento, sizeof(fecha), 1, f);
}

void destruirMiembroL (miembroL &L){
    destruirMiembroA(L.m);
}

//MODIFICADORAS

void modificarMonarcaActual (miembroL &L, boolean mActual){
    L.monarcaActual = mActual;
}

void modificarFueMonarca (miembroL &L){
    L.fueMonarca = TRUE;
}

void modificarAspiranteAlTrono (miembroL &L){
    L.aspiranteAlTrono = FALSE;
}

void modificarAbdico (miembroL &L){
    L.abdico = TRUE;
}

void modificarEstaVivo (miembroL &L){
    L.estaVivo = FALSE;
}

void modificarFechaAscencion (miembroL &L, fecha asc){
    L.ascencion = asc;
}

void modificarFechaAbdicacion (miembroL &L, fecha abd){
    L.abdicacion = abd;
}

void modificarFechaFallecimiento (miembroL &L, fecha fall){
    L.fallecimiento = fall;
}

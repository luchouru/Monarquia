#include "respaldoFecha.h"

void bajarFecGlobal (fecha fec, string nomArch){
    FILE * f = fopen (nomArch, "wb");
    bajarFecha (fec, f);
    fclose (f);
}

void levantarFecGlobal (fecha &fec, string nomArch){
    FILE * f = fopen (nomArch, "rb");
    fecha buffer;
    subirFecha(fec, f);
    fclose (f);
}

boolean existeArchivoFecha (string nomArch){
    boolean existeArchivo = TRUE;
    FILE * f = fopen (nomArch, "rb");
    if (f == NULL)
        existeArchivo = FALSE;
    else
        fclose (f);
    return existeArchivo;
}

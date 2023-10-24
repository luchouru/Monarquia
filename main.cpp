#include <stdio.h>
#include "listaStrings.h"
#include "listaMiembros.h"
#include "ABBMonarquia.h"
#include "respaldoFecha.h"

int main()
{
    string comando,pos1,pos2,pos3,pos4,pos5,sucesor1;
    string archABB= "abb.txt";
    string archLista = "lista.txt";
    string archFecha = "fecha.txt";
    strCrear(comando);
    strCrear(pos1);
    strCrear(pos2);
    strCrear(pos3);
    strCrear(pos4);
    strCrear(pos5);
    listaStrings ls;
    fecha f,fall,abd,asc,fallece,abdica;
    cargarFecha(asc,00,00,0000);
    cargarFecha(fall,00,00,0000);
    cargarFecha(abd,00,00,0000);
    miembroA a;
    miembroL l, auxL;
    string progenitor;
    strCrear(progenitor);
    ABBMonarquia abbm;
    listaMiembros lm;
    crearABB(abbm);
    crearLista(lm);
    fecha ultimaFecha;
    cargarFecha(ultimaFecha,00,00,0000);
    boolean terminar = FALSE;


    do{
    printf("\nIngrese comando: ");
    strCrear(comando);
    scan(comando);
    crearListaString(ls);
    partirString(comando,ls);
    obtenerString(ls,1,pos1);

    if(strEq(pos1,"iniciar")){
        if(listaVacia(lm) && ABBVacio(abbm)){
            if(cantidadStrings(ls) == 3){
                obtenerString(ls,2,pos2);
                if(validarFormatoFecha(pos2)){
                    f = convertirFecha(pos2);
                    if(validarFecha(f)){
                        obtenerString(ls,3,pos3);
                        if(soloLetras(pos3)){
                            convertirMayus(pos3);
                            cargarMiembroA(a,pos3,f,TRUE,progenitor);
                            cargarMiembroL(l,TRUE,FALSE,FALSE,FALSE,TRUE,f,abd,fall,a);
                            insertABB(abbm,a);
                            insFront(lm,l);
                            ultimaFecha = f;
                            printf("Resultado:  Dinastia iniciada\n");
                        }else printf("Error: el nombre solo puede contener letras\n");
                    }else printf("Error: La fecha ingresada no pertenece a un dia valido\n");
                }else printf("Error: El formato de la fecha ingresada no es correcto\n");
            }else printf("Error: La cantidad de parametros es incorrecta\n");
        }else printf("Error: La monarquia ya fue iniciada previamente\n");
    }
    else if (strEq(pos1,"nacimiento")){
        if(cantidadStrings(ls) == 5){
            obtenerString(ls,2,pos2);
            if(validarFormatoFecha(pos2)){
                f = convertirFecha(pos2);
                if(validarFecha(f)){
                    if(compararFecha(f,ultimaFecha)){
                        obtenerString(ls,3,pos3);
                        if(soloLetras(pos3)){
                            convertirMayus(pos3);
                            if(existeMiembro(abbm,pos3)){
                                obtenerString(ls,4,pos4);
                                 if(soloFlecha(pos4)){
                                    obtenerString(ls,5,pos5);
                                    if(soloLetras(pos5)){
                                        convertirMayus(pos5);
                                        if(!existeMiembro(abbm,pos5)){
                                            cargarMiembroA(a,pos5,f,FALSE,pos3);
                                            insertABB(abbm,a);
                                            if(existeMonarca(lm)){
                                                cargarMiembroL(l,FALSE,FALSE,TRUE,FALSE,TRUE,asc,abd,fall,a);
                                                nacimiento(lm,l);
                                                if(compararPosicion(lm,pos5))
                                                    abdicarAlNacer(lm,pos5,f);
                                            }else {
                                                cargarMiembroL(l,TRUE,FALSE,FALSE,FALSE,TRUE,f,abd,fall,a);
                                                nacimiento(lm,l);
                                            }
                                                ultimaFecha = f;
                                                printf("Resultado:  Nacimiento registrado\n");
                                        }else printf("Error: Ya existe un miembro con el nombre del nuevo integrante\n");
                                    }else printf("Error: El nombre solo puede contener letras\n");
                                }else printf("Error: Debe utilizar -> para señalar del progenitor al nuevo miembro de la familia real\n");
                            }else printf("Error: No existe miembro con el nombre del progenitor\n");
                        }else printf("Error: Los nombres solo puede contener letras\n");
                    }else printf("Error: Existen fechas registradas posteriores a la fecha de nacimiento\n");
                }else printf("Error: La fecha ingresada no pertenece a un dia valido\n");
            }else printf("Error: El formato de la fecha ingresada no es correcto\n");
        }else printf("Error: La cantidad de parametros es incorrecta\n");
    }
	else if (strEq(pos1,"fallecimiento")){
        if(cantidadStrings(ls) == 3){
            obtenerString(ls,2,pos2);
            if(validarFormatoFecha(pos2)){
                fallece=convertirFecha(pos2);
                if(validarFecha(fallece)){
                    if(compararFecha(fallece,ultimaFecha)){
						obtenerString(ls,3,pos3);
                        if(soloLetras(pos3)){
							convertirMayus(pos3);
                            if(existeMiembro(abbm,pos3)){
                                auxL = buscarMiembro(lm,pos3);
                                if(darEstaVivo(auxL)){
                                    registrarFallecimiento(lm,pos3,fallece);
                                    ultimaFecha = fallece;
									printf("Resultado:  Fallecimiento ingresado correctamente\n");
                                    if(darAspiranteAlTrono(auxL))
                                        fallecimientoAspirante(lm,pos3);
									else{
                                        if(darMonarcaActual(auxL)){
                                            fallecimientoMonarca(lm,pos3);
                                            if(existeSucesion(lm)){
                                            strCrear(sucesor1);
                                            sucesor(lm,sucesor1);
                                            deAspiranteAMonarca(lm,sucesor1,fallece);
                                            }else printf("Precaucion: No existen miembros con la capacidad de acceder al trono\n");
                                        }
									}
                                }else printf("Error: El miembro ya se encuentra fallecido\n");
                            }else printf("Error: No existe miembro\n");
                        }else printf("Error: El nombre solo puede contener letras\n");
                    }else printf("Error: Existen fechas registradas posteriores a la fecha de fallecimiento\n");
                }else printf("Error: La fecha ingresada no pertenece a un dia valido\n");
            }else printf("Error: El formato de la fecha ingresada no es correcto\n");
        }else printf("Error: La cantidad de parametros es incorrecta\n");
    }
    else if (strEq(pos1,"abdicacion")){
        if(cantidadStrings(ls) == 3){
            obtenerString(ls,2,pos2);
            if(validarFormatoFecha(pos2)){
                abdica = convertirFecha(pos2);
                if(validarFecha(abdica)){
                    if(compararFecha(abdica,ultimaFecha)){
						obtenerString(ls,3,pos3);
                        if(soloLetras(pos3)){
							convertirMayus(pos3);
                            if(existeMiembro(abbm,pos3)){
                                auxL = buscarMiembro(lm,pos3);
                                if(darEstaVivo(auxL)){
									if(!darAbdico(auxL)){
										if(darMonarcaActual(auxL)){
                                            abdicacionMonarca(lm,pos3,abdica);
                                            ultimaFecha = abdica;
											printf("Resultado: Abdicacion ingresada correctamente\n");
											if(existeSucesion(lm)){
                                                strCrear(sucesor1);
                                                sucesor(lm,sucesor1);
                                                deAspiranteAMonarca(lm,sucesor1,abdica);
                                            }else printf("Precaucion: No existen miembros con la capacidad de acceder al trono\n");

										}else{
											abdicacionAspirante(lm,pos3,abdica);
                                            ultimaFecha = abdica;
											printf("Resultado: Abdicacion ingresada correctamente\n");
											}
                                    }else printf("Error: El miembro abdico anteriormente\n");
								}else printf("Error: El miembro se encuentra fallecido\n");
                            }else printf("Error: No existe miembro\n");
                        }else printf("Error: El nombre solo puede contener letras\n");
                    }else printf("Error: Existen fechas registradas posteriores a la fecha de abdicacion\n");
                }else printf("Error: La fecha ingresada no pertenece a un dia valido\n");
            }else printf("Error: El formato de la fecha ingresada no es correcto\n");
        }else printf("Error: La cantidad de parametros es incorrecta\n");
    }
    else if(strEq(pos1,"miembros")){
                if(cantidadStrings(ls) == 1){
                    if(!ABBVacio(abbm)){
                        printf("Resultado:\n");
                        listarOrdenado(abbm);
                    }else printf("Error: No hay miembros registrados\n");
                }else printf("Error: Cantidad de parametros incorrecta\n");
    }
    else if(strEq(pos1,"monarcas")){
                if(cantidadStrings(ls) == 1){
                    if(!listaVacia(lm)){
                        printf("Resultado:");
                        desplegarMonarcas(lm);
                    }else printf("Error: Aun no fue cargado ningun dato\n");
                }else printf("Error: Cantidad de parametros incorrecta\n");
    }
    else if(strEq(pos1,"aspirantes")){
                if(cantidadStrings(ls) == 1){
                    if(!listaVacia(lm)){
                        if(existeSucesion(lm)){
                            printf("Resultado:");
                            desplegarAspirantes(lm);
                        }else printf("Error: No hay aspirantes al trono\n");
                    }else printf("Error: No hay miembros registrados\n");
                }else printf("Error: Cantidad de parametros incorrecta\n");
    }
    else if(strEq(pos1,"historial")){
                if(cantidadStrings(ls) == 1){
                    if(!listaVacia(lm)){
                        printf("Resultado:");
                        desplegarHistorial(lm);
                    }else printf("Error: No hay miembros registrados\n");
                }else printf("Error: Cantidad de parametros incorrecta\n");
	}
	else if(strEq(pos1,"respaldar")){
                if(cantidadStrings(ls) == 1){
                        if(!ABBVacio(abbm)){
                                bajarABB(abbm,archABB);
                                if(!listaVacia(lm)){
                                    bajarLista(lm,archLista);
                                    bajarFecGlobal(ultimaFecha,archFecha);
                                    printf("Resultado: Informacion respaldada con exito\n");
                                }else printf("Error: No se encontro informacion de sucesion para respaldar\n");
                        }else printf("Error: No se encontro informacion de miembros familiares para respaldar\n");
                }else printf("Error: Cantidad de parametros incorrecta\n");
	}
	else if(strEq(pos1,"recuperar")){
                if(cantidadStrings(ls) == 1){
                        if(existeArchivoABB(archABB)){
                                if(!archivoVacioABB(archABB)){
                                    levantarABB(abbm,archABB);
                                    if(existeArchivoLista(archLista)){
                                            if(!vacioArchivoLista(archLista)){
                                                 levantarLista(lm,archLista);
                                                 if(existeArchivoFecha(archFecha))
                                                    levantarFecGlobal(ultimaFecha,archFecha);
                                                 printf("Resultado: Datos recuperados con exito\n");
                                            }else printf("Error: No se encontraron datos respaldados\n");
                                    }else printf("Error: No se econtro archivo con datos de sucesion respaldado\n");
                                }else printf("Error: No se encontraron datos respaldados\n");
                        }else printf("Error: No se encontro archivo con datos respaldados\n");
                }else printf("Error: Cantidad de parametros incorrecta\n");
	}
    else if(strEq(pos1,"salir")){
        if(cantidadStrings(ls) == 1){
            if(!ABBVacio(abbm))
                eliminarArbol(abbm);
            if(!listaVacia(lm))
                eliminarLista(lm);
        printf("Resultado: Hasta la proxima\n");
        terminar = TRUE;
        }else printf("Error: Cantidad de parametros incorrecta\n");
    }
    else printf("Comando incorrecto\n");

    eliminarListaString(ls);

    }while(!terminar);


}

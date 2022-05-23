#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include "ArrayFecha.h"
#include "ArrayEmpresa.h"
#include "ArrayTipo.h"
#include "ArrayMicro.h"
#include "ArrayDestino.h"
#include "ArrayViaje.h"
#include "ArrayChofer.h"


//int informarPreciosMicro(eMicro vec[], int tam, eViaje vecv[], int tamv, eDestino vecd[], int tamd);
int informarDestinoMicros(eViaje vec[], int tamv, eDestino vecd[], int tamd);
int encontrarDestinoPorId(eDestino vec[], int tam, int id, int* pIndex);



int menuModificarMicro();
int menu();

int viajesPorFecha(eViaje vec[], int tam)
{
    int todoOk = 0;

    eFecha auxFecha;

    if(vec != NULL && tam > 0)
        {
        printf("\nIngrese fecha para ver los viajes realizados: \n");
        printf("Ingrese dia: ");
        scanf("%d", &auxFecha.dia);
        printf("Ingrese mes: ");
        scanf("%d", &auxFecha.mes);
        printf("Ingrese anio: ");
        scanf("%d", &auxFecha.anio);
        for(int i = 0; i < tam; i++)
        {
            if(vec[i].fecha.dia == auxFecha.dia && vec[i].fecha.mes == auxFecha.mes && vec[i].fecha.anio == auxFecha.anio)
            {
                printf("\n\nLos viajes realizados en esa fecha son: \n");
                printf("Id viaje    id micro    id destino \n");
                printf("    %6d     %4d     %6d",
                        vec[i].id,
                        vec[i].idMicro,
                        vec[i].idDestino
                );
            }else{
                printf("\n\nNo hay viajes en la fecha ingresada\n");
            }
        }

    }

    return todoOk;
}

int informarDestinoMicros(eViaje vec[], int tamv, eDestino vecd[], int tamd){
    int id;
    int indice;
    int todoOk = 0;

    informarDestino(vecd, tamd);

    printf("\nIngrese el id del destino: ");
    scanf("%d", &id);

        if(encontrarDestinoPorId(vecd, tamd, id, &indice))
        {
            if(id == -1)
            {
                printf("No hay un destino con id %d\n", id);
            }
            else
            {



                for(int i = 0; i < tamv; i++)
                    {
                    if(vec != NULL && vec[i].idDestino == id)
                    {
                        printf("\nId micro  Fecha\n");
                        printf(" %3d   %02d/%02d/%d\n\n",
                        vec[i].idMicro,
                        vec[i].fecha.dia,
                        vec[i].fecha.mes,
                        vec[i].fecha.anio
                        );
                    }
                }
            }





    todoOk = 1;
    }

    return todoOk;
}

int informarViajesMicro(eMicro vec[], int tam, eViaje vecv[], int tamv){
    int id;
    int indice;
    int todoOk = 0;

    informarMicros(vec, tam);

    printf("\nIngrese el id del micro: ");
    scanf("%d", &id);

        if(encontrarMicroPorId(vec, tam, id, &indice))
        {
            if(id == -1)
            {
                printf("No hay un micro con id %d\n", id);
            }
            else
            {
                for(int i = 0; i < tam; i++)
                    {
                    if(vecv != NULL && vecv[i].idMicro == id)
                    {
                        printf(" %3d   %3d    %10d   %02d/%02d/%d\n\n",
                        vecv[i].id,
                        vecv[i].idMicro,
                        vecv[i].idDestino,
                        vecv[i].fecha.dia,
                        vecv[i].fecha.mes,
                        vecv[i].fecha.anio
                        );
                    }
                }
            }

    todoOk = 1;
    }

    return todoOk;
}

int informarEmpresaMenosMicros(eMicro vec[], int tam, eEmpresa vecE[], int tame){
    int todoOk = 0;
    int empresaA = 0;
    int empresaB = 0;
    int empresaC = 0;
    int empresaD = 0;

    int empresaMenorCantidad = 1000;

    informarEmpresa(vecE, tame);

    for(int i = 0; i<tam; i++){
        if(!vec[i].isEmpty){
            if(vec[i].idEmpresa == 1000)
            {
                empresaA++;
            }

            if(vec[i].idEmpresa == 1001)
            {
                empresaB++;
            }

            if(vec[i].idEmpresa == 1002)
            {
                empresaC++;
            }

            if(vec[i].idEmpresa == 1003)
            {
                empresaD++;
            }
        }
    }

    if(empresaA < empresaMenorCantidad){
        empresaMenorCantidad = empresaA;
    }
    if(empresaB < empresaMenorCantidad){
        empresaMenorCantidad = empresaB;
    }
    if(empresaC < empresaMenorCantidad){
        empresaMenorCantidad = empresaC;
    }
    if(empresaD < empresaMenorCantidad){
        empresaMenorCantidad = empresaD;
    }

    printf("\n\nLa empresa con menor cantidad de micros es: %d", empresaMenorCantidad);

        todoOk = 1;

        return todoOk;
}


int informarMasCapacidad(eMicro vec[], int tam){
    int todoOk = 0;

	informarMicros(vec, tam);

    for(int i = 0; i<tam; i++){
        if(!vec[i].isEmpty && vec[i].capacidad < 50)
        {
            printf("\nEste micro puede tener mas capacidad\n");
            printf(" %3d   %3d    %10d   %5d\n",
            vec[i].id,
            vec[i].idEmpresa,
            vec[i].idTipo,
            vec[i].capacidad
            );
        }

        todoOk = 1;
    }

    return todoOk;
}


int informarMicroPorEmpresa(eMicro vec[], int tam, eEmpresa vecE[], int tame){
    int todoOk = 0;

        if(vec != NULL && tam > 0)
        {
            for(int i = 0; i < tam; i++){
                if(vec[i].idEmpresa == 1000){
                    printf(" %3d   %3d    %10d   %5d\n",
                    vec[i].id,
                    vec[i].idEmpresa,
                    vec[i].idTipo,
                    vec[i].capacidad
                    );
                }
            }

            for(int i = 0; i < tam; i++){
                if(vec[i].idEmpresa == 1001){
                    printf(" %3d   %3d    %10d   %5d\n",
                    vec[i].id,
                    vec[i].idEmpresa,
                    vec[i].idTipo,
                    vec[i].capacidad
                    );
                }
            }

            for(int i = 0; i < tam; i++){
                if(vec[i].idEmpresa == 1002){
                    printf(" %3d   %3d    %10d   %5d\n",
                    vec[i].id,
                    vec[i].idEmpresa,
                    vec[i].idTipo,
                    vec[i].capacidad
                    );
                }
            }

            for(int i = 0; i < tam; i++){
                if(vec[i].idEmpresa == 1003){
                    printf(" %3d   %3d    %10d   %5d\n",
                    vec[i].id,
                    vec[i].idEmpresa,
                    vec[i].idTipo,
                    vec[i].capacidad
                    );
                }
            }


    todoOk = 1;
    }

    return todoOk;
}

int totalPromedioVip(eMicro vec[], int tam){
    int todoOk;
    float promedio;
    float cantVip = 0;
    float cantMicros = 0;

    if(vec != NULL && tam > 0){
        for(int i=0; i < tam; i++){
            if(vec[i].isEmpty == 0){
            	cantMicros++;
            }
        }
    }

    if(vec != NULL && tam > 0){
        for(int i=0; i < tam; i++){
            if(vec[i].isEmpty == 0 && vec[i].idTipo == 5003){
            	cantVip++;
            }
        }

        promedio = cantMicros / cantVip;


        informarTotalPromedioVip(vec, tam, cantMicros, promedio);

        todoOk = 1;
    }

    return todoOk;
}

int informarTotalPromedioVip(eMicro vec[], int len, float cantMicro, float promedio){
    int todoOk = 0;

    if(vec != NULL && len > 0){
        printf("\n\nTotal micros: %.0f", cantMicro);
        printf("\nPromedio de VIP: %.2f", promedio);

        todoOk = 1;
    }

    return todoOk;
}

int informarTipoMicro(eMicro vec[], int tam, eTipo vect[], int tamt){
    int id;
    int indice;
    int todoOk = 0;

    informarTipo(vect, tamt);

    printf("\nIngrese el id del tipo: ");
    scanf("%d", &id);

        if(encontrarTipoPorId(vect, tamt, id, &indice))
        {
            if(id == -1)
            {
                printf("No hay un tipo con id %d\n", id);
            }
            else
            {
                for(int i = 0; i < tam; i++){
                    if(vec != NULL){
                        printf(" %3d   %3d    %10d   %5d\n\n",
                        vec[indice].id,
                        vec[indice].idEmpresa,
                        vec[indice].idTipo,
                        vec[indice].capacidad
                        );
                    }
                }
            }

    todoOk = 1;
    }

    return todoOk;
}

int informarEmpresaMicro(eMicro vec[], int tam, eEmpresa vecE[], int tame){
    int id;
    int indice;
    int todoOk = 0;

    informarEmpresa(vecE, tame);

    printf("\nIngrese el id de la empresa: ");
    scanf("%d", &id);

        if(encontrarEmpresaPorId(vecE, tame, id, &indice))
        {
            if(id == -1)
            {
                printf("No hay una empresa con id %d\n", id);
            }
            else
            {
                for(int i = 0; i < tam; i++){
                    if(vec != NULL){
                        printf(" %3d   %3d    %10d   %5d\n\n",
                        vec[indice].id,
                        vec[indice].idEmpresa,
                        vec[indice].idTipo,
                        vec[indice].capacidad
                        );
                    }
                }
            }

    todoOk = 1;
    }

    return todoOk;
}

int encontrarDestinoPorId(eDestino vec[], int tam, int id, int* pIndex){
    int todoOk = 0;

    if(vec != NULL && tam > 0 && pIndex != NULL && id > 0){
        *pIndex = -1;
        for(int i = 0; i<tam; i++){
            if(vec[i].isEmpty == 0 && vec[i].id == id){
                *pIndex = i;

                break;
            }
        }
        todoOk = 1;
    }

	return todoOk;
}

int encontrarTipoPorId(eTipo vec[], int tam, int id, int* pIndex){
    int todoOk = 0;

    if(vec != NULL && tam > 0 && pIndex != NULL && id > 0){
        *pIndex = -1;
        for(int i = 0; i<tam; i++){
            if(vec[i].isEmpty == 0 && vec[i].id == id){
                *pIndex = i;

                break;
            }
        }
        todoOk = 1;
    }

	return todoOk;
}

int encontrarEmpresaPorId(eEmpresa vec[], int tam, int id, int* pIndex){
    int todoOk = 0;

    if(vec != NULL && tam > 0 && pIndex != NULL && id > 0){
        *pIndex = -1;
        for(int i = 0; i<tam; i++){
            if(vec[i].isEmpty == 0 && vec[i].id == id){
                *pIndex = i;

                break;
            }
        }
        todoOk = 1;
    }

	return todoOk;
}

int ordenarMicros(eMicro vec[], int tam){
    int todoOk = 0;
    eMicro auxMicro;

    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {
                if( ((((vec[i].idEmpresa > vec[j].idEmpresa) && (vec[i].capacidad > vec[j].capacidad))
                || ((vec[i].capacidad != vec[j].capacidad) &&(vec[i].capacidad > vec[j].capacidad)))))

                {
                    auxMicro = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxMicro;
                }
            }
        }
        todoOk = 1;
    }

    return todoOk;
}

int altaViaje(eViaje vec[], int tam, eMicro vecM[], int tamm, eDestino vecD[], int tamd, int* pId){
    int todoOk = 0;
    int indice = 1;
    int idMicro;
    int idDestino;

    eViaje nuevoViaje;

    if(vec != NULL && tam > 0 && pId != NULL)
    {
        if( buscarViajeLibre(vec, tam, &indice) )
        {

            if(indice != 0)
            {
                printf("No hay lugar en el sistema\n");
            }
            else
            {
                informarMicros(vecM, tamm);
                printf("\nIngrese el id del micro: ");
                scanf("%d", &idMicro);

                nuevoViaje.idMicro = idMicro;


                informarDestino(vecD, tamd);
                printf("\nIngrese el id del destino: ");
                scanf("%d", &idDestino);
                while(idDestino < 20000 || idDestino > 20004){
                    printf("El id ingresado no es correcto. Reingresar:");
                    scanf("%d", &idDestino);
                }
                nuevoViaje.idDestino = idDestino;


                nuevoViaje.id = indice + 1;
                *pId = *pId + 1;

                aniadirViaje(vec, tam, nuevoViaje.id, nuevoViaje.idMicro, nuevoViaje.idDestino);
                todoOk = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema con los parametros\n");
        }
    }

    return todoOk;
}

int aniadirViaje(eViaje vec[], int tam, int id, int idMicro, int idDestino){
    int todoOk = 0;
    int pIndex;

    if( buscarViajeLibre(vec, tam, &pIndex) ){
        vec[pIndex].id = id;
        vec[pIndex].idMicro = idMicro;
        vec[pIndex].idDestino = idDestino;
        vec[pIndex].isEmpty = 0;

        todoOk = 1;
    }

    return todoOk;
}

int removerMicro(eMicro vec[], int tam, int id){
    int todoOk = -1;
    char confirmar;
    int indice;


    encontrarMicroPorId(vec, tam, id, &indice);

    if(vec != NULL && tam > 0){
        if(indice == -1){
            printf("No hay un micro con id %d\t", id);
        }else{
            if(vec != NULL){
                    printf(" %3d   %3d    %10d   %5d\n",
                    vec[indice].id,
                    vec[indice].idEmpresa,
                    vec[indice].idTipo,
                    vec[indice].capacidad
                    );
                }
            printf("Confirmar baja? (S/N): ");
            fflush(stdin);
            scanf("%c", &confirmar);

            if(confirmar != 's' && confirmar != 'S'){
                printf("Baja cancelada por el usuario\n");
            }else{
                vec[indice].isEmpty = 1;
                printf("Baja realizada con el exito!!!\n");
                todoOk = 1;
            }
        }
    }

    return todoOk;
}

int encontrarMicroPorId(eMicro vec[], int tam, int id, int* pIndex){
    int todoOk = 0;

    if(vec != NULL && tam > 0 && pIndex != NULL && id > 0){
        *pIndex = -1;
        for(int i = 0; i<tam; i++){
            if(vec[i].isEmpty == 0 && vec[i].id == id){
                *pIndex = i;

                break;
            }
        }
        todoOk = 1;
    }

	return todoOk;
}

int menuModificarMicro()
{
    int opcion;


    printf("     *** Campos a modificar ***\n");
    printf("1- Id de la empresa\n");
    printf("2- Id del tipo\n");
    printf("3- Capacidad\n");
    printf("4- Chofer\n");
    printf("5- Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int modificarMicro(eMicro vec[], int tam, eEmpresa vecE[], int tame, eTipo vecT[], int tamt){
    int todoOk = 0;
    int indice;
    int id;
    char salir = 'n';
    int idEmpresa;
    int idTipo;
    int capacidad;
    int idChofer;
    char auxCad[100];
    char sexo;


    if(vec != NULL && tam > 0){
        printf("Ingrese id: ");
        scanf("%d", &id);
        if(encontrarMicroPorId(vec, tam, id, &indice))
        {
            if(id == -1)
            {
                printf("No hay un micro con id %d\n", id);
            }
            else
            {
                if(vec != NULL){
                    printf(" %3d   %3d    %10d   %5d\n",
                    vec[indice].id,
                    vec[indice].idEmpresa,
                    vec[indice].idTipo,
                    vec[indice].capacidad
                    );
                }

                do
                {
                    switch(menuModificarMicro())
                    {

                    case 1:
                        informarEmpresa(vecE, tame);
                        printf("\nIngrese el id de la empresa: ");
                        scanf("%d", &idEmpresa);
                        while(idEmpresa < 1000 || idEmpresa > 1004){
                            printf("El id ingresado no es correcto. Reingresar:");
                            scanf("%d", &idEmpresa);
                        }
                        vec[id].idEmpresa = idEmpresa;

                        break;

                    case 2:
                        informarTipo(vecT, tamt);
                        printf("\nIngrese el id del tipo: ");
                        scanf("%d", &idTipo);
                        while(idTipo < 5000 || idTipo > 5004){
                            printf("El id ingresado no es correcto. Reingresar:");
                            scanf("%d", &idTipo);
                        }
                        vec[id].idTipo = idTipo;

                    case 3:
                        printf("\nIngrese el la capacidad del micro: ");
                        scanf("%d", &capacidad);
                        while(capacidad < 1 || capacidad > 50){
                            printf("El numero ingresado no es correcto. Reingresar:");
                            scanf("%d", &capacidad);
                        }
                        vec[id].capacidad = capacidad;

                        break;

                    case 4:
                        printf("\nIngrese el id del chofer: ");
                        scanf("%d", &idChofer);
                        while(idChofer < 0){
                            printf("\nId incorrecto. Reingresar: ");
                            scanf("%d", &idChofer);
                        }
                        vec[id].chofer.id = idChofer;

                        printf("\nIngrese el nombre del chofer: ");
                        gets(auxCad);
                        while(strlen(auxCad) > 51)
                            {
                                printf("Nombre demasiado largo. Reingrese nombre: ");
                                fflush(stdin);
                                gets(auxCad);
                            }
                        strcpy(vec[id].chofer.nombre, auxCad);

                        printf("\nIngrese el sexo del chofer (f/m): ");
                        fflush(stdin);
                        scanf("%c", &sexo);
                        while(sexo != 'f' && sexo != 'm')
                            {
                                printf("Lo ingresado no es valido. Reingrese sexo: ");
                                fflush(stdin);
                                scanf("%c", &sexo);
                            }
                        vec[id].chofer.sexo = sexo;

                        break;

                    case 5:
                        salir = 's';

                        break;

                    default: printf("\nLa opcion ingresada no existe\n");
                    }

                }while(salir != 's');
            }
        }
        else
        {
            printf("Ocurrio un problema al buscar pasajero\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int informarViajes(eViaje vec[], int tam){
    int todoOk = 0;
	int bandera = 0;

    if(vec != NULL && tam > 0){
        printf("\t\t *** Listado de viajes *** \n\n");
        printf("  Id   Id micro        Id destino");
        printf("\n-------------------------------------------------\n");
        for(int i = 0; i<tam; i++){
            if(!vec[i].isEmpty)
            {
                if(vec != NULL){
                    printf(" %3d   %3d    %10d\n",
                    vec[i].id,
                    vec[i].idMicro,
                    vec[i].idDestino
                );
                }
                bandera = 1;
            }
        }

        if(bandera == 0){
            printf("\nNo hay viajes en el sistema\n");
        }

        todoOk = 1;
    }

    return todoOk;
}

int informarMicros(eMicro vec[], int tam){
    int todoOk = 0;
	int bandera = 0;

    if(vec != NULL && tam > 0){
        printf("\t\t *** Listado de micros *** \n\n");
        printf("  Id   Id empresa        Id tipo     Capacidad");
        printf("\n--------------------------------------------------------------\n");
        for(int i = 0; i<tam; i++){
            if(!vec[i].isEmpty)
            {
                if(vec != NULL){
                    printf(" %3d   %3d    %10d   %5d\n",
                    vec[i].id,
                    vec[i].idEmpresa,
                    vec[i].idTipo,
                    vec[i].capacidad
                );
                }
                bandera = 1;
            }
        }

        if(bandera == 0){
            printf("\nNo hay micros en el sistema\n");
        }

        todoOk = 1;
    }

    return todoOk;
}

int informarDestino(eDestino vec[], int tam){
    int todoOk = 0;
	int bandera = 0;

    if(vec != NULL && tam > 0){
        printf("\t\t *** Listado de destinos *** \n\n");
        printf("  Id   Descripcion      Precio");
        printf("\n------------------------------\n");
        for(int i = 0; i<tam; i++){
                if(vec != NULL){
                    printf(" %3d   %-12s    %.2f\n",
                    vec[i].id,
                    vec[i].desc,
                    vec[i].precio
                );
                }

                bandera = 1;
        }
        if(bandera == 0){
            printf("\nNo hay destinos en el sistema\n");
        }

        todoOk = 1;
    }

    return todoOk;
}

int informarEmpresa(eEmpresa vec[], int tam){
    int todoOk = 0;
	int bandera = 0;

    if(vec != NULL && tam > 0){
        printf("\t\t *** Listado de empresas *** \n\n");
        printf("  Id   Descripcion");
        printf("\n------------------------------\n");
        for(int i = 0; i<tam; i++){
                if(vec != NULL){
                    printf(" %3d   %-12s\n",
                    vec[i].id,
                    vec[i].desc
                );
                }

                bandera = 1;
        }
        if(bandera == 0){
            printf("\nNo hay empresas en el sistema\n");
        }

        todoOk = 1;
    }

    return todoOk;
}

int informarTipo(eTipo vec[], int tam){
    int todoOk = 0;
	int bandera = 0;

    if(vec != NULL && tam > 0){
        printf("\t\t *** Listado de tipos *** \n\n");
        printf("  Id   Descripcion");
        printf("\n------------------------------\n");
        for(int i = 0; i<tam; i++){
                if(vec != NULL){
                    printf(" %3d   %-12s\n",
                    vec[i].id,
                    vec[i].desc
                );
                }

                bandera = 1;
        }
        if(bandera == 0){
            printf("\nNo hay tipos en el sistema\n");
        }

        todoOk = 1;
    }

    return todoOk;
}

int altaMicro(eMicro vec[], int tam, int* pId, eEmpresa vecE[], int tame, eTipo vecT[], int tamt)
{
    int todoOk = 0;
    int indice = 1;
    int idEmpresa;
    int idTipo;
    int capacidad;

    int idChofer;
    char auxCad[100];
    char sexo;

    eMicro nuevoMicro;

    if(vec != NULL && tam > 0 && pId != NULL)
    {
        if( buscarMicroLibre(vec, tam, &indice) )
        {

            if(indice != 0)
            {
                printf("No hay lugar en el sistema\n");
            }
            else
            {
                printf("\nIngrese el id del chofer: ");
                scanf("%d", &idChofer);
                while(idChofer < 0){
                    printf("\nId incorrecto. Reingresar: ");
                    scanf("%d", &idChofer);
                }
                nuevoMicro.chofer.id = idChofer;

                printf("\nIngrese el nombre del chofer: ");
                gets(auxCad);
                while(strlen(auxCad) > 51)
                    {
                        printf("Nombre demasiado largo. Reingrese nombre: ");
                        fflush(stdin);
                        gets(auxCad);
                    }
                strcpy(nuevoMicro.chofer.nombre, auxCad);

                printf("\nIngrese el sexo del chofer (f/m): ");
                fflush(stdin);
                scanf("%c", &sexo);
                while(sexo != 'f' && sexo != 'm')
                    {
                        printf("Lo ingresado no es valido. Reingrese sexo: ");
                        fflush(stdin);
                        scanf("%c", &sexo);
                    }
                nuevoMicro.chofer.sexo = sexo;

                informarEmpresa(vecE, tame);
                printf("\nIngrese el id de la empresa: ");
                scanf("%d", &idEmpresa);
                while(idEmpresa < 1000 || idEmpresa > 1004){
                    printf("El id ingresado no es correcto. Reingresar:");
                    scanf("%d", &idEmpresa);
                }
                nuevoMicro.idEmpresa = idEmpresa;


                informarTipo(vecT, tamt);
                printf("\nIngrese el id del tipo: ");
                scanf("%d", &idTipo);
                while(idTipo < 5000 || idTipo > 5004){
                    printf("El id ingresado no es correcto. Reingresar:");
                    scanf("%d", &idTipo);
                }
                nuevoMicro.idTipo = idTipo;


                printf("\nIngrese el la capacidad del micro: ");
                scanf("%d", &capacidad);
                while(capacidad < 1 || capacidad > 50){
                    printf("El numero ingresado no es correcto. Reingresar:");
                    scanf("%d", &capacidad);
                }
                nuevoMicro.capacidad = capacidad;


                nuevoMicro.id = indice + 1;
                *pId = *pId + 1;

                aniadirMicro(vec, tam, nuevoMicro.id, nuevoMicro.idEmpresa, nuevoMicro.idTipo, nuevoMicro.capacidad, nuevoMicro.chofer.id, nuevoMicro.chofer.nombre, nuevoMicro.chofer.sexo);
                todoOk = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema con los parametros\n");
        }
    }

    return todoOk;
}

int aniadirMicro(eMicro vec[], int tam, int id, int idEmpresa, int idTipo, int capacidad, int idChofer, char nombre[], char sexo){
    int todoOk = 0;
    int pIndex;

    if( buscarMicroLibre(vec, tam, &pIndex) ){
        vec[pIndex].id = id;
        vec[pIndex].idEmpresa = idEmpresa;
        vec[pIndex].idTipo = idTipo;
        vec[pIndex].capacidad = capacidad;
        vec[pIndex].isEmpty = 0;
        vec[pIndex].chofer.id = idChofer;
        vec[pIndex].chofer.nombre[25] = nombre[25];
        vec[pIndex].chofer.sexo = sexo;

        todoOk = 1;
    }

    return todoOk;
}

int buscarMicroLibre(eMicro vec[], int tam, int* pIndex){
    int todoOk = 0;

    if(vec != NULL && tam > 0 && pIndex != NULL){
        *pIndex = -1;

        for(int i=0; i < tam; i++){
            if( vec[i].isEmpty){
                *pIndex = i;
                break;
            }
        }

        todoOk = 1;
    }else{
        printf("\nNo hay lugar dispoible\n");
    }

    return todoOk;
}

int buscarViajeLibre(eViaje vec[], int tam, int* pIndex){
    int todoOk = 0;

    if(vec != NULL && tam > 0 && pIndex != NULL){
        *pIndex = -1;

        for(int i=0; i < tam; i++){
            if( vec[i].isEmpty){
                *pIndex = i;
                break;
            }
        }

        todoOk = 1;
    }else{
        printf("\nNo hay lugar dispoible\n");
    }

    return todoOk;
}

int inicializarMicros(eMicro vec[], int tam){
    int todoOk = 0;

	if(vec != NULL && tam > 0){
		for(int i = 0; i < tam; i++){
			vec[i].isEmpty = 1;
		}
		todoOk = 1;
	}

    return todoOk;
}

int inicializarViajes(eViaje vec[], int tam){
    int todoOk = 0;

	if(vec != NULL && tam > 0){
		for(int i = 0; i < tam; i++){
			vec[i].isEmpty = 1;
		}
		todoOk = 1;
	}

    return todoOk;
}

int menu(){
    int rta;

    printf("\n\nIngrese una opcion: ");
    printf("\n\n1.Alta micro\t\t2.Modificar micro");
    printf("\n3.Eliminar micro\t\t4.Informar micros");
    printf("\n5.Informar empresas\t\t6.Informar tipos");
    printf("\n7.Informar destinos\t\t8.Alta viaje");
    printf("\n9.Informar viajes\t\t10.Mostrar micros de una empresa");
    printf("\n11.Mostrar micros de un tipo\t\t12.Mostrar promedo de micros VIP");
    printf("\n13.Mostrar micros por empresa\t\t14.Mostrar si se puede llevar mas pasajeros");
    printf("\n15.Empresa con menos micros\t\t16.Viajes que realizo un micro");
    printf("\n17.Informar suma de precios\t\t18.Micros que viajaron a un destino");
    printf("\n19.viajes realizados en una fecha\n\n");
    printf("\n20.Salir\n\n");
    scanf("%d", &rta);

    return rta;
}

int hardcodeoEmpresa(eEmpresa vec[], int tam, int cant, int* pId){
    int todoOk = 0;

	eEmpresa listaE[] = {
		{1000, "Plusmar", 0},
		{1001, "Flecha Bus", 0},
		{1002, "Tas", 0},
		{1003, "El Rapido", 0}
	};


	if(vec != NULL && tam > 0 && pId != NULL && cant > 0 && cant <= tam)
    {

        for(int i=0; i < cant; i++)
        {
            vec[i] = listaE[i];
            vec[i].id = *pId;
            *pId = *pId +1;

        }

        todoOk = 1;
    }

	return todoOk;
}

int hardcodeoTipo(eTipo vec[], int tam, int cant, int* pId){
    int todoOk = 0;

	eTipo listaT[] = {
		{5000, "Comun", 0},
		{5001, "Coche Cama", 0},
		{5002, "Doble", 0},
		{5003, "Vip", 0}
	};


	if(vec != NULL && tam > 0 && pId != NULL && cant > 0 && cant <= tam)
    {

        for(int i=0; i < cant; i++)
        {
            vec[i] = listaT[i];
            vec[i].id = *pId;
            *pId = *pId +1;

        }

        todoOk = 1;
    }

	return todoOk;
}

int hardcodeoViajes(eViaje vec[], int tam, int cant, int* pId){
    int todoOk = 0;

	eViaje listaV[] = {
		{1, 1, 20000, {20, 5, 2022}, 0},
		{2, 2, 20000, {22, 6, 2022}, 0},
		{3, 3, 20003, {7, 8, 2022}, 0},
		{4, 4, 20001, {16, 5, 2022}, 0}
	};


	if(vec != NULL && tam > 0 && pId != NULL && cant > 0 && cant <= tam)
    {

        for(int i=0; i < cant; i++)
        {
            vec[i] = listaV[i];
            vec[i].id = *pId;
            *pId = *pId +1;

        }

        todoOk = 1;
    }

	return todoOk;
}

int hardcodeoDestino(eDestino vec[], int tam, int cant, int* pId){
    int todoOk = 0;

	eDestino listaD[] = {
		{20000, "Calafate", 22250.00},
		{20001, "Bariloche", 103000.00},
		{20002, "Iguazu", 84400.00},
		{20003, "Mendoza", 95600.00}
	};


	if(vec != NULL && tam > 0 && pId != NULL && cant > 0 && cant <= tam)
    {

        for(int i=0; i < cant; i++)
        {
            vec[i] = listaD[i];
            vec[i].id = *pId;
            *pId = *pId +1;

        }

        todoOk = 1;
    }

	return todoOk;
}

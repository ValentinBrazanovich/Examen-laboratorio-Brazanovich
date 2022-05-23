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

#define TAME 4
#define TAMT 4
#define TAMD 4
#define TAMM 100
#define TAMV 100


int main()
{
    char salir = 'n';
    int proximoIdE = 1000;
    int proximoIdT = 5000;
    int proximoIdD = 20000;
    int proximoIdM = 1;
    int proximoIdV = 1;
    int id;
    int flagMicros = 0;
    int flagViajes = 0;

    eEmpresa listaE[TAME];
    eTipo listaT[TAMT];
    eDestino listaD[TAMD];

    eMicro listaM[TAMM];
    eViaje listaV[TAMV];

    inicializarMicros(listaM, TAMM);
    inicializarViajes(listaV, TAMV);
    hardcodeoEmpresa(listaE, TAME, 4, &proximoIdE);
    hardcodeoTipo(listaT, TAMT, 4, &proximoIdT);
    hardcodeoDestino(listaD, TAMD, 4, &proximoIdD);
    hardcodeoViajes(listaV, TAMV, 3, &proximoIdV);
    flagViajes = 1;

    do{
        switch(menu()){
            case 1:
                altaMicro(listaM, TAMM, &proximoIdM, listaE, TAME, listaT, TAMT);
                flagMicros = 1;

                break;

            case 2:
                if(flagMicros == 1){
                    informarMicros(listaM, TAMM);
                    modificarMicro(listaM, TAMM, listaE, TAME, listaT, TAMT);
                }


                break;

            case 3:
                if(flagMicros == 1){
                    informarMicros(listaM, TAMM);
                    printf("\n\nIngrese el id del micro que desea eliminar: ");
                    scanf("%d", &id);
                    removerMicro(listaM, TAMM, id);
                }

                break;

            case 4:
                if(flagMicros == 1){
                    informarMicros(listaM, TAMM);
                }

                break;
            case 5:
                informarEmpresa(listaE, TAME);
                break;

            case 6:
                informarTipo(listaT, TAMT);
                break;

            case 7:

                informarDestino(listaD, TAMD);
                break;

            case 8:
                altaViaje(listaV, TAMV, listaM, TAMM, listaD, TAMD, &proximoIdV);
                flagViajes = 1;

                break;

            case 9:
                if(flagViajes == 1){
                    informarViajes(listaV, TAMV);
                }

                break;
            case 10:
                if(flagMicros == 1){
                    informarEmpresaMicro(listaM, TAMM, listaE, TAME);
                }
                break;
            case 11:
                if(flagMicros == 1){
                    informarTipoMicro(listaM, TAMM, listaT, TAMT);
                }
                break;
            case 12:
                if(flagMicros == 1){
                    totalPromedioVip(listaM, TAMM);
                }
                break;
            case 13:
                if(flagMicros == 1){
                    informarMicroPorEmpresa(listaM, TAMM, listaE, TAME);
                }
                break;
            case 14:
                if(flagMicros == 1){
                    informarMasCapacidad(listaM, TAMM);
                }
                break;
            case 15:
                if(flagMicros == 1){
                    informarEmpresaMenosMicros(listaM, TAMM, listaE, TAME);
                }
                break;
            case 16:
                if(flagMicros == 1){
                    informarViajesMicro(listaM, TAMM, listaV, TAMV);
                }
                break;
            case 17:

                break;
            case 18:
                if(flagViajes == 1){
                    informarDestinoMicros(listaV, TAMV, listaD, TAMD);
                }

                break;
            case 19:
                if(flagViajes == 1){
                     viajesPorFecha(listaV, TAMV);
                }
                break;

            case 20:
                salir = 's';
                break;

            default: printf("\nLa opcion ingresada no existe\n");
        }

    }while(salir != 's');

    return 0;
}


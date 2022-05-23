#ifndef ARRAYVIAJE_H_INCLUDED
#define ARRAYVIAJE_H_INCLUDED
#include "ArrayDestino.h"

typedef struct{
    int id;
    int idMicro;
    int idDestino;
    eFecha fecha;
    int isEmpty;
} eViaje;

#endif // ARRAYVIAJE_H_INCLUDED

int buscarViajeLibre(eViaje vec[], int tam, int* pIndex);
int informarViajes(eViaje vec[], int tam);
int aniadirViaje(eViaje vec[], int tam, int id, int idMicro, int idDestino);
int inicializarViajes(eViaje vec[], int tam);
int altaViaje(eViaje vec[], int tam, eMicro vecM[], int tamm, eDestino vecD[], int tamd, int* pId);
int hardcodeoViajes(eViaje vec[], int tam, int cant, int* pId);
int informarViajesMicro(eMicro vec[], int tam, eViaje vecv[], int tamv);
int viajesPorFecha(eViaje vec[], int tam);


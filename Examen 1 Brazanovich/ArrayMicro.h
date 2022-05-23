#ifndef ARRAYMICRO_H_INCLUDED
#define ARRAYMICRO_H_INCLUDED
#include "ArrayChofer.h"

typedef struct{
    int id;
    int idEmpresa;
    int idTipo;
    int capacidad;
    eChofer chofer;
    int isEmpty;
} eMicro;

#endif // ARRAYMICRO_H_INCLUDED

int altaMicro(eMicro vec[], int tam, int* pId, eEmpresa vecE[], int tame, eTipo vecT[], int tamt);
int buscarMicroLibre(eMicro vec[], int tam, int* pIndex);
int modificarMicro(eMicro vec[], int tam, eEmpresa vecE[], int tame, eTipo vecT[], int tamt);
int encontrarMicroPorId(eMicro vec[], int tam, int id, int* pIndex);
int aniadirMicro(eMicro vec[], int tam, int id, int idEmpresa, int idTipo, int capacidad, int idChofer, char nombre[], char sexo);
int informarMicros(eMicro vec[], int tam);
int removerMicro(eMicro vec[], int tam, int id);
int inicializarMicros(eMicro vec[], int tam);
int informarEmpresaMicro(eMicro vec[], int tam, eEmpresa vecE[], int tame);
int informarTipoMicro(eMicro vec[], int tam, eTipo vecT[], int tamT);
int totalPromedioVip(eMicro vec[], int tam);
int informarTotalPromedioVip(eMicro vec[], int len, float cantMicro, float promedio);
int informarMicroPorEmpresa(eMicro vec[], int tam, eEmpresa vecE[], int tame);
int informarMasCapacidad(eMicro vec[], int tam);
int informarEmpresaMenosMicros(eMicro vec[], int tam, eEmpresa vecE[], int tame);

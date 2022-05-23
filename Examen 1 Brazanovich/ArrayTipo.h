#ifndef ARRAYTIPO_H_INCLUDED
#define ARRAYTIPO_H_INCLUDED

typedef struct{
    int id;
    char desc[20];
    int isEmpty;
} eTipo;

#endif // ARRAYTIPO_H_INCLUDED

int hardcodeoTipo(eTipo vec[], int tam, int cant, int* pId);
int encontrarTipoPorId(eTipo vec[], int tam, int id, int* pIndex);
int informarTipo(eTipo vec[], int tam);

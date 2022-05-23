#ifndef ARRAYDESTINO_H_INCLUDED
#define ARRAYDESTINO_H_INCLUDED

typedef struct{
    int id;
    char desc[25];
    float precio;
    int isEmpty;
} eDestino;

#endif // ARRAYDESTINO_H_INCLUDED

int hardcodeoDestino(eDestino vec[], int tam, int cant, int* pId);
int informarDestino(eDestino vec[], int tam);

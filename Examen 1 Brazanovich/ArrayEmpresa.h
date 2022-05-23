#ifndef ARRAYEMPRESA_H_INCLUDED
#define ARRAYEMPRESA_H_INCLUDED

typedef struct{
    int id;
    char desc[20];
    int isEmpty;
} eEmpresa;

#endif // ARRAYEMPRESA_H_INCLUDED


int hardcodeoEmpresa(eEmpresa vec[], int tam, int cant, int* pId);
int informarEmpresa(eEmpresa vec[], int tam);
int encontrarEmpresaPorId(eEmpresa vec[], int tam, int id, int* pIndex);

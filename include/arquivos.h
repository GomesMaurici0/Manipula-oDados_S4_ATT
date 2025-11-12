#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include "structs.h"

int carregarProfessores(const char *arquivo, Professor professores[], int *qtd);
int carregarAlunos(const char *arquivo, Aluno alunos[], int *qtd);
int carregarTC(const char *arquivo, TC tcs[], int *qtd);
int carregarEleitores(const char *arquivo, Eleitor eleitores[], int *qtd);

int salvarParcial(const char *arquivo, Eleitor eleitores[], int qtdEleitores);
int salvarResultado(const char *arquivo, TC tcs[], int qtdTCs, Eleitor eleitores[], int qtdEleitores);

#endif

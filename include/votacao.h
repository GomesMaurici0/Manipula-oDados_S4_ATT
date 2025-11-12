#ifndef VOTACAO_H
#define VOTACAO_H

#include "structs.h"

// Funções da votação
int registrarVoto(Eleitor eleitores[], int qtdEleitores, TC tcs[], int qtdTCs, const char *cpf, int codigoTC);
void exibirMenu1();
void exibirMenu2(Eleitor eleitores[], int qtdEleitores, TC tcs[], int qtdTCs);

#endif

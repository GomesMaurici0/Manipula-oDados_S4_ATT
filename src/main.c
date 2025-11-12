#include <stdio.h>
#include <stdlib.h>
#include "arquivos.h"
#include "validacoes.h"
#include "votacao.h"
#include "structs.h"

int main() {
    Professor professores[MAX_PROFESSORES];
    Aluno alunos[MAX_ALUNOS];
    TC tcs[MAX_TCS];
    Eleitor eleitores[MAX_ELEITORES];

    int qtdProf=0, qtdAlunos=0, qtdTCs=0, qtdEleitores=0;

    // Carregar arquivos
    if(!carregarProfessores("data/professor.txt", professores, &qtdProf)) return 1;
    if(!carregarAlunos("data/aluno.txt", alunos, &qtdAlunos)) return 1;
    if(!carregarTC("data/TC_BCC.txt", tcs, &qtdTCs)) return 1;
    if(!carregarEleitores("data/comissao.txt", eleitores, &qtdEleitores)) return 1;

    printf("=== Sistema de Votacao de TCs ===\n");

    // Menu inicial
    exibirMenu1();

    // Menu de votacao
    exibirMenu2(eleitores, qtdEleitores, tcs, qtdTCs);

    return 0;
}

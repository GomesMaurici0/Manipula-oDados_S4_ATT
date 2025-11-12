#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/votacao.h"
#include "../include/validacoes.h"
#include "../include/arquivos.h"


int registrarVoto(Eleitor eleitores[], int qtdEleitores, TC tcs[], int qtdTCs, const char *cpf, int codigoTC){
    int i;
    for(i=0;i<qtdEleitores;i++){
        if(strcmp(eleitores[i].cpf, cpf)==0) break;
    }
    if(i==qtdEleitores){
        printf("CPF nao pertence a comissao.\n");
        return 0;
    }
    if(eleitores[i].jaVotou){
        printf("Eleitor ja votou.\n");
        return 0;
    }
    int tcEncontrado=0;
    for(int j=0;j<qtdTCs;j++){
        if(tcs[j].codigoTC==codigoTC){
            tcs[j].votos++;
            tcEncontrado=1;
            break;
        }
    }
    if(!tcEncontrado){
        printf("Codigo de TC invalido.\n");
        return 0;
    }
    eleitores[i].jaVotou=1;
    eleitores[i].voto=codigoTC;
    printf("Voto registrado com sucesso.\n");
    return 1;
}

void exibirMenu1(){
    char opcao;
    printf("=== MENU1 ===\n");
    printf("a) Iniciar nova votacao\n");
    printf("b) Continuar votacao gravada\n");
    printf("Escolha: ");
    scanf(" %c", &opcao);
    opcao=tolower(opcao);

    if(opcao=='a'){
        printf("Iniciando nova votacao...\n");
    }else if(opcao=='b'){
        printf("Continuando votacao gravada...\n");
    }else{
        printf("Opcao invalida!\n");
        exibirMenu1();
    }
}

void exibirMenu2(Eleitor eleitores[], int qtdEleitores, TC tcs[], int qtdTCs){
    char opcao;
    do{
        printf("\n=== MENU2 ===\n");
        printf("a) Entrar com voto\n");
        printf("b) Suspender votacao\n");
        printf("c) Concluir votacao\n");
        printf("Escolha: ");
        scanf(" %c", &opcao);
        opcao=tolower(opcao);

        if(opcao=='a'){
            char cpf[MAX_CPF];
            int codigoTC;
            printf("Digite o CPF do eleitor: ");
            scanf("%s", cpf);
            if(!validarCPF(cpf)){
                printf("CPF invalido.\n");
                continue;
            }
            printf("Digite o codigo do TC: ");
            scanf("%d", &codigoTC);
            registrarVoto(eleitores, qtdEleitores, tcs, qtdTCs, cpf, codigoTC);
        }else if(opcao=='b'){
            salvarParcial("output/parcial.txt", eleitores, qtdEleitores);
            printf("Votacao suspensa e salva em parcial.txt\n");
            break;
        }else if(opcao=='c'){
            salvarResultado("output/resultado.txt", tcs, qtdTCs, eleitores, qtdEleitores);
            printf("Votacao concluida e salva em resultado.txt\n");
            break;
        }else{
            printf("Opcao invalida.\n");
        }
    }while(1);
}



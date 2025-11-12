#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/arquivos.h"

int carregarProfessores(const char *arquivo, Professor professores[], int *qtd) {
    FILE *fp = fopen(arquivo, "r");
    if(!fp) { printf("Arquivo %s nao encontrado!\n", arquivo); return 0; }
    fscanf(fp, "%d", qtd);
    for(int i=0;i<*qtd;i++){
        fscanf(fp, "%d %s %d", &professores[i].codigo, professores[i].departamento, &professores[i].idade);
        fgets(professores[i].nome, 100, fp);
        professores[i].nome[strcspn(professores[i].nome, "\n")] = '\0';
    }
    fclose(fp);
    return 1;
}

int carregarAlunos(const char *arquivo, Aluno alunos[], int *qtd) {
    FILE *fp = fopen(arquivo, "r");
    if(!fp) { printf("Arquivo %s nao encontrado!\n", arquivo); return 0; }
    fscanf(fp, "%d", qtd);
    for(int i=0;i<*qtd;i++){
        fscanf(fp, "%d %d %s %d", &alunos[i].matricula, &alunos[i].ano, alunos[i].departamento, &alunos[i].idade);
        fgets(alunos[i].nome, 100, fp);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';
    }
    fclose(fp);
    return 1;
}

int carregarTC(const char *arquivo, TC tcs[], int *qtd) {
    FILE *fp = fopen(arquivo, "r");
    if(!fp) { printf("Arquivo %s nao encontrado!\n", arquivo); return 0; }
    fscanf(fp, "%d", qtd);
    for(int i=0;i<*qtd;i++){
        fscanf(fp, "%d %d %d", &tcs[i].codigoTC, &tcs[i].codigoAluno, &tcs[i].codigoOrientador);
        fgets(tcs[i].titulo, 100, fp);
        tcs[i].titulo[strcspn(tcs[i].titulo, "\n")] = '\0';
        tcs[i].votos = 0;
    }
    fclose(fp);
    return 1;
}

int carregarEleitores(const char *arquivo, Eleitor eleitores[], int *qtd) {
    FILE *fp = fopen(arquivo, "r");
    if(!fp) { printf("Arquivo %s nao encontrado!\n", arquivo); return 0; }
    fscanf(fp, "%d", qtd);
    for(int i=0;i<*qtd;i++){
        fscanf(fp, "%s", eleitores[i].cpf);
        eleitores[i].jaVotou = 0;
        eleitores[i].voto = -1;
    }
    fclose(fp);
    return 1;
}

int salvarParcial(const char *arquivo, Eleitor eleitores[], int qtdEleitores) {
    FILE *fp=fopen(arquivo,"w");
    if(!fp) return 0;
    int count=0;
    for(int i=0;i<qtdEleitores;i++){
        if(eleitores[i].jaVotou) count++;
    }
    fprintf(fp,"%d\n", count);
    for(int i=0;i<qtdEleitores;i++){
        if(eleitores[i].jaVotou){
            fprintf(fp,"%s %d\n", eleitores[i].cpf, eleitores[i].voto);
        }
    }
    fclose(fp);
    return 1;
}

int salvarResultado(const char *arquivo, TC tcs[], int qtdTCs, Eleitor eleitores[], int qtdEleitores){
    FILE *fp=fopen(arquivo,"w");
    if(!fp) return 0;

    int maxVotos=0;
    for(int i=0;i<qtdTCs;i++){
        if(tcs[i].votos>maxVotos) maxVotos=tcs[i].votos;
    }

    fprintf(fp,"TC(s) vencedor(es):\n");
    for(int i=0;i<qtdTCs;i++){
        if(tcs[i].votos==maxVotos && maxVotos>0){
            fprintf(fp,"Codigo: %d\nTitulo: %s\nVotos: %d\n\n", tcs[i].codigoTC, tcs[i].titulo, tcs[i].votos);
        }
    }

    fprintf(fp,"Eleitores que votaram:\n");
    for(int i=0;i<qtdEleitores;i++){
        if(eleitores[i].jaVotou){
            fprintf(fp,"%s %d\n", eleitores[i].cpf, eleitores[i].voto);
        }
    }

    fprintf(fp,"Eleitores que nao votaram:\n");
    for(int i=0;i<qtdEleitores;i++){
        if(!eleitores[i].jaVotou){
            fprintf(fp,"%s\n", eleitores[i].cpf);
        }
    }

    fclose(fp);
    return 1;
}
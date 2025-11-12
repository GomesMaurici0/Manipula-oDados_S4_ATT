#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "../include/validacoes.h"

int validarCPF(const char *cpf) {
    if(strlen(cpf) != 14) return 0;
    for(int i=0;i<14;i++){
        if(i==3||i==7){ if(cpf[i]!='.') return 0; }
        else if(i==11){ if(cpf[i]!='-') return 0; }
        else if(!isdigit(cpf[i])) return 0;
    }
    return 1;
}

int alunoExiste(int codigoAluno, const char *departamento, Aluno alunos[], int qtdAlunos) {
    for(int i=0;i<qtdAlunos;i++){
        if(alunos[i].matricula == codigoAluno && strcmp(alunos[i].departamento, departamento)==0)
            return 1;
    }
    return 0;
}

int professorExiste(int codigoProfessor, Professor professores[], int qtdProfessores) {
    for(int i=0;i<qtdProfessores;i++){
        if(professores[i].codigo == codigoProfessor) return 1;
    }
    return 0;
}

int tcExiste(int codigoTC, TC tcs[], int qtdTCs) {
    for(int i=0;i<qtdTCs;i++){
        if(tcs[i].codigoTC == codigoTC) return 1;
    }
    return 0;
}

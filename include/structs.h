#ifndef STRUCTS_H
#define STRUCTS_H

#define MAX_DEPARTAMENTOS 5
#define MAX_NOME 100
#define MAX_CPF 15
#define MAX_TCS 1000
#define MAX_PROFESSORES 1000
#define MAX_ALUNOS 1000
#define MAX_ELEITORES 1000

typedef struct {
    int codigo;
    char departamento[10];
    int idade;
    char nome[MAX_NOME];
} Professor;

typedef struct {
    int matricula;
    int ano;
    char departamento[10];
    int idade;
    char nome[MAX_NOME];
} Aluno;

typedef struct {
    int codigoTC;
    int codigoAluno;
    int codigoOrientador;
    char titulo[MAX_NOME];
    int votos;
} TC;

typedef struct {
    char cpf[MAX_CPF];
    int jaVotou;
    int voto;
} Eleitor;

#endif

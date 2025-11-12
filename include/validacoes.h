#ifndef VALIDACOES_H
#define VALIDACOES_H

#include "structs.h"

int validarCPF(const char *cpf);
int alunoExiste(int codigoAluno, const char *departamento, Aluno alunos[], int qtdAlunos);
int professorExiste(int codigoProfessor, Professor professores[], int qtdProfessores);
int tcExiste(int codigoTC, TC tcs[], int qtdTCs);

#endif

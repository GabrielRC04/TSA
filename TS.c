#include <stdio.h>

struct aluno{
    int matricula;
    int telefone;
    char nome[40];
};

struct disciplina{
    int codigo;
    char nome[40];
    struct aluno alunos[40];
};

struct turmas{
    int numero;
    struct disciplina disciplinas[10];
};

typedef struct turmas t_turmas;

int cadastro_turmas(t_turmas turmas[]){
    int q,i;
    printf("Quantas turmas deseja criar?");
    scanf("%d",&q);
    for(i=0;i<q;i++){
    printf("Qual o numero da turma %d?",i+1);
    scanf("%d",&turmas[i].numero);
    }
    return(q);
}
void lista_turmas(t_turmas turmas[], int q){
    int i; 
    printf("Lista de Turmas\n");
    for(i=0;i<q;i++){
        printf("Turma %d - %d\n",i+1,turmas[i].numero);
    }
}

int cadastro_disciplinas(t_turmas turmas[].disciplina[]){
    printf("a");

}

int main() {
    t_turmas turmas[100]; 
    int quantidade;
    quantidade = cadastro_turmas(turmas);
    lista_turmas(turmas, quantidade);
    

    return 0;
}

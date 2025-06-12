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



int cadastro_disciplinas(t_turmas turmas[]){
      int nd,nt,i;
      printf("Deseja adicionar quantas discliplinas?");
      scanf("%d",&nd);
      printf("Deseja adicionar a qual turma?");
      scanf("%d",&nt);
      nt--;
      for(i=0;i<nd;i++){
        printf("Qual sera o codigo da %do disciplina?",i+1);
        scanf("%d",&turmas[nt].disciplinas[i].codigo);
        printf("Qual sera o nome da %do disciplina?",i+1);
        scanf("%s",&turmas[nt].disciplinas[i].nome);
 }
    return(0);
}

void lista_disciplinas(t_turmas turmas[],int q){
    int i,j; 
    printf("Lista de Turmas\n");
    for(i=0;i<q;i++){
        printf("Turma %d - %d\n",i+1,turmas[i].numero);
        for(j=0;j<q;j++){
            printf("Disciplina %d \n",j+1);
            printf("Codigo da Disciplina %d\n",turmas[i].disciplinas[j].codigo);
            printf("Nome da Disciplina %s\n",turmas[i].disciplinas[j].nome);

        }
    }
}

int main() {
    t_turmas turmas[30]; 
    int quantidade;
    quantidade = cadastro_turmas(turmas);
    lista_turmas(turmas, quantidade);
    cadastro_disciplinas(turmas);
    lista_disciplinas(turmas,quantidade);
    

    return 0;
}

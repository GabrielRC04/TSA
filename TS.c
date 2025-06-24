#include <stdio.h>
#include <stdlib.h>

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
    printf("\nLista de Turmas\n");
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
        scanf("%s",turmas[nt].disciplinas[i].nome);
 }
    return(nd);
}

void lista_disciplinas(t_turmas turmas[],int q){
    int nturma,i,j; 
    printf("Deseja ver as disciplinas de qual turma?");
    scanf("%d",&nturma);
    nturma = nturma-1;
    printf("Lista de Disciplinas\n");
    printf("Turma %d - %d\n",i+1,turmas[nturma].numero);
    for(i=0;i<q;i++){
        printf("Disciplina %d \n",j+1);
        printf("Codigo da Disciplina %d\n",turmas[nturma].disciplinas[i].codigo);
        printf("Nome da Disciplina %s\n",turmas[nturma].disciplinas[i].nome);

        }
    }

int cadastro_alunos(t_turmas turmas[]){
    int qntaln,ndsc,nturma,i;
    printf("Quantos(as) alunos deseja cadastrar?");
    scanf("%d",&qntaln);
    printf("Em qual disciplina?");
    scanf("%d",&ndsc);
    printf("Essa disciplina pertence a qual turma?");
    scanf("%d",&qntaln);
    for(i=0;i<qntaln;i++){
        printf("Qual o nome do aluno %d?",i+1);
        scanf("%s",turmas[nturma].disciplinas[ndsc].alunos[i].nome);
        printf("Qual o telefone do aluno %d?",i+1);
        scanf("%d",&turmas[nturma].disciplinas[ndsc].alunos[i].telefone);
        printf("Qual a matricula do aluno %d?",i+1);
        scanf("%d",&turmas[nturma].disciplinas[ndsc].alunos[i].matricula);
    }
    return(qntaln);
}
   

void lista_alunos(t_turmas turmas[],int qntaln){
    int ndsc,nturma,i;
    printf("Deseja ver a lista de alunos de qual turma?");
    scanf("%d",&nturma);
    printf("E de qual disciplina?");
    scanf("%d",&ndsc);
    printf("Lista de Alunos\n");
    for(i=0;i<qntaln;i++){
        printf("Aluno %d\n",i+1);
        printf("Nome: %s\n",turmas[nturma].disciplinas[ndsc].alunos[i].nome);
        printf("Telefone: %d\n",turmas[nturma].disciplinas[ndsc].alunos[i].telefone);
        printf("Matricula: %d\n",turmas[nturma].disciplinas[ndsc].alunos[i].matricula);
    }
}


int main() {
    t_turmas turmas[30]; 
    int seletor,qntturmas,qntalunos,qntdisc;

    printf("## Sistema Academico ##\n1- Inserir turmas\n2- Listar turmas\n3- Inserir disciplinas\n4- Listar disciplinas\n5- Cadastrar alunos\n6- Listar alunos\n0- Sair do Programa\n");
    printf("\nO que deseja fazer?");
    scanf("%d",&seletor);

    while(seletor>0 || seletor>9){
        switch (seletor) {
            case 1:
            qntturmas = cadastro_turmas(turmas);
            break;
            case 2:
            lista_turmas(turmas, qntturmas);
            break;
            case 3:
            qntdisc = cadastro_disciplinas(turmas);
            break;
            case 4:
            lista_disciplinas(turmas,qntdisc);
            break;
            case 5:
            qntalunos = cadastro_alunos(turmas);
            break;
            case 6:
            lista_alunos(turmas,qntalunos);
            break;
        }
        printf("\n## Sistema Academico ##\n1- Inserir turmas\n2- Listar turmas\n3- Inserir disciplinas\n4- Listar disciplinas\n5- Cadastrar alunos\n6- Listar alunos\n0- Sair do Programa\n");
        printf("\nO que deseja fazer?");
        scanf("%d",&seletor);
    }

    return 0;
}

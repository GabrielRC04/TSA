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
    struct aluno alunos[30];
};

struct turmas{
    int numero;
    struct disciplina disciplinas[10];
};

typedef struct turmas t_turmas;

int interface_sistema();
int cadastro_turmas(t_turmas turmas[]);
void lista_turmas(t_turmas turmas[],int);
int cadastro_disciplinas(t_turmas turmas[]);
void lista_disciplinas(t_turmas turmas[],int);
int cadastro_alunos(t_turmas turmas[]);
void lista_alunos(t_turmas turmas[],int);


int main() {
    t_turmas turmas[30];
    int escolha,qntturmas,qntalunos,qntdisc; 
    int *contadort = calloc(1,sizeof(int));

    do {
        escolha = interface_sistema(); 
        while (escolha < 0 || escolha > 9) {
            printf("\nEscolha invalida, favor escolher um numero de 0 a 9 (0 para sair).\n");
            escolha = interface_sistema();
        }
        switch (escolha) {
            case 1:
                qntturmas = cadastro_turmas(turmas);
                break;
            case 2:
                if (qntturmas > 0) {
                    lista_turmas(turmas, qntturmas);
                } else {
                    printf("Nenhuma turma cadastrada ainda.\n");
                }
                break;
            case 3:
                qntdisc = cadastro_disciplinas(turmas);
                
                break;
            case 4:
                if (qntdisc > 0) {
                    lista_disciplinas(turmas, qntdisc);
                } else {
                    printf("Nenhuma disciplina cadastrada ainda.\n");
                }
                break;
            case 5:
                qntalunos = cadastro_alunos(turmas);
                printf("Alunos cadastrados: %d\n", qntalunos);
                break;
            case 6:
                if (qntalunos > 0) {
                    lista_alunos(turmas, qntalunos);
                } else {
                    printf("Nenhum aluno cadastrado ainda.\n");
                }
                break;
            case 7:
                printf("Funcionalidade de remover turma ainda nao implementada.\n");
                break;
            case 8:
                printf("Funcionalidade de remover disciplina ainda nao implementada.\n");
                break;
            case 9:
                printf("Funcionalidade de remover alunos ainda nao implementada.\n");
                break;
            case 0:
                free(contadort);
                printf("Saindo do sistema. Ate mais!\n");
                break;
            default:
                printf("Opcao invalida. Por favor, tente novamente.\n");
                break;
        }
    } while (escolha != 0); 

    return 0;
}


int interface_sistema(){
    int seletor;
    printf("\n## Sistema Academico ##\n1- Inserir turmas\n2- Listar turmas\n3- Inserir disciplinas\n");
    printf("4- Listar disciplinas\n5- Cadastrar alunos\n6- Listar alunos\n");
    printf("7- Remover Turma\n8- Remover Disciplina\n9- Remover Aluno\n0- Sair do Programa\n");
    printf("\nO que deseja fazer?");
    scanf("%d",&seletor);
    return(seletor);
}

int cadastro_turmas(t_turmas turmas[]){
    int qntturmas,i;
    printf("Quantas turmas deseja criar?");
    scanf("%d",&qntturmas);
    for(i=0;i<qntturmas;i++){
    printf("Qual o numero da turma %d?",i+1);
    scanf("%d",&turmas[i].numero);
    }
    return(qntturmas);
}

void lista_turmas(t_turmas turmas[], int q) {
    int i;
    printf("\nLista de Turmas\n");
        if (q == 0) {
        printf("\nNenhuma turma cadastrada para exibir.\n");
        return;
    }
    for (i = 0; i < q; i++) {
        printf("Turma %d - Numero: %d\n", i + 1, turmas[i].numero);
    }}

int cadastro_disciplinas(t_turmas turmas[]){
      int nd,nt,i;
      printf("Deseja adicionar a qual turma?");
      scanf("%d",&nt);
      nt--;
      printf("Deseja adicionar quantas disciplinas?");
      scanf("%d",&nd);

      for(i=0;i<nd;i++){
        printf("Qual sera o codigo da disciplina %d?",i+1);
        scanf("%d",&turmas[nt].disciplinas[i].codigo);
        printf("Qual sera o nome da disciplina? %d?",i+1);
        scanf(" %s",turmas[nt].disciplinas[i].nome);
 }
    return(nd);
}

void lista_disciplinas(t_turmas turmas[],int q){
    int nturma,i,j; 
    printf("Deseja ver as disciplinas de qual turma?");
    scanf("%d",&nturma);
    nturma = nturma-1;
    printf("Lista de Disciplinas\n");
    printf("Turma %d - %d\n",nturma+1,turmas[nturma].numero);
    for(i=0;i<q;i++){
        printf("Disciplina %d \n",i+1);
        printf("Codigo da Disciplina %d\n",turmas[nturma].disciplinas[i].codigo);
        printf("Nome da Disciplina %s\n",turmas[nturma].disciplinas[i].nome);
        
    } }

int cadastro_alunos(t_turmas turmas[]){
    int qntaln,ndsc,nturma,i;
    printf("Quantos(as) alunos deseja cadastrar?");
    scanf("%d",&qntaln);
    printf("Em qual disciplina?");
    scanf("%d",&ndsc);
    printf("Essa disciplina pertence a qual turma?");
    scanf("%d",&nturma);
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
    }}

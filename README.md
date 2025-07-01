# TSA - Trabalho Semestral Algoritmos e Estruturas de Dados
O objetivo do programa é criar um sistema para administração de turmas, disciplinas e alunos. (Mais informações no TS.pdf feito pelo professor Cayo Magno da Cruz Fontana)

## Structs
### Struct para Alunos.
```
struct aluno{
    int matricula;
    int telefone;
    char nome[40];
};
```
### Struct para Disciplinas.
```
struct disciplina{
    int codigo;
    char nome[40];
    struct aluno alunos[30];
};
```
### Struct para Turmas.
```
struct turmas{
    int numero;
    struct disciplina disciplinas[10];
};
```
- *typedef* para criar um apelido para simplificação e legibilidade do código. 
```
typedef struct turmas t_turmas;
```
## Protótipos
- Para que as funções abaixo da função main sejam utilizadas além de facilitar a compreensão do codigo.
```
int interface_sistema();
int cadastro_turmas(t_turmas turmas[]);
void lista_turmas(t_turmas turmas[],int);
int cadastro_disciplinas(t_turmas turmas[]);
void lista_disciplinas(t_turmas turmas[],int);
int cadastro_alunos(t_turmas turmas[]);
void lista_alunos(t_turmas turmas[],int);

```

## Função Main
### Definição de variaveis e criação de vetor para que seja possível a criação de mais de uma turma
```
    t_turmas turmas[30];
    int escolha,qntturmas,qntalunos,qntdisc; 
    int *contadort = calloc(1,sizeof(int));
```
### Criação de loop e condição 
-
```
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

```



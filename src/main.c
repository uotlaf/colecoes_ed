#include <stdio.h>
#include "colecao.h"
#include "aluno.h"
#include "compara.h"
#include <stdlib.h>


int main() {
    int resposta, cont = 1, maxItens, escolha;
    char nome[30];
    float nota;
    Colecao* colecao = NULL;
    ALUNO* aluno;

    do {
        printf("\033[2J \033[H");

        printf("Pergunta:\n");
        printf("1 - Criar uma coleção\n");
        printf("2 - Inserir elementos na coleção\n");
        printf("3 - Listar os elementos da coleção\n");
        printf("4 - Consultar um dos elementos da coleção\n");
        printf("5 - Remover algum elemento da coleção\n");
        printf("6 - Esvaziar a coleção\n");
        printf("7 - Destruir a coleção\n");
        scanf("%d", &resposta);
        switch (resposta) { 
            case 1:
                printf("Digite a quantidade de itens pra botar na coleção:\n");
                scanf("%d", &maxItens);

                colecao = colCriar(maxItens);

                if (colecao != NULL) {
                    printf("Coleção criada com sucesso!\n");

                } else {
                    printf("Erro ao fazer a coleção\n");
                }
                break;
            
            case 2:
                if (colecao == NULL) {
                    printf("Aloque primeiro a colecao\n");
                    break;
                }

                if (colecao->maxItens <= colecao->quantItens) {
                    printf("Coleção já cheia\n");
                    break;
                }

                aluno = (ALUNO*)malloc(sizeof(ALUNO));

                if (aluno == NULL) {
                    printf("Não pude alocar aluno. Saindo\n");
                    break;
                }
                printf("Digite o nome do aluno: ");
                scanf("%s", aluno->nome);
                while(getchar() != '\n'); // Limpa o stdin caso a pessoa tenha digitado um sobrenome

                printf("Digite a idade do aluno: ");
                scanf("%d", &aluno->idade);

                printf("Digite a nota do aluno: \n");
                scanf("%f", &aluno->nota);

                colInserir(colecao, (void*)aluno);

                printf("Aluno %s, com idade %d e nota %.2f inserido com sucesso\n", aluno->nome, aluno->idade, aluno->nota);
                break;

            case 3:
                if (colecao == NULL) {
                    printf("Aloque primeiro a colecao\n");
                    break;
                }

                if (colecao->quantItens == 0) {
                    printf("Bote algo na coleção antes!\n");
                    break;
                }

                for (int i = 0; i < colecao->quantItens; i++) {
                    aluno = colecao->itens[i];
                    printf("Aluno %s, índice %d, idade %d, nota %.2f\n", aluno->nome, i, aluno->idade, aluno->nota);
                }
                
                break;
            
            case 4:
                if (colecao == NULL) {
                    printf("Aloque primeiro a colecao\n");
                    break;
                }

                if (colecao->quantItens == 0) {
                    printf("Bote algo na coleção antes!\n");
                    break;
                }

                printf("Você deseja procurar por:\n");
                printf("1 - Nome\n");
                printf("2 - Idade\n");
                printf("3 - Nota\n");
                scanf("%d", &escolha);

                switch (escolha) {
                    case 1:
                        printf("Digite o nome a procurar: ");
                        scanf("%s", nome);
                        aluno = colProcura(colecao, (void*)nome, cmpString);
                        break;
                    case 2:
                        printf("Digite a idade a procurar: ");
                        scanf("%d", &resposta);
                        aluno = colProcura(colecao, (void*)&resposta, cmpInt);  
                        break;
                    case 3:
                        printf("Digite a nota a procurar: ");
                        scanf("%f", &nota);
                        aluno = colProcura(colecao, (void*)&nota, cmpFloat);
                }
                if (aluno != NULL) {
                    printf("Aluno encontrado: \n");
                    printf("Nome: %s\n", aluno->nome);
                    printf("Idade: %d\n", aluno->idade);
                    printf("Nota: %.2f\n", aluno->nota);
                } else {
                    printf("Aluno não encontrado!\n");
                }
                break;

            case 5:
                if (colecao == NULL) {
                    printf("Aloque primeiro a colecao\n");
                    break;
                }

                if (colecao->quantItens == 0) {
                    printf("Bote algo na coleção antes!\n");
                    break;
                }

                printf("Você deseja procurar por:\n");
                printf("1 - Nome\n");
                printf("2 - Idade\n");
                printf("3 - Nota\n");
                scanf("%d", &escolha);

                switch (escolha) {
                    case 1:
                        printf("Digite o nome a procurar: ");
                        scanf("%s", nome);
                        aluno = colProcura(colecao, (void*)nome, cmpString);
                        break;
                    case 2:
                        printf("Digite a idade a procurar: ");
                        scanf("%d", &resposta);
                        aluno = colProcura(colecao, (void*)&resposta, cmpInt);
                        break;
                    case 3:
                        printf("Digite a nota a procurar: ");
                        scanf("%f", &nota);
                        aluno = colProcura(colecao, (void*)&nota, cmpFloat);
                }

                if (aluno != NULL) {
                    printf("Você deseja remover esse objeto:\n");
                    printf("Nome: %s\n", aluno->nome);
                    printf("Idade: %d", aluno->idade);
                    printf("Nota: %.2f\n", aluno->nota);
                    printf("Digite 1 para apagar e outro número para cancelar\n");

                    scanf("%d", &escolha);
                    switch(escolha) {
                        case 1:
                            colRemover(colecao, aluno);
                            break;
                    }
                }
                break;
            case 6:
                if (colecao == NULL) {
                    printf("Aloque primeiro a colecao\n");
                    break;
                }

                if (colecao->quantItens == 0) {
                    printf("Bote algo na coleção antes!\n");
                    break;
                }
                colEsvaziar(colecao);
                break;
            case 7:
                if (colecao == NULL) {
                    printf("Aloque primeiro a colecao\n");
                    break;
                }

                if (colecao->quantItens != 0) {
                    printf("A coleção deve estar vazia!\n");
                    break;
                }
                colDestruir(colecao);
                colecao = NULL;
                break;
            default:
                printf("Saindo\n");
                cont=0;
        }

        printf("Pressione um botão para continuar\n");
        while(getchar() != '\n'); // Limpa o stdin
        getchar(); // Espera a pessoa digitar ENTER

    }while (cont);

    if (colecao != NULL) {
        colEsvaziar(colecao);
    }
}
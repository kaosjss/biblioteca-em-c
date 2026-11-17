#include <stdio.h>
#include <string.h>                 
#include <locale.h>      
int main(void) {

setlocale(LC_ALL, "Portuguese");
    // ===== CATALOGO DE LIVROS =====
    int codigosCatalogo[5] = {201, 202, 203, 204, 205};
    char titulosCatalogo[5][50] = {
        "Duna",
        "harry potter 1 ",
        "Vidas Secas",
        "Iracema",
        "Memorias Postumas de Bras Cubas"
    };

    // ===== VARIAVEIS DOS EMPRESTIMOS =====
    int clientes[50];
    int livros[50];
    char nomesLivros[50][50];       
    int dia[50];
    int mes[50];
    int ano[50];

    // ===== CONTROLE DAS INTERACOES COM O USUARIO =====
    int total = 0;
    int opcao;
    int escolha;                    
    int i;                          

    printf("===============================\n");
    printf("||    BIBLIOTECA DO CHAOS    ||\n");
    printf("===============================\n\n");

    do {
        if (total == 50) {
            printf("Limite de emprestimos atingido!\n");
            break;
        }

        printf("==== Cadastro de emprestimo ====\n");

        printf("Codigo do cliente: ");
        scanf("%d", &clientes[total]);

        // ===== ESCOLHA DO LIVRO =====
        do {
            printf("\n--- Catalogo de livros ---\n");
            for (i = 0; i < 5; i++) {
                printf("(%d) [%d] %s\n", i + 1, codigosCatalogo[i], titulosCatalogo[i]);
            }
            printf("(6) Outro livro (nao esta na lista)\n");
            printf("Escolha: ");
            scanf("%d", &escolha);

            if (escolha < 1 || escolha > 6) {
                printf("Opcao invalida! Digite um numero de 1 a 6.\n");
            }
        } while (escolha < 1 || escolha > 6);

        if (escolha == 6) {
            printf("Digite o codigo do livro: ");
            scanf("%d", &livros[total]);
            printf("Digite o nome do livro: ");
            scanf(" %49[^\n]", nomesLivros[total]);
        } else {
            livros[total] = codigosCatalogo[escolha - 1];
            strcpy(nomesLivros[total], titulosCatalogo[escolha - 1]);
        }
        // ===== FIM DA ESCOLHA DO LIVRO =====

        printf("Data de entrega (dd/mm/aaaa): ");
        scanf("%d/%d/%d", &dia[total], &mes[total], &ano[total]);

        printf("\nEmprestimo cadastrado!\n\n");

        printf("--- Dados do emprestimo ---\n");
        printf("Cliente: %d\n", clientes[total]);
        printf("Livro: %d - %s\n", livros[total], nomesLivros[total]);
        printf("Data de entrega: %02d/%02d/%d\n", dia[total], mes[total], ano[total]);

        total = total + 1;

        do {
            printf("\nDeseja cadastrar outro emprestimo?\n");
            printf("(1) Sim\n");
            printf("(0) Nao\n");
            printf("Opcao: ");
            scanf("%d", &opcao);

            if (opcao != 1 && opcao != 0) {
                printf("Opcao invalida! Digite 1 ou 0.\n");
            }
        } while (opcao != 1 && opcao != 0);

        printf("\n");

    } while (opcao == 1);

    // ===== LISTAR TODOS OS EMPRESTIMOS =====
    printf("=================================\n");
    printf("||    LISTA DE EMPRESTIMOS     ||\n");
    printf("=================================\n");

    if (total == 1) {
        printf("1 emprestimo cadastrado.\n\n");
    } else {
        printf("%d emprestimos cadastrados.\n\n", total);
    }

    for (i = 0; i < total; i++) {
        printf("Emprestimo #%d\n", i + 1);
        printf("  Cliente: %d\n", clientes[i]);
        printf("  Livro: %d - %s\n", livros[i], nomesLivros[i]);
        printf("  Data de entrega: %02d/%02d/%d\n", dia[i], mes[i], ano[i]);
        printf("---------------------------------\n");
    }

    printf("\nOBRIGADO POR VIR NA BIBLIOTECA!\n");

    return 0;
}
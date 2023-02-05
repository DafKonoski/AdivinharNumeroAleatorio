#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

printf("\n");
printf("      []  ,----.___ \n");
printf("    __||_/___      '. \n");
printf("   / O||    /|       ) \n");
printf("  /   ""   / /   =._/ \n");
printf(" /________/ / \n");
printf(" |________|/   \n");
printf("\n");

    int segundos = time(0);
    srand(segundos);

    int numerogrande = rand();

    int numerosecreto = numerogrande % 100;

    int chute;
    int tentativas = 1;
    double pontos = 1000;
    int nivel;

    printf("Escolha o level:\n1: Facil\n2: Medio\n3: Dificil\n");
    scanf("%d", &nivel);

    int numerodetentativas;

    switch (nivel){
        case 1:
        numerodetentativas = 20;
        break;
        case 2:
        numerodetentativas = 10;
        break;
        case 3:
        numerodetentativas = 5;
        break;
    
        default:
        printf("Opcao invalida!\n");
        break;
    }

    for(int i = 0; i < numerodetentativas; i++) {

        printf("Tentativa %d\n", tentativas);
        printf("Qual e o seu chute? ");

        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        if(chute < 0) {
            printf("Voce nao pode chutar numeros negativos!\n");
            continue;
        }

        int acertou = (chute == numerosecreto);
        int maior = chute > numerosecreto;

        if(acertou) {
            printf("Parabens! Voce acertou!\n");
            printf("Voce acertou em %d tentativas!\n", tentativas);
            printf("Jogue de novo, voce e um bom jogador!\n");
            printf("Total de pontos: %.1f\n", pontos);

            break;
        }

        else if(maior) {
            printf("Seu chute foi maior que o numero secreto\n");
        } 

        else {
            printf("Seu chute foi menor que o numero secreto\n");
        }

        tentativas++;

        double pontosPerdidos = abs (chute - numerosecreto) / (double) 2;
        pontos = pontos - pontosPerdidos;
        

    }

    printf("Game Over!\n");
    
}
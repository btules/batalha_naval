#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define tamanho 21
    //INICIALIZA O CAMPO DO JOGADOR 1, MOSTRA COMO DEVERA SER POSICIONADO OS NAVIOS
    void inicializa_campo (char linhas [20], char mapa[tamanho][tamanho]){
            //VARIAVEL DE LINHA E COLUNA, COMO NÃO ACHEI OUTRA MANEIRA DE IMPLEMENTAR AS LINHAS
            //CRIEI UM VETOR DE LINHAS E PERCORRI O VETOR
            int linha,coluna;

        //ESTE FOR É SO PARA MOSTRAR AS COLUNAS
            for (int i = 1; i < tamanho; ++i) {
                    if (i <=10){
                        printf("  %d", i);
                    }else if (i>10){
                        printf(" %d", i);
                    }
            }

            printf("\n");
            //AQUI MOSTRA A MATRIZ COM AS LINHAS DE A-T E COLUNA DE 1 A 20
            for (linha = 1; linha < tamanho ; linha ++) {
                printf("%c ", linhas[linha-1]);
                for (coluna = 1; coluna < tamanho ; coluna++) {
                    mapa[linha][coluna] = '~';
                    printf("%c  ", mapa[linha][coluna]);
                }
                printf("\n");
            }
    }

    //INICIALIZA O COMPO DE BATALHA DO JOGADOR DOIS, JA DEIXA PRONTO PARA QUANDO ELE FOR FAZER SEUS DISPAROS
    void inicializa_campobatalha (char linhas[20],char mapa_jogador[tamanho][tamanho]){
        //MESMA COISA DA PRIMEIRA FUNCAO INICIALIZA, EU NÃO QUIS CORRER O RISCO DO MAPA
        //DO JOGADOR 1 INFLUENCIAR NO MAPA DO JOGADOR 2
            int linha,coluna;
        //ESTE FOR É SO PARA MOSTRAR AS COLUNAS
            for (int i = 1; i < tamanho; ++i) {
                if (i <=10){
                    printf("  %d", i);
                }else if (i>10){
                    printf(" %d", i);
                }
            }
            printf("\n");
            for (linha = 1; linha < tamanho ; linha ++) {
                printf("%c ", linhas[linha-1]);
                for (coluna = 1; coluna < tamanho ; coluna++) {
                    mapa_jogador[linha][coluna] = '~';
                    printf("%c  ", mapa_jogador[linha][coluna]);
                }
                printf("\n");
            }
    }

    //FUNCAO QUE POSICIONA OS NAVIOS DO JOGADOR 1
    void posicionar_navio(int contador,int opcao, int posi_linha, int posi_coluna,char linhas[20],char posicao_letra,
                          int conta_linha,char mapa[tamanho][tamanho]){
    int linha,coluna;
    //ESSE VETOR DE CARACTERES SÃO OS NAVIOS, QUANDO O JOGADOR POSICIONA O NAVIO, ELE SO TEM
    //DUAS ALTERNATIVAS HORIZONTAL E VERTICAL, POIS O PROGRAMA JA POSICIONA O RESTANTE PRA ELE
    char navio_1[] = {"00000"};

        while (contador <=2) {
            printf("\n");
            printf("escolha a posicao da linha: \n");
            scanf("%s", &posicao_letra);
            getchar();
            printf("escolha a posicao da coluna: \n");
            scanf("%d", &posi_coluna);
            getchar();
            printf("voce prefere  \n 1- horizontal: \n 2- vertical\n ");
            scanf("%d", &opcao);
            getchar();


            //trata de pegar a letra e transformar em um numero, para a posição da linha
            for (int k = 0; k < 20; ++k) {
                if (linhas[k] == toupper(posicao_letra)) {
                    conta_linha = k;
                }
            }
            posi_linha = conta_linha + 1;
            //trata de pegar a letra e transformar em um numero, para a posição da linha

            //Inicializa esse jogo
            //como eu defini o tamanho dos navios, se passar dessa coluna o navio sai fora do mapa
            while (opcao == 1 && posi_linha >= 17 ) {
                printf("Escolha outra linha e coluna, pois, e fim do mapa \n");
                printf("escolha a posicao da linha: \n");
                scanf("%s", &posicao_letra);
                getchar();
                printf("escolha a posicao da coluna: \n");
                scanf("%d", &posi_coluna);
                getchar();
                printf("voce prefere  \n 1- horizontal: \n 2- vertical ");
                scanf("%d", &opcao);
                getchar();
            }
            //se passar dessa linha o navio sai fora do mapa
            while (opcao == 2 && posi_coluna >= 17) {
                printf("Escolha outra linha e coluna, pois, e fim do mapa \n");
                printf("escolha a posicao da linha: \n");
                scanf("%s", &posicao_letra);
                getchar();
                printf("escolha a posicao da coluna: \n");
                scanf("%d", &posi_coluna);
                getchar();
                printf("voce prefere  \n 1- horizontal: \n 2- vertical ");
                scanf("%d", &opcao);
                getchar();
            }

    //ESTE FOR TRATA DE PERCORRER AS LINHAS E COLUNAS QUE O JOGADOR SELECIONOU E ADICIONAR OS NAVIOS
        for (linha = 1; linha < tamanho; linha++) {
            for (coluna = 1; coluna < tamanho; coluna++) {
                if (opcao == 1 && posi_linha == linha && posi_coluna == coluna) {
                    //ESSE FOR PERCORRE O VETOR DE CARACTERES NAVIO[I], PARA DICIONAR TODOS OS CARACTERES
                    for (int i = 0; i < 5; ++i) {
                        //SE CASO HOUVER UM NAVIO, O PROGRAMA NAO ADICIONA
                        if (mapa[linha][coluna] == '0') {
                            printf("Escolha outra linha e coluna\n");
                            //SE CASO NAO PODER, O CONTADOR NÃO É INCREMENTADO
                            contador--;
                            break;
                        } else {
                            mapa[linha][coluna] = navio_1[i];
                            //COMO É NA HORIZONTAL, ELE SO INCREMENTA A LINHA, POIS A COLUNA DEVE SER A MESMA
                            linha++;
                        }
                    }
                } else if (opcao == 2 && posi_linha == linha && posi_coluna == coluna) {
                    //SE CASO HOUVER UM NAVIO, O PROGRAMA NAO ADICIONA
                    if (mapa[linha][coluna] == '0' ) {
                        printf("Escolha outra linha e coluna\n");
                        contador--;
                        break;
                    }else{
                        for (int j = 0; j < 5; ++j) {
                            //COMO É NA VERTICAL, ELE SO INCREMENTA A COLUNA, POIS A LINHA DEVE SER A MESMA
                            mapa[linha][coluna] = navio_1[j];
                            coluna++;
                        }
                    }
                }
            }
        }
            //MAPA JOGADOR 1
            for (int i = 1; i < tamanho; ++i) {
                if (i <= 10) {
                    printf("  %d", i);
                } else if (i > 10) {
                    printf(" %d", i);
                }
            }
            printf("\n");
            for (linha = 1; linha < tamanho; linha++) {
                printf("%c  ", linhas[linha - 1]);
                for (coluna = 1; coluna < tamanho; coluna++) {
                    printf("%c  ", mapa[linha][coluna]);
                }
                printf("\n");
            }
            contador++;
        }
    }


    int main (){
        //VARIAVEIS "GLOBAIS"
        char linhas [] = {"ABCDEFGHIJKLMNOPQRST"};
        char mapa[tamanho][tamanho];
        char mapa_jogador[tamanho][tamanho], posicao_letra, v[1];
        int linha,coluna, conta_linha = 0;
        char jogador_um[10], jogador_dois[10], jogar[4];
        int tentativas = 30, acertos=0, linha_tiro, coluna_tiro;
        int opcao = 0, contador = 0, posi_linha,posi_coluna;
        int navio_destruido = 0, rodada_jogador_um = 0, rodada_jogador_dois = 0;

        do {
            printf("Batalha naval\n");

            //Trata a escolha de jogadores 1 ou 2
            printf("Informe nome do Jogador 1  \n");
            fgets(jogador_um, 10, stdin);
            printf("Informe nome do Jogador 2 \n");
            fgets(jogador_dois, 10, stdin);
            printf("-------------------------------------------------\n");
            printf("-------- ESCOLHA AS POSICOES DOS NAVIOS ---------\n");
            printf("-------------------------------------------------\n");
            //Inicializa esse jogo
            inicializa_campo(linhas,mapa);
            posicionar_navio(contador, opcao, posi_linha, posi_coluna,linhas,posicao_letra,conta_linha, mapa);

                //AQUI É PRA LIMPAR A TELA DAS POSICOES DOS NAVIOS DO JOGADOR 1
                printf("Aperte V para limpar a tela: ");
                scanf("%s", v);
                getchar();
                    if (strcmp(v, "v") == 0){
                        system("cls");
                    } else{
                        system("clean");
                    }

                //COMECA A PARTE DO JOGADOR 2
                printf("\n%s Sua vez \n", jogador_dois);
                printf(" Voce devera Escolher uma Linha e coluna \nPara Tentar Eliminar os Navios do Jogador 1 \n ");

                //inicializa o mapa do jogador 2
                inicializa_campobatalha(linhas,mapa_jogador);

                //escolhe onde sera dado o tiro
                while (tentativas > acertos || tentativas >= 1) {
                    printf("\n");
                    printf("Escolha uma linha\n");
                    scanf("%s", &posicao_letra);
                    getchar();
                    printf("Escolha uma coluna\n");
                    scanf("%d", &coluna_tiro);
                    getchar();

                        //trata de tranformar a letra em um numero para a matriz
                        for (int i = 0; i < 20; ++i) {
                            if (linhas[i] == toupper(posicao_letra)) {
                                conta_linha = i;
                            }
                        }

                        linha_tiro = conta_linha+1;

                    for (linha = 1; linha < tamanho ; linha ++) {
                        for ( coluna = 1; coluna < tamanho; ++coluna) {
                            if (linha_tiro == linha && coluna_tiro == coluna){
                                //AQUI COMPARA SE NA LINHA E COLUNA DA MATRIZ, QUE FOI INFORMADO, TEM UM CARACTERE DE NAVIO
                                if (mapa[linha][coluna] == '0'){
                                    //SE TIVER ELE AVISA QUE VOCE ACERTOU, E INCREMENTA NO MAPA DO JOGADOR 2,
                                    //NESSA PARTE PROFESSOR, QUE EU FIQUEI COM MEDO DE INFLUENCIA A FUNCAO DE INCIALIZACAO DO MAPA
                                    mapa_jogador[linha][coluna] = mapa[linha][coluna];
                                    printf("Voce Acertou \n");
                                    acertos++;
                                } else{
                                    // SE ERROU ELE ACRESCENTA UM X E INFORMA QUE VOCE  ERROU
                                    printf("Voce errou\n");
                                    mapa_jogador[linha][coluna] = 'X';
                                }
                            }

                        }
                    }
                    //mostra o mapa atualizado, com o acerto ou o erro
                    for (int i = 1; i < tamanho; ++i) {
                        if (i <=10){
                            printf("  %d", i);
                        }else if (i>10){
                            printf(" %d", i);
                        }
                    }

                    printf("\n");

                    for (linha = 1; linha < tamanho; linha++) {
                        printf("%c ", linhas[linha-1]);
                        for (coluna = 1; coluna < tamanho; coluna++) {
                            printf("%c  ", mapa_jogador[linha][coluna]);
                        }
                        printf("\n");
                    }

                    if(acertos == 5){
                        navio_destruido++;
                    }else if( acertos == 10 ) {
                        navio_destruido++;
                    } else if(acertos == 15){
                        navio_destruido++;
                    }

                    //decrementa cada tentativa do jogador
                    tentativas--;
                    //finaliza o jogo quando as tentativas chegarem a 0

                    // CONTA OS ACERTOS, PARA DECLARAR O VENCEDOR 2 SE CASO HOUVER
                    printf(" Tentativas Restantes: %d\nAcertos: %d\n",tentativas,acertos);
                }

                    //AQUI INFORMA QUAL FOI O VENCEDOR
                    if (acertos == 15) {
                        printf("Parabens %s Voce destruiu os %d navios \n",jogador_dois, navio_destruido);
                        rodada_jogador_dois++;
                    } else{
                        printf("Parabens %s\n Escondeu bem os navios \n",jogador_um);
                        rodada_jogador_um++;
                    }

                //PERGUNTA SE DESEJA JOGAR NOVAMENTE
                printf("Deseja jogar novamente: ");
                fgets(jogar,4, stdin);
                getchar();
        }while(strcmp(jogar, "sim") == 0);

        printf(" Jogador 1 %s ganhou %d rodadas \n",jogador_um,rodada_jogador_um);
        printf(" Jogador 2 %s ganhou %d rodadas \n",jogador_dois,rodada_jogador_dois);

        return 0;
    }
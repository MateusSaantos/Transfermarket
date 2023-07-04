#include "jogador.h"
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <time.h>

//IMPRIMIR
void imprime(TPlayer *jogador) {
	printf("\n***********************JOGADOR*******************************");
	//JOGADOR
   printf("\nCODIGO: ");
    printf("%d", jogador->id);
    printf("\nNOME: ");
    printf("%s", jogador->nome);
    printf("\nPOSICAO: ");
    printf("%s", jogador->posicao);
    printf("\nIDADE: ");
    printf("%d", jogador->idade);
    printf("\nSALARIO R$: ");
    printf("%4.2f", jogador->salario);
	printf("\nVALOR DE MERCADO R$: ");
    printf("%4.2f", jogador->valorMercado);
	printf("\nSCORE: ");
    printf("%4.2f", jogador->score);
	printf("\nCONTRATO: ");
    printf("%s", jogador->contrato);

	//CLUBE
	printf("\n************************CLUBE********************************");
	printf("\nCODIGO DO CLUBE: ");
    printf("%d", jogador->clube.id);
	printf("\nNOME DO CLUBE: ");
    printf("%s", jogador->clube.nome);
    printf("\n*************************************************************\n");
}

//IMPRIMIR CLUBE
void imprimeClube(TClub *clube){
    printf("\n************************CLUBE********************************");
	printf("\nCODIGO DO CLUBE: ");
    printf("%d", clube->id);
	printf("\nNOME DO CLUBE: ");
    printf("%s", clube->nome);
    printf("\n*************************************************************\n");
}

// CRIAR JOGADOR
TPlayer *criarJogador(int id, char *nome, char *posicao, int idade, double salario,
                      double valorMercado, float score, char *contrato, TClub *clube) {
    TPlayer *jogador = (TPlayer *) malloc(sizeof(TPlayer));
    if (jogador) memset(jogador, 0, sizeof(TPlayer));
    jogador->id = id;
    strcpy(jogador->nome, nome);
    strcpy(jogador->posicao, posicao);
	jogador->idade = idade;
	jogador->salario = salario;
	jogador->valorMercado = valorMercado;
	jogador->score = score;
    strcpy(jogador->contrato, contrato);

	jogador->clube.id = clube->id;
	strcpy(jogador->clube.nome, clube->nome);
    return jogador;
}

// CRIAR CLUBE
TClub *criarClube(int id, char *nome){
    TClub *clube = (TClub *) malloc(sizeof(TClub));
    if (clube) memset(clube, 0, sizeof(TClub));
    clube->id = id;
    strcpy(clube->nome, nome);
    return clube;
}

// SALVA JOGADOR
void salva(TPlayer *jogador, FILE *out) {
    fwrite(&jogador->id, sizeof(int), 1, out);
    fwrite(jogador->nome, sizeof(char), sizeof(jogador->nome), out);
    fwrite(jogador->posicao, sizeof(char), sizeof(jogador->posicao), out);
    fwrite(&jogador->idade, sizeof(int), 1, out);
    fwrite(&jogador->salario, sizeof(double), 1, out);
	fwrite(&jogador->valorMercado, sizeof(double), 1, out);
	fwrite(&jogador->score, sizeof(float), 1, out);
	fwrite(jogador->contrato, sizeof(char), sizeof(jogador->contrato), out);

	fwrite(&jogador->clube.id, sizeof(int), 1, out);
	fwrite(jogador->clube.nome, sizeof(char), sizeof(jogador->clube.nome), out);
}

// SALVA CLUBE
void salvaClube(TClub *clube, FILE *out){
    fwrite(&clube->id, sizeof(int), 1, out);
    fwrite(clube->nome, sizeof(char), sizeof(clube->nome), out);
}

//LE JOGADOR
TPlayer *le(FILE *out) {
    TPlayer *jogador = (TPlayer *) malloc(sizeof(TPlayer));
    if (0 >= fread(&jogador->id, sizeof(int), 1, out)) {
        free(jogador);
        return NULL;
    }
    fread(jogador->nome, sizeof(char), sizeof(jogador->nome), out);
    fread(jogador->posicao, sizeof(char), sizeof(jogador->posicao), out);
    fread(&jogador->idade, sizeof(int), 1, out);
    fread(&jogador->salario, sizeof(double), 1, out);
	fread(&jogador->valorMercado, sizeof(double), 1, out);
	fread(&jogador->score, sizeof(float), 1, out);
	fread(jogador->contrato, sizeof(char), sizeof(jogador->contrato), out);

	fread(&jogador->clube.id, sizeof(int), 1, out);
	fread(jogador->clube.nome, sizeof(char), sizeof(jogador->clube.nome), out);
    return jogador;
}

//LE CLUBE
void *leClube(FILE *out){
    TClub *clube = (TClub *) malloc(sizeof(TClub));
    if (0 >= fread(&clube->id, sizeof(int), 1, out)) {
        free(clube);
        return NULL;
    }
    fread(clube->nome, sizeof(char), sizeof(clube->nome), out);
    return clube;
}

//INSERE CLUBES
void insereClubes(FILE *out){
    TClub *c1 = criarClube(2, "Cruzeiro");
    salvaClube(c1, out);
    free(c1);
    fflush(out);

    TClub *c2 = criarClube(5, "Atletico-MG");
    salvaClube(c2, out);
    free(c2);
    fflush(out);

    TClub *c3 = criarClube(3, "Vasco");
    salvaClube(c3, out);
    free(c3);
    fflush(out);

    TClub *c4 = criarClube(18, "Flamengo");
    salvaClube(c4, out);
    free(c4);
    fflush(out);

    TClub *c5 = criarClube(10, "Botafogo");
    salvaClube(c5, out);
    free(c5);
    fflush(out);

    TClub *c6 = criarClube(1, "Fluminense");
    salvaClube(c6, out);
    free(c6);
    fflush(out);

    TClub *c7 = criarClube(4, "America-MG");
    salvaClube(c7, out);
    free(c7);
    fflush(out);

    TClub *c8 = criarClube(20, "Sao Paulo");
    salvaClube(c8, out);
    free(c8);
    fflush(out);

    TClub *c9 = criarClube(6, "Palmeiras");
    salvaClube(c9, out);
    free(c9);
    fflush(out);

    TClub *c10 = criarClube(16, "Santos");
    salvaClube(c10, out);
    free(c10);
    fflush(out);

    TClub *c11 = criarClube(7, "Corinthians");
    salvaClube(c11, out);
    free(c11);
    fflush(out);

    TClub *c12 = criarClube(15, "Bragantino");
    salvaClube(c12, out);
    free(c12);
    fflush(out);

    TClub *c13 = criarClube(17, "Gremio");
    salvaClube(c13, out);
    free(c13);
    fflush(out);

    TClub *c14 = criarClube(11, "Internacional");
    salvaClube(c14, out);
    free(c14);
    fflush(out);

    TClub *c15 = criarClube(9, "Athletico-PR");
    salvaClube(c15, out);
    free(c15);
    fflush(out);

    TClub *c16 = criarClube(12, "Coritiba");
    salvaClube(c16, out);
    free(c16);
    fflush(out);

    TClub *c17 = criarClube(8, "Cuiaba");
    salvaClube(c17, out);
    free(c17);
    fflush(out);

    TClub *c18 = criarClube(14, "Goias");
    salvaClube(c18, out);
    free(c18);
    fflush(out);

    TClub *c19 = criarClube(19, "Fortaleza");
    salvaClube(c19, out);
    free(c19);
    fflush(out);

    TClub *c20 = criarClube(13, "Bahia");
    salvaClube(c20, out);
    free(c20);
    fflush(out);
}

//INSERE MULTIPLOS JOGADORES
int insere_multiplos_jogadores(FILE *out) {
    int contador = 0;
    printf("Informe quantos jogadores deseja cadastrar: ");
    scanf("%d", &contador);

    srand(time(NULL));

    int *numeros = malloc(contador * sizeof(int));

    for (int i = 0; i < contador; i++) {
        numeros[i] = i + 1;
    }

    for (int i = contador - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = numeros[i];
        numeros[i] = numeros[j];
        numeros[j] = temp;
    }

    int x = 0;
    for (int i = 0; i < contador; i = i + 10) {
    TClub *c1 = criarClube(2, "Cruzeiro");
    TClub *c2 = criarClube(5, "Atletico-MG");
    TClub *c3 = criarClube(3, "Vasco");
    TClub *c4 = criarClube(18, "Flamengo");
    TClub *c5 = criarClube(10, "Botafogo");
    TClub *c6 = criarClube(1, "Fluminense");
    TClub *c7 = criarClube(4, "America-MG");
    TClub *c8 = criarClube(20, "Sao Paulo");
    TClub *c9 = criarClube(6, "Palmeiras");
    TClub *c10 = criarClube(16, "Santos");
    TClub *c11 = criarClube(7, "Corinthians");
    TClub *c12 = criarClube(15, "Bragantino");
    TClub *c13 = criarClube(17, "Gremio");
    TClub *c14 = criarClube(11, "Internacional");
    TClub *c15 = criarClube(9, "Athletico-PR");
    TClub *c16 = criarClube(12, "Coritiba");
    TClub *c17 = criarClube(8, "Cuiaba");
    TClub *c18 = criarClube(14, "Goias");
    TClub *c19 = criarClube(19, "Fortaleza");
    TClub *c20 = criarClube(13, "Bahia");
    TClub *c21 = criarClube(0, "");

        TPlayer *j1 = criarJogador(numeros[x], "Joao", "Atacante", 28, 35500, 222200, 4.8, "Contrato ate 2024", c1);
        x++;
        salva(j1, out);
        free(j1);

        TPlayer *j2 = criarJogador(numeros[x], "Alexandre", "Meio Campo", 30, 48500, 388200, 4.7, "Contrato ate 2026 ", c2);
        x++;
        salva(j2, out);
        free(j2);

        TPlayer *j3 = criarJogador(numeros[x], "Davi", "Lateral-Direito", 22, 58500, 499200, 4.8, "Fim de 2023", c3);
        x++;
        salva(j3, out);
        free(j3);

        TPlayer *j4 = criarJogador(numeros[x], "Jonas", "Zagueiro", 25, 58500, 455200, 4.8, "Livre no mercado", c21);
        x++;
        salva(j4, out);
        free(j4);

        TPlayer *j5 = criarJogador(numeros[x], "Abel", "Lateral-Esquerdo", 23, 58500, 598200, 6.8, "Contrato ate 2025", c5);
        x++;
        salva(j5, out);
        free(j5);

        TPlayer *j6 = criarJogador(numeros[x], "Rafael", "Goleiro", 27, 56500, 423200, 8.8, "Fim de 2023", c6);
        x++;
        salva(j6, out);
        free(j6);

        TPlayer *j7 = criarJogador(numeros[x], "Lucas", "Atacante", 27, 59500, 467200, 7.8, "Livre no mercado", c21);
        x++;
        salva(j7, out);
        free(j7);

        TPlayer *j8 = criarJogador(numeros[x], "Leandro", "Meio-Campo", 26, 89500, 423200, 8.9, "Fim de 2023", c8);
        x++;
        salva(j8, out);
        free(j8);

        TPlayer *j9 = criarJogador(numeros[x], "Bruno", "Zagueiro", 27, 55500, 412200, 4.8, "Fim de 2025", c9);
        x++;
        salva(j9, out);
        free(j9);

        TPlayer *j10 = criarJogador(numeros[x], "Mateus", "Volante", 29, 55000, 482200, 7.8, "Contrato ate 2027", c10);
        x++;
        salva(j10, out);
        free(j10);
    }
    free(numeros);
    return contador;
}

// LE JOGADORES
void le_jogadores(FILE *in) {
    printf("\n\nLendo jogadores do arquivo...\n\n");
    rewind(in);
    TPlayer *f;
    while ((f = le(in)) != NULL) {
        imprime(f);
        free(f);
    }
}

// LER JOGADORES (IMPRIMIR)
void le_clubes(FILE *in){
    printf("\n\nLendo clubes do arquivo...\n\n");
    rewind(in);
    TClub *c;
    while ((c = leClube(in)) != NULL){
        imprimeClube(c);
        free(c);
    }
}

// BUSCA SEQUENCIAL JOGADOR
void busca_sequencial_jogador(FILE *in){
    int c;
    rewind(in);
    TPlayer *j;
    int found = 0;
    int cont = 0;

    printf("\n\nInforme o codigo do jogador: ");
    scanf("%d", &c);

    clock_t inicio = clock();
    while((j = le(in)) != NULL){
        cont++;
        if (j->id == c){
            printf("Jogador Encontrado!\n");
            imprime(j);
            found = 1;
            break;
        }
        free(j);
    }
    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    if(found){
        printf("\nTempo de execucao da busca: %.2f segundos\n", tempo);
        printf("Numero de comparacoes: %d\n", cont);
    } else {
        printf("Jogador nao pertence a base de dados!...");
        printf("\nNumero de comparacoes: %d\n", cont);
    }
}

//BUSCA SEQUENCIAL CLUBE
void busca_sequencial_clube(FILE *in){
    int c;
    rewind(in);
    TClub *clube;
    int found = 0;
    int cont = 0;

    printf("\n\nInforme o codigo do clube: ");
    scanf("%d", &c);

    clock_t inicio = clock();
    while((clube = leClube(in)) != NULL){
        cont++;
        if (clube->id == c){
            printf("\nClube Encontrado!\n");
            imprimeClube(clube);
            found = 1;
            break;
        }
        free(clube);
    }
    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    if(found){
        printf("\nTempo de execucao da busca: %.2f segundos\n", tempo);
        printf("Numero de comparacoes: %d\n", cont);
    } else {
        printf("Clube nao pertence a base de dados!...");
        printf("\nNumero de comparacoes: %d\n", cont);
    }
}

//TAMANHO DO REGISTRO DE JOGADOR
int tamanho_registro() {
    return sizeof(int) + sizeof(char) * 100 + sizeof(char) * 50 + sizeof(int)
    + sizeof(double) * 2 + sizeof(float) + sizeof(char) * 100 + sizeof(TClub);
}

//TAMANHO DO ARQUIVO JOGADOR
int tamanho_arquivo(FILE *arq) {
  fseek(arq, 0, SEEK_END);
  int tam = trunc(ftell(arq) / tamanho_registro());
  return tam;
}
//TAMANHO REGISTRO DE CLUBE
int tamanho_registro_clube(){
    return sizeof(int)
    + sizeof(char) * 100;
}
//TAMANHO ARQUIVO CLUBE
int tamanho_arquivo_clube(FILE *arq){
  fseek(arq, 0, SEEK_END);
  int tam = trunc(ftell(arq) / tamanho_registro_clube());
  return tam;
}

//ORDENA JOGADORES
void insertion_sort_disco(FILE *arq) {
    int i;
    int tam = tamanho_arquivo(arq);
    //faz o insertion sort
    for (int j = 2; j <= tam; j++) {
        //posiciona o arquivo no registro j
        fseek(arq, (j-1) * tamanho_registro(), SEEK_SET);
        TPlayer *jogj = le(arq);
        printf("\n********* Jogador atual: %d\n", jogj->id);
        i = j - 1;
        //posiciona o cursor no registro i
        fseek(arq, (i-1) * tamanho_registro(), SEEK_SET);
        TPlayer *jogi = le(arq);
        printf("jogi = %d\n", jogi->id);
        while ((i > 0) && (jogi->id > jogj->id)) {
            //posiciona o cursor no registro i+1
            fseek(arq, i * tamanho_registro(), SEEK_SET);
            printf("Salvando jogador %d na posicao %d\n", jogi->id, i+1);
            salva(jogi, arq);
            i = i - 1;
            //posiciona o cursor no registro i
            fseek(arq, (i-1) * tamanho_registro(), SEEK_SET);
            jogi = le(arq);
            printf("jogi = %d; i = %d\n", jogi->id, i);
        }
        //posiciona cursor no registro i + 1
        fseek(arq, (i) * tamanho_registro(), SEEK_SET);
        printf("*** Salvando jogador %d na posicao %d\n", jogj->id, i+1);
        //salva registro j na posicao i
        salva(jogj, arq);
    }
    //descarrega o buffer para ter certeza que dados foram gravados
    fflush(arq);
}

//ORDENAR CLUBES
void insertion_sort_disco_clube(FILE *arq) {
    int i;
    int tam = tamanho_arquivo_clube(arq);
    //faz o insertion sort
    for (int j = 2; j <= tam; j++) {
        //posiciona o arquivo no registro j
        fseek(arq, (j-1) * tamanho_registro_clube(), SEEK_SET);
        TClub *clbj = leClube(arq);
        printf("\n********* Clube atual: %d\n", clbj->id);
        i = j - 1;
        //posiciona o cursor no registro i
        fseek(arq, (i-1) * tamanho_registro_clube(), SEEK_SET);
        TClub *clbi = leClube(arq);
        printf("clbi = %d\n", clbi->id);
        while ((i > 0) && (clbi->id > clbj->id)) {
            //posiciona o cursor no registro i+1
            fseek(arq, i * tamanho_registro_clube(), SEEK_SET);
            printf("Salvando clube %d na posicao %d\n", clbi->id, i+1);
            salvaClube(clbi, arq);
            i = i - 1;
            //posiciona o cursor no registro i
            fseek(arq, (i-1) * tamanho_registro_clube(), SEEK_SET);
            clbi = leClube(arq);
            printf("clbi = %d; i = %d\n", clbi->id, i);
        }
        //posiciona cursor no registro i + 1
        fseek(arq, (i) * tamanho_registro_clube(), SEEK_SET);
        printf("*** Salvando clube %d na posicao %d\n", clbj->id, i+1);
        //salva registro j na posicao i
        salvaClube(clbj, arq);
    }
    //descarrega o buffer para ter certeza que dados foram gravados
    fflush(arq);
}

//BUSCA BINARIA
TPlayer* busca_binaria(FILE *arq) {
  int tam = tamanho_arquivo(arq);
  int cod;
  printf("\nInforme o codigo do jogador: ");
  scanf("%d", &cod);

  int left = 0, right = tam - 1;
  int cont = 0;

  clock_t inicio = clock();

  while (left <= right) {
    int middle = (left + right) / 2;
    fseek(arq, middle * tamanho_registro(), SEEK_SET);
    TPlayer* jog = le(arq);
    cont++;

    if (cod == jog->id) {
      printf("\nJogador Encontrado!\n");
      imprime(jog);
      clock_t fim = clock();
      double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
      printf("\nTempo de execucao: %.2f segundos\n", tempo);
      printf("Numero de comparacoes: %d\n", cont);
      return jog;
    } else if (cod < jog->id) {
      right = middle - 1;
    } else {
      left = middle + 1;
    }

    free(jog);
  }

  printf("Jogador nao pertence a base de dados!...\n");
  printf("Numero de comparacoes: %d\n", cont);

  return NULL;
}

//BUSCA BINARIA CLUBE
TClub* busca_binaria_clube(FILE *arq) {
  int tam = tamanho_arquivo_clube(arq);
  int cod;
  printf("\nInforme o codigo do clube: ");
  scanf("%d", &cod);

  int left = 0, right = tam - 1;
  int cont = 0;

  clock_t inicio = clock();

  while (left <= right) {
    int middle = (left + right) / 2;
    fseek(arq, middle * tamanho_registro_clube(), SEEK_SET);
    TClub* club = leClube(arq);
    cont++;

    if (cod == club->id) {
      printf("\nClube Encontrado!\n");
      imprimeClube(club);
      clock_t fim = clock();
      double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
      printf("\nTempo de execucao: %.2f segundos\n", tempo);
      printf("Numero de comparacoes: %d\n", cont);
      return club;
    } else if (cod < club->id) {
      right = middle - 1;
    } else {
      left = middle + 1;
    }

    free(club);
  }

  printf("Clube nao pertence a base de dados!...\n");
  printf("Numero de comparacoes: %d\n", cont);

  return NULL;
}

//JOGADORES POR CLUBE
void pesquisar_jogadores_clube(FILE *out){
    int contador = 0;
    printf("Informe o codigo do clube que deseja visualizar os jogadores: ");
    scanf("%d", &contador);

    rewind(out);
    TPlayer *f;

    while ((f = le(out)) != NULL) {
        if(f->clube.id == contador){
            imprime(f);
            free(f);
        }
    }
}

// LER JOGADORES (IMPRIMIR)
TClub* pesquisar_clube_codigo(FILE *in, int codigoClube){
    int flag = 0;

    rewind(in);
    TClub *c;
    while ((c = leClube(in)) != NULL){
        if(c->id == codigoClube){
            imprimeClube(c);
            return c;
        }
    }
    c->id = -1;
    return c;
}

void transferencia_jogador(FILE *in, FILE * clube){
    int contador = 0;
    int flag = 0;
    int codigoClube;
    printf("Informe o codigo do jogador que deseja contratar: \n");
    scanf("%d", &contador);

    rewind(in);
    TPlayer *f;
    while ((f = le(in)) != NULL) {
        if(f->id == contador){
            imprime(f);

            printf("Deseja realizar a contratacao do jogador?: \n");
            printf("1 SIM\n");
            printf("2 NAO\n");
            scanf("%d", &flag);

            if(flag == 1){
                printf("Informe o codigo do clube para finalizar a contratacao do jogador: \n");
                scanf("%d", &codigoClube);

                TClub *clubeTransferencia = pesquisar_clube_codigo(clube, codigoClube);

                if(clubeTransferencia->id != -1){

                        //fseek(in, -sizeof(TPlayer), SEEK_CUR); // Move o ponteiro de volta para a posição do jogador
                        strcpy(f->clube.nome, clubeTransferencia->nome);
                        //fwrite(f, sizeof(TPlayer), 1, in); // Salva o jogador com o novo nome

                        //fseek(in, -sizeof(TPlayer), SEEK_CUR); // Move o ponteiro de volta para a posição do jogador
                        f->clube.id = clubeTransferencia->id;
                        //fwrite(f, sizeof(TPlayer), 1, in); // Salva o jogador com o novo nome

                        printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> JOGADOR TRANSFERIDO <<<<<<<<<<<<<<<<<<<<<<<<\n");
                        imprime(f);
                }

                } else {
                    printf("Clube nao encontrado, transacao cancelada! \n");
                }
                printf("Contratacao realizada com sucesso!\n");
                //fclose(in);


                return 0;
            } else if(flag == 2){
                printf("Contratacao cancelada!\n");
                return 0;
            }
        }
        printf("Jogador nao encontrado na base de dados\n");
    }

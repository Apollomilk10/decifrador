

/* Data de submissao: 13/07
 * Nome: Lucas Leite Tavares  
 * RA: 156377
 *
*
/* Tarefa de decifrar uma cifra
 *
 * Dica: veja em referencia/cifrador.c o codigo-fonte do programa
 * que gerou as cifras que voce precisa decifrar!
 */

#include <stdio.h>
#include<stdlib.h>

#define TAM_BUFFER 60 

char buffer_entrada[TAM_BUFFER];
char buffer_saida[TAM_BUFFER];


const char senha[] = "SENHASECRETA";


//Função que descobre quem são as letras do nosso código
char VigenereDec(char X, char Z){
	char K, Y, W;
	if (X>='A' && X<='Z') {
    	K = X -'A';
      Y = Z -'A';
    	W = 'A'+ (K-Y+(26)) % ('Z'-'A'+1); // adicionamos o MOD26 que corresponde a criptografia do código.
    	return W;
  	} else return X;

}

int main() {
  /* Leitura da entrada */
  fgets(buffer_entrada, TAM_BUFFER, stdin);
  int i,j;
  // Organização das palavras de entradas no buffer de entrada e saida.
  for (i=0; (i<TAM_BUFFER) && (buffer_entrada[i]!='\0') && (buffer_entrada[i]!='\n'); i++) {

    buffer_saida[i] = VigenereDec(buffer_entrada[i], senha[j]);
    j++;
    if (senha[j]=='\0') j=0;
  }
  buffer_saida[i]='\0';


  /* Escrever saida na tela */
  printf("%s\n", buffer_saida);

  return 0;
}

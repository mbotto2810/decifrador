/* Tarefa de decifrar uma cifra
 *
 * Dica: veja em referencia/cifrador.c o codigo-fonte do programa
 * que gerou as cifras que voce precisa decifrar!
 */

#include <stdio.h>

#define TAM_BUFFER 100

char buffer_entrada[TAM_BUFFER];
char buffer_saida[TAM_BUFFER];
const char senha[] = "SENHASECRETA";

char decifrador(char a, char b) {
  char caracter_entrada, caracter_senha, aux;
  if (a>='A' && a<='Z') {
    caracter_entrada = a-'A';
    caracter_senha = b-'A';
    aux = caracter_entrada - caracter_senha;
    if (aux>=0){
        return 'A' + aux;
    }
    else {
        return aux + 'Z' + 1;
    }
  } else return a;
}

int main() {
    int j =0;
    int i =0;
  /* Leitura da entrada */
  fgets(buffer_entrada, TAM_BUFFER, stdin);

  for (i=0; (i<TAM_BUFFER) && (buffer_entrada[i]!='\0') && (buffer_entrada[i]!='\n'); i++) {

    buffer_saida[i] = decifrador(buffer_entrada[i], senha[j]);
    j++;
    if (senha[j]=='\0') j=0;
  }
  buffer_saida[i]='\0';

  /* Escrever saida na tela */
  printf("%s\n", buffer_saida);

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Retorna o caractere resultante da criptografia de um caractere
char change(char c){
  if(isalpha(c) && islower(c)) return 'z' + 'a' - c;
  if(isalpha(c)) return 'Z' + 'A' - c;
  if(isdigit(c)) return c - 15;
  if(c == ' ') return '/';
  return c;
}

//Retorna o caractere original a partir de um caractere criptografado
char unchange(char c){
  if(isalpha(c) && islower(c)) return 'z' + 'a' - c;
  if(isalpha(c)) return 'Z' + 'A' - c;
  if(c > 32 && c < 43) return c + 15;
  if(c == '/') return ' ';
  return c;
}

//Criptografa a string
void encrypt(char *str){
  while(*str){
    *str = change(*str);
    str++;
  }
}

//Descriptografa a string
void decrypt(char *str){
  while(*str){
    *str = unchange(*str);
    str++;
  }
}

int main()
{
  char *str = (char *) malloc(1000);
  printf("Insira a string a ser criptografada: ");
  scanf("%[^\n]", str);
  str = realloc(str, strlen(str) + 1);
  printf("\nString inserida: %s\n", str);
  encrypt(str);
  printf("\nString criptografada: %s\n", str);
  decrypt(str);
  printf("\nString descriptografada: %s\n\n", str);
  free(str);
  return 0;
}

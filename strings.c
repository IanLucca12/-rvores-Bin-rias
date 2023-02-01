#include <stdio.h>
#include <string.h>

/*typedef struct cell
{
    char Campo_Chave[100];
    int Linha;
    cell *esquerda;
    cell *direita;
} No;*/
//#ifndef Teste
//#define Teste
typedef struct Teste Teste;
struct teste{
char Chave[100];
int linha;
Teste *direita;
Teste *esquerda;

};


int alfabeto(char str1[100], char str2[100]){      //retorna 1 se a str1 estiver depois no alfabeto
        int i = 0;
        int a = 0;
        int b = 0;

        while(str1[i] != '\0'){
            str1[i] = tolower(str1[i]);
            i = i+1;
        }i=0;
        while(str2[i] != '\0'){
            str2[i] = tolower(str2[i]);
            i = i+1;
        }i=0;
        while(str1[a] != '\0' && str2[b] != '\0'){
        if(str1[a]<=122 && str1[a ]>=97){
            if(str2[b]<=122 && str2[b]>=97){
                if(str1[a]>str2[b]){
                    return 1;
                }else if(str1[a]<str2[b]){
                    return 0;
                }else{a++;
                      b++;}
            }else{b++;}
        }else{a++;}

        }return 0;
}



/*void tree(No *A, int Line, char key[100]){
        if(a!=null){
            if(alfabeto(key, a->esquerda) == -1){
                    tree(a->esquerda, line, key);

            }else{tree(a->direita, Line, key);}
        }else{
            A = (No*)malloc(sizeof(No));
            A -> Linha = Line;
            A -> Campo_Chave = key;
            A -> esquerda = NULL;
            A -> direita = NULL;
        }

}*/


int main() {
   // int count =0;
   // FILE *ptr
   // ptr = fopen("CO2_emissionCorrigido.txt", "r");
    //if (ptr == NULL) {
     //   printf("no such file.");
      //  return 0;
    //}
    char country[100], region[100], sigla[10];
  // char str1[100] = "This is ", str2[100] = "programiz.com";

   // concatenates str1 and str2
   // the resultant string is stored in str1.
   //strcat(str1, str2);

  // printf("%s\n", str1);
  // printf("%s", str2);

 // while(count != 215){
  //  fscanf(ptr,"%s %s %s", country, sigla, region);

  //}

    int a;

    strcpy(country, "Brazil");
    strcpy(region, "Belarus");
    a = alfabeto(region, country);
    printf("%d\n", a);
    printf("%s\n", country);
    printf("%s\n", region);


   return 0;
}

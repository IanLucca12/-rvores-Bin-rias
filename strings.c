#include <stdio.h>
#include <string.h>

typedef struct No No;
struct No{
char Campo_Chave[100];
int Linha;
No *Direita;
No *Esquerda;

};

FILE acessLine(FILE *fp, int line){  /* the first argument is a file pointer that points to the first element of a file*/
                                        /*the second argument is the line u want to acess*/
                                        /*after using this the next fgetc(fp) will point to the first element of the line u wanted to acess*/
    char ch;                            /*see an exemple in the main*/
    int count = 0;
    while(count<line){
        ch = fgetc(fp);
        if(ch == 10){
            count = count+1;
        }
    }
    return *fp;
}


int alfabeto(char str1[100], char str2[100]){      //retorna 1 se a str1 estiver depois no alfabeto
        int i = 0;                                  // caso contrario retorna 0
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



No* tree(No *A, int Line, char Key[100]){
        if(A!=NULL){
            if(alfabeto(Key, A->Esquerda) == 0){
                    tree(A->Esquerda, Line, Key);

            }else{tree(A->Direita, Line, Key);}
        }else{
            A = (No*)malloc(sizeof(No));
            A -> Linha = Line;
            strcpy(A -> Campo_Chave, Key);
            A -> Esquerda = NULL;
            A -> Direita = NULL;
        }

}


int main() {
   // int count =0;
   // FILE *pt
   //char arquivo[26]
   //scanf(arquivo)
   // ptr = fopen(arquivo, "r");
    //if (ptr == NULL) {
     //   printf("no such file.");
      //  return 0;
    //}
    char Country[100], Region[100], Sigla[10];
  // char str1[100] = "This is ", str2[100] = "programiz.com";

   // concatenates str1 and str2
   // the resultant string is stored in str1.
   //strcat(str1, str2);
   /*
   fscanf(%s%s%s,country, sigla,region);
   strcat(country, region);
   tree(pointeiro_para a arvore, linha_do_novo_no, campo_chave)

   */

  // printf("%s\n", str1);
  // printf("%s", str2);

 // while(count != 215){
  //  fscanf(ptr,"%s %s %s", country, sigla, region);

  //}

    int a;

    strcpy(Country, "Brazil");
    strcpy(Region, "Belarus");
    a = alfabeto(Region, Country);
    printf("%d\n", a);
    printf("%s\n", Country);
    printf("%s\n", Region);

    No *Teste = NULL;
    int Linha =15;
    Teste = tree(Teste, 15, "teste");
    printf("saiu da function\n");
    printf("%d\n", Teste->Linha);
    printf("%s\n", Teste->Campo_Chave);
    free(Teste);
    /*vai ter que rodar um laço acessando cada no e dando um free nele*/

   return 0;
}

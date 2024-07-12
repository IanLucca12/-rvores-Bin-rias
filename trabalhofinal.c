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
    int count = 1;
    while(count<line){
        ch = fgetc(fp);
        if(ch == 10){
            count = count+1;
        }
    }
    return *fp;
}

void PrintNo(No* head, char nome_arquivo[30], FILE *fp){ /*parameters: nó raiz, nome do arquivo, ponteiro pro começo do arquivo*/
    int a=1;
    int i=0;
    FILE *fp2, *fp3;
    FILE *copy;
    copy = fopen("Copia.csv","w");
    fp2 = fopen(nome_arquivo,"r");
    char ch;
    if (head->Esquerda==NULL && head->Direita==NULL){
        //printf("option 1");
        a=head->Linha;
        fp2 = fopen(nome_arquivo,"r");
        *fp2 = acessLine(fp2, a);

        while ( 1 ){
        ch = fgetc(fp2);
        //printf("loop1");
        if(ch==10 ||ch==EOF){
            //printf("saiu1\n");
            break;}
            printf("%c",ch);}

        printf("\n");

        }else if(head->Esquerda!=NULL && head->Direita==NULL){
           //printf("option 2");
            PrintNo(head->Esquerda, nome_arquivo, fp);
            a=head->Linha;
            fp2 = fopen(nome_arquivo,"r");
            *fp2 = acessLine(fp2, a);

            while ( 1 ){
            ch = fgetc(fp2);
            //printf("loop2");
            if(ch==10 ||ch==EOF){
                //printf("saiu2\n");
                break;}
                printf("%c",ch);}

                printf("\n");;
        }else if(head->Esquerda==NULL && head->Direita!=NULL){
            //printf("option 3");
            a=head->Linha;
            fp2 = fopen(nome_arquivo,"r");
            *fp2 = acessLine(fp2, a);

            while ( 1 ){
                ch = fgetc(fp2);
               // printf("loop3");
                if(ch==10 ||ch==EOF){
                   // printf("saiu3\n");
                    break;}
                    printf("%c",ch);}

                    printf("\n");
        PrintNo(head->Direita, nome_arquivo,fp);}

        else if(head->Esquerda!=NULL && head->Direita!=NULL){

        printf("option 4");
        PrintNo(head->Esquerda, nome_arquivo,fp);
        a=head->Linha;
            fp2 = fopen(nome_arquivo,"r");
            *fp2 = acessLine(fp2, a);

            while ( 1 ){
            ch = fgetc(fp2);
            //printf("(%c)",ch);
           // printf("loop4");
            if(ch==10 ||ch==EOF){
            //printf("saiu4\n");
            break;}
            printf("%c",ch);}
            printf("\n");
        PrintNo(head->Direita, nome_arquivo,fp);
        }

        fclose(fp2);
        fclose(copy);
}


void liberal_geral(No* head){
    if (head->Esquerda==NULL && head->Direita==NULL){
       free(head);
        }else if(head->Esquerda!=NULL){
            liberal_geral(head->Esquerda);
            free(head->Esquerda);
        }else {
            liberal_geral(head->Direita);
            free(head->Direita);}
}


/*int alfabeto(char str1[100], char str2[100]){      //retorna 1 se a str1 estiver depois no alfabeto
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
}função n está mais sendo usada*/


No* tree(No *A, int Line, char Key[100]){
    if(A == NULL){
        A=(No*)malloc(sizeof(No));
        A->Linha = Line;
        strcpy(A -> Campo_Chave, Key);
            A->Esquerda = NULL;
        A->Direita = NULL;
    }else{
        if((strcmp(Key, A -> Campo_Chave)) == 0){
            A->Esquerda = tree(A->Esquerda,Line,Key);
        }else{
            A->Direita = tree(A->Direita,Line,Key);
        }
    }
    return A;
}


int main() {
   // int count =0;
   FILE *ptr, *ptr2;
   No *Teste = NULL;
   No *B = NULL;
   int linha=1;
   int i=0;
   char ch;
   char Arquivo[30];
   char busca[100];
   char concatenada[100];
   char Country[100], Region[100], Sigla[10], str[50];
do{
   printf("\nDigite a opcao desejada\n");
   printf("1 - Para Carrregar o Arquivo\n");
   printf("2 - Emitir o Relatorio\n");
   printf("3 - Sair \n");
   scanf("%d",&i);
   switch(i){
   case 1:
        printf("digite o nome do arquivo de entrada com a extensao\n");
        scanf("%s",Arquivo);
        ptr=fopen(Arquivo,"r");
            if (ptr == NULL) {
                printf("no such file.\n");
            break;
            }else{
                printf("O arquivo foi aberto\n");
            }
            do{
                fscanf(ptr,"%s%s%s",Country, Sigla,Region);
                strcat(Country, Region);
                Teste = tree(Teste, linha, Country);
                linha++;
                fclose(ptr);
                ptr=fopen(Arquivo,"r");
                *ptr=acessLine(ptr,linha);
                ch = fgetc(ptr);
                printf("%d\n", linha);


            }while(linha!=168);

            ptr=fopen(Arquivo,"r");
        break;
    case 2:
        if(ptr!=NULL){
        PrintNo(Teste,Arquivo,ptr);}
        else{printf("Arquivo Vazio!\n");}
        break;
    case 3:
        liberal_geral(Teste);
        fclose(ptr);
        break;
    default:
        printf("opção incorreta\n");
   }}while(i!=3);
   return 0;
}

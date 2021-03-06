#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum { FALSE, TRUE } bool;

typedef struct tNo {    char caractere;
                        struct tNo * prox;
                    } tNo;

typedef struct {
                tNo* inicio;
                tNo* fim;
                int tam;
               } Lista;


// ***********************************************
// ******************** Initlista ****************
// ***********************************************
bool initString ( Lista* S)
{
    bool r = TRUE;
    S->inicio=NULL;
    S->fim = NULL;
    S->tam = 0;
    return r;
}

// ***********************************************
// ******            empty check            ******
// ***********************************************
bool testavazio(Lista S)
{
    return((S.inicio == NULL)&&(S.fim == NULL));
}
// ***********************************************
// ******                                   ******
// ***********************************************





// ***********************************************
// ******             imprimir              ******
// ***********************************************
void imprimeLista (Lista S) {

int pos =0;

	printf("========================\n");

   if ( S.inicio == NULL)
      printf("Lista Vazia\n");
   else {

      printf("Inicio = %p\n", S.inicio);
      printf("Final = %p\n", S.fim);
      tNo* posAtual = S.inicio;

      do {
          printf("posicao[%i] - dado[%c] -> ponteiro[%p]\n", pos, posAtual->caractere , posAtual);
          posAtual = posAtual->prox;
          pos++;
          } while (posAtual != NULL);
      }
	printf("========================\n");
}
// ***********************************************
// ******              inserir              ******
// ***********************************************


bool inserirItem(Lista* S, char caractere)
{
    bool OK;
    bool r = TRUE;
    tNo* novoNo;

    novoNo = (tNo*) malloc(sizeof(tNo));
        if(novoNo == NULL)
            {
                r = FALSE;
                return r;
            }
     novoNo->caractere = caractere;
     novoNo->prox = NULL;

    OK = testavazio(*S);

    if (OK == TRUE)
        {
            if(S->inicio == NULL)
                {
                    novoNo->caractere = caractere;
                    novoNo->prox = NULL;

                    if (S->fim == NULL) S->fim = novoNo;

                    novoNo->prox = S->fim;
                    S->inicio = novoNo;

                    if(S->inicio == NULL)
                        {
                          printf("Ocorreu um erro na inserção do primeiro termo.");
                        }

                }


        }
        else
        {
                    S->fim->prox = novoNo;
                    S->fim = novoNo;
        }
    S->tam++;
    return r;
}

// ***********************************************
// ******        copia strings              ******
// ***********************************************
bool copiaString(Lista*Original, Lista* Copia)
{
    bool OK,r = TRUE;
    int pos =0;
    char elemento;
    tNo* posOriginal = Original->inicio;

   if ( Original->inicio == NULL)
    {
        printf("Lista Vazia\n");
        r = FALSE;
        return r;
    }

   else {


        do {

          //printf("posicao[%i] - dado[%c] -> ponteiro[%p]\n", pos, posOriginal->caractere , posOriginal);
          elemento = posOriginal->caractere;
          OK = inserirItem(Copia,elemento);
                if(OK == TRUE)
                    {
                    posOriginal = posOriginal->prox;
                    }
                 else
                    {
                        printf("erro na copia da lista.\n");
                    }


          } while (posOriginal != NULL);
      }
   return r;

}

// ***********************************************
// ******           Verificar 2 strings     ******
// ***********************************************
bool verificarStrings(Lista* S1, Lista * S2)
{
    bool OK,r = TRUE;
    int pos,flag =0;
    char elemento,elemento1;
    tNo* posPrimaria = S1->inicio;
    tNo* posSecundaria = S2->inicio;

   if (( S1->inicio == NULL)||(S2->inicio == NULL))
    {
        printf("Lista Vazia\n");
        r = FALSE;
        return r;
    }

   else {


        do {


          elemento = posPrimaria->caractere;
          elemento1 = posSecundaria->caractere;
          if(elemento == elemento1)
                    {
                        //printf("o elemento[%c] está presente nas duas listas.\n",elemento);
                    }
                 else
                    {
                        //printf("o elemento[%c] não está presente nas duas listas.\n",elemento);
                        flag++;
                    }
          posPrimaria =  posPrimaria->prox;
          posSecundaria= posSecundaria->prox;

          } while (posPrimaria != NULL);
      }
   if(flag > 0)
   {
       r = FALSE;
       return r;
   }
   return r;
}


// ***********************************************
// ******              Inverter as letras   ******
// ***********************************************
void inverteFrase(Lista S)
{
char frase[40];
char c;
int pos,i = 0;

	printf("========================\n");

   if ( S.inicio == NULL)
      printf("Lista Vazia\n");
   else {

      printf("Inicio = %p\n", S.inicio);
      printf("Final = %p\n", S.fim);
      tNo* posAtual = S.inicio;


        do
        {
         // printf("posicao[%i] - dado[%c] -> ponteiro[%p]\n", pos ,posAtual->caractere , posAtual);

          frase[i] = posAtual->caractere;
          posAtual = posAtual->prox;
          printf("dado[%c]\n",frase[i]);
          i++;
          pos++;
        }while(posAtual != NULL);

        pos=S.tam;
        printf("tamanho lista[%i]\n" , pos);
        printf("a frase inversa eh :");
        do
        {
          c = frase[pos];
          printf("%c",c);
           pos--;
        }while((pos >= 0 )||( c >= 32)&&(c <= 125));

      }
    printf("\n");
	printf("========================\n");
}




// ***********************************************
// ******              Menu                 ******
// ***********************************************
int menu()
{
    int opcao;
    system("cls");
    printf("|-----------------------------------------------|\n");
    printf("                    |>Testes<|                   \n");
    printf("|-----------------------------------------------|\n");
    printf("\n\n");
    printf("1. Criar uma String vazia.\n");
    printf("2. Criar uma string S1 e copia-la para a string S.\n");
    printf("3. Verificar se S1 e S2 não identicas.\n");
    printf("4. Contar o numero de palavras na string S.\n");
    printf("5. Inverter uma as letras.\n");
    printf("6. Concatenar duas strings.\n");
    printf("7. Intercalar strings.\n");
    printf("8. Inverter as palavras.\n");
    printf("9. Inverter as letras das palavras.\n");
    printf("10. Sair.\n");
    printf("\n\n");
    printf("|-----------------------------------------------|\n");
    printf("Opcao:");
    scanf("%d", &opcao);
    printf("|-----------------------------------------------|\n");
    return opcao;
}


// ***********************************************
// ******        copia strings              ******
// ***********************************************





// ***********************************************
// ***********************************************
// ***********************************************



int main()
{
    int opcao,i,j,tam,contpalavra,volta;
    char c;
    char caracter;
    Lista SVazia,S1,S,S2,S3,S4;
    opcao = 0;
    bool OK,OK1;
    opcao = menu();
    system("cls");

        if(opcao == 1)
        {
            system("cls");
            printf("\n\n");
            printf("Criando uma string vazia...\n\n");
            OK = initString(&SVazia);
                if(OK == TRUE)
                    {
                        OK = testavazio(SVazia);
                            if(OK == TRUE)
                                {
                                printf("\n");
                                printf("String vazia criada com sucesso.\n");
                                printf("\n");
                                }
                    }else
                    {
                        system("cls");
                        printf("Ocorreu um erro na criação da lista vazia.\n");
                    }
            printf("\n\n");
        }

        if(opcao == 2)
        {   i,contpalavra = 0;
            c = '\0';
            system("cls");
            OK = initString(&S1);
            OK1 = initString(&S);
            printf("\n\n");
            printf("Criar uma String[S1] e copiar para outra String[S]...\n\n");
            if((OK == TRUE)&&(OK1 == TRUE))
                {
                    printf("Lista S1 e S criadas com sucesso. \n");
                }
                printf("\n\n");
            printf("insira a String[S1]:\n");
            scanf("%c",&c);
            if((OK == TRUE)&&(OK1 == TRUE))
                {
                    OK = testavazio(S1);
                    OK1 = testavazio(S);
                        if((OK == TRUE)&&(OK1 == TRUE))
                            {
                                //  while(frase[i]!= '.')
                                    for(i=0; i<=200 ;i++)
                                        {
                                                   if(caracter!='.')
                                                {
                                                    scanf("%c",&c);
                                                    caracter = c;
                                                            if(caracter == ' ')
                                                                    {
                                                                        contpalavra++;
                                                                    }

                                                    OK = inserirItem(&S1,caracter);
                                                            if(OK == TRUE)
                                                            {
                                                            printf("inserção[%i] realizada com sucesso.\n",i);
                                                            }else
                                                                {
                                                                    printf("inserção[%i] falhou.\n",i);
                                                                }
                                                    }else
                                                {
                                                contpalavra++;
                                                break;
                                                }

                                        }
                            }
                                }else
                                    {
                                    system("cls");
                                    printf("Ocorreu um erro na criação da lista S1.\n");
                                    }
                    printf("\n\n");
                    //printf("palavras[%i]",contpalavra);
                    printf("\n\n");
                    OK = copiaString(&S1,&S);
                    if(OK == TRUE)
                    {
                    printf("\n\n");
                    printf("String Original [S1]");
                    printf("\n\n");
                    imprimeLista(S1);
                    printf("\n\n");
                    printf("String Copia [S]");
                    printf("\n\n");
                    imprimeLista(S);
                    }else
                    {
                    printf("erro na criacao da copia da lista.\n");
                    }
         OK = verificarStrings(&S1,&S);
         if (OK == TRUE)
         {
          printf("\n\n");
          printf("As Strings sao identicas.\n");
          printf("\n\n");
         }else
         {
          printf("\n\n");
          printf("As Strings não são identicas.\n");
          printf("\n\n");
         }

        }
        if(opcao == 3)
        {
            i,contpalavra = 0;
            c = '\0';
            system("cls");
            OK = initString(&S1);
            OK1 = initString(&S2);
            printf("\n\n");
            printf("Criar uma String[S1] e copiar para outra String[S]...\n\n");
            if((OK == TRUE)&&(OK1 == TRUE))
                {
                    printf("Lista S1 e S criadas com sucesso. \n");
                }
            printf("\n\n");
            printf("insira a String[S1]:\n");
            scanf("%c",&c);
            if(OK == TRUE)
                {
                    OK = testavazio(S1);
                      if(OK == TRUE)
                            {
                                      for(i=0; i<=200 ;i++)
                                        {
                                                   if(caracter!='.')
                                                {
                                                    scanf("%c",&c);
                                                    caracter = c;
                                                            if(caracter == ' ')
                                                                    {
                                                                        contpalavra++;
                                                                    }

                                                    OK = inserirItem(&S1,caracter);
                                                            if(OK == TRUE)
                                                            {
                                                            printf("inserção[%i] realizada com sucesso.\n",i);
                                                            }else
                                                                {
                                                                    printf("inserção[%i] falhou.\n",i);
                                                                }
                                                    }else
                                                {
                                                contpalavra++;
                                                break;
                                                }

                                            }
                                }else
                                    {
                                    system("cls");
                                    printf("Ocorreu um erro na criação da lista S2.\n");
                                    }
            printf("\n\n");
            //printf("palavras[%i]",contpalavra);
            printf("\n\n");
            contpalavra = 0;
            caracter = '\0';
            printf("insira a String[S2]:\n");
            scanf("%c",&c);
            if(OK == TRUE)
                {
                    OK = testavazio(S2);
                      if(OK == TRUE)
                            {
                                      for(i=0; i<=200 ;i++)
                                        {
                                                   if(caracter!='.')
                                                {
                                                    scanf("%c",&c);
                                                    caracter = c;
                                                            if(caracter == ' ')
                                                                    {
                                                                        contpalavra++;
                                                                    }

                                                    OK = inserirItem(&S2,caracter);
                                                            if(OK == TRUE)
                                                            {
                                                            printf("inserção[%i] realizada com sucesso.\n",i);
                                                            }else
                                                                {
                                                                    printf("inserção[%i] falhou.\n",i);
                                                                }
                                                }else
                                                {
                                                contpalavra++;
                                                break;
                                                }

                                            }
                                }else
                                    {
                                    system("cls");
                                    printf("Ocorreu um erro na criação da lista S1.\n");
                                    }


                    printf("\n\n");
                    //printf("palavras[%i]",contpalavra);
                    printf("\n\n");
                    printf("\n\n");
                    }else
                    {
                    printf("erro na criacao da copia da lista.\n");
                    }
         OK = verificarStrings(&S1,&S2);
         if (OK == TRUE)
         {
          printf("\n\n");
          printf("As Strings sao identicas.\n");
          printf("\n\n");
         }else
         {
          printf("\n\n");
          printf("As Strings nao sao identicas.\n");
          printf("\n\n");
         }
            }

         /* voltar ao menu.
          printf("\n\n");
          printf("Deseja voltar ao menu? 1- Sim / 2- Sair do programa.\n");
          printf("\n\n");
          scanf("%i",volta);
          if(volta == 1)
          {
              system("cls");

          }

            */

        }
     if(opcao == 4)
        {
            int i,contpalavra = 0;
            c = '\0';
            caracter='\0';
            system("cls");
            OK = initString(&S3);
            printf("\n\n");
            printf("Criar uma String[S3] e contar quantas palavras...\n\n");
            if(OK == TRUE)
                {
                    printf("Lista S3 criadas com sucesso. \n");
                }
                printf("\n\n");
            printf("insira a String:\n");
            scanf("%c",&c);
            if(OK == TRUE)
                {
                    OK = testavazio(S3);

                        if(OK == TRUE)
                            {
                                //  while(frase[i]!= '.')
                                    for(i=0; i<=200 ;i++)
                                        {
                                                   if(caracter!='.')
                                                {
                                                    scanf("%c",&c);
                                                    caracter = c;
                                                            if(caracter == ' ')
                                                                    {
                                                                        contpalavra++;
                                                                    }

                                                    OK = inserirItem(&S3,caracter);
                                                            if(OK == TRUE)
                                                            {
                                                            //printf("inserção[%i] realizada com sucesso.\n",i);
                                                            }else
                                                                {
                                                                    printf("inserção[%i] falhou.\n",i);
                                                                }
                                                    }else
                                                {
                                                contpalavra++;
                                                break;
                                                }

                                        }
                            }
                                }else
                                    {
                                    system("cls");
                                    printf("Ocorreu um erro na criação da lista S3.\n");
                                    }
                    printf("\n\n");
                    printf("palavras[%i]",contpalavra);
                    printf("\n\n");

        }
      if(opcao == 5)
      {
            int i,contpalavra = 0;
            c = '\0';
            caracter='\0';
            system("cls");
            OK = initString(&S4);
            printf("\n\n");
            printf("Criar uma String[S4] inverter as letras de uma frase...\n\n");
            if(OK == TRUE)
                {
                    printf("Lista S4 criadas com sucesso. \n");
                }
                printf("\n\n");
            printf("insira a String:\n");
            scanf("%c",&c);
            if(OK == TRUE)
                {
                    OK = testavazio(S4);

                        if(OK == TRUE)
                            {
                                    for(i=0; i<=200 ;i++)
                                        {
                                                   if(caracter!='.')
                                                {
                                                    scanf("%c",&c);
                                                    caracter = c;
                                                            if(caracter == ' ')
                                                                    {
                                                                        contpalavra++;
                                                                    }

                                                    OK = inserirItem(&S4,caracter);
                                                            if(OK == TRUE)
                                                            {
                                                            //printf("inserção[%i] realizada com sucesso.\n",i);
                                                            }else
                                                                {
                                                                    printf("inserção[%i] falhou.\n",i);
                                                                }
                                                    }else
                                                {
                                                contpalavra++;
                                                break;
                                                }

                                        }
                            }
                                }else
                                    {
                                    system("cls");
                                    printf("Ocorreu um erro na criação da lista S4.\n");
                                    }
            inverteFrase(S4);

      }

}


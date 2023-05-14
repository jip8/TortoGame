/*

  JOGO TORTO
  Dev By Jip8

  OBJETIVOS:
    Matriz de letras 6x3
    Leitura de input do usuario
    Verificação palavra na matriz
    Printar palavras e quantidade de acertos do usuario

  REGRAS GERAÇÃO DA MATRIZ
    7 ou 8 vogais
    3>= vogais diferentes
    1>= vogal em cada linha
    2<= consoantes na matriz
    Toda consoante com 1>= vogal adjacente
    Não ocorrer repetição na adjacencia

  REGRAS VERIFICAÇÃO
    Input apenas 4>= letras
    Possibilitar apenas sequencias adjacentes 
    Uma posição não pode ser repetida no input

*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int GeraLetra() {
  srand(time(NULL)^(unsigned)rand() << 16);
  char letra = 'a' + rand() % 26;
  return letra;
}

int TestaMatriz(char matriz[6][3]) {
  int boolean=1, len, cont, vogal;
  char str[10];
  for (int i = 0; i<6 ; i++){
    for (int j = 0; j<3 ; j++){
      len=0;
      memset(str, 0, sizeof(str));
      cont=0;
      
      if (
          matriz[i][j]=='a' ||
          matriz[i][j]=='e' ||
          matriz[i][j]=='i' ||
          matriz[i][j]=='o' ||
          matriz[i][j]=='u'
        )
        vogal=1;
      
      else 
        vogal=0;
      
      if (i<5){
        str[cont]=matriz[i+1][j];
        cont++;
        if (j>0){
          str[cont]=matriz[i+1][j-1];
          cont++;
        }
        if (j<2){
          str[cont]=matriz[i+1][j+1];
          cont++;
        }
      }  
      if (i>0){
        str[cont]=matriz[i-1][j];
        cont++;
        if (j>0){
          str[cont]=matriz[i-1][j-1];
          cont++;
        }
        if (j<2){
          str[cont]=matriz[i-1][j+1];
          cont++;
        }
      }
      if (j>0){
        str[cont]=matriz[i][j-1];
        cont++;
      }
      if (j<2){
        str[cont]=matriz[i][j+1];
        cont++;
      }
      
      len = strlen(str);

      if (vogal==1){
        for (int k = 0 ; k<len ;k++){
          for (int l = k+1 ; l<len;l++){
            if (str[k]==str[l])
              boolean=0;
          }
        }
      }
      else {
        for (int k = 0 ; k<len ;k++){
          for (int l = k+1 ; l<len;l++){
            if (str[k]==str[l])
              boolean=0;
            if (
                  matriz[k][l]=='a' ||
                  matriz[k][l]=='e' ||
                  matriz[k][l]=='i' ||
                  matriz[k][l]=='o' ||
                  matriz[k][l]=='u'
                )
              vogal++;
          }
        }
      }
      if (vogal==0)
        boolean=0;
    }
  } 
  return boolean;
}

int VerificaPalavra(char matriz[6][3],char str[20]) {
  int pos;
  int teste[6][3];
  char strAux[18];
  for(int i = 0;i<6;i++){
    for (int j = 0;j<3;j++){
      pos=0;
      if (matriz[i][j]==str[pos]){
        memset(teste, 0, sizeof(teste));
        memset(strAux, 0, sizeof(strAux));
        teste [i][j]=1;
        int k=i,l=j;
        strAux[pos]=str[pos];
        pos=1;
        while(1){
          if (k<5){
            if (matriz[k+1][l]==str[pos] && !teste[k+1][l]){
              strAux[pos]=matriz[k+1][l];
              
              if (strcmp(strAux, str) == 0)
                return 1;

              pos++;
              k++;
              teste [k][l]=1;
              continue;
            }
            if (l>0){
              if (matriz[k+1][l-1]==str[pos] && !teste[k+1][l-1]){
                strAux[pos]=matriz[k+1][l-1];
                
                if (strcmp(strAux, str) == 0)
                  return 1;
                
                pos++;
                k++;
                l--;
                teste [k][l]=1;
                continue;
              }
            }
            if (l<2){
              if (matriz[k+1][l+1]==str[pos] && !teste[k+1][l+1]){
                strAux[pos]=matriz[k+1][l+1];
                
                if (strcmp(strAux, str) == 0)
                  return 1;
                
                pos++;
                k++;
                l++;
                teste [k][l]=1;
                continue;
              }
            }
          }  
          if (k>0){
            if (matriz[k-1][l]==str[pos] && !teste[k-1][l]){
              strAux[pos]=matriz[k-1][l];
              
              if (strcmp(strAux, str) == 0)
                return 1;
              
              pos++;
              k--;
              teste [k][l]=1;
              continue;
            }
            if (l>0){
              if (matriz[k-1][l-1]==str[pos] && !teste[k-1][l-1]){
                strAux[pos]=matriz[k-1][l-1];
                
                if (strcmp(strAux, str) == 0)
                  return 1;
                
                pos++;
                k--;
                l--;
                teste [k][l]=1;
                continue;
              }
            }
            if (l<2){
              if (matriz[k-1][l+1]==str[pos] && !teste[k-1][j+1]){
                strAux[pos]=matriz[k-1][l+1];
                
                if (strcmp(strAux, str) == 0)
                  return 1;
                
                pos++;
                k--;
                l++;
                teste [k][l]=1;
                continue;
              }
            }
          }
          if (l>0){
            if (matriz[k][l-1]==str[pos] && !teste[k][l-1]){
              strAux[pos]=matriz[k][l-1];
              
              if (strcmp(strAux, str) == 0)
                return 1;
              
              pos++;
              l--;
              teste [k][l]=1;
              continue;
            }
          }
          if (l<2){
            if (matriz[k][l+1]==str[pos] && !teste[k][l+1]){
              strAux[pos]=matriz[k][l+1];
              
              if (strcmp(strAux, str) == 0)
                return 1;
              
              pos++;
              l++;
              teste [k][l]=1;
              continue;
            }
          }
          break;
        }
      }
    }
  }
  return 0;
}


int main() {
  int flag=0, Cont;
  char matriz[6][3];
  while (flag==0){
    Cont=0;
    for (int i = 0;i<6;i++){
      for (int j = 0;j<3;j++){
        matriz[i][j]=GeraLetra();
        if (
            matriz[i][j]=='a' ||
            matriz[i][j]=='e' ||
            matriz[i][j]=='i' ||
            matriz[i][j]=='o' ||
            matriz[i][j]=='u'
          )
            Cont++;
      }
    }
    if (Cont==7 || Cont==8){
      //flag=1;
      Cont=0;
      int flag1=0;
      for (int i = 0;i<6;i++){
        for (int j = 0;j<3;j++){
          if (matriz[i][j]=='a'){
            flag1=1;
            break;
          }
        }
      }
      if (flag1==1)
        Cont++;
    
      flag1=0;
      for (int i = 0;i<6;i++){
        for (int j = 0;j<3;j++){
          if (matriz[i][j]=='e'){
            flag1=1;
            break;
          }
        }
      }
      if (flag1==1)
        Cont++;

      flag1=0;
      for (int i = 0;i<6;i++){
        for (int j = 0;j<3;j++){
          if (matriz[i][j]=='i'){
            flag1=1;
            break;
          }
        }
      }
      if (flag1==1)
        Cont++;

      flag1=0;
      for (int i = 0;i<6;i++){
        for (int j = 0;j<3;j++){
          if (matriz[i][j]=='o'){
            flag1=1;
            break;
          }
        }
      }
      if (flag1==1)
        Cont++;

      flag1=0;
      for (int i = 0;i<6;i++){
        for (int j = 0;j<3;j++){
          if (matriz[i][j]=='u'){
            flag1=1;
            break;
          }
        }
      }
      if (flag1==1)
        Cont++;

    
      if (Cont>2){
        //flag=1;
        flag1=0;
        for (int i = 0;i<6;i++){
          Cont=0;
          for (int j = 0;j<3;j++){
            if ( 
                matriz[i][j]=='a' || 
                matriz[i][j]=='e' ||
                matriz[i][j]=='i' ||
                matriz[i][j]=='o' ||
                matriz[i][j]=='u'
              )
              break;
            Cont--;
          }
          if (Cont==-3)
            break;
          flag1++;
        }
        if (flag1==6) {
          //flag=1;
          flag1=0;
          for (int i = 0;i<6;i++){
            for (int j = 0;j<3;j++){
              Cont=0;
              if (
                matriz[i][j]!='a' || 
                matriz[i][j]!='e' ||
                matriz[i][j]!='i' ||
                matriz[i][j]!='o' ||
                matriz[i][j]!='u'
              ){
                for (int k = 0;k<6;k++){
                  for (int l = 0;l<3;l++){
                    if (matriz[i][j]==matriz[k][l]){
                      Cont++;
                    }
                  }
                }
              }
              if (Cont>2){
                flag1=1;  
              }
            }
          }
          if (flag1==0){
            flag1=TestaMatriz(matriz);
            if (flag1==1)
              flag=1;
          }
        }
      } 
    }
  }

  while (flag){
    for (int i = 0;i<6;i++){
      printf("\n");
      for (int j = 0;j<3;j++){
         printf("%c ", matriz[i][j]);
      }
    }
    int flag1=1, len;
    char str[20];
    printf("\nIndique uma palavra:\n");
    while (flag1){
      scanf(" %19[^\n]", str);
      fflush(stdin);
      len = strlen(str);
      if (len < 4 || len > 18)
        printf("\nIndique uma palavra com 4 a 18 letras:\n");
      else
        flag1=0;
    }
    
    flag1 = VerificaPalavra(matriz, str);
    printf("flag1: %i", flag1);
    if (flag1==1)
      printf("\n");
    else
      printf("\n");
  }  
  return 0;
}


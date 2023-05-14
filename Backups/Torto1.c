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
  int boolean=0, vogal=0, cont;
  char str[10];
  for (int i = 0; i<6 ; i++){
    for (int j = 0; j<3 ; j++){
      if (
          matriz[i][j]=='a' ||
          matriz[i][j]=='e' ||
          matriz[i][j]=='i' ||
          matriz[i][j]=='o' ||
          matriz[i][j]=='u'
        )
        vogal=1;
      
      else {
        vogal=0;
      }
      memset(str, 0, sizeof(str));
      cont=0;
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
        if (j<3){
          str[cont]=matriz[i-1][j+1];
          cont++;
        }
      }
      if (j>0){
        str[cont]=matriz[i+1][j];
        cont++;
      }
      if (j<2){
        str[cont]=matriz[i][j+1];
        cont++;
      }
      int len = strlen(str);
      
      cont=0;
      if (vogal==1){
        for (int i = 0; str[i]<len ;i++){
          for (int j = i+1;str[j]<len;j++){
            if (str[i]==str[j])
              boolean=0;
          }
        }
      }
      else {
        for (int i = 0; str[i]<len ;i++){
          for (int j = i+1;str[j]<len;j++){
            if (str[i]==str[j])
              boolean=0;
            if (
                matriz[i][j]=='a' ||
                matriz[i][j]=='e' ||
                matriz[i][j]=='i' ||
                matriz[i][j]=='o' ||
                matriz[i][j]=='u'
              )
              vogal++;
          }
        }
      }
      if (vogal==0)
        boolean=0;
    }
  }
  printf("%i",boolean);
  return boolean;
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
            if (flag1)
              flag=1;
          }        ///////////////parei aqui/////////////////
        }
      } 
    }
  }


  
  for (int i = 0;i<6;i++){
    printf("\n");
    for (int j = 0;j<3;j++){
       printf("%c ", matriz[i][j]);
    }
  }
  
  return 0;
}

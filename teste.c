#include <stdio.h>
#include <string.h>

int VerificaPalavra(char matriz[6][3],char str[20]) {
  int pos;
  //int posI[18], posJ[18];
  char strAux[18];
  for(int i = 0;i<6;i++){
    for (int j = 0;j<3;j++){
      pos=0;
      if (matriz[i][j]==str[pos]){
        memset(strAux, 0, sizeof(strAux));
        int k=i,l=j;
        strAux[pos]=str[pos];
        pos=1;
        while(1){
          if (k<5){
            if (matriz[k+1][l]==str[pos]){
              strAux[pos]=matriz[k+1][l];
              
              if (strcmp(strAux, str) == 0)
                return 1;

              pos++;
              k++;
              continue;
            }
            if (l>0){
              if (matriz[k+1][l-1]==str[pos]){
                strAux[pos]=matriz[k+1][l-1];
                
                if (strcmp(strAux, str) == 0)
                  return 1;
                
                pos++;
                k++;
                l--;
                continue;
              }
            }
            if (l<2){
              if (matriz[k+1][l+1]==str[pos]){
                strAux[pos]=matriz[k+1][l+1];
                
                if (strcmp(strAux, str) == 0)
                  return 1;
                
                pos++;
                k++;
                l++;
                continue;
              }
            }
          }  
          if (k>0){
            if (matriz[k-1][l]==str[pos]){
              strAux[pos]=matriz[k-1][l];
              
              if (strcmp(strAux, str) == 0)
                return 1;
              
              pos++;
              k--;
              continue;
            }
            if (l>0){
              if (matriz[k-1][l-1]==str[pos]){
                strAux[pos]=matriz[k-1][l-1];
                
                if (strcmp(strAux, str) == 0)
                  return 1;
                
                pos++;
                k--;
                l--;
                continue;
              }
            }
            if (l<2){
              if (matriz[k-1][l+1]==str[pos]){
                strAux[pos]=matriz[k-1][l+1];
                
                if (strcmp(strAux, str) == 0)
                  return 1;
                
                pos++;
                k--;
                l++;
                continue;
              }
            }
          }
          if (l>0){
            if (matriz[k][l-1]==str[pos]){
              strAux[pos]=matriz[k][l-1];
              
              if (strcmp(strAux, str) == 0)
                return 1;
              
              pos++;
              l--;
              continue;
            }
          }
          if (l<2){
            if (matriz[k][l+1]==str[pos]){
              strAux[pos]=matriz[k][l+1];
              
              if (strcmp(strAux, str) == 0)
                return 1;
              
              pos++;
              l++;
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
  char matriz[6][3] = {
    {'a', 'b', 'c'},
    {'d', 'e', 'f'},
    {'g', 'h', 'i'},
    {'j', 'k', 'l'},
    {'m', 'n', 'o'},
    {'p', 'q', 'r'}
  };
  
  char palavra1[] = "abc";
  char palavra2[] = "jkl";
  char palavra3[] = "ghi";
  char palavra4[] = "pqr";
  char palavra5[] = "mnopq";
  
  printf("Palavra %s encontrada? %d\n", palavra1, VerificaPalavra(matriz, palavra1));
  printf("Palavra %s encontrada? %d\n", palavra2, VerificaPalavra(matriz, palavra2));
  printf("Palavra %s encontrada? %d\n", palavra3, VerificaPalavra(matriz, palavra3));
  printf("Palavra %s encontrada? %d\n", palavra4, VerificaPalavra(matriz, palavra4));
  printf("Palavra %s encontrada? %d\n", palavra5, VerificaPalavra(matriz, palavra5));
  
  return 0;
}
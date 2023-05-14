#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0 

int main(){

    FILE *input;
    input = fopen("input/entrada1.txt","r");
    int n;
    fscanf(input,"%d\n",&n);
    char matriz[n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            fscanf(input, "%c", &matriz[i][j]);
        fscanf(input,"\n");
    }

    int matriz_binaria[n][n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) {
            if (matriz[i][j] == 'V')
                matriz_binaria[i][j]=1;
            else    
                matriz_binaria[i][j]=0;
        }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            printf("%d", matriz_binaria[i][j]);
        printf("\n");
    }

    


return 0;
}

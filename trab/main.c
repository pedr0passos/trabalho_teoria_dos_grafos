#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0 

void imprime(int n,int matriz[n][n]);
void rgraph(FILE *input, int n, char tabela[n][n]);
void create_adj( int n, char tabela[n][n], int m_adj[n][n]);

int main(){

    int n; // total de vertices 
    FILE *input;
    input = fopen("input/entrada1.txt","r");
    fscanf(input,"%d\n",&n);

    int numero_familias=0;
    char tabela[n][n];
    int matriz_adj[n][n];
    
    rgraph(input, n, tabela);
    fclose(input);

    create_adj(n, tabela, matriz_adj);

    for (int x=0; x<n; x++) {
        for(int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i!=j) {
                    
                }
            }
        }
    }

imprime(n, matriz_adj);

return 0;
}

void imprime(int n, int matriz[n][n]) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++)
                printf("%d", matriz[i][j]);
        printf("\n");
    }
}

void rgraph(FILE *input, int n, char tabela[n][n]) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            fscanf(input, "%c", &tabela[i][j]);
        fscanf(input,"\n");
    }
}

void create_adj( int n, char tabela[n][n], int m_adj[n][n]) {
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) {
            if (i==j)
                if(tabela[i][j]=='F'){
                    printf("INFELIZMENTE OS C(K)AIOS ESTAVAM BEBADOS");
                    exit(1);
                }
            if ( tabela[i][j] == 'V')            
                m_adj[i][j]=1;
            else   
                m_adj[i][j]=0;
        }
}

void familias(int n, int m_adj[n][n], int n_familias, int *familias) {
    int i,j,x;
    for (i=0; i<n; i++) {
        j=0;
        while (j<n)
            x = n+1;
            while(x<n) {
                if (m_adj[i][j] == m_adj[x][j]) {
                    j++;
                    if (j == n) {
                        
                        familias[i] = familias[x] = n_familias;
                        x++;
                        j=0;
                    }
                } else {
                    x++;
                    j=0;
                }         
            }
    }

}


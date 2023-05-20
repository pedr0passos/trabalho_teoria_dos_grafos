#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

void rgraph(FILE *input, int n, char tabela[n][n]);
void create_adj( int n, char tabela[n][n], int m_adj[n][n]);
int n_familias(int n, int m_adj[n][n], int *visitado);
void n_familias2(int n, int m_adj[n][n], int *visitado, int vertice, int n_familias);
void conta_graus(int n, int m_adj[n][n], int *graus);
void conta_vertices(int n, int *visitado, int numero_familias, int *total);
void verifica (int n, int numero_familias, int *total_familias, int *graus, int *visitado);

int main(){

    int n;
    FILE *input = fopen("input/entrada1.txt","r");
    fscanf(input,"%d\n",&n);
    
    char tabela[n][n];
    int visitado[n];
    int matriz_adj[n][n];
    int numero_familias;
    int graus[n];

    rgraph(input, n, tabela);
    fclose(input);
    create_adj(n, tabela, matriz_adj);
    conta_graus(n, matriz_adj, graus);

    numero_familias = n_familias(n, matriz_adj, visitado);
    int total_familias[numero_familias+1];

    conta_vertices(n, visitado, numero_familias, total_familias);
    verifica(n, numero_familias, total_familias, graus, visitado);

    return 0;
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

int n_familias(int n, int m_adj[n][n], int *visitado) {
    int n_familias=0;
    int i;
    for (i=0; i<n; i++)
        visitado[i]=-1;
    for (i=0; i<n; i++)
        if(visitado[i]==-1) {
            n_familias++;
            n_familias2(n, m_adj, visitado, i, n_familias);
        }
    return n_familias;
}

void n_familias2(int n, int m_adj[n][n], int *visitado, int vertice, int n_familias) {
    visitado[vertice] = n_familias;
    for(int j=0; j<n; j++)
        if ( m_adj[vertice][j] == 1)
            if (visitado[j] == -1)
                n_familias2(n, m_adj, visitado, j, n_familias);
}

void conta_graus(int n, int m_adj[n][n], int *graus) {
    int i, j;
    int contador;
    for (i=0; i<n; i++) {
        contador=0;
        for(j=0; j<n; j++)
            if (m_adj[i][j] != 0 && i!=j) 
                contador++;
        graus[i]=contador;
    }
}

void conta_vertices(int n, int *visitado, int numero_familias, int *total) {
    int contador;
    for(int i=1; i<=numero_familias; i++) {
        contador=0;
        for(int j=0; j<n; j++)
            if(visitado[j] == i)
                contador++;
        total[i] = contador;
    }
}

void verifica (int n, int numero_familias, int *total_familias, int *graus, int *visitado) {
    int grau_max;
    int verdadeiro;
    int i, j;
    for(i=1; i<=numero_familias; i++) {
        grau_max = total_familias[i]-1;
        for (j=0; j<n; j++)
            if ( visitado[j] == i )
                if ( graus[j] != grau_max ) {
                    verdadeiro = false;
                    break;
                } else
                    verdadeiro = true;  
    }
    if (verdadeiro) {
        printf("%d\n", numero_familias);
        for(int i=1;i<=numero_familias;i++) 
            printf("%d ", total_familias[i]);
    } else
        printf("INFELIZMENTE OS C(K)AIOS ESTAVAM BEBADOS\n");
}
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

void rgraph(FILE *input, int n, char matriz[n][n]);
int n_familias(int n, char matriz[n][n], int *visitados);
void n_familias2(int n, char matriz[n][n], int *visitados, int vertice, int n_familias);
void conta_graus(int n, char matriz[n][n], int *graus);
void conta_vertices(int n, int *visitados, int numero_familias, int *total);
void verifica (int n, int numero_familias, int *total_familias, int *graus, int *visitados);

int main(){

    int n;
    FILE *input = fopen("input/entradas_novas/12.txt","r");
    fscanf(input,"%d\n",&n);
    
    char matriz[n][n];
    int visitados[n];
    int numero_familias;
    int graus[n];

    rgraph(input, n, matriz);
    fclose(input);
    conta_graus(n, matriz, graus);

    numero_familias = n_familias(n, matriz, visitados);
    int total_familias[numero_familias+1];

    conta_vertices(n, visitados, numero_familias, total_familias);
    verifica(n, numero_familias, total_familias, graus, visitados);

    return 0;
}

void rgraph(FILE *input, int n, char matriz[n][n]) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            fscanf(input, "%c", &matriz[i][j]);
            if (i==j && matriz[i][j] == 'F') {
                printf("INFELIZMENTE OS C(K)AIOS ESTAVAM BEBADOS\n");
                exit(1);
            }
        }
        fscanf(input,"\n");
    }
}

int n_familias(int n, char matriz[n][n], int *visitados) {
    int n_familias=0, i;
    for (i=0; i<n; i++)
        visitados[i]=-1;
    for (i=0; i<n; i++)
        if(visitados[i]==-1) {
            n_familias++;
            n_familias2(n, matriz, visitados, i, n_familias);
        }
    return n_familias;
}

void n_familias2(int n, char matriz[n][n], int *visitados, int vertice, int n_familias) {
    visitados[vertice] = n_familias;
    for(int j=0; j<n; j++)
        if ( matriz[vertice][j] == 'V' && visitados[j] == -1)
                n_familias2(n, matriz, visitados, j, n_familias);
}

void conta_graus(int n, char matriz[n][n], int *graus) {
    int i, j, contador;
    for (i=0; i<n; i++) {
        contador=0;
        for(j=0; j<n; j++)
            if (matriz[i][j] == 'V' && i!=j) 
                contador++;
        graus[i]=contador;
    }
}

void conta_vertices(int n, int *visitados, int numero_familias, int *total) {
    int contador;
    for(int i=1; i<=numero_familias; i++) {
        contador=0;
        for(int j=0; j<n; j++)
            if(visitados[j] == i)
                contador++;
        total[i] = contador;
    }
}

void verifica (int n, int numero_familias, int *total_familias, int *graus, int *visitados) {
    int grau_max,completos=true,i,j;
    for(i=1; i<=numero_familias; i++) {
        if (!completos)
            break;
        grau_max = total_familias[i]-1;
        for (j=0; j<n; j++)
            if (visitados[j] == i)
                if ( graus[j] != grau_max ) {
                    completos = false;
                    break;
                } else
                    completos = true;  
    }
    if (completos) {
        printf("%d\n", numero_familias);
        for(int i=1;i<=numero_familias;i++) 
            printf("%d ", total_familias[i]);
    } else
        printf("INFELIZMENTE OS C(K)AIOS ESTAVAM BEBADOS\n");
}
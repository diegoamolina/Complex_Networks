#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

#include "Conexiones.c"
#include "Propiedades y funciones.c"
#include "Dinamicas.c"

int main(void)
{

    /*Definimos las  variables del programa */

    int N; //Cantidad de nodos total de la red

    int N0; //Cantidad de nodos interconectados ( - En cuarentena cantidad de habitantes por hogar)

    int L; //Cantidad de conexiones para cada nodo nuevo (Solo para conexión preferencial)

    int C; //Cantidad de contactos aleatorios de un solo nodo por casa (Solo para conexión cuarentena)

    int D; //Cantidad de pasos para que un Infectado se considere asintomático. (Solo para SIR_con_asintomaticos)

    int T; //Cantidad de testeos aleatorios por paso (Solo para SIR_con_asintomaticos)

    /* Inicialización de variables del programa (comentar para hacer un bucle sobre variables)*/

    N = 5040; // En cuarentena se recomienda N = múltiplo de N0 (40320 = 8!)

    //N0 = 4;

    L = 1;

    //C = 4; //Debe ser menor o igual a N-N0-(N/N0)

    D = 15;

    T = N;

    /* Definicion de variables tontas */

    int i,j,R;
    float dp,cl;
    char c[20];

    for(N0=2;N0<=7;N0++)
    {
        printf("N0 = %d \n ",N0);
        FILE *Archivo;
        sprintf(c,"Estadisticas-N0-%d .txt",N0);
        Archivo = fopen( c , "w" );
        fprintf(Archivo,"N0 \t C \t cl \t R \n");

        for(C=1 ; C<=10 ; C++)
        {
            printf("C = %d \n ",C);
    /* Definimos y asignamos memoria a la red */

            int **red;

            red = malloc(N*2*sizeof(int));

            for(i=0; i<N ; i++)
            {
                red[i] = malloc(N0*sizeof(int));
            }

    /* Conectamos la red */

            //conectar_preferencial(red,N,N0,L);

            conectar_cuarentena(red,N,N0,C);

    /* Propiedades y Coeficientes estructurales */

            //mat_dist(red,N);

            //radio(red,N);

            cl = cluster_coef(red,N);

            //dp = dist_prom(red,N);

            //smallworldness(red,N);

            //conectividad(red);

    /* Impresion y exportaciones de red */

            //imprimir_red(red,N);

            //exportar_bat(red);

    /* Inicio de dinámicas */

            R = SIR(red,N,N0,C);

            //SIR_con_asintomaticos(red,N,D,T);

    /* Resultados */

            fprintf(Archivo,"%d \t %d \t %f \t %d \n", N0, C, cl, R);

            free(red);
        }

        fclose(Archivo);
    }

    return 0;
}




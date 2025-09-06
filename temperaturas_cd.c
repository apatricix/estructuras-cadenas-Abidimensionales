#include <stdio.h>
#include <string.h>
#define N 4
#define M 6

void imprimir_ciudad(char *ciudad, char *ciudades[N], char *meses[M], float temperaturas[N][M]);
void imprimir_mes(char *mes, char *ciudades[N], char *meses[M], float temperaturas[N][M]);
void min_max(char *ciudades[N], float temperaturas[N][M]);

int main()
{
    float temperaturas[N][M] = {
        {5.2, 7.1, 12.3, 18.5, 23.1, 26.8},
        {4.1, 5.3, 8.7, 12.4, 16.9, 20.2},
        {0.8, 2.9, 8.1, 14.7, 20.3, 25.1},
        {18.2, 21.3, 24.8, 26.1, 27.9, 26.4}
    };

    char *ciudades[N] = {"tokio", "londres", "nueva york", "ciudad de mexico"};
    char *meses[M] = {"enero", "febrero", "marzo", "abril", "mayo", "junio"};

    int clasificacion;
    char option[30];

    do
    {
        printf("seleccione la opcion que necesita: 1)temperatura por ciudad  2) temperatura por mes  3) minimo y maximo ");
        scanf("%d", &clasificacion);
        if(clasificacion==1)
        {
            printf("ciudad: ");
            scanf(" %[^\n]", option);
            imprimir_ciudad(option, ciudades, meses, temperaturas);
        }
        else if(clasificacion==2)
        {
            printf("mes: ");
            scanf(" %[^\n]", option);
            imprimir_mes(option, ciudades, meses, temperaturas);
        }
        else if(clasificacion==3)
        {
            min_max(ciudades, temperaturas);
        }
    }
    while(clasificacion<4);
    return 0;
}

void imprimir_ciudad(char *ciudad, char *ciudades[N], char *meses[M], float temperaturas[N][M])
{
    for(int i=0; i<N; i++)
    {
        if(strcmp(ciudad, ciudades[i])==0)
        {
            for(int j=0; j<M; j++)
            {
                printf("%s: %.2f\n", meses[j], temperaturas[i][j]);
            }
            return;
        }
    }
}

void imprimir_mes(char *mes, char *ciudades[N], char *meses[M], float temperaturas[N][M])
{
    for(int j=0; j<M; j++)
    {
        if(strcmp(mes, meses[j])==0)
        {
            for(int i=0; i<N; i++)
            {
                printf("%s: %.2f\n", ciudades[i], temperaturas[i][j]);
            }
            return;
        }
    }

}

void min_max(char *ciudades[N], float temperaturas[N][M])
{
    float min = temperaturas[0][0], max = temperaturas[0][0];
    char cdMin[30], cdMax[30];
    strcpy(cdMin, ciudades[0]);
    strcpy(cdMax, ciudades[0]);

    for(int i=0;i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(temperaturas[i][j]<min)
            {
                min=temperaturas[i][j];
                strcpy(cdMin, ciudades[i]);
            }
            if(temperaturas[i][j]>max)
            {
                max=temperaturas[i][j];
                strcpy(cdMax, ciudades[i]);
            }
        }
    }
    printf("la temperatura minima fue %.2f en %s\n", min, cdMin);
    printf("la temperatura maxima fue %.2f en %s\n", max, cdMax);
}
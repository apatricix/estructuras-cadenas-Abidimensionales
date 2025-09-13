#include <stdio.h>

int contar_mayusculas(char cadena[], int i);
int contar_espacio(char cadena[], int i);
void  reemplazar( char cadena[],int i);


int main()
{
    char texto[500];
    int menu;

    printf(" ingrese el texto:\n");
    scanf("%[^\n]", texto);

    do{
        printf("menu:\n");
        printf("1) contar mayusculas\n  2) contar espacios\n   3) reemplazar a\n   4)salir del programa");
        scanf("%d", &menu);



        switch(menu)
        {
            case 1:
            printf("el texto %s tiene %d mayusculas\n", texto, contar_mayusculas(texto, 0));
            break;

            case 2: printf("el texto %s tiene %d espacios\n", texto, contar_espacio(texto,0));
            break;
            case 3: 
            reemplazar(texto, 0);
            printf("su texto reemplazando a es %s\n", texto);
            break;

            case 4: 
            break;
        }
    }
    while(menu!=4);

    return 0;
}

int contar_mayusculas(char cad[], int i)
{
    if(cad[i]=='\0')
    {
        return 0;
    }
    if(cad[i]>='A'&& cad[i]<='Z')
    {
        return 1+ contar_mayusculas(cad, i+1);
    }
    else
    {
        return contar_mayusculas(cad, i+1);
    }
}


int contar_espacio(char cad[], int i)
{
    if(cad[i]==' ')
    {
        return 1;
    }
    else
    {
        return contar_espacio(cad, i+1);
    }
}


void reemplazar(char cad[], int i)
{
    if(cad[i]=='\0')
    {
        return;
    }
    if(cad[i]=='a')
    {
        cad[i]= '@';
    }
    reemplazar(cad, i+1);  
}



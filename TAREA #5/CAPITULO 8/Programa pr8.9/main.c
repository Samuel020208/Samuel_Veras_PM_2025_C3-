#include <stdio.h>
#include <string.h>
typedef struct
{
    char zona[20];
    char calle[20];
    char colo[20];
} ubicacion;
typedef struct
{
    char clave[5];
    float scu;
    float ste;
    char car[50];
    ubicacion ubi;
    float precio;
    char dispo;
} propiedades;
void Lectura(propiedades *, int);
void F1(propiedades *, int);
void F2(propiedades *, int);
void main(void)
{
    propiedades PROPIE[100];
    int TAM;
    do
    {
        printf("\nIngrese el numero de propiedades: ");
        scanf("%d", &TAM);
    }
    while (TAM > 100 || TAM < 1);
    Lectura(PROPIE, TAM);
    F1(PROPIE, TAM);
    F2(PROPIE, TAM);
}
void Lectura(propiedades A[], int T)
{
    int I;
    for (I=0; I<T; I++)
    {
        printf("\ningrese datos de la propiedad %d", I + 1);
        printf("\nClave:");
        while (getchar() != '\n');
        gets(A[I].clave);
        printf("\nSuperficie cubierta: ");
        scanf("%f", &A[I].scu);
        while (getchar() != '\n');
        printf("\nSuperficie terreno: ");
        scanf("%f", &A[I].ste);
        while (getchar() != '\n');
        printf("\nCaracteristicas: ");
        while (getchar() != '\n');
        gets(A[I].car);
        printf("\tZona: ");
        while (getchar() != '\n');
        gets(A[I].ubi.zona);
        printf("\tCalle: ");
        while (getchar() != '\n');
       gets(A[I].ubi.calle);
       printf("\tColonia: ");
       while (getchar() != '\n');
       gets(A[I].ubi.colo);
       printf("\tprecio: ");
       scanf("%f", &A[I].precio);
       while (getchar() != '\n');
       printf("\tDisponibilidad (Venta-V   Renta-R): ");
       scanf("%c", &A[I].dispo);
}
}
void F1(propiedades A[], int T)
{
    int I;
    printf("\nListado de propiedades para Venta en Miraflores");
    for (I=0; I<T; I++)
        if ((A[I].dispo == 'V') && (strcmp(A[I].ubi.zona, "Miraflores") == 0))
        if ((A[I].precio >= 450000) && (A[I].precio <= 650000))
    {
        printf("\nClave de la propiedad: ");
        puts(A[I].clave);
        printf("\nSuperficie cubierta: %f", A[I].scu);
        printf("\nSuperficie terreno: %f", A[I].ste);
        printf("\ncaracteristicas: ");
        puts(A[I].car);
        printf("\ncalle: ");
        puts(A[I].ubi.calle);
        printf("\nColonia: ");
        puts(A[I].ubi.colo);
        printf("\nPrecio: %.2f", A[I].precio);
}
}
void F2(propiedades A[], int T)
{
    int I;
    float li, ls;
    char zon[20];
    printf("\nListado de propiedades para renta");
    printf("\ningrese zona geografica: ");
    while (getchar() != '\n');
    gets(zon);
    printf("\nIngrese el limite inferior del precio: ");
    scanf("%f", &li); while (getchar() != '\n');
    printf("\nIngrese el limite superior del precio: ");
    scanf("%f", &ls); while (getchar() != '\n');
   for (I=0; I<T; I++)
        if ((A[I].dispo == 'R') && (strcmp(A[I].ubi.zona, zon) == 0))
        if ((A[I].precio >= li) && (A[I].precio <= ls))
{
    printf("\nclave de la propiedad: ");
    puts(A[I].clave);
    printf("\nSuperficie cubierta: %d", A[I].scu);
    printf("\nSuperficie terreno: %d", A[I].ste);
    printf("\nCaracteristicas: ");
    puts(A[I].car);
    printf("\nCalle: ");
    puts(A[I].ubi.calle);
    printf("\nColonia: ");
    puts(A[I].ubi.colo);
    printf("\nPrecio: %.2f", A[I].precio);
}
}

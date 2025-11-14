#include <stdio.h>
#include <string.h>

typedef struct
{
    int clave;
    char nombre[15];
    float precio;
    int existencia;
} producto;
void Lectura(producto *, int);
void Ventas(producto *, int);
void Reabastecimiento(producto *, int);
void Nuevos_Productos(producto *, int *);
void Inventario(producto *, int);
void main(void)
{
 producto INV[100];
 int TAM, OPE;
 do
 {
     printf("\nIngrese el numero de productos: ");
     scanf("%d", &TAM);
 }
 while (TAM > 100 || TAM < 1);
 Lectura(INV, TAM);
 printf("\nIngrese operacion a realizar.   \n\t\t1 - Ventas   \n\t\t 2 - Reabastecimiento   \n\t\t 3 - Nuevos Productos \n\t\t 4 - Inventario \n\t\t 0 - Salir: ");
 scanf("%d", &OPE);
 while (getchar() != '\n');
 while(OPE)
 {
     switch (OPE)
     {
         case 1: Ventas(INV, TAM);
         break;
         case 2: Reabastecimiento(INV, TAM);
         break;
         case 3: Nuevos_Productos(INV, &TAM);
         break;
         case 4: Inventario(INV, TAM);
         break;
     };
    printf("\nIngrese operacion a realizar.   \n\t\t 1 - Ventas   \n\t\t 2 - Reabastecimiento   \n\t\t 3 - Nuevos Productos \n\t\t 4 - Inventario \n\t\t 0 - Salir: ");
 scanf("%d", &OPE);
while (getchar() != '\n');
}
}
void Lectura(producto A[], int T)
{
    int I;
    for (I=0; I<T; I++)
    {
        printf("\nIngrese informacion del producto %d", I+1);
        printf("\n\tClave: ");
        scanf("%d", &A[I].clave);
        while (getchar() != '\n');
        printf("\tNombre: ");
        gets(A[I].nombre);
        printf("\tPrecio: ");
        scanf("%f", &A[I].precio);
        while (getchar() != '\n');
        printf("\tExistencia: ");
        scanf("%d", &A[I].existencia);
        while (getchar() != '\n');
}
}
void Ventas(producto A[], int T)
{
    int CLA, CAN, I, RES;
    float TOT, PAR;
    printf("\nIngrese clave del prodcuto -0 para salir.: ");
    scanf("%d", &CLA);
    while (getchar() != '\n');
    TOT = 0.0;
    while (CLA)
    {
        printf("\tCantidad: ");
        scanf("%d", &CAN);
        while (getchar() != '\n');
        I = 0;
        while ((I < T) && (A[I].clave < CLA))
            I++;
        if ((I == T) || (A[I].clave > CLA))
            printf("\nLa clave del producto es incorrecta");
        else
            if (A[I].existencia >= CAN)
        {
            A[I].existencia -= CAN;
            PAR = A[I].precio * CAN;
            TOT += PAR;
        }
       else
       {
           printf("\nNo existe en inventario la cantidad solicitada. Solo hay %d", A[I].existencia);
           printf("\nLos lleva 1 - Si    0 - No:");
           scanf("%d", &RES);
           while (getchar() != '\n');
           if (RES)
           {
               PAR = A[I].precio * A[I].existencia;
               A[I].existencia = 0;
               TOT += PAR;
           }
       }
       printf("\nIngrese la siguiente clave del producto -0 para salir-;");
       scanf("%d", &CLA);
       while (getchar() != '\n');
    }
    printf("\nTotal de la venta:  %f", TOT);
}
void Reabastecimiento(producto A[], int T)
{
    int CLA, CAN, I;
    printf("\nIngrese clave del producto -0 para salir-: ");
    scanf("%d", &CLA);
    while (getchar() != '\n');
    while (CLA)
    {
        I = 0;
        while ((I < T) && (A[I].clave < CLA))
            I++;
        if ((I==T) || (A[I].clave > CLA))
            printf("\nLa clave del producto ingresada es incorrecta");
        else
        {
            printf("\tCantidad: ");
            scanf("%d", &CAN);
            while (getchar() != '\n');
            A[I].existencia += CAN;
        }
        printf("\nIngrese otra clave del producto -0 para salir-: ");
        scanf("%d", &CLA); while (getchar() != '\n');
}
}
void Nuevos_Productos(producto A[], int *T)
{
    int CLA, I, J;
    printf("\nIngrese clave del prodcuto -0 para salir-: ");
    scanf("%d", &CLA); while (getchar() != '\n');
    while ((*T < 100) && (CLA))
    {
        I=0;
        while ((I < T) && (A[I].clave < CLA))
            I++;
        if (I == *T)
        {
            A[I].clave = CLA;
            printf("\nNombre: ");
            while (getchar() != '\n');
            gets(A[I].nombre);
            printf("\tPrecio: ");
            scanf("%f", &A[I].precio);
            while (getchar() != '\n');
            printf("\nCantidad: ");
            scanf("%d", &A[I].existencia);
            while (getchar() != '\n');
            *T = *T + 1;
        }
        else
            if (A[I].clave == CLA)
            printf("\nEl producto ya se encuentra en el invenario");
        else
        {
            for (J=*T; J>I; J--)
                A[J] = A[J-1];
            A[I].clave = CLA;
            printf("\nNombre: ");
            while (getchar() != '\n');
            gets(A[I].nombre);
            printf("\tPrecio: ");
            scanf("%f", &A[I].precio);
            while (getchar() != '\n');
            printf("\tCantidad: ");
            scanf("%d", &A[I].existencia);
            while (getchar() != '\n');
            *T = *T + 1;
        }
       printf("\ningrese otra clave de producto -0 para salir-: ");
       scanf("%d", &CLA); while (getchar() != '\n');
    }
    if (*T == 100)
        printf("\nYa no hay espacio para incorporar nuevos productos");
}

void Inventario(producto A[], int T)
{
    int I;
    for (I=0; I<T; I++)
{
printf("\nClave: %d", A[I].clave);
printf("\nNombre: %s", A[I].nombre);
printf("\nPrecio: %.2f", A[I].precio);
printf("\nExistencia: %d", A[I].existencia);
}
}

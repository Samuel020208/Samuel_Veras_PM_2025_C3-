#include <stdio.h>
#include <string.h>
typedef struct
{
    char noba[10];
    char nucu[10];
} banco;
typedef union
{
    banco che;
    banco nomi;
    char venta;
} fpago;
typedef struct
{
char cnu[20];
char col[20];
char cp[6];
char ciu[15];
} domicilio;
typedef struct
{
    int num;
    char nom[20];
    float ven[12];
    domicilio domi;
    float sal;
    fpago pago;
    int CLA;
} vendedor;
void Lectura(vendedor *, int);
void F1(vendedor *, int);
void F3(vendedor *, int);
void F2(vendedor *, int);
void F4(vendedor *, int);

void main (void)
{
    vendedor VENDEDORES[100];
    int TAM;
    do
    {
        printf("\nIngrese el numero de vendedores: ");
        scanf("%d", &TAM);
        while (getchar() != '\n');
    }
    while (TAM > 100 || TAM < 1);
    Lectura(VENDEDORES, TAM);
    F1 (VENDEDORES, TAM);
    F2 (VENDEDORES, TAM);
    F3 (VENDEDORES, TAM);
    F4 (VENDEDORES, TAM);
    printf("\nFIN DEL PROGRAMA");
}
void Lectura(vendedor A[], int T)
{
    int I, J;
    for (I=0; I<T; I++)
    {
        printf("\nIngrese datos del vendedor %d", I+1);
        printf("\nNumero de vendedor: ");
        scanf("%d", &A[I].num);
        while (getchar() != '\n');
        printf("\nNombre del vendedor: ");
       gets(A[I].nom);
       printf("\nVentas del ano: ");
       for (J=0; J<12; J++)
       {
           printf("\tMes %d; ", J+1);
           scanf("%f", &A[I].ven[J]);
           while (getchar() != '\n');
       }
        printf("\nDomicilio del vendedor: ");
        printf("\tCalle y numero: ");
        gets(A[I].domi.cnu);
        printf("\tColonia: ");
        gets(A[I].domi.col);
        printf("\tCodigo postal: ");
        gets(A[I].domi.cp);
        printf("\tCiudad: ");
        gets(A[I].domi.ciu);
        printf("\tSalario del vendedor: ");
        scanf("%f", &A[I].sal);
        while (getchar() != '\n');
        printf("\tForma de pago (Banco-1  Nomina-2  Ventanilla-3): ");
        scanf("%d", &A[I].CLA);
        while (getchar() != '\n');
        switch (A[I].CLA)
        {
            case 1:
            {
                printf("\tNombre del banco: ");
                gets(A[I].pago.che.noba);
                printf("\tNumero de cuenta: ");
                gets(A[I].pago.che.nucu);
            } break;
            case 2:
                {
                  printf("\tNombre del banco: ");
                gets(A[I].pago.che.noba);
                printf("\tNumero de cuenta: ");
                gets(A[I].pago.che.nucu);
                } break;
        case 3: A[I].pago.venta = 'S';
        break;
}
}
}
void F1(vendedor A[], int T)
{
    int I, J;
    float SUM;
    printf("\nVentas Totales de los vendedores");
    for (I=0; I<T; I++)
    {
        printf("\nVendedor: %d", A[I].num);
        SUM = 0.0;
        for (J=0; J<12; J++)
            SUM += A[I].ven[J];
        printf("\nVentas: %.2f", SUM);
}
}

void F2(vendedor A[], int T)
{
    int I, J;
    float SUM;
    printf("\nIncremento a los vendedores con ventas > 1,500,000$");
    for (I=0; I<T; I++)
    {
        SUM = 0.0;
        for (J=0; J<12; J++)
            SUM += A[I].ven[J];
        if (SUM > 1500000.00)
        {
            A[I].sal = A[I].sal * 1.05;
            printf("\nNumero de empleado: %d  \nventas:  %.2f  \nNuevo salario:  %.2f", A[I].num, SUM, A[I].sal);
}
}
}

void F3(vendedor A[], int T)
{
    int I, J;
    float SUM;
    printf("\nVendedores con Ventas < 300,000");
    for (I=0; I<T; I++)
    {
        SUM = 0.0;
        for (J=0; J<12; J++)
            SUM += A[I].ven[J];
        if (SUM < 300000.00)
        printf("\nNumero de empleado: %d  \nNombre:  %s  \nVentas:  %.2f", A[I].num, A[I].nom, SUM);
}
}
void F4(vendedor A[], int T)
{
    int I, J;
    float SUM;
    printf("\nVendedores con Cuenta en el banco");
    for (I=0; I<T; I++)
        if (A[I].CLA == 1)
        printf("\nNumero de vendedor: %d \n Banco. %s \n Cuenta: %s", A[I].num, A[I].pago.che.noba, A[I].pago.che.nucu);
}

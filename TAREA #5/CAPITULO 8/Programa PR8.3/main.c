#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char calle[20];
    int numero;
    int cp;
    char localidad[20];
}
domicilio;
struct empleado
{
char nombre[20];
char departamento[20];
float sueldo;
domicilio direccion;
};
void lectura(struct empleado *a)
{

    printf("\nIngrese el nombre del empleado: ");
    gets(a->nombre);
    while (getchar() != '\n');
    printf("\nIngrese el departamento de la empresa: ");
    gets(a->departamento);
    printf("\nIngrese el sueldo del empleado: ");
    scanf("%f", &a->sueldo);
    while (getchar() != '\n');
    printf("\n-Ingrese la direccion del empleado-.");
    printf("\n \tCalle: ");
    gets(a->direccion.calle);
    printf("\tNumero: ");
    scanf("%d", &a->direccion.numero);
    printf("\tCodigo postal: ");
    scanf("%d", &a->direccion.cp);
    while (getchar() != '\n');
    printf("\tLocalidad: ");
    gets(a->direccion.localidad);
}

void main (void)
{
struct empleado e0 = {"Arturo", "Compras", 15500.75, "San Jeronimo", 120, 3490, "toluca"};
struct empleado *e1, *e2, *e3, *e4;

e1 = (struct empleado *)malloc(sizeof(struct empleado));
e3 = (struct empleado *)malloc(sizeof(struct empleado));

printf("\nIngrese el nombre del empleado 1: ");
    scanf("%s", e1->nombre);
    while (getchar() != '\n');
    printf("\nIngrese el departamento de la empresa: ");
    gets(e1->departamento);
    printf("\nIngrese el sueldo del empleado: ");
    scanf("%f", &e1->sueldo);
    while (getchar() != '\n');
    printf("\n-Ingrese la direccion del empleado-.");
    printf("\n \tCalle: ");
    gets(e1->direccion.calle);
    printf("\tNumero: ");
    scanf("%d", &e1->direccion.numero);
    printf("\tCodigo postal: ");
    scanf("%d", &e1->direccion.cp);
    while (getchar() != '\n');
    printf("\tLocalidad: ");
    gets(e1->direccion.localidad);


printf("\nIngrese el nombre del empleado 1: ");
    scanf("%s", e3->nombre);
    while (getchar() != '\n');
    printf("\nIngrese el departamento de la empresa: ");
    gets(e3->departamento);
    printf("\nIngrese el sueldo del empleado: ");
    scanf("%f", &e3->sueldo);
    while (getchar() != '\n');
    printf("\n-Ingrese la direccion del empleado-.");
    printf("\n \tCalle: ");
    gets(e3->direccion.calle);
    printf("\tNumero: ");
    scanf("%d", &e3->direccion.numero);
    printf("\tCodigo postal: ");
    scanf("%d", &e3->direccion.cp);
    while (getchar() != '\n');
    printf("\tLocalidad: ");
    gets(e3->direccion.localidad);

    e2 = (struct empleado *)malloc(sizeof(struct empleado));

    e4 = (struct empleado *)malloc(sizeof(struct empleado));
    lectura(e2);
    lectura(e4);

    printf("\nDatos del empleado 2\n");
    printf("\n%s \t%s \t%.2f \t%s \t%d \t%d \t%s", e2->nombre, e2->departamento, e2->sueldo, e2->direccion.calle, e2->direccion.numero, e2->direccion.cp, e2->direccion.localidad);

    printf("\nDatos del empleado 4\n");
    printf("\n%s \t%s \t%.2f \t%s \t%d \t%d \t%s", e4->nombre, e4->departamento, e4->sueldo, e4->direccion.calle, e4->direccion.numero, e4->direccion.cp, e4->direccion.localidad);
}

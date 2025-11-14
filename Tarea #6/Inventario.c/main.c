#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTOS 100

typedef struct {
    char nombre[50];
    float precio;
    int cantidad;
} Producto;

// Muestra el inventario
void mostrarInventario(Producto inventario[], int total) {
    if (total == 0) {
        printf("\nNo hay productos en el inventario.\n");
        return;
    }

    printf("\n=== INVENTARIO ACTUAL ===\n");
    printf("%-15s %-10s %-10s\n", "Nombre", "Precio", "Cantidad");
    for (int i = 0; i < total; i++) {
        printf("%-15s %-10.2f %-10d\n",
               inventario[i].nombre, inventario[i].precio, inventario[i].cantidad);
    }
}

// Agrega un nuevo producto
void agregarProducto(Producto inventario[], int *total) {
    if (*total >= MAX_PRODUCTOS) {
        printf("Inventario lleno. No se pueden agregar más productos.\n");
        return;
    }

    Producto nuevo;
    printf("\nIngrese nombre del producto: ");
    scanf("%s", nuevo.nombre);
    printf("Ingrese precio: ");
    scanf("%f", &nuevo.precio);
    printf("Ingrese cantidad: ");
    scanf("%d", &nuevo.cantidad);

    inventario[*total] = nuevo;
    (*total)++;

    printf("Producto agregado correctamente.\n");
}

// Modifica un producto existente
void modificarProducto(Producto inventario[], int total) {
    if (total == 0) {
        printf("Inventario vacío.\n");
        return;
    }

    char nombre[50];
    printf("\nIngrese el nombre del producto a modificar: ");
    scanf("%s", nombre);

    for (int i = 0; i < total; i++) {
        if (strcmp(inventario[i].nombre, nombre) == 0) {
            printf("Producto encontrado: %s\n", inventario[i].nombre);
            printf("Nuevo precio: ");
            scanf("%f", &inventario[i].precio);
            printf("Nueva cantidad: ");
            scanf("%d", &inventario[i].cantidad);
            printf("Producto actualizado correctamente.\n");
            return;
        }
    }

    printf("Producto no encontrado.\n");
}

// Elimina un producto
void eliminarProducto(Producto inventario[], int *total) {
    if (*total == 0) {
        printf("Inventario vacío.\n");
        return;
    }

    char nombre[50];
    printf("\nIngrese el nombre del producto a eliminar: ");
    scanf("%s", nombre);

    for (int i = 0; i < *total; i++) {
        if (strcmp(inventario[i].nombre, nombre) == 0) {
            for (int j = i; j < *total - 1; j++) {
                inventario[j] = inventario[j + 1];
            }
            (*total)--;
            printf("Producto eliminado correctamente.\n");
            return;
        }
    }

    printf("Producto no encontrado.\n");
}

int main() {
    Producto inventario[MAX_PRODUCTOS] = {
        {"Arroz", 45.50, 20},
        {"Habichuelas", 60.00, 15},
        {"Aceite", 120.00, 10},
        {"Azucar", 55.00, 25},
        {"Cafe", 150.00, 8}
    };

    int total = 5;
    int opcion;
    char respuesta;

    printf("¿Desea imprimir los productos en inventario? (s/n): ");
    scanf(" %c", &respuesta);

    if (respuesta == 's' || respuesta == 'S') {
        mostrarInventario(inventario, total);
    } else {
        printf("Inventario no mostrado.\n");
    }

    do {
        printf("\n====== MENU DE INVENTARIO ======\n");
        printf("1. Mostrar inventario\n");
        printf("2. Agregar producto\n");
        printf("3. Modificar producto\n");
        printf("4. Eliminar producto\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                mostrarInventario(inventario, total);
                break;
            case 2:
                agregarProducto(inventario, &total);
                break;
            case 3:
                modificarProducto(inventario, total);
                break;
            case 4:
                eliminarProducto(inventario, &total);
                break;
            case 5:
                printf("\n Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 5);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200

// =====================================================
// ESTRUCTURAS
// =====================================================
typedef struct
{
    int id;
    char marca[50];
    char modelo[50];
    int ano;
    char placa[20];
    float consumoCiudad;
    float consumoCarretera;
    float seguroAnual;
    float costoCambioKm;
    float depAnios;
    float costoVehiculo;
    float costoDepreciacion;
    float kmPromedio;
    float limpieza;
} Vehiculo;

typedef struct {
    char tipo[20];
    float precio;
} Combustible;


// =====================================================
// VARIABLES
// =====================================================
Vehiculo vehiculos[MAX];
Combustible combustibles[MAX];
int totalVehiculos = 0;
int totalCombustibles = 0;


// =====================================================
// FUNCIONES DE BUFFER SEGURO
// =====================================================
void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void leerCadena(char *cadena, int tam) {
    limpiarBuffer();
    fgets(cadena, tam, stdin);
    cadena[strcspn(cadena, "\n")] = 0;
}


// =====================================================
// GUARDAR / CARGAR
// =====================================================
void guardarVehiculos() {
    FILE *f = fopen("vehiculos.txt", "wb");
    fwrite(vehiculos, sizeof(Vehiculo), totalVehiculos, f);
    fclose(f);
}

void cargarVehiculos() {
    FILE *f = fopen("vehiculos.txt", "rb");
    if (!f) return;
    totalVehiculos = fread(vehiculos, sizeof(Vehiculo), MAX, f);
    fclose(f);
}

void guardarCombustibles() {
    FILE *f = fopen("combustibles.txt", "wb");
    fwrite(combustibles, sizeof(Combustible), totalCombustibles, f);
    fclose(f);
}

void cargarCombustibles() {
    FILE *f = fopen("combustibles.txt", "rb");
    if (!f) return;
    totalCombustibles = fread(combustibles, sizeof(Combustible), MAX, f);
    fclose(f);
}


/* ===================================================== */
// AGREGAR VEHICULO
/* ===================================================== */
void agregarVehiculo() {
    Vehiculo v;

    printf("ID del vehiculo: ");
    scanf("%d", &v.id);

    printf("Marca: "); scanf("%s", v.marca);
    printf("Modelo: "); scanf("%s", v.modelo);
    printf("Ano: "); scanf("%d", &v.ano);
    printf("Placa: "); scanf("%s", v.placa);
    printf("Consumo Ciudad L/100 km: "); scanf("%f", &v.consumoCiudad);
    printf("Consumo Carretera L/100 km: "); scanf("%f", &v.consumoCarretera);
    printf("Costo seguro anual: "); scanf("%f", &v.seguroAnual);
    printf("Costo cambio por km: "); scanf("%f", &v.costoCambioKm);
    printf("Tiempo depreciacion (anos): "); scanf("%f", &v.depAnios);
    printf("Costo vehiculo: "); scanf("%f", &v.costoVehiculo);
    printf("Km promedio ano: "); scanf("%f", &v.kmPromedio);
    printf("Costo limpieza: "); scanf("%f", &v.limpieza);

    v.costoDepreciacion = v.costoVehiculo / v.depAnios;

    vehiculos[totalVehiculos++] = v;
    guardarVehiculos();

    printf("\nVehiculo agregado correctamente.\n");
}



// =====================================================
// LISTAR VEHICULOS
// =====================================================
void listarVehiculos() {
    printf("\n--- LISTA DE VEHICULOS ---\n");
    for (int i = 0; i < totalVehiculos; i++) {
        printf("%d - %s %s (%s)\n",
               vehiculos[i].id,
               vehiculos[i].marca,
               vehiculos[i].modelo,
               vehiculos[i].placa);
    }
}


// =====================================================
// MENU PROPIEDADES
// =====================================================
void menuPropiedades() {
    int op, id;
    Vehiculo *v = NULL;

    do {
        printf("\n--- PROPIEDADES VEHICULO ---\n");
        printf("1. Marca\n");
        printf("2. Modelo\n");
        printf("3. Ano\n");
        printf("4. ID\n");
        printf("5. Placa\n");
        printf("6. Consumo ciudad\n");
        printf("7. Consumo carretera\n");
        printf("8. Seguro anual\n");
        printf("9. Cambio por KM\n");
        printf("10. Depreciacion\n");
        printf("11. Km promedio\n");
        printf("12. Limpieza\n");
        printf("13. Volver\n");
        printf("Seleccione opcion: ");
        scanf("%d", &op);

        if (op == 13) return;

        // Mostrar lista antes de pedir ID
        printf("\n--- VEHICULOS DISPONIBLES ---\n");
        for (int i = 0; i < totalVehiculos; i++) {
            printf("%d - %s %s (%s)\n",
                vehiculos[i].id,
                vehiculos[i].marca,
                vehiculos[i].modelo,
                vehiculos[i].placa);
        }

        printf("Seleccione vehiculo por ID: ");
        scanf("%d", &id);

        v = NULL;
        for (int i = 0; i < totalVehiculos; i++) {
            if (vehiculos[i].id == id) {
                v = &vehiculos[i];
                break;
            }
        }

        if (!v) {
            printf("ID no valido.\n");
            continue;
        }

        // Ahora mostrar propiedad seleccionada
        switch (op) {
            case 1: printf("Marca: %s\n", v->marca); break;
            case 2: printf("Modelo: %s\n", v->modelo); break;
            case 3: printf("Ano: %d\n", v->ano); break;
            case 4: printf("ID: %d\n", v->id); break;
            case 5: printf("Placa: %s\n", v->placa); break;
            case 6: printf("Consumo ciudad: %.2f\n", v->consumoCiudad); break;
            case 7: printf("Consumo carretera: %.2f\n", v->consumoCarretera); break;
            case 8: printf("Seguro anual: %.2f\n", v->seguroAnual); break;
            case 9: printf("Cambio por KM: %.2f\n", v->costoCambioKm); break;
            case 10: printf("Depreciacion: %.2f\n", v->costoDepreciacion); break;
            case 11: printf("Km promedio: %.2f\n", v->kmPromedio); break;
            case 12: printf("Limpieza: %.2f\n", v->limpieza); break;
        }

    } while (op != 13);
}


// =====================================================
// AGREGAR COMBUSTIBLE
// =====================================================
void agregarCombustible() {
    Combustible c;
    printf("Tipo combustible: ");
    leerCadena(c.tipo, 20);

    printf("Precio por litro: ");
    scanf("%f", &c.precio);

    combustibles[totalCombustibles++] = c;
    guardarCombustibles();

    printf("Combustible agregado.\n");
}


// =====================================================
// CALCULAR VIAJE
// =====================================================
void calcularViaje() {
    int id;
    float km, pctCiudad;

    listarVehiculos();

    printf("Seleccione ID del vehiculo: ");
    scanf("%d", &id);

    if (id < 1 || id > totalVehiculos) {
        printf("No existe.\n");
        return;
    }

    Vehiculo *v = &vehiculos[id - 1];

    printf("Cantidad de KM: ");
    scanf("%f", &km);

    printf("%% KM Ciudad: ");
    scanf("%f", &pctCiudad);

    float kmCiudad = km * (pctCiudad / 100.0f);
    float kmCarretera = km - kmCiudad;

    float litrosCiudad = (v->consumoCiudad / 100.0f) * kmCiudad;
    float litrosCarretera = (v->consumoCarretera / 100.0f) * kmCarretera;
    float litrosTotal = litrosCiudad + litrosCarretera;

    printf("\n--- COMBUSTIBLES ---\n");
    for (int i = 0; i < totalCombustibles; i++)
        printf("%d. %s - %.2f\n", i + 1, combustibles[i].tipo, combustibles[i].precio);

    int cid;
    printf("Seleccione combustible: ");
    scanf("%d", &cid);

    float precio = combustibles[cid - 1].precio;

    float costoComb = litrosTotal * precio;

    float costoTotal =
        costoComb +
        (v->seguroAnual / 12.0f) +
        (v->costoDepreciacion / 12.0f) +
        (v->costoCambioKm * km) +
        v->limpieza;

    printf("\nCosto total del viaje: RD$ %.2f\n", costoTotal);
    printf("Costo por km: RD$ %.2f\n", costoTotal / km);
}
void eliminarVehiculo() {
    if (totalVehiculos == 0) {
        printf("\nNo hay vehiculos registrados.\n");
        return;
    }

    int id, index = -1;

    printf("\n--- LISTA DE VEHICULOS ---\n");
    for (int i = 0; i < totalVehiculos; i++) {
        printf("%d - %s %s (%s)\n",
               vehiculos[i].id,
               vehiculos[i].marca,
               vehiculos[i].modelo,
               vehiculos[i].placa);
    }

    printf("\nIngrese el ID del vehiculo a eliminar: ");
    scanf("%d", &id);

    // Buscar vehiculo por ID
    for (int i = 0; i < totalVehiculos; i++) {
        if (vehiculos[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("ID no valido.\n");
        return;
    }

    // Desplazar todos los elementos
    for (int i = index; i < totalVehiculos - 1; i++) {
        vehiculos[i] = vehiculos[i + 1];
    }

    totalVehiculos--;

    guardarVehiculos();

    printf("\nVehiculo eliminado correctamente.\n");
}


// =====================================================
// MENU SISTEMA
// =====================================================
void menuSistema() {
    int op;
    do {
        printf("\n--- SISTEMA CALCULO DE VIAJE ---\n");
        printf("1. Agregar Vehiculo\n");
        printf("2. Lista Vehiculo\n");
        printf("3. Agregar Combustible\n");
        printf("4. Lista Combustibles\n");
        printf("5. Calcular Viaje\n");
        printf("6. Eliminar Vehiculo\n");
        printf("7. Volver\n");
        printf("Seleccione: ");
        scanf("%d", &op);

        switch (op) {
            case 1: agregarVehiculo(); break;
            case 2: listarVehiculos(); break;
            case 3: agregarCombustible(); break;
            case 4:
                for (int i = 0; i < totalCombustibles; i++)
                    printf("%s - %.2f\n", combustibles[i].tipo, combustibles[i].precio);
                break;
            case 5: calcularViaje(); break;
            case 6: eliminarVehiculo(); break;
        }

    } while (op != 7);
}



// =====================================================
// MENU PRINCIPAL
// =====================================================
int main() {
    cargarVehiculos();
    cargarCombustibles();

    int op;

    do {
        printf("\n======= MENU PRINCIPAL =======\n");
        printf("1. Sistema calculo costo de viaje\n");
        printf("2. Propiedades vehiculos\n");
        printf("3. Salidas\n");
        printf("4. Salir\n");
        printf("Seleccione: ");
        scanf("%d", &op);

        switch (op) {
            case 1: menuSistema(); break;
            case 2: menuPropiedades(); break;
            case 3: printf("\nLos costos se muestran al calcular viaje.\n"); break;
        }

    } while (op != 4);

    return 0;
}

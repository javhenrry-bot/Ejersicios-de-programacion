#include <iostream>     // Permite usar cin, cout
#include <string>       // Permite usar strings
#include <stdexcept>    // Permite usar excepciones
using namespace std;    // Evita escribir std:: en cada línea

// ESTRUCTURA DEL PRODUCTO
struct Producto {
    int id;             // ID del producto
    string nombre;      // Nombre del producto
    float precio;       // Precio del producto
    int cantidad;       // Cantidad en inventario
};

// ==========================================
//   FUNCIÓN PARA MOSTRAR UN PRODUCTO
// ==========================================
void mostrarProducto(const Producto &p) {
    cout << "ID: " << p.id 
         << " | Nombre: " << p.nombre 
         << " | Precio: " << p.precio 
         << " | Cantidad: " << p.cantidad << endl;
}

// ==========================================================
//   FUNCIÓN DE BÚSQUEDA POR ID (LANZA EXCEPCIÓN SI NO EXISTE)
// ==========================================================
Producto* buscarPorID(Producto productos[], int n, int idBuscado) {
    for (int i = 0; i < n; i++) {                    // Recorrido del arreglo
        if (productos[i].id == idBuscado)           // Si se encuentra coincidencia
            return &productos[i];                   // Devuelve puntero al producto
    }
    throw runtime_error("ERROR: Producto no encontrado por ID.");  // Excepción
}

// ================================================================
//   FUNCIÓN DE BÚSQUEDA POR NOMBRE (LANZA EXCEPCIÓN SI NO EXISTE)
// ================================================================
Producto* buscarPorNombre(Producto productos[], int n, string nombreBuscado) {
    for (int i = 0; i < n; i++) {                     // Recorrido del arreglo
        if (productos[i].nombre == nombreBuscado)    // Comparar nombre
            return &productos[i];                    // Retorna puntero
    }
    throw runtime_error("ERROR: Producto no encontrado por nombre."); // Excepción
}

// ============================================
//   ORDENAMIENTO BURBUJA POR PRECIO
// ============================================
void ordenarPorPrecio(Producto productos[], int n) {
    for (int i = 0; i < n - 1; i++) {                 // Recorrido general
        for (int j = 0; j < n - i - 1; j++) {         // Comparaciones por burbuja
            if (productos[j].precio > productos[j+1].precio) { // Si están mal ordenados
                swap(productos[j], productos[j+1]);   // Intercambiar posiciones
            }
        }
    }
}

// ============================================
//   ORDENAMIENTO BURBUJA POR CANTIDAD
// ============================================
void ordenarPorCantidad(Producto productos[], int n) {
    for (int i = 0; i < n - 1; i++) {                 // Recorrido general
        for (int j = 0; j < n - i - 1; j++) {         // Comparaciones por burbuja
            if (productos[j].cantidad > productos[j+1].cantidad) { // Si están mal ordenados
                swap(productos[j], productos[j+1]);   // Intercambiar
            }
        }
    }
}

// ===============================
//   MOSTRAR TODA LA LISTA
// ===============================
void mostrarLista(Producto productos[], int n) {
    cout << "\n--- LISTA DE PRODUCTOS ---\n";
    for (int i = 0; i < n; i++) {        // Recorre todo el arreglo
        mostrarProducto(productos[i]);   // Muestra cada producto
    }
}


int main() {                 // Inicio del programa principal

    const int MAX = 50;      // Límite máximo de productos
    Producto productos[MAX]; // Arreglo donde se guardarán los productos
    int total = 0;           // Cantidad actual de productos registrados

    int opcion;              // Variable para la opción del menú

    do {                     // Inicia ciclo del menú

        cout << "\n===== SISTEMA DE INVENTARIO =====\n"; //
        cout << "1. Agregar producto\n";                // Opción 1
        cout << "2. Mostrar productos\n";               // Opción 2
        cout << "3. Buscar producto por nombre\n";      // Opción 3
        cout << "4. Ordenar por nombre\n";              // Opción 4
        cout << "5. Ordenar por precio\n";              // Opción 5
        cout << "6. Salir\n";                           // Opción 6
        cout << "Seleccione una opcion: ";              // Solicita opción
        cin >> opcion;                                  // Guarda opción

        switch (opcion) {                               // Evalúa la opción seleccionada

        case 1:                                         // Agregar producto
            if (total < MAX) {                          // Verifica si hay espacio
                cout << "\n-- Agregar Producto --\n";   // Título

                cout << "Nombre: ";                     // Pide nombre
                cin >> productos[total].nombre;         // Guarda nombre

                cout << "Precio: ";                     // Pide precio
                cin >> productos[total].precio;         // Guarda precio

                cout << "Cantidad: ";                   // Pide cantidad
                cin >> productos[total].cantidad;       // Guarda cantidad

                total++;                                // Aumenta contador de productos
                cout << "Producto agregado exitosamente.\n"; // Mensaje de éxito
            } else {
                cout << "Inventario lleno.\n";          // Si ya no hay espacio
            }
            break;

        case 2:                                         // Mostrar productos
            cout << "\n-- Lista de Productos --\n";     // Título
            if (total == 0) {                           // Si no hay productos
                cout << "No hay productos registrados.\n";
            } else {
                for (int i = 0; i < total; i++) {       // Recorre todos los productos
                    cout << i + 1 << ". ";              // Número del producto
                    cout << "Nombre: " << productos[i].nombre << " | ";   // Nombre
                    cout << "Precio: $" << productos[i].precio << " | ";  // Precio
                    cout << "Cantidad: " << productos[i].cantidad << endl;// Cantidad
                }
            }
            break;

        case 3:                                         // Buscar producto por nombre
        {
            cout << "\n-- Buscar Producto --\n";        // Título
            string buscar;                              // Variable para el nombre a buscar
            cout << "Ingrese el nombre a buscar: ";     // Solicita nombre
            cin >> buscar;                              // Lo guarda

            bool encontrado = false;                    // Variable para saber si se encontró

            for (int i = 0; i < total; i++) {           // Recorre los productos
                if (productos[i].nombre == buscar) {    // Compara nombres
                    cout << "Producto encontrado:\n";   // Mensaje
                    cout << "Nombre: " << productos[i].nombre << endl;
                    cout << "Precio: $" << productos[i].precio << endl;
                    cout << "Cantidad: " << productos[i].cantidad << endl;
                    encontrado = true;                  // Marca que se encontró
                    break;                              // Termina la búsqueda
                }
            }

            if (!encontrado) {                          // Si no se encontró
                cout << "Producto no encontrado.\n";
            }
            break;
        }

        case 4:                                         // Ordenar por nombre
            cout << "\n-- Ordenando por nombre... --\n";
            for (int i = 0; i < total - 1; i++) {       // Primer bucle del método burbuja
                for (int j = 0; j < total - 1 - i; j++) {// Segundo bucle del método burbuja
                    if (productos[j].nombre > productos[j+1].nombre) { // Compara nombres
                        swap(productos[j], productos[j+1]);            // Intercambia posiciones
                    }
                }
            }
            cout << "Productos ordenados por nombre.\n"; // Confirmación
            break;

        case 5:                                         // Ordenar por precio
            cout << "\n-- Ordenando por precio... --\n";
            for (int i = 0; i < total - 1; i++) {       // Primer bucle
                for (int j = 0; j < total - 1 - i; j++) {// Segundo bucle
                    if (productos[j].precio > productos[j+1].precio) { // Compara precios
                        swap(productos[j], productos[j+1]);            // Intercambia
                    }
                }
            }
            cout << "Productos ordenados por precio.\n"; // Confirmación
            break;

        case 6:
            cout << "Saliendo del sistema...\n";        // Mensaje de salida
            break;

        default:
            cout << "Opcion no valida.\n";              // Error para opciones inexistentes
        }

    } while (opcion != 6);                              // Repite hasta que se elija salir

    return 0;                                           // Fin del programa
}

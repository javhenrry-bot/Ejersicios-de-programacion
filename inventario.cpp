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

int main() {

    // ====================================
    //   REGISTRO 10 PRODUCTOS COMO INICIO
    // ====================================
    Producto productos[10] = {
        {1,  "Pan",        1.20, 50},
        {2,  "Leche",      0.99, 30},
        {3,  "Queso",      2.50, 20},
        {4,  "Huevos",     1.80, 40},
        {5,  "Arroz",      1.10, 80},
        {6,  "Azucar",     0.90, 60},
        {7,  "Cafe",       3.50, 15},
        {8,  "Cereal",     2.20, 25},
        {9,  "Fideos",     1.00, 70},
        {10, "Aceite",     4.00, 10}
    };

    int opcion;   // Guardará opción del usuario

    // Bucle principal del menú
    do {
        cout << "\n========= MENU =========\n";
        cout << "1. Mostrar productos\n";
        cout << "2. Buscar por ID\n";
        cout << "3. Buscar por nombre\n";
        cout << "4. Ordenar por precio\n";
        cout << "5. Ordenar por cantidad\n";
        cout << "6. Modificar inventario (puntero)\n";
        cout << "0. Salir\n";
        cout << "Elige una opción: ";
        cin >> opcion;

        // Manejo del menú
        switch(opcion) {

        case 1:
            mostrarLista(productos, 10);
            break;

        case 2: {
            int id;
            cout << "Ingrese ID: ";
            cin >> id;
            try {
                Producto* p = buscarPorID(productos, 10, id); // Usa puntero
                mostrarProducto(*p);                           // Muestra el contenido apuntado
            }
            catch (exception &e) {
                cout << e.what() << endl;                     // Muestra mensaje de error
            }
            break;
        }

        case 3: {
            string nombre;
            cout << "Ingrese nombre: ";
            cin >> nombre;
            try {
                Producto* p = buscarPorNombre(productos, 10, nombre); // Puntero
                mostrarProducto(*p);                                  // Mostrar
            }
            catch (exception &e) {
                cout << e.what() << endl;                             // Excepción
            }
            break;
        }

        case 4:
            ordenarPorPrecio(productos, 10);  // Ordenamiento burbuja
            cout << "Ordenado por precio.\n";
            break;

        case 5:
            ordenarPorCantidad(productos, 10); // Ordenamiento burbuja
            cout << "Ordenado por cantidad.\n";
            break;

        case 6: {
            int id, nuevaCant;
            cout << "ID del producto: ";
            cin >> id;

            try {
                Producto* p = buscarPorID(productos, 10, id); // Obtener puntero al producto
                cout << "Cantidad nueva: ";
                cin >> nuevaCant;
                p->cantidad = nuevaCant;                     // Modificación mediante puntero
                cout << "Inventario actualizado.\n";
            }
            catch (exception &e) {
                cout << e.what() << endl;
            }
            break;
        }

        case 0:
            cout << "Saliendo...\n";
            break;

        default:
            cout << "Opción invalida.\n";
        }

    } while (opcion != 0); // Repite mientras no elijan salir

    return 0;  // Fin del programa
}

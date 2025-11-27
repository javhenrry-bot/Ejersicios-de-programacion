#include <iostream>  // Biblioteca para entrada y salida
#include <string>    // Biblioteca para usar strings
#include <limits>    // Biblioteca para limpiar el buffer de entrada

using namespace std; // Usamos el espacio de nombres estándar

// Definimos una estructura para representar una cuenta bancaria
struct Cuenta {
    int numeroCuenta;   // Número de la cuenta
    string titular;     // Nombre del titular de la cuenta
    float saldo;        // Saldo actual de la cuenta
};

// Declaración de funciones que vamos a usar
void mostrarMenu();  // Función para mostrar el menú
int seleccionarCuenta(Cuenta cuentas[], int totalCuentas); // Función para seleccionar una cuenta
void consultarSaldo(Cuenta *cuenta); // Función para consultar saldo
void depositar(Cuenta *cuenta);      // Función para depositar dinero
void retirar(Cuenta *cuenta);        // Función para retirar dinero
void transferir(Cuenta cuentas[], int totalCuentas, Cuenta *cuentaOrigen); // Función para transferir dinero

int main() {
    // Creamos un arreglo de 3 cuentas con saldo inicial
    Cuenta cuentas[3] = {
        {1, "Javier Reyes", 1500.0}, //el numero de cuenta de Javier sera 1
        {2, "Maria Lopez", 2000.0}, // el numero de cuenta de Maria sera 2
        {3, "Carlos Sanchez", 3000.0} //el numero de cuenta de Carlos sera 3
    };

do { // Bucle principal para mostrar el menú repetidamente
    



    return 0;  // Fin del programa
}

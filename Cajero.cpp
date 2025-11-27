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

    while (true) { // Bucle infinito hasta que el usuario decida salir
        mostrarMenu(); // Mostramos el menú al usuario
        cout << "Seleccione una opción: "<< endl; // Pedimos al usuario que ingrese una opción

        // Manejo de entrada con excepciones
        try {
            if (!(cin >> opcion)) { // Si la entrada no es un número
                throw runtime_error("Entrada inválida. Debe ingresar un número."); // Lanzamos una excepción
            }
        } catch (runtime_error &e) { // Capturamos la excepción
            cout << e.what() << endl; // Mostramos mensaje de error
            cin.clear(); // Limpiamos el estado de error del cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiamos el buffer de entrada
            continue; // Volvemos al inicio del bucle
        }

        switch (opcion) { // Evaluamos la opción seleccionada
            case 1:
                // Consultar saldo
                cuentaSeleccionada = seleccionarCuenta(cuentas, 3); // Pedimos al usuario seleccionar una cuenta
                if (cuentaSeleccionada != -1) // Si la cuenta existe
                    consultarSaldo(&cuentas[cuentaSeleccionada]); // Mostramos el saldo
                break;
            case 2:
                // Depositar dinero
                cuentaSeleccionada = seleccionarCuenta(cuentas, 3); // Seleccionamos cuenta
                if (cuentaSeleccionada != -1) // Si la cuenta es válida
                    depositar(&cuentas[cuentaSeleccionada]); // Depositamos dinero
                break;
            case 3:
                // Retirar dinero
                cuentaSeleccionada = seleccionarCuenta(cuentas, 3); // Seleccionamos cuenta
                if (cuentaSeleccionada != -1) // Si la cuenta es válida
                    retirar(&cuentas[cuentaSeleccionada]); // Retiramos dinero
                break;
            case 4:
                // Transferir dinero
                cuentaSeleccionada = seleccionarCuenta(cuentas, 3); // Seleccionamos cuenta origen
                if (cuentaSeleccionada != -1) // Si la cuenta es válida
                    transferir(cuentas, 3, &cuentas[cuentaSeleccionada]); // Transferimos dinero
                break;
            case 5:
                // Salir del programa
                cout << "Gracias por usar el cajero automático." << endl; // Mensaje de despedida
                return 0; // Salimos del programa
            default:
                // Opción inválida
                cout << "Opción inválida. Intente nuevamente." << endl; // Mensaje de error
        }
    }

    return 0; // Retorno de la función principal (aunque no se alcanzará por el while infinito)
}

// Función para mostrar el menú principal
void mostrarMenu() {
    cout << "\n=== Cajero Automático ===" << endl; // Título del menú
    cout << "1. Consultar saldo" << endl; // Opción 1
    cout << "2. Depositar dinero" << endl; // Opción 2
    cout << "3. Retirar dinero" << endl; // Opción 3
    cout << "4. Transferir dinero" << endl; // Opción 4
    cout << "5. Salir" << endl; // Opción 5
}

// Función para seleccionar una cuenta
int seleccionarCuenta(Cuenta cuentas[], int totalCuentas) {
    int numeroCuenta; // Variable para almacenar el número de cuenta ingresado
    cout << "Ingrese el número de cuenta: "<< endl; // Pedimos número de cuenta
    if (!(cin >> numeroCuenta)) { // Validamos la entrada
        cout << "Entrada inválida." << endl; // Mensaje de error
        cin.clear(); // Limpiamos estado de error
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiamos buffer
        return -1; // Retornamos -1 si hubo error
    }

    // Buscamos la cuenta en el arreglo
    for (int i = 0; i < totalCuentas; i++) {
        if (cuentas[i].numeroCuenta == numeroCuenta) { // Si encontramos la cuenta
            return i; // Retornamos el índice de la cuenta
        }
    }

    cout << "Cuenta no encontrada." << endl; // Mensaje si la cuenta no existe
    return -1; // Retornamos -1 si no se encuentra
}

// Función para consultar saldo
void consultarSaldo(Cuenta *cuenta) {
    cout << "Titular: " << cuenta->titular << endl; // Mostramos el nombre del titular
    cout << "Saldo actual: $" << cuenta->saldo << endl; // Mostramos el saldo actual
}

// Función para depositar dinero
void depositar(Cuenta *cuenta) {
    float monto; // Variable para almacenar monto a depositar
    cout << "Ingrese el monto a depositar: $"; // Pedimos el monto
    if (!(cin >> monto)) { // Validamos entrada
        cout << "Monto inválido." << endl; // Mensaje de error
        cin.clear(); // Limpiamos estado de error
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiamos buffer
        return; // Salimos de la función
    }

    if (monto <= 0) { // Validamos que sea mayor que cero
        cout << "El monto debe ser mayor a cero." << endl; // Mensaje de error
        return;
    }

    cuenta->saldo += monto; // Sumamos el monto al saldo
    cout << "Depósito exitoso. Nuevo saldo: $" << cuenta->saldo << endl; // Mensaje de éxito
}




    return 0;  // Fin del programa
}

#include <iostream>     // Permite usar cin y cout
#include <stdexcept>    // Permite usar excepciones (runtime_error)
#include <cmath>        // Funciones matemáticas: sqrt, pow
using namespace std;    // Para evitar usar std

//     OPERACIONES BÁSICAS
// SUMA SOBREcargada (2 parámetros)
double sumar(double a, double b) {  // Función sumar con dos argumentos
    return a + b;                   // Retorna la suma de ambos
}

// SUMA SOBREcargada (3 parámetros)
double sumar(double a, double b, double c) { // Misma función, diferente firma
    return a + b + c;                        // Retorna la suma de los tres
}

// RESTA 
double restar(double a, double b) { // Resta dos números
    return a - b;                   // Retorna resultado
}

// MULTIPLICACIÓN
double multiplicar(double a, double b) { // Multiplica dos números
    return a * b;                        // Retorna resultado
}

// DIVISIÓN con excepción
double dividir(double a, double b) { // División
    if (b == 0)                      // Verifica si divisor es cero
        throw runtime_error("ERROR: No se puede dividir entre cero."); 
                                      // Lanza excepción si es cero
    return a / b;                     // Retorna división válida
}

//       OPERACIONES AVANZADAS
// -------- FACTORIAL (RECURSIVO) --------
long long factorial(int n) {              // Factorial de un entero
    if (n < 0)                            // Si el número es negativo
        throw runtime_error("ERROR: Factorial no definido para negativos.");
                                          // Lanza excepción

    if (n == 0 || n == 1)                 // Caso base
        return 1;

    return n * factorial(n - 1);          // Llamada recursiva
}

// POTENCIA con parámetro por omisión
double potencia(double base, int exponente = 2) { // exponente por defecto = 2
    return pow(base, exponente);                  // Usa pow() de cmath
}

// RAÍZ CUADRADA con excepción
double raiz(double x) {
    if (x < 0)                                     // Si el número es negativo
        throw runtime_error("ERROR: No se puede sacar raiz de un negativo.");
                                                   // Lanza excepción
    return sqrt(x);                                // Retorna raíz cuadrada
}

//==============================================================================

//  PROGRAMA PRINCIPAL
int main() {
    int opcion;                         // Variable para almacenar elección del menú

    do {                                // Bucle para mostrar menú repetidamente
        cout << "\n=========== CALCULADORA CIENTÍFICA ===========" << endl;
        cout << "1. Suma" << endl;      // Opción de suma
        cout << "2. Resta" << endl;     // Opción de resta
        cout << "3. Multiplicacion" << endl; // Opción de multiplicación
        cout << "4. Division" << endl;  // Opción de división
        cout << "5. Factorial" << endl; // Factorial (recursivo)
        cout << "6. Potencia" << endl;  // Potencia (con parámetro por omisión)
        cout << "7. Raiz cuadrada" << endl; // Raíz cuadrada
        cout << "0. Salir" << endl;     // Opción para salir
        cout << "Elija una opcion: ";   // Solicita opción
        cin >> opcion;                  // Guarda opción del usuario

        try {                           // Inicia bloque de manejo de errores

            double a, b;                // Variables numéricas
            int n;                      // Variable para factorial o exponente

            switch(opcion) {            // Selecciona acción según opción

            case 1:                     // SUMA
                cout << "Ingrese dos numeros: ";
                cin >> a >> b;          // Lee dos números
                cout << "Resultado: " << sumar(a, b) << endl; // Llama función sumar
                break;

            case 2:                     // RESTA
                cout << "Ingrese dos numeros: ";
                cin >> a >> b;
                cout << "Resultado: " << restar(a, b) << endl;
                break;

            case 3:                     // MULTIPLICACIÓN
                cout << "Ingrese dos numeros: ";
                cin >> a >> b;
                cout << "Resultado: " << multiplicar(a, b) << endl;
                break;

            case 4:                     // DIVISIÓN
                cout << "Ingrese dos numeros: ";
                cin >> a >> b;
                cout << "Resultado: " << dividir(a, b) << endl; // Puede lanzar excepción
                break;

            case 5:                     // FACTORIAL
                cout << "Ingrese un numero entero: ";
                cin >> n;
                cout << "Resultado: " << factorial(n) << endl; // Llama función recursiva
                break;

            case 6:                     // POTENCIA
                cout << "Ingrese base: ";
                cin >> a;
                cout << "Ingrese exponente (opcional, si pone 0 se usa por defecto 2): ";
                cin >> n;

                if (n == 0)                             // Si ingresa 0 usamos parámetro por omisión
                    cout << "Resultado: " << potencia(a) << endl;
                else
                    cout << "Resultado: " << potencia(a, n) << endl;
                break;

            case 7:                     // RAÍZ CUADRADA
                cout << "Ingrese un numero: ";
                cin >> a;
                cout << "Resultado: " << raiz(a) << endl; // Puede lanzar excepción
                break;

            case 0:                     // SALIR
                cout << "Saliendo..." << endl;
                break;

            default:                    // Opción no válida
                cout << "Opcion invalida." << endl;
            }

        } catch (exception &e) {        // Captura cualquier excepción lanzada
            cout << e.what() << endl;   // Muestra mensaje de error
        }

    } while (opcion != 0);              // Repite mientras no se elija "Salir"

    return 0;                           // Fin del programa
}

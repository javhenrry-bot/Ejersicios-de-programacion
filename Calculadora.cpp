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
int main() {
    double num1, num2;   // Variables para los números
    char operacion;      // Variable para la operación a realizar

    cout << "=== CALCULADORA BASICA ===\n";

    // Pedir al usuario los números
    cout << "Ingrese el primer numero: ";
    cin >> num1;

    cout << "Ingrese el segundo numero: ";
    cin >> num2;

    // Pedir operación
    cout << "Ingrese la operacion (+, -, *, /): ";
    cin >> operacion;

    // Realizar la operación
    switch (operacion) {
        case '+':
            cout << "Resultado: " << num1 + num2 << endl;
            break;

        case '-':
            cout << "Resultado: " << num1 - num2 << endl;
            break;

        case '*':
            cout << "Resultado: " << num1 * num2 << endl;
            break;

        case '/':
            if (num2 == 0) {
                cout << "ERROR: No se puede dividir entre cero." << endl;
            } else {
                cout << "Resultado: " << num1 / num2 << endl;
            }
            break;

        default:
            cout << "Operacion invalida." << endl;
            break;
    }

    return 0;
}

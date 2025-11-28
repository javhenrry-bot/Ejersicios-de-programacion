#include <iostream>
using namespace std;

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

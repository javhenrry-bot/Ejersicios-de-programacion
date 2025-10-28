#include <iostream>
#include <vector>
#include <limits> // Para manejar la limpieza del buffer de entrada

using namespace std;

// Definición de constantes
const char JUGADOR_X = 'X';
const char JUGADOR_O = 'O';
const char VACIO = ' ';

    // --- FUNCIONES DE TABLERO Y VISUALIZACIÓN ---

void mostrarTablero(const vector<vector<char>>& tablero) {
    cout << "\n";
    cout << "     |     |     " << endl;
    cout << "  " << tablero[0][0] << "  |  " << tablero[0][1] << "  |  " << tablero[0][2] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << tablero[1][0] << "  |  " << tablero[1][1] << "  |  " << tablero[1][2] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << tablero[2][0] << "  |  " << tablero[2][1] << "  |  " << tablero[2][2] << "  " << endl;
    cout << "     |     |     " << endl;
    cout << "\n";
}



void mostrarReferencia() {
    cout << "\n---- Referencia de Casillas (1-9) ---" << endl;
    cout << "     |     |     " << endl;
    cout << "  1  |  2  |  3  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  4  |  5  |  6  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  7  |  8  |  9  " << endl;
    cout << "     |     |     " << endl;
    cout << " " << endl;
    cout << "=================" << endl;
}

// --- MENÚ PRINCIPAL ---

void menuPrincipal() {
    int opcion = 0;
    while (opcion != 2) {
        cout << "\n=== TIC TAC TOE ===" << endl;
        cout << "1. Jugar nueva partida" << endl;
        cout << "2. Salir" << endl;
        cout << "Seleccione una opción: ";

        // Leer la opción y validar entrada
        if (!(cin >> opcion)) {
            cout << "Opción inválida. Intente de nuevo." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (opcion == 1) {
            jugarPartida();
        } else if (opcion == 2) {
            cout << "¡Gracias por jugar! " << endl;
        } else {
            cout << "Opción no reconocida. Por favor, seleccione 1 o 2." << endl;
        }
    }
}

int main() {
    menuPrincipal();
    return 0;
}


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

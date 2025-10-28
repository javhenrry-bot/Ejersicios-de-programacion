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

// --- LÓGICA DE DETECCIÓN DE ESTADO ---

 //return true si el jugador ha ganado, false en caso contrario.

bool checarGanador(const vector<vector<char>>& tablero, char jugador) {
    // 1. Verificar Filas y Columnas
    for (int i = 0; i < 3; ++i) {
        // Checar Fila i
        if (tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador) return true;
        
        // Checar Columna i
        if (tablero[0][i] == jugador && tablero[1][i] == jugador && tablero[2][i] == jugador) return true;
    }

    // 2. Verificar Diagonales
    // Diagonal principal
    if (tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador) return true;

    // Diagonal secundaria
    if (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador) return true;

    return false;
}


    //return true si hay empate, false en caso contrario.
 
bool checarEmpate(const vector<vector<char>>& tablero) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (tablero[i][j] == VACIO) {
                return false; // Todavía hay una casilla vacía
            }
        }
    }
    return true; // No hay casillas vacías
}

// --- FUNCIONALIDAD PRINCIPAL DEL JUEGO ---

void realizarMovimiento(vector<vector<char>>& tablero, char jugador) {
    int posicion = 0;
    int fila, columna;
    bool movimientoValido = false;

    while (!movimientoValido) {
        cout << "Jugador " << jugador << ", ingrese el número de casilla (1-9): ";
        
        // --- Validación de la entrada (Tipo de dato y Rango) ---
        if (!(cin >> posicion) || posicion < 1 || posicion > 9) {
            cout << "Entrada inválida. Debe ser un número entre 1 y 9." << endl;
            
            // Limpiar el buffer de entrada en caso de fallo de tipo de dato
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue; 
        }

        // Convertir la posición de 1-9 a coordenadas de matriz (0-2, 0-2)
        fila = (posicion - 1) / 3;
        columna = (posicion - 1) % 3;

        // --- Validación de la casilla (Ocupada) ---
        if (tablero[fila][columna] == VACIO) {
            tablero[fila][columna] = jugador;
            movimientoValido = true;
        } else {
            cout << " Casilla ocupada. Elija otra posición." << endl;
        }
    }
}

void jugarPartida() {
    // Inicializa el tablero como una matriz 3x3 llena de VACIO (' ')
    vector<vector<char>> tablero(3, vector<char>(3, VACIO));
    char jugadorActual = JUGADOR_X;
    bool juegoActivo = true;

    cout << "\n ¡El juego ha comenzado! Jugador X inicia." << endl;
    mostrarReferencia();

    while (juegoActivo) {
        mostrarTablero(tablero);
        
        realizarMovimiento(tablero, jugadorActual);

        // Checar si el jugador actual ganó
        if (checarGanador(tablero, jugadorActual)) {
            mostrarTablero(tablero);
            cout << " ¡El Jugador " << jugadorActual << " ha ganado!" << endl;
            juegoActivo = false;
        } 
        // Checar si hay empate
        else if (checarEmpate(tablero)) {
            mostrarTablero(tablero);
            cout << " ¡Es un empate!" << endl;
            juegoActivo = false;
        } 
        // Cambiar de turno
        else {
            jugadorActual = (jugadorActual == JUGADOR_X) ? JUGADOR_O : JUGADOR_X;
        }
    }
    cout << "\nPresione cualquier tecla para volver al menú principal...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer antes de la pausa
    cin.get(); // Pausa
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


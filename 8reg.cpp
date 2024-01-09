#include <iostream>
#include <vector>

const int N = 8; // Dimensiunea tablei de șah

// Funcție pentru afișarea tablei de șah
void printChessboard(const std::vector<std::vector<int>>& chessboard) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << (chessboard[i][j] ? "Q" : ".") << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

// Funcție pentru a verifica dacă o regină poate fi plasată pe poziția (row, col)
bool isSafe(const std::vector<std::vector<int>>& chessboard, int row, int col) {
    // Verificăm rândul
    for (int i = 0; i < col; ++i) {
        if (chessboard[row][i]) {
            return false;
        }
    }

    // Verificăm diagonala superioară
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (chessboard[i][j]) {
            return false;
        }
    }

    // Verificăm diagonala inferioară
    for (int i = row, j = col; i < N && j >= 0; ++i, --j) {
        if (chessboard[i][j]) {
            return false;
        }
    }

    return true;
}

// Funcție pentru a rezolva Problema Reginei utilizând backtracking
bool solveNQueens(std::vector<std::vector<int>>& chessboard, int col) {
    if (col == N) {
        // Am plasat toate reginele cu succes
        printChessboard(chessboard);
        return true; // Putem să continuăm pentru a găsi toate soluțiile
    }

    bool res = false;
    for (int i = 0; i < N; ++i) {
        if (isSafe(chessboard, i, col)) {
            chessboard[i][col] = 1; // Plasăm regina

            // Recursivitate pentru a plasa restul reginelor
            res = solveNQueens(chessboard, col + 1) || res;

            // Dacă nu găsim o soluție în continuare, ne întoarcem și anulăm plasarea reginei
            chessboard[i][col] = 0;
        }
    }

    return res;
}

int main() {
    std::vector<std::vector<int>> chessboard(N, std::vector<int>(N, 0));

    if (!solveNQueens(chessboard, 0)) {
        std::cout << "Nu exista solutie.\n";
    }

    return 0;
}

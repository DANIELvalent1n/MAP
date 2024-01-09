# Problema Celor 8 Regine - Documentație

## Descriere

**Problema Celor 8 Regine** este o problemă clasică de puzzle matematic în care obiectivul este să plasați 8 regine pe o tablă de șah de dimensiune 8x8 astfel încât nicio regină să nu poată ataca nicio altă regină. Atacul între regine este posibil în orizontală, verticală și pe diagonale.

## Algoritm de Rezolvare

Algoritmul folosit pentru rezolvarea Problemei Celor 8 Regine este **Backtracking**. Acesta constă în plasarea reginelor pe tablă în mod recursiv, verificând în fiecare pas dacă poziția curentă respectă condițiile cerute (adică, nicio regină nu poate ataca nicio altă regină).

1. **Funcția `isSafe`:**
   - Verifică dacă o regină poate fi plasată pe o anumită poziție fără a fi atacată de celelalte regine deja plasate.

2. **Funcția `solveNQueens`:**
   - Folosește recursivitatea pentru a încerca să plaseze reginele pe tablă în mod sigur.
   - Plasează o regină pe coloana curentă și apoi trece la coloana următoare.
   - Dacă se ajunge la o soluție validă, aceasta este afișată.

## Implementare în C++

```cpp
#include <iostream>
#include <vector>

const int N = 8;

// Funcții
void printChessboard(const std::vector<std::vector<int>>& chessboard);
bool isSafe(const std::vector<std::vector<int>>& chessboard, int row, int col);
bool solveNQueens(std::vector<std::vector<int>>& chessboard, int col);

int main() {
    std::vector<std::vector<int>> chessboard(N, std::vector<int>(N, 0));

    if (!solveNQueens(chessboard, 0)) {
        std::cout << "Nu exista solutie.\n";
    }

    return 0;
}

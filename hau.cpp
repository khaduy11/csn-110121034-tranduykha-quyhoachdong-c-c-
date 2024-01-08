#include <stdio.h>
#include <stdbool.h>

#define N 8

// In b?ng vua
void printBoard(int board[N][N]) {
	
	printf("---------------------------\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%2d ", board[i][j]);
        printf("\n");
        
        
        
        
    }
}

// Ki?m tra xem m?t � c� th? d?t h?u hay kh�ng
bool isSafe(int board[N][N], int row, int col) {
    // Ki?m tra d�ng d?u ti�n d?n d�ng hi?n t?i
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;

    // Ki?m tra du?ng ch�o tr�i tr�n
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    // Ki?m tra du?ng ch�o ph?i tr�n
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j] == 1)
            return false;

    return true;
}

// Gi?i b�i to�n B�t Qu�i b?ng d? quy
bool solveNQueens(int board[N][N], int row) {
    if (row == N) {
        // Khi d� d?t h?u tr�n t?t c? c�c d�ng, in b?ng
        printBoard(board);
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, row, i)) {
            // N?u � hi?n t?i l� an to�n, d?t h?u v� gi?i ti?p
            board[row][i] = 1;

            // Ki?m tra du?ng ch�o ph?i du?i cho c�c tru?ng h?p ti?p theo
            res = solveNQueens(board, row + 1) || res;

            // N?u kh�ng t�m du?c c�ch gi?i, quay lui v� th? � kh�c
            board[row][i] = 0;
        }
    }

    return res;
}

int main() {
    int board[N][N] = {0};

    if (!solveNQueens(board, 0))
        printf("Khong co loi giai cho bai toan B�t Qu�i.");

    return 0;
}


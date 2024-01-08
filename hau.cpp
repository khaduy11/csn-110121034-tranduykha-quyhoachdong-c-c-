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

// Ki?m tra xem m?t ô có th? d?t h?u hay không
bool isSafe(int board[N][N], int row, int col) {
    // Ki?m tra dòng d?u tiên d?n dòng hi?n t?i
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;

    // Ki?m tra du?ng chéo trái trên
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    // Ki?m tra du?ng chéo ph?i trên
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j] == 1)
            return false;

    return true;
}

// Gi?i bài toán Bát Quái b?ng d? quy
bool solveNQueens(int board[N][N], int row) {
    if (row == N) {
        // Khi dã d?t h?u trên t?t c? các dòng, in b?ng
        printBoard(board);
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, row, i)) {
            // N?u ô hi?n t?i là an toàn, d?t h?u và gi?i ti?p
            board[row][i] = 1;

            // Ki?m tra du?ng chéo ph?i du?i cho các tru?ng h?p ti?p theo
            res = solveNQueens(board, row + 1) || res;

            // N?u không tìm du?c cách gi?i, quay lui và th? ô khác
            board[row][i] = 0;
        }
    }

    return res;
}

int main() {
    int board[N][N] = {0};

    if (!solveNQueens(board, 0))
        printf("Khong co loi giai cho bai toan Bát Quái.");

    return 0;
}


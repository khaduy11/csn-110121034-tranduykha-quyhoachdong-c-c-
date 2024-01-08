#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int cutRod(int n, int val[]) {
    int dp[n + 1];
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int max_val = -1;

        for (int j = 0; j < i; j++) {
            max_val = max(max_val, val[j] + dp[i - j - 1]);
        }

        dp[i] = max_val;
    }

    return dp[n];
}

int main() {
    int n;

    // Nh?p d? dài queu
    printf("Nhap do dai queu: ");
    scanf("%d", &n);

    int val[n];

    // Nh?p giá tr? tuong ?ng cho t?ng d? dài
    printf("Nhap gia tri cho tung do dai queu:\n");
    for (int i = 0; i < n; i++) {
        printf("Nhap gia tri cho do dai %d: ", i + 1);
        scanf("%d", &val[i]);
    }

    // G?i hàm gi?i quy?t bài toán
    int result = cutRod(n, val);

    // In k?t qu?
    printf("Gia tri lon nhat co the dat duoc la: %d\n", result);

    return 0;
}


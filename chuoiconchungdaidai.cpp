#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void printLCS(char *s1, char *s2, int dp[][100], int m, int n) {
    int index = dp[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs[index - 1] = s1[i - 1];
            i--;
            j--;
            index--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("Chuoi con chung dai nhat la: %s\n", lcs);
}

int longestCommonSubsequence(char *s1, char *s2) {
    int m = strlen(s1);
    int n = strlen(s2);

    int dp[m + 1][100];

    // Kh?i t?o b?ng dp
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // In chu?i con chung dài nh?t
    printLCS(s1, s2, dp, m, n);

    return dp[m][n];
}

int main() {
    char s1[100], s2[100];

    // Nhap chuoi 1
    printf("Nhap chuoi 1: ");
    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = '\0'; // Xóa ký t? newline n?u có

    // Nhap chuoi 2
    printf("Nhap chuoi 2: ");
    fgets(s2, sizeof(s2), stdin);
    s2[strcspn(s2, "\n")] = '\0'; // Xóa ký t? newline n?u có

    int result = longestCommonSubsequence(s1, s2);

    printf("Do dai cua chuoi con chung dai nhat la: %d\n", result);

    return 0;
}


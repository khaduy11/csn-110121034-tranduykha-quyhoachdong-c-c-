#include <stdio.h>
#include <string.h>

int ls(char str[], int n) {
    int dp[n][n];

    // dp
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    for (int cl = 2; cl <= n; cl++) {
        for (int i = 0; i < n - cl + 1; i++) {
            int j = i + cl - 1;
            if (str[i] == str[j] && cl == 2)
                dp[i][j] = 2;
            else if (str[i] == str[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else
                dp[i][j] = (dp[i][j - 1] > dp[i + 1][j]) ? dp[i][j - 1] : dp[i + 1][j];
        }
    }

    return dp[0][n - 1];
}

int main() {
    char str[100];
    printf("Nhap Mot Xau: ");
    scanf("%s", str);

    int n = strlen(str);

    int result = ls(str, n);

    printf("Do dai cua xau con chung dai nhat là: %d\n", result);

    return 0;
}

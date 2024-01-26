#include <stdio.h>


void inputCoins(int coins[], int m) {
    printf("Nhap gia tri %d cua loai dong xu:\n", m);
    for (int i = 0; i < m; i++) {
        printf("Dong xu thu %d: ", i + 1);
        scanf("%d", &coins[i]);
    }
}

int inputTargetAmount() {
    int V;
    printf("Nhap so tien can tra lai: ");
    scanf("%d", &V);
    return V;
}

int countWays(int coins[], int m, int V) {
    int dp[m + 1][V + 1];

    // khoi tao gia tri ban dau
    for (int i = 0; i <= m; i++)
        dp[i][0] = 1;

    for (int j = 1; j <= V; j++)
        dp[0][j] = 0;

    // dp
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= V; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - coins[i - 1] >= 0)
                dp[i][j] += dp[i][j - coins[i - 1]];
        }
    }

    return dp[m][V];
}

int main() {
    int m;
    printf("Nhap so loai dong xu: ");
    scanf("%d", &m);

    int coins[m];
    inputCoins(coins, m);

    int V = inputTargetAmount();

    int ways = countWays(coins, m, V);

    printf("So cach  tra lai %d bang dong xu la: %d\n", V, ways);

    return 0;
}


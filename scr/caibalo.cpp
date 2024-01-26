#include <stdio.h>

#define MAX_ITEMS 100

int weights[MAX_ITEMS];
int values[MAX_ITEMS];
int knapsack[MAX_ITEMS][MAX_ITEMS];

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsackAlgorithm(int numItems, int maxWeight) {
    for (int i = 0; i <= numItems; i++) {
        for (int w = 0; w <= maxWeight; w++) {
            if (i == 0 || w == 0) {
                knapsack[i][w] = 0;
            } else if (weights[i] <= w) {
                knapsack[i][w] = max(values[i] + knapsack[i - 1][w - weights[i]], knapsack[i - 1][w]);
            } else {
                knapsack[i][w] = knapsack[i - 1][w];
            }
        }
    }
}

void printItems(int numItems, int maxWeight) {
    int i = numItems;
    int j = maxWeight;

    while (i > 0 && j > 0) {
        if (knapsack[i][j] != knapsack[i - 1][j]) {
            printf("%d ", i);
            j -= weights[i];
        }
        i--;
    }
}

int main() {
    int numItems, maxWeight;

    printf("Nhap so luong do vat: ");
    scanf("%d", &numItems);

    printf("Nhap trong luong toi da cua balo: ");
    scanf("%d", &maxWeight);

    printf("Nhap khoi luong cua cac do vat:\n");
    for (int i = 1; i <= numItems; i++) {
        printf("Do vat %d: ", i);
        scanf("%d", &weights[i]);
    }

    printf("Nhap gia tri cua cac do vat:\n");
    for (int i = 1; i <= numItems; i++) {
        printf("Do vat %d: ", i);
        scanf("%d", &values[i]);
    }

    knapsackAlgorithm(numItems, maxWeight);

    printf("\nBang tinh:\n");
    for (int i = 0; i <= numItems; i++) {
        for (int w = 0; w <= maxWeight; w++) {
            printf("%5d", knapsack[i][w]);
        }
        printf("\n");
    }

    printf("\nCac do vat duoc chon: ");
    printItems(numItems, maxWeight);

    printf("\nTong gia tri lon nhat cua balo: %d\n", knapsack[numItems][maxWeight]);

    return 0;
}

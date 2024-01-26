#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int longestIncreasingSubsequence(int arr[], int n) {
    int lis[n];
    int maxLIS = 1;

    // Kh?i t?o LIS cho m?i ph?n t? là 1
    for (int i = 0; i < n; i++) {
        lis[i] = 1;
    }

    // Xây d?ng b?ng LIS
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
        // C?p nh?t d? dài LIS l?n nh?t
        maxLIS = max(maxLIS, lis[i]);
    }

    return maxLIS;
}

int main() {
    int n;

    // Nh?p s? lu?ng ph?n t? c?a m?ng
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n];

    // Nh?p m?ng
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    // G?i hàm tính d? dài c?a dãy con tang dài nh?t
    int result = longestIncreasingSubsequence(arr, n);

    // In k?t qu?
    printf("Do dai cua day con tang dai nhat la: %d\n", result);

    return 0;
}


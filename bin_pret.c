#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(float V[], int n) {
    int i, j;
    float temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (V[j] > V[j + 1]) {
                temp = V[j];
                V[j] = V[j + 1];
                V[j + 1] = temp;
            }
        }
    }
}

int bin_pret(float V[], int n, float x) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (V[mid] == x)
            return mid;
        else if (V[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    time_t  t1, t2;
    srand((unsigned)time(NULL));
    int n = rand() % 1000;
    float* V = (float*)malloc(n * sizeof(float));
    if (V == NULL) {
        return -1;
    }
    float x = rand() % n;


    for (int i = 0; i < n; i++) {
        V[i] = rand() % n;
    }

    bubble_sort(V, n);
    t1 = clock();
    int result = bin_pret(V, n, x);
    t2 = clock();

    if (result == -1) {
        printf("Element nije pronaden.\n");
    }
    else {
        printf("Element na indexu %d.\n", result);
    }
    printf("Vrijeme trajanja je % dms\n", t2 - t1);
    printf("broj elemenata %d", n);

    free(V);

    return 0;
}


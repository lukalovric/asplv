#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(float V[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (V[j] < V[min_index])
                min_index = j;
        }
        float temp = V[i];
        V[i] = V[min_index];
        V[min_index] = temp;
    }
}

int main() {
    time_t  t1, t2;
    srand((unsigned)time(NULL));
    int n = rand() % 1000;
    float* V = (float*)malloc(n * sizeof(float));
    if (V == NULL) {
        return -1;
    }

    for (int i = 0; i < n; i++) {
        V[i] = rand()%1000;
    }

    t1 = clock();
    sort(V, n);
    t2 = clock();

    
    printf("Vrijeme trajanja je %dms\n", (int)(t2 - t1));
    printf("broj elemenata %d", n);

    free(V);

    return 0;
}

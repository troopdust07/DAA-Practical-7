#include <stdio.h>

#define n 5

int G[n][n] = {
    {0, 1, 1, 0, 1},
    {1, 0, 1, 1, 0},
    {1, 1, 0, 1, 1},
    {0, 1, 1, 0, 1},
    {1, 0, 1, 1, 0}
};

int x[n];

int NextValue(int k) {
    int j;
    do {
        x[k] = (x[k] + 1) % n; 
        if (x[k] == 0) return 0; 

        if (G[x[k - 1]][x[k]] != 0) {

            for (j = 0; j < k; j++)
                if (x[j] == x[k])
                    break;

            if (j == k) {
                if ((k < n - 1) || ((k == n - 1) && G[x[k]][x[0]] != 0))
                    return 1;
            }
        }
    } while (1);
}

void Hamiltonian(int k) {
    int flag;
    do {
        flag = NextValue(k);
        if (!flag) return;

        if (k == n - 1) {
            printf("\nHamiltonian Cycle Found: ");
            for (int i = 0; i < n; i++)
                printf("%c -> ", x[i] + 'A');
            printf("%c\n", x[0] + 'A');
        } else
            Hamiltonian(k + 1);

    } while (1);
}

int main() {
    printf("\nAdjacency Matrix Representation:\n");
    printf("   T M S H C\n");
    printf("T: 0 1 1 0 1\n");
    printf("M: 1 0 1 1 0\n");
    printf("S: 1 1 0 1 1\n");
    printf("H: 0 1 1 0 1\n");
    printf("C: 1 0 1 1 0\n");

    for (int i = 0; i < n; i++)
        x[i] = 0;
    x[0] = 0;

    Hamiltonian(1);
    return 0;
}

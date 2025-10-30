#include <stdio.h>
#define N 5
int G[N][N] = {
    {0,1,1,0,1}, // A
    {1,0,1,1,0}, // B
    {1,1,0,1,0}, // C
    {0,1,1,0,1}, // D
    {1,0,0,1,0}  // E
};
int x[N];
char vertexName[] = {'A','B','C','D','E'};
void NextValue(int k) {
    int j;
    while (1) {
        x[k]++;
        if (x[k] >= N) {
            x[k] = -1;
            return;
        }
        if (G[x[k-1]][x[k]] == 0)
            continue;
        for (j = 0; j < k; j++)
            if (x[j] == x[k])
                break;
        if (j < k) continue;
        if (k == N-1 && G[x[k]][x[0]] == 0)
            continue;
        return;
    }
}

void Hamiltonian(int k) {
    while (1) {
        NextValue(k);
        if (x[k] == -1)
            return;
        if (k == N-1) {
            printf("Hamiltonian Cycle Found: ");
            for (int i = 0; i < N; i++)
                printf("%c -> ", vertexName[x[i]]);
            printf("%c\n", vertexName[x[0]]);
        } else {
            Hamiltonian(k + 1);
        }
    }
}

int main() {
    for (int i = 0; i < N; i++)
        x[i] = -1;
    x[0] = 0;
    Hamiltonian(1);
    return 0;
}

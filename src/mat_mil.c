#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1024           // Matrix size (NxN)
#define BLOCK_SIZE 32    // Tile size (try 16, 32, 64)

void naive_multiply(float *A, float *B, float *C) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                C[i * N + j] += A[i * N + k] * B[k * N + j];
}

void tiled_multiply(float *A, float *B, float *C) {
    for (int ii = 0; ii < N; ii += BLOCK_SIZE)
        for (int jj = 0; jj < N; jj += BLOCK_SIZE)
            for (int kk = 0; kk < N; kk += BLOCK_SIZE)

                for (int i = ii; i < ii + BLOCK_SIZE && i < N; i++)
                    for (int j = jj; j < jj + BLOCK_SIZE && j < N; j++)
                        for (int k = kk; k < kk + BLOCK_SIZE && k < N; k++)
                            C[i * N + j] += A[i * N + k] * B[k * N + j];
}

void fill_matrix(float *mat) {
    for (int i = 0; i < N * N; i++)
        mat[i] = (float)(rand() % 10);
}

void zero_matrix(float *mat) {
    for (int i = 0; i < N * N; i++)
        mat[i] = 0.0f;
}

int main() {
    float *A = (float *)malloc(N * N * sizeof(float));
    float *B = (float *)malloc(N * N * sizeof(float));
    float *C = (float *)malloc(N * N * sizeof(float));

    srand(time(NULL));
    fill_matrix(A);
    fill_matrix(B);

    // Naive version
    zero_matrix(C);
    clock_t start = clock();
    naive_multiply(A, B, C);
    clock_t end = clock();
    double naive_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Naive Time: %.4f seconds\n", naive_time);

    // Tiled version
    zero_matrix(C);
    start = clock();
    tiled_multiply(A, B, C);
    end = clock();
    double tiled_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tiled Time: %.4f seconds\n", tiled_time);

    free(A);
    free(B);
    free(C);
    return 0;
}


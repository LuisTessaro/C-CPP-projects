#include <stdio.h>
#include <stdlib.h>
#define max 3

void calc(int matrix1[][max], int matrix2[][max], int result[][max], int n);
void showy(int result[][max]);

int main() {
	int a = 0;
	int i, j, k = 0;
	int matrix1[max][max], matrix2[max][max], res[max][max] = {0};


	for (i = 0; i<max; i++) {
		for (j = 0; j<max; j++) {
			matrix1[i][j] = 2;
		}
	}

	for (i = 0; i<max; i++) {
		for (j = 0; j<max; j++) {
			matrix2[i][j] = 2;
		}
	}

	calc(matrix1, matrix2, res,max);
	showy(res);


	return 0;
}

void showy(int res[][max]) {
	int i;
	int j;
	for (i = 0; i < max; i++) {
		for (j = 0; j < max; j++)
			printf("%d ", res[i][j]);
		printf("\n");
	}
}

void calc(int matrix1[][max], int matrix2[][max], int res[][max], int n) {
	int i, j, k;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			for (k = 0; k < n; k++)
				res[i][j] += matrix1[i][k] * matrix2[k][j];
}
#include <stdio.h>

typedef struct matrix {
    int n_row; // number of rows
    int n_col; // number of columns
    short data[100][100]; // matrix data
} matrix;

matrix input_matrix(int n, int m)
{
    matrix mat = { n, m, { 0 } };

    for (int r = 0; r < mat.n_row; r++) {
        for (int c = 0; c < mat.n_col; c++) {
            scanf("%d", &mat.data[r][c]);
        }
    }

    return mat;
}

matrix add_matrix(matrix a, matrix b)
{
    matrix result = { a.n_row, a.n_col, { 0 } };

    for (int r = 0; r < result.n_row; r++) {
        for (int c = 0; c < result.n_col; c++) {
            result.data[r][c] = a.data[r][c] + b.data[r][c];
        }
    }

    return result;
}

void print_matrix(matrix mat)
{
    for (int r = 0; r < mat.n_row; r++) {
        for (int c = 0; c < mat.n_col; c++) {
            printf("%d ", mat.data[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    matrix a = input_matrix(n, m);
    matrix b = input_matrix(n, m);

    matrix c = add_matrix(a, b);
    print_matrix(c);

    return 0;
}
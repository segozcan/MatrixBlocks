#include <stdio.h>
#include <stdlib.h>

int **TwoDArray(int dim) {

    int i;

    int **matrix = (int **) malloc(dim * sizeof(int *));

    for (i = 0; i < dim; i++) {
        int *temp = (int *) malloc(dim * sizeof(int));
        matrix[i] = temp;
    }

    return matrix;
}

int **multiArray(int row, int coloumn) {

    int i;
    int **matrix = (int **) malloc(sizeof(int *) * row);

    for (i = 0; i < coloumn; i++) {

        int *line = (int *) malloc(sizeof(int) * coloumn);
        matrix[i] = line;
    }
    return matrix;
}

int **partition(int **matrix, int size, int matrix_size) {

    printf("partition starts\n");
    int i = 0;
    int j = 0;
    int m = 0;
    int k = 0;
    int c = -1;
    int biggest;
    int count = 0;
    int a, b;

    int **output = multiArray(matrix_size - size + 1, matrix_size - size + 1);
    printf("output allocated\n");

    for (i = 0; i < matrix_size - size + 1; i++) {

        for (j = 0; j < matrix_size - size + 1; j++) {
            int array[size * size];
            for (k = 0; k < size; k++) {
                for (m = 0; m < size; m++) {

                    if ((*(matrix + i + k) + j + m) != NULL) {
                        c++;
                        int value = matrix[i + k][j + m];
                        array[c] = value;
                        printf(" i = %d j = %d k = %d m = %d\nvalue : %d c : %d \n", i, j, k, m, value, c);
                    }
                }
            }

            if (c < size * size - 1) {
                printf("less than array\n");
                c = -1;
                continue;
            }


            for (a = 0; a < c; a++) {
                for (b = 0; b < c - a; b++) {
                    if (array[b] < array[b + 1]) {
                        int temp = array[b];
                        array[b] = array[b + 1];
                        array[b + 1] = temp;
                    }
                }
            }
            c = -1;
            count++;
            biggest = array[0];
            printf("biggest : %d count : %d\n\n", biggest, count);
            output[(count - 1) / (matrix_size - size + 1)][(count - 1) % (matrix_size - size + 1)] = biggest;

        }
    }

    printf("partition over\n");
    return output;
}

void greatestInteger() {
    int dim;
    int i = 0;
    int j = 0;
    int t = 0;
    int p = 0;
    int size;
    int **output;
    scanf(" %d %d", &dim, &size);

    int **matrix = multiArray(dim, dim);

    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            scanf("%d ", *(matrix + i) + j);
        }
    }

    output = partition(matrix, size, dim);

    for (t = 0; t < dim - size + 1; t++) {
        for (p = 0; p < dim - size + 1; p++) {
            printf("%d ", output[t][p]);
        }
        printf("\n");
    }
}

void printMatrix(int **matrix, int row, int coloumn) {

    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < coloumn; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int **getMatrix(int row, int coloumn) {

    int i, j;
    int **matrix = multiArray(row, coloumn);
    for (i = 0; i < row; i++) {
        for (j = 0; j < coloumn; j++) {
            scanf("%d ", *(matrix + i) + j);
        }
    }
    return matrix;
}

int **translate(int **array, int *index1, int width, int height, int *index2) {

    int x1 = index1[0];
    int y1 = index1[1];
    int x2 = index2[0];
    int y2 = index2[1];

    int i, j;
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            if(x1+width >= x2 || y1+height >= y2){
                int k , m;
                for(k = 0; k < x1 + width-x2; k++){
                    for(m = 0; m < y1+height-y2 ){
                        int i1[2] = {x2+k, y2+m};
                        int i2[2] = {};
                        translate(array,i1, 1,1,)
                    }
                }
            }
            *(*(array + x2 + i) + j + y2) = *(*(array + x1 + i) + j + y1);
        }
    }
    return array;
}

int main() {

    int **matrix = getMatrix(5, 5);
    int index1[] = {1, 1};
    int index2[] = {2, 1};
    matrix = translate(matrix, index1, 2, 2, index2);
    printMatrix(matrix, 5, 5);
    return 0;
}

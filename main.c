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

    for( i= 0; i< matrix_size-size +1 ; i++){

        for(j = 0; j< matrix_size-size +1 ; j++){
            int array[size * size];
            for (k = 0; k < size; k++) {
                for (m = 0; m < size; m++) {

                    if ((*(matrix+i+k)+ j+m) != NULL) {
                        c++;
                        int value = matrix[i + k][j + m];
                        array[c] = value;
                        printf(" i = %d j = %d k = %d m = %d\nvalue : %d c : %d \n",i, j ,k, m,value, c);
                    }
                }
            }

            if(c < size * size -1){
                printf("less than array\n");
                c = -1;
                continue;
            }


            for (a = 0; a < c; a++) {
                for (b = 0; b < c-a; b++) {
                    if (array[b] < array[b + 1]) {
                        int temp = array[b];
                        array[b] = array[b + 1];
                        array[b + 1] = temp;
                    }
                }
            }
            c = -1 ;
            count ++;
            biggest = array[0];
            printf("biggest : %d count : %d\n\n", biggest, count);
            output[(count-1) / (matrix_size - size + 1)][(count-1) % (matrix_size - size + 1)] = biggest;

        }
    }

    printf("partition over\n");
    return output;
}

int main() {
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
    return 0;
}

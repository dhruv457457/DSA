#include <stdio.h>
#include <stdlib.h>

// Typedefs for cleaner code
typedef struct ColumnNode {
    int col, val;
    struct ColumnNode *link;
} ColumnNode;

typedef struct RowNode {
    int row;
    ColumnNode *column;
    struct RowNode *next;
} RowNode;

typedef struct {
    int rowNo, columnNo, NZele;
    RowNode *Row;
} Header;

// Function to read sparse matrix
void readMatrix(Header **start) {
    *start = (Header *)malloc(sizeof(Header));
    printf("Enter rows, columns, and non-zero terms: ");
    scanf("%d %d %d", &(*start)->rowNo, &(*start)->columnNo, &(*start)->NZele);

    if ((*start)->NZele <= 0) {
        printf("Invalid operation\n");
        return;
    }

    (*start)->Row = NULL;
    RowNode *currentRow = NULL;
    for (int i = 0; i < (*start)->NZele; i++) {
        int row, col, term;
        printf("Enter row, col, and value: ");
        scanf("%d %d %d", &row, &col, &term);

        if (!currentRow || currentRow->row != row) {
            RowNode *newRow = (RowNode *)malloc(sizeof(RowNode));
            newRow->row = row;
            newRow->column = NULL;
            newRow->next = NULL;

            if (!(*start)->Row) (*start)->Row = newRow;
            else currentRow->next = newRow;

            currentRow = newRow;
        }

        ColumnNode *newCol = (ColumnNode *)malloc(sizeof(ColumnNode));
        newCol->col = col;
        newCol->val = term;
        newCol->link = currentRow->column;
        currentRow->column = newCol;
    }
}

// Function to print sparse matrix
void printSparseMatrix(Header *head) {
    printf("%d\t%d\t%d\n", head->rowNo, head->columnNo, head->NZele);
    for (RowNode *row = head->Row; row; row = row->next) {
        for (ColumnNode *col = row->column; col; col = col->link)
            printf("%d\t%d\t%d\n", row->row, col->col, col->val);
    }
}

// Convert linked list to array
int readArray(Header *start, int arr[][3]) {
    arr[0][0] = start->rowNo;
    arr[0][1] = start->columnNo;
    arr[0][2] = start->NZele;

    int i = 1;
    for (RowNode *row = start->Row; row; row = row->next) {
        for (ColumnNode *col = row->column; col; col = col->link) {
            arr[i][0] = row->row;
            arr[i][1] = col->col;
            arr[i][2] = col->val;
            i++;
        }
    }
    return arr[0][2];
}

// Fast transpose
void fast_transpose(int A[][3], int B[][3]) {
    int m = A[0][0], n = A[0][1], t = A[0][2];
    B[0][0] = n; B[0][1] = m; B[0][2] = t;

    if (t <= 0) return;

    int *C = (int *)calloc(n, sizeof(int));
    int *S = (int *)malloc((n + 1) * sizeof(int));

    for (int i = 1; i <= t; i++) C[A[i][1]]++;
    S[0] = 1;
    for (int k = 1; k <= n; k++) S[k] = S[k - 1] + C[k - 1];

    for (int i = 1; i <= t; i++) {
        int j = A[i][1];
        int pos = S[j]++;
        B[pos][0] = A[i][1];
        B[pos][1] = A[i][0];
        B[pos][2] = A[i][2];
    }

    free(C); free(S);
}

// Convert array back to linked list
void arrayToLinked(int arr[][3], Header **start) {
    *start = (Header *)malloc(sizeof(Header));
    (*start)->rowNo = arr[0][0];
    (*start)->columnNo = arr[0][1];
    (*start)->NZele = arr[0][2];
    (*start)->Row = NULL;

    RowNode *currentRow = NULL;
    for (int i = 1; i <= arr[0][2]; i++) {
        if (!currentRow || currentRow->row != arr[i][0]) {
            RowNode *newRow = (RowNode *)malloc(sizeof(RowNode));
            newRow->row = arr[i][0];
            newRow->column = NULL;
            newRow->next = NULL;

            if (!(*start)->Row) (*start)->Row = newRow;
            else currentRow->next = newRow;

            currentRow = newRow;
        }

        ColumnNode *newCol = (ColumnNode *)malloc(sizeof(ColumnNode));
        newCol->col = arr[i][1];
        newCol->val = arr[i][2];
        newCol->link = currentRow->column;
        currentRow->column = newCol;
    }
}

int main() {
    int arr[50][3], b[50][3];
    Header *start = NULL, *transposedStart = NULL;

    readMatrix(&start);
    printf("Sparse Matrix Representation:\n");
    printSparseMatrix(start);

    readArray(start, arr);
    fast_transpose(arr, b);
    arrayToLinked(b, &transposedStart);

    printf("\nTransposed Sparse Matrix Representation:\n");
    printSparseMatrix(transposedStart);

    return 0;
}

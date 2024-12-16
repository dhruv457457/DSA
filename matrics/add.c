#include <stdio.h>
#include <stdlib.h>

// Typedefs for cleaner code
typedef struct ColumnNode {
    int col, val;
    struct ColumnNode *link;
} ColumnNode;

typedef struct RowNode {
    int row;
    struct RowNode *next;
    ColumnNode *column;
} RowNode;

typedef struct {
    int rowNo, columnNo, NZele;
    RowNode *Row;
} Header;

// Function to insert sparse matrix
Header *insert(Header *head) {
    int m, n, t, row, column, val;
    head = (Header *)malloc(sizeof(Header));

    printf("Enter the no. of rows, columns, and non-zero elements: ");
    scanf("%d %d %d", &m, &n, &t);

    head->rowNo = m;
    head->columnNo = n;
    head->NZele = t;
    head->Row = NULL;

    if (t <= 0) return head;

    RowNode *currentRow = NULL, *newRow;
    ColumnNode *currentCol, *newCol;

    for (int i = 0; i < t; i++) {
        printf("Enter row, column, and value: ");
        scanf("%d %d %d", &row, &column, &val);

        if (!currentRow || currentRow->row != row) {
            newRow = (RowNode *)malloc(sizeof(RowNode));
            newRow->row = row;
            newRow->next = NULL;
            newRow->column = NULL;

            if (!head->Row) head->Row = newRow;
            else currentRow->next = newRow;

            currentRow = newRow;
            currentCol = NULL;
        }

        newCol = (ColumnNode *)malloc(sizeof(ColumnNode));
        newCol->col = column;
        newCol->val = val;
        newCol->link = NULL;

        if (!currentRow->column) currentRow->column = newCol;
        else currentCol->link = newCol;

        currentCol = newCol;
    }
    return head;
}

// Function to print sparse matrix
void printSparseMatrix(Header *head) {
    printf("%d\t%d\t%d\n", head->rowNo, head->columnNo, head->NZele);
    for (RowNode *row = head->Row; row; row = row->next) {
        for (ColumnNode *col = row->column; col; col = col->link) {
            printf("%d\t%d\t%d\n", row->row, col->col, col->val);
        }
    }
}

// Function to add two sparse matrices
Header *addSparseMatrix(Header *mat1, Header *mat2) {
    if (!mat1 || !mat2 || mat1->rowNo != mat2->rowNo || mat1->columnNo != mat2->columnNo) {
        printf("Matrices cannot be added due to size mismatch.\n");
        return NULL;
    }

    Header *result = (Header *)malloc(sizeof(Header));
    result->rowNo = mat1->rowNo;
    result->columnNo = mat1->columnNo;
    result->NZele = 0;
    result->Row = NULL;

    RowNode *row1 = mat1->Row, *row2 = mat2->Row, *lastRow = NULL;

    while (row1 || row2) {
        RowNode *newRow = (RowNode *)malloc(sizeof(RowNode));
        newRow->column = NULL;
        newRow->next = NULL;

        if (!row2 || (row1 && row1->row < row2->row)) {
            newRow->row = row1->row;
            for (ColumnNode *col1 = row1->column; col1; col1 = col1->link) {
                ColumnNode *newCol = (ColumnNode *)malloc(sizeof(ColumnNode));
                *newCol = *col1;
                newCol->link = newRow->column;
                newRow->column = newCol;
                result->NZele++;
            }
            row1 = row1->next;
        } else if (!row1 || (row2 && row1->row > row2->row)) {
            newRow->row = row2->row;
            for (ColumnNode *col2 = row2->column; col2; col2 = col2->link) {
                ColumnNode *newCol = (ColumnNode *)malloc(sizeof(ColumnNode));
                *newCol = *col2;
                newCol->link = newRow->column;
                newRow->column = newCol;
                result->NZele++;
            }
            row2 = row2->next;
        } else {
            newRow->row = row1->row;
            ColumnNode *col1 = row1->column, *col2 = row2->column;
            while (col1 || col2) {
                ColumnNode *newCol = (ColumnNode *)malloc(sizeof(ColumnNode));
                if (!col2 || (col1 && col1->col < col2->col)) {
                    *newCol = *col1;
                    col1 = col1->link;
                } else if (!col1 || (col2 && col1->col > col2->col)) {
                    *newCol = *col2;
                    col2 = col2->link;
                } else {
                    newCol->col = col1->col;
                    newCol->val = col1->val + col2->val;
                    newCol->link = NULL;
                    col1 = col1->link;
                    col2 = col2->link;
                }
                newCol->link = newRow->column;
                newRow->column = newCol;
                result->NZele++;
            }
            row1 = row1->next;
            row2 = row2->next;
        }

        if (!result->Row) result->Row = newRow;
        else lastRow->next = newRow;
        lastRow = newRow;
    }
    return result;
}

int main() {
    Header *head1 = NULL, *head2 = NULL, *head3 = NULL;

    printf("Input First Matrix:\n");
    head1 = insert(head1);
    printf("First Matrix:\n");
    printSparseMatrix(head1);

    printf("\nInput Second Matrix:\n");
    head2 = insert(head2);
    printf("Second Matrix:\n");
    printSparseMatrix(head2);

    printf("\nSum of Matrices:\n");
    head3 = addSparseMatrix(head1, head2);
    if (head3) printSparseMatrix(head3);

    return 0;
}

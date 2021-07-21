#ifndef _SPARSE_H_
#define _SPARSE_H_

#define MAXSIZE 20

#define TRUE 1
#define FALSE 2

struct sparse
{
    int *sp;
    int row;
    int *result;
};

void initsparse(struct sparse *);
void create_array(struct sparse *, int MAX1, int MAX2);
int count(struct sparse, int MAX1, int MAX2);
void display(struct sparse, int MAX1, int MAX2);
void create_tuple(struct sparse *, struct sparse, int MAX1, int MAX2);
void display_tuple(struct sparse);
void prodmat(struct sparse *, struct sparse, struct sparse);
void searchina(int *sp, int ii, int *p, int *flag);
void searchinb(int *sp, int jj, int colofa, int *p, int *flag);
void display_result(struct sparse);
void delsparse(struct sparse *);

//--------------------------------------------------------------------//

void rep_sparse(int m, int n, int mat[m][n]); //Time Complexity = O(mn)

int **create_sparse(int m, int n, int mat[m][n]); //Time Complexity = O(mn)

void print_sparse(int size, int **sparse);

int size_sparse(int m, int n, int mat[m][n]); //Time Complexity = O(mn)

void check_sparse(int r, int c, int mat[r][c]); //Time Complexity = O(rc)

void addition(int ktemp[3][100], int ltemp[3][100], int k, int l); //Time Complexity = O(k or l) + O(x)

void subtraction(int ktemp[3][100], int ltemp[3][100], int k, int l); //Time Complexity = O(k or l) + O(x)

void sort(int k[3][100], int count); //Time Complexity = O(count^2)

void transpose(int k[3][100], int count); //Time Complexity = O(count^2)

void multiply(int k[3][100], int count, int r1, int c1);

//Linked list

// Node to represent sparse matrix

struct Node
{
    int value;
    int row_position;
    int column_postion;
    struct Node *next;
};

void create_new_node(struct Node **start, int non_zero_element, int row_index, int column_index);

void PrintList(struct Node *start);

//lists of lists

// Node to represent row - list
struct row_list
{
    int row_number;
    struct row_list *link_down;
    struct value_list *link_right;
};

// Node to represent triples
struct value_list
{
    int column_index;
    int value;
    struct value_list *next;
};

void create_value_node(int data, int j, struct row_list **z);

void create_row_list(struct row_list **start, int row, int column, int Sparse_Matrix[row][column]);

void print_LIL(struct row_list *start);

#endif
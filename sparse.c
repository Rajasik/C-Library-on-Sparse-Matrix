//Library for sparse matrix

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#include"sparse.h"

/* initialises elements of structure */
void initsparse ( struct sparse *p )
{
    p -> sp = NULL ;
    p -> result = NULL ;
}

/* dynamically creates the matrix */
void create_array ( struct sparse *p , int MAX1, int MAX2)
{
    int n, i ;

    /* allocate memory */

    p -> sp = ( int * ) malloc ( MAX1 * MAX2 * sizeof ( int ) ) ;

    /* add elements to the array */
    for ( i = 0 ; i < MAX1 * MAX2 ; i++ )
    {
            printf ( "Enter element no. %d: ", i ) ;
            scanf ( "%d", &n ) ;
            * ( p -> sp + i ) = n ;
    }
}

/* displays the contents of the matrix */
void display ( struct sparse s ,int MAX1, int MAX2)
{
    int i ;

    /* traverses the entire matrix */
for ( i = 0 ; i < MAX1 * MAX2 ; i++ )
    {
        /* positions the cursor to the new line for every new row */
if ( i % 3 == 0 )
            printf ( "\n" ) ;
        printf ( "%d\t", * ( s.sp + i ) ) ;
    }
}

/* counts the number of non-zero elements */
int count ( struct sparse s, int MAX1, int MAX2 )
{
    int cnt = 0, i ;

    for ( i = 0 ; i < MAX1 * MAX2 ; i++ )
    {
        if ( * ( s.sp + i ) != 0 )
            cnt++ ;
    }
    return cnt ;
}

/* creates an array that stores information about non-zero elements */
void create_tuple ( struct sparse *p, struct sparse s, int MAX1, int MAX2)
{
    int r = 0 , c = -1, l = -1, i ;
    
    /* get the total number of non-zero elements */
    p -> row = count ( s , MAX1, MAX2) + 1 ;

    /* allocate memory */
    p -> sp = ( int * ) malloc ( p -> row * 3 * sizeof ( int ) ) ;

    /* store information about
      total no. of rows, cols, and non-zero values */
    * ( p -> sp + 0 ) = MAX1 ;
    * ( p -> sp + 1 ) = MAX2 ;
    * ( p -> sp + 2 ) = p -> row - 1 ;

    l = 2 ;

    /* scan the array and store info. about non-zero values
       in the 3-tuple */
  for ( i = 0 ; i < MAX1 * MAX2 ; i++ )
    {
      c++ ;

      /* sets the row and column values */
      if ( ( ( i % MAX2 ) == 0 ) && ( i != 0 ) )
        {
            r++ ;
            c = 0 ;
        }

        /* checks for non-zero element,
           row, column and non-zero value
           is assigned to the matrix */
        if ( * ( s.sp + i ) != 0 )
        {
            l++ ;
            * ( p -> sp + l ) = r ;
            l++ ;
            * ( p -> sp + l ) = c ;
            l++ ;
            * ( p -> sp + l ) = * ( s.sp + i ) ;
        }
    }
}

/* displays the contents of the matrix */
void display_tuple ( struct sparse s )
{
    int i, j ;

    /* traverses the entire matrix */

    printf ( "\nElements in a 3-tuple: " ) ;

    j = ( * ( s.sp + 2 ) * 3 ) + 3 ;

    for ( i = 0 ; i < j ; i++ )
    {
        /* positions the cursor to the new line for every new row */
if ( i % 3 == 0 )
            printf ( "\n" ) ;
        printf ( "%d\t", * ( s.sp + i ) ) ;
    }
    printf ( "\n\n" ) ;
}

/* performs multiplication of sparse matrices */
void prodmat ( struct sparse *p, struct sparse a, struct sparse b )
{
    int sum, k, position, posi, flaga, flagb, i , j ;
    k = 1 ;

    p -> result = ( int * ) malloc ( MAXSIZE * 3 * sizeof ( int ) ) ;

    for ( i = 0 ; i < * ( a.sp + 0 * 3 + 0 ) ; i++ )
    {
        for ( j = 0 ; j < * ( b.sp + 0 * 3 + 1 ) ; j++  )
        {
            /* search if an element present at ith row */

            searchina ( a.sp, i, &position, &flaga ) ;
            if ( flaga == TRUE )
            {
                sum = 0 ;

                /* run loop till there are element at ith row
                   in first 3-tuple */
            while ( * ( a.sp + position * 3 + 0 ) == i )
                {
                    /* search if an element present at ith col.
                       in second 3-tuple */

                    searchinb ( b.sp, j, * ( a.sp + position * 3 + 1 ),
                            &posi, &flagb ) ;

                    /* if found then multiply */
                    if ( flagb == TRUE )
                        sum = sum + * ( a.sp + position * 3 + 2 ) *
                                * ( b.sp + posi * 3 + 2 ) ;
                    position = position + 1 ;
                }

                /* add result */
                if ( sum != 0 )
                {
                    * ( p -> result + k * 3 + 0 ) = i ;
                    * ( p -> result + k * 3 + 1 ) = j ;
                    * ( p -> result + k * 3 + 2 ) = sum ;
                    k = k + 1 ;
                }
            }
         }
      }

    /* add total no. of rows, cols and non-zero values */

    * ( p -> result + 0 * 3 + 0 ) = * ( a.sp + 0 * 3 + 0 ) ;
    * ( p -> result + 0 * 3 + 1 ) = * ( b.sp + 0 * 3 + 1 ) ;
    * ( p -> result + 0 * 3 + 2 ) = k - 1 ;
}

/* searches if an element present at iith row */
void searchina ( int *sp, int ii, int *p, int *flag )
{
    int j ;
    *flag = FALSE ;
    for ( j = 1 ; j <= * ( sp + 0 * 3 + 2 ) ; j++ )
    {
        if ( * ( sp + j * 3 + 0 ) == ii )
        {
            *p = j ;
            *flag = TRUE ;
            return ;
        }
     }
}

/* searches if an element where col. of first 3-tuple
   is equal to row of second 3-tuple */
void searchinb ( int *sp, int jj, int colofa, int *p, int *flag )
{
     int j ;
     *flag = FALSE ;
     for ( j = 1 ; j <= * ( sp + 0 * 3 + 2 ) ; j++ )
     {
        if ( * ( sp + j * 3 + 1 ) == jj && * ( sp + j * 3 + 0 ) == colofa )
        {
            *p = j ;
            *flag = TRUE ;
            return ;
        }
    }
}

/* displays the contents of the matrix */
void display_result ( struct sparse s )
{
    int i ;

    /* traverses the entire matrix */
for ( i = 0 ; i < ( * ( s.result + 0 + 2 ) + 1 ) * 3 ; i++ )
    {
        /* positions the cursor to the new line for every new row */
if ( i % 3 == 0 )
            printf ( "\n" ) ;
        printf ( "%d\t", * ( s.result + i ) ) ;
    }
}

/* deallocates memory */
void delsparse ( struct sparse *s )
{
    if ( s -> sp != NULL )
        free ( s -> sp ) ;
    if ( s -> result != NULL )
        free ( s -> result ) ;
}


//------------------------------------------------------------------------//

//function to print a matrix in sparse form. Doesn't return the matrix.

void rep_sparse(int m, int n, int mat[m][n]) 
//Time Complexity = O(mn)
{
    int size = 0;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(mat[i][j] != 0)
                size++;
        }
    }
    int sparse[3][size]; //sparse matrix
    int k = 0;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++ )
        {
            if(mat[i][j] != 0)
            {
                sparse[0][k] = i;
                sparse[1][k] = j;
                sparse[2][k] = mat[i][j];
                k++;
            }
        }
    }
    for(int i = 0; i < 3; i++)
    {   if(i==0)
        printf("Row   : ");
        else if(i==1)
        printf("column: ");
        else
        printf("value : ");
        for(int j = 0; j < size; j++)
        {
            printf("%d ",sparse[i][j]);
        }
        printf("\n");
    }
}


//function to form a sparse matrix from a normal matrix and return the matrix

int** create_sparse(int m, int n, int mat[m][n])
//Time Complexity = O(mn)
{
	int size = 0;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(mat[i][j] != 0)
                size++;
        }
    }
    // int sparse[3][size]; //sparse matrix
	int **sparse = (int **)malloc(3 * sizeof(int *)); 
    for (int i=0; i<3; i++) 
        sparse[i] = (int *)malloc(size * sizeof(int)); 
    int k = 0;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(mat[i][j] != 0)
            {
                sparse[0][k] = i;
                sparse[1][k] = j;
                sparse[2][k] = mat[i][j];
                k++;
            }
        }
    }
	
	for(int i = 0; i < 3; i++)
    {   
		if(i==0)
        printf("Row   : ");
        else if(i==1)
        printf("Column: ");
        else
        printf("Value : ");
        for(int j = 0; j < size; j++)
        {
            printf("%d ",sparse[i][j]);
        }
        printf("\n");
    }

	return sparse;
}


//function to return size of a sparse matrix

int size_sparse(int m, int n, int mat[m][n])
//Time Complexity = O(mn)
{
	int size = 0;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(mat[i][j] != 0)
                size++;
        }
    }
	return size;
}


//function to print a sparse matrix

void print_sparse(int size, int** sparse){
	for(int i = 0; i < 3; i++)
    {   
		if(i==0)
        printf("Row   : ");
        else if(i==1)
        printf("column: ");
        else
        printf("value : ");
        for(int j = 0; j < size; j++)
        {
            printf("%d ",sparse[i][j]);
        }
        printf("\n");
    }
}


//function to check sparse or not

void check_sparse(int r, int c, int mat[r][c])
//Time Complexity = O(rc)
{
	int Total=0;
	for(int i = 0; i < r; i++)
  	{
   		for(int j = 0; j < c; j++)
    	{
    		if(mat[i][j] == 0)
    		{
    			Total++;    		
			}
   	 	}
  	}
  	if(Total >= (r * c)/2)
  	{
  		printf("\nThe Matrix that you have entered is a Sparse Matrix!\n");
	}
	else
	{
		printf("\nThe Matrix that you have entered is Not a Sparse Matrix!\n");
	}
}


//function to add two sparse matrices

void addition(int ktemp[3][100], int ltemp[3][100], int k, int l)
//Time Complexity = O(k or l) + O(x)
{
    int i = 0, j = 0, sparse[3][100], x = 0;

    while (i < k && j < l)
    {
        if ((ktemp[0][i] == ltemp[0][j]) && (ltemp[1][j] == ktemp[1][i]))
        {
            //printf("Entered this");
            sparse[0][x] = ktemp[0][i];
            sparse[1][x] = ktemp[1][i];
            sparse[2][x] = ltemp[2][j] + ktemp[2][i];
            x++;
            i++;
            j++;
        }
        else if (ktemp[0][i] < ltemp[0][j])
        {
			sparse[0][x] = ktemp[0][i];
			sparse[1][x] = ktemp[1][i];
			sparse[2][x] = ktemp[2][i];
			x++;
			i++;
        }

		else if ((ktemp[0][i] == ltemp[0][j]) && (ktemp[1][i] < ltemp[1][j]))
		{
			sparse[0][x] = ktemp[0][i];
			sparse[1][x] = ktemp[1][i];
			sparse[2][x] = ktemp[2][i];
			x++;
			i++;
		}

        else
		{
			sparse[0][x] = ltemp[0][j];
			sparse[1][x] = ltemp[1][j];
			sparse[2][x] = ltemp[2][j];
			x++;
			j++;
		}
    }

    while (i < k)
    {
        sparse[0][x] = ktemp[0][i];
        sparse[1][x] = ktemp[1][i];
        sparse[2][x] = ktemp[2][i];
        x++;
        i++;
    }
    while (j < l)
    {
        sparse[0][x] = ltemp[0][j];
        sparse[1][x] = ltemp[1][j];
        sparse[2][x] = ltemp[2][j];
        x++;
        j++;
    }

    printf("\nAddition Matrix is \n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < x; j++)
        {
            printf("%d ", sparse[i][j]);
        }
        printf("\n");
    }
}

// Function to subtract sparse matrices
void subtraction(int ktemp[3][100], int ltemp[3][100], int k, int l)
//Time Complexity = O(k or l) + O(x)
{
    int i = 0, j = 0, sparse[3][100], x = 0;
    for(int b=0; b<100;b++){
      sparse[2][b] = 0;
    }

    while (i < k && j < l)
    {
        if ((ktemp[0][i] == ltemp[0][j]) && (ltemp[1][j] == ktemp[1][i]))
		{
			if(ktemp[2][i] - ltemp[2][j] != 0){
			sparse[0][x] = ktemp[0][i];
			sparse[1][x] = ktemp[1][i];
			sparse[2][x] = ktemp[2][i] - ltemp[2][j];
			x++;
			}                        
			i++;
			j++;
		}
		
        else if (ktemp[0][i] < ltemp[0][j])
		{
			sparse[0][x] = ktemp[0][i];
			sparse[1][x] = ktemp[1][i];
			sparse[2][x] = ktemp[2][i];
			x++;
			i++;
		}

        else if ((ktemp[0][i] == ltemp[0][j]) && (ktemp[1][i] < ltemp[1][j]))
		{
			sparse[0][x] = ktemp[0][i];
			sparse[1][x] = ktemp[1][i];
			sparse[2][x] = ktemp[2][i];
			x++;
			i++;
		}
        else
		{
			sparse[0][x] = ltemp[0][j];
			sparse[1][x] = ltemp[1][j];
			sparse[2][x] = 0-ltemp[2][j];
			x++;
			j++;
		}
    }

    while (i < k)
    {
        sparse[0][x] = ktemp[0][i];
        sparse[1][x] = ktemp[1][i];
        sparse[2][x] = ktemp[2][i];
        x++;
        i++;
    }
    while (j < l)
    {
        sparse[0][x] = ltemp[0][j];
        sparse[1][x] = ltemp[1][j];
        sparse[2][x] = 0-ltemp[2][j];
        x++;
        j++;
    }

    printf("\nSubtraction Matrix is \n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < x; j++)
        {
            printf("%d ", sparse[i][j]);
        }
        printf("\n");
    }
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int k[3][100], int count)
//Time Complexity = O(count^2)
{
    int i, j;
    for (i = 0; i < count; i++)
    {
        for (j = 0; j < count - i - 1; j++)
        {

            if (k[0][j] > k[0][j + 1])
            {

                swap(&k[0][j], &k[0][j + 1]);
                swap(&k[1][j], &k[1][j + 1]);
                swap(&k[2][j], &k[2][j + 1]);
            }
            else if (k[0][j] == k[0][j + 1])
            {
                if (k[1][j] > k[1][j + 1])
                {
                    swap(&k[0][j], &k[0][j + 1]);
                    swap(&k[1][j], &k[1][j + 1]);
                    swap(&k[2][j], &k[2][j + 1]);
                }
            }
        }
    }
}

//function to find the transpose of a sparse matrix.
void transpose(int k[3][100], int count)
//Time Complexity = O(count^2)
{
    int i, j, temp;
    printf("\n");

    for (j = 0; j < count; j++)
    {
        swap(&k[0][j], &k[1][j]);
    }
    sort(k, count);
    
    printf("Transpose of Matrix A:\n");
    
    for (j = 0; j < 3; j++)
    {
        for (i = 0; i < count; i++)
        {
            printf("%d ", k[j][i]);
        }
        printf("\n");
    }
}
  
// Function to create new node
void create_new_node(struct Node** start, int non_zero_element, int row_index, int column_index ) 
{ 
    struct Node *temp, *r; 
    temp = *start; 
    if (temp == NULL) 
    { 
        // Create new node dynamically 
        temp = (struct Node *) malloc (sizeof(struct Node)); 
        temp->value = non_zero_element; 
        temp->row_position = row_index; 
        temp->column_postion = column_index; 
        temp->next = NULL; 
        *start = temp; 
  
    } 
    else
    { 
        while (temp->next != NULL) 
            temp = temp->next; 
  
        // Create new node dynamically 
        r = (struct Node *) malloc (sizeof(struct Node)); 
        r->value = non_zero_element; 
        r->row_position = row_index; 
        r->column_postion = column_index; 
        r->next = NULL; 
        temp->next = r; 
  
    } 
}

void PrintList(struct Node* start) 
{ 
    struct Node *temp, *r, *s; 
    temp = r = s = start; 
  
    printf("row_position:   "); 
    while(temp != NULL) 
    { 
  
        printf("%d ", temp->row_position); 
        temp = temp->next; 
    } 
    printf("\n"); 
  
    printf("column_postion: "); 
    while(r != NULL) 
    { 
        printf("%d ", r->column_postion); 
        r = r->next; 
    } 
    printf("\n"); 
    printf("Value:          "); 
    while(s != NULL) 
    { 
        printf("%d ", s->value); 
        s = s->next; 
    } 
    printf("\n"); 
} 


//List of lists

// Function to create node for non - zero elements 
void create_value_node(int data, int j, struct row_list **z)
{ 
    struct value_list *temp, *d; 
  
    // Create new node dynamically 
    temp = (struct value_list*)malloc(sizeof(struct value_list)); 
    temp->column_index = j+1; 
    temp->value = data; 
    temp->next = NULL; 
  
    // Connect with row list 
    if ((*z)->link_right==NULL) 
        (*z)->link_right = temp; 
    else
    { 
        // d points to data list node 
        d = (*z)->link_right; 
        while(d->next != NULL) 
            d = d->next; 
        d->next = temp; 
    } 
} 
  
// Function to create row list 
void create_row_list(struct row_list **start, int row, int column, int Sparse_Matrix[row][column]) 
{ 
    // For every row, node is created 
    for (int i = 0; i < row; i++) 
    { 
        struct row_list *z, *r; 
  
        // Create new node dynamically 
        z = (struct row_list*)malloc(sizeof(struct row_list)); 
        z->row_number = i+1; 
        z->link_down = NULL; 
        z->link_right = NULL; 
        if (i==0) 
            *start = z; 
        else
        { 
            r = *start; 
            while (r->link_down != NULL) 
                r = r->link_down; 
            r->link_down = z; 
        } 
  
        // Firstiy node for row is created, 
        // and then travering is done in that row 
        for (int j = 0; j < column; j++) 
        { 
            if (Sparse_Matrix[i][j] != 0) 
            { 
                create_value_node(Sparse_Matrix[i][j], j, &z); 
            } 
        } 
    } 
} 
  
//Function display data of LIL 
void print_LIL(struct row_list *start) 
{ 
    struct row_list *r; 
    struct value_list *z; 
    r = start; 
  
    // Traversing row list 
    while (r != NULL) 
    { 
        if (r->link_right != NULL) 
        { 
            printf("row=%d \n", r->row_number-1); 
            z = r->link_right; 
  
            // Traversing data list 
            while (z != NULL) 
            { 
                printf("column=%d value=%d \n", z->column_index-1, z->value); 
                z = z->next; 
            } 
        } 
        r = r->link_down; 
		printf("\n");
    } 
} 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#include "sparse.h"

void menu()
{
	printf("\n*_*_*_*_*_*_*_*_*_*_*_*_*_*_MENU_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n\n");
	printf("The following Operations can be operated by using predefined \nfunctions in the library 'sparse.h'.\n\n");
	printf(" 1.Print a matrix in sparse form.\n 2.Check if a matrix is sparse or not.\n 3.Forming a sparse matrix from a normal matrix.\n 4.Find the size of a sparse matrix. \n 5.Addition of two sparse matrices.\n 6.Transpose of a sparse matrix.\n 7.Multiplication of two sparse matrices \n 8.Representaion of a sparse matrix using linked list.\n 9.Representation of a sparse matrix using list of lists.\n 10.Subtraction of two sparse matrices.\n 11.Display the Function Menu.\n 12.Exit");
	printf("\n\n*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n");
}

int main()
{

	int option, m, i, j, n;
	struct sparse s[5];

	menu();

	do
	{
		printf("\n\n--> Enter choice:");
		scanf("%d", &option);
		printf("\n");
		switch (option)
		{
		case 1:
		{
			printf("Enter the size of the matrix A:\n");
			scanf("%d %d", &m, &n);
			int mat[m][n];
			printf("\nEnter the values of the matrix:\n");
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
					scanf("%d", &mat[i][j]);
			}
			printf("\n");
			rep_sparse(m, n, mat);
			printf("\n____________________________________________________\n");
			break;
		}

		case 2:
		{
			printf("Enter the size of the matrix A:\n");
			scanf("%d %d", &m, &n);
			int mat[m][n];
			printf("\nEnter the values of the matrix:\n");
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
					scanf("%d", &mat[i][j]);
			}
			check_sparse(m, n, mat);
			printf("\n____________________________________________________\n");
			break;
		}

		case 3:
		{
			printf("Enter the size of the matrix A:\n");
			scanf("%d %d", &m, &n);
			int mat[m][n];
			printf("\nEnter the values of the matrix:\n");
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
					scanf("%d", &mat[i][j]);
			}
			printf("\n");
			int **s = create_sparse(m, n, mat);

			printf("\n____________________________________________________\n");
			break;
		}

		case 4:
		{
			printf("Enter the size of the matrix A:\n");
			scanf("%d %d", &m, &n);
			int mat[m][n];
			printf("\nEnter the values of the matrix:\n");
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
					scanf("%d", &mat[i][j]);
			}
			int size = size_sparse(m, n, mat);
			printf("\nThe size of the sparse matrix: 3X%d\n", size);
			printf("\n____________________________________________________\n");
			break;
		}
		case 5:
		{
			int m, n, q, p, i, l = 0, j, k = 0;
			printf("Sparse Matrix Representation:\nRows\nColumns\nValue\n\n");
			printf("\nEnter the size of the matrix A:\n");
			scanf("%d %d", &n, &m);

			int a[n][m], ktemp[3][100];

			printf("\nEnter the elements of the matrix A:\n\n");

			for (i = 0; i < n; ++i)
			{
				for (j = 0; j < m; ++j)
				{
					printf("Enter %d%d element: ", i, j);
					scanf("%d", &a[i][j]);
					if (a[i][j] != 0)
					{
						ktemp[0][k] = i;
						ktemp[1][k] = j;
						ktemp[2][k] = a[i][j];
						k++;
					}
				}
			}

			printf("\nEnter the size of the matrix B:\n");
			scanf("%d %d", &p, &q);

			int b[p][q], ltemp[3][100];

			if (p != n || q != m)
			{
				printf("\nAddtition can be performed on matrix of same order");
			}
			else
			{
				printf("\nEnter the elements of the matrix B:\n\n");
				for (i = 0; i < n; ++i)
				{
					for (j = 0; j < m; ++j)
					{
						printf("Enter %d%d element: ", i, j);
						scanf("%d", &b[i][j]);
						if (b[i][j] != 0)
						{
							ltemp[0][l] = i;
							ltemp[1][l] = j;
							ltemp[2][l] = b[i][j];
							l++;
						}
					}
				}
			}

			addition(ktemp, ltemp, k, l);
			printf("\n_____________________________________________________\n");
			break;
		}

		case 6:
		{
			int m, n, q, p, i, l = 0, j, count = 0;

			printf("Sparse Matrix Representation:\nRows\nColumns\nValue\n\n");

			printf("\nEnter the size of the matrix A:\n");
			scanf("%d %d", &n, &m);

			int a[n][m], k[3][100];

			printf("\nEnter the elements of the matrix A:\n\n");

			for (i = 0; i < n; ++i)
			{
				for (j = 0; j < m; ++j)
				{
					printf("Enter %d%d element: ", i, j);
					scanf("%d", &a[i][j]);
					if (a[i][j] != 0)
					{
						k[0][count] = i;
						k[1][count] = j;
						k[2][count] = a[i][j];
						count++;
					}
				}
			}

			printf("\nSparse matrix is: \n");
			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < count; j++)
				{
					printf("%d ", k[i][j]);
				}
				printf("\n");
			}

			transpose(k, count);
			printf("\n____________________________________________________\n");
			break;
		}

		case 7:
		{
			int MAX1, MAX2;

			printf("\nSparse Matrix Representation:\n\nTotal Rows\t|\tTotal Columns\t|\tTotal non-Zero Elements\n\nFollowed by the Matrix in Same Manner!\n\n");

			printf("\nFor Matrix A:\n\n");
			printf("\nEnter No of Rows And Columns of the Matrix A:");
			scanf("%d %d", &MAX1, &MAX2);

			for (i = 0; i <= 3; i++)
				initsparse(&s[i]);

			create_array(&s[0], MAX1, MAX2);

			create_tuple(&s[1], s[0], MAX1, MAX2);
			display_tuple(s[1]);

			int MAX3, MAX4;
			printf("\nFor Matrix B:\n\n");
			printf("\nEnter No of Rows And Columns of the Matrix:");
			scanf("%d %d", &MAX3, &MAX4);
			create_array(&s[2], MAX3, MAX4);

			create_tuple(&s[3], s[2], MAX3, MAX4);
			display_tuple(s[3]);
			if (MAX2 == MAX3)
			{
				prodmat(&s[4], s[1], s[3]);

				printf("\nResult of multiplication of two matrices: ");
				display_result(s[4]);

				for (i = 0; i <= 3; i++)
					delsparse(&s[i]);
			}
			else
				printf("\nINVALID!!!Multiplication not possible!!\n");

			printf("\n___________________________________________________\n");

			break;
		}

		case 8:
		{
			printf("Enter the size of the matrix A:\n");
			scanf("%d %d", &n, &m);
			int mat[m][n];
			printf("\nEnter the values of the matrix:\n");
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
					scanf("%d", &mat[i][j]);
			}

			struct Node *start = NULL;
			for (int i = 0; i < m; i++)
				for (int j = 0; j < n; j++)
					// Pass only those values which are non - zero
					if (mat[i][j] != 0)
						create_new_node(&start, mat[i][j], i, j);

			printf("\nThe required sparse matrix:\n\n");
			PrintList(start);
			printf("\n____________________________________________________\n");
			break;
		}
		case 9:
		{
			printf("Enter the size of the matrix A:\n");
			scanf("%d %d", &n, &m);
			int mat[m][n];
			printf("\nEnter the values of the matrix:\n");
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
					scanf("%d", &mat[i][j]);
			}

			// Start with the empty List of lists
			struct row_list *start = NULL;

			//Function creating List of Lists
			create_row_list(&start, m, n, mat);

			// Display data of List of lists

			printf("\nThe required sparse matrix:\n\n");
			print_LIL(start);
			printf("\n____________________________________________________\n");
			break;
		}

		case 10:
		{
			int m, n, q, p, i, l = 0, j, k = 0;
			printf("\nEnter the size of the matrix A:\n");
			scanf("%d %d", &n, &m);

			int a[n][m], ktemp[3][100];

			printf("\nEnter the elements of the matrix A:\n");

			for (i = 0; i < n; ++i)
			{
				for (j = 0; j < m; ++j)
				{
					printf("Enter %d%d element: ", i, j);
					scanf("%d", &a[i][j]);
					if (a[i][j] != 0)
					{
						ktemp[0][k] = i;
						ktemp[1][k] = j;
						ktemp[2][k] = a[i][j];
						k++;
					}
				}
			}

			printf("\nEnter the size of the matrix B:\n");
			scanf("%d %d", &p, &q);

			int b[p][q], ltemp[3][100];

			if (p != n || q != m)
			{
				printf("\nSubtraction can be performed on matrix of same order!\n");
			}
			else
			{
				printf("\nEnter the elements of the matrix B:\n");
				for (i = 0; i < n; ++i)
				{
					for (j = 0; j < m; ++j)
					{
						printf("Enter %d%d element: ", i, j);
						scanf("%d", &b[i][j]);
						if (b[i][j] != 0)
						{
							ltemp[0][l] = i;
							ltemp[1][l] = j;
							ltemp[2][l] = b[i][j];
							l++;
						}
					}
				}
			}
			printf("\n");
			subtraction(ktemp, ltemp, k, l);
			printf("\n____________________________________________________\n");
			break;
		}

		case 11:
		{
			menu();
			break;
		}

		case 12:
		{
			printf("Terminating the Program.............\n");
			printf("=============================================================\n");
			exit(0);
		}
		default:
			printf("Invalid Option, Please Enter Again!");
		}
	} while (option != 12);

	return 0;
}
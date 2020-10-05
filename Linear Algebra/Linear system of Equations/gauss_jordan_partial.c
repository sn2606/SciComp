# include <stdio.h>
# include <stdlib.h>
# include "utility.h"
# define VARNUM 26

float **arr;
int varcount;
char varname[VARNUM];

void for_equation();
void input_values();
void print_equations();
void exchange_row(int r);
void pivot(int r);
void gauss_jordan_elimination();
void print_answer();

int main()
{
	for_equation();
	input_values();
	print_equations();
	gauss_jordan_elimination();
	print_answer();

	return 0;
}

// To name the variables
void for_equation()
{
	int i;

	for(i = 0;i < VARNUM; i++)
		varname[i] = (char)(97 + i);
}

// A function to take input of the matrix
void input_values()
{
	int i, j;

	printf("Enter number of variables: ");
	scanf("%d", &varcount);

	// arr = (float **)malloc(varcount * sizeof(float *));
	// for(i = 0; i < varcount; i++)
	// 	*(arr + i) = (float *)malloc((varcount + 1) * sizeof(float));

	arr = fmatrix(varcount, varcount + 1);

	for(i = 0; i < varcount; i++)
	{
		printf("\nEnter variable coefficients for equation %d: ", (i + 1));

		for(j = 0; j <= varcount; j++)
		{
			if(j == varcount)
			{
				printf("\nEnter result value of equation %d: ", (i + 1));
			}
			scanf("%f",&arr[i][j]);
		}
	}
}

// Function to print the equations
void print_equations()
{
	int i, j;

	printf("\n");

	for(i = 0; i < varcount; i++)
	{
		for(j = 0; j <= varcount; j++)
		{
			if(j == varcount - 1)
			{
				printf("%0.3f%c = ", arr[i][j], varname[j]);
			}
			else if(j == varcount)
			{
				printf("%0.3f ", arr[i][j]);
			}
			else
			{
				printf("%0.3f%c + ", arr[i][j], varname[j]);
			}
		}
		printf("\n");
	}
}

// Function to exchange rows
void exchange_row(int r)
{
	int flag = 0, i, j;
	float temp;
	// char chtemp;

	for(i = r; i < varcount; i++)
	{
		if(arr[i][r] != 0)
		{
			for(j = 0; j <= varcount; j++)
			{
				temp       = arr[i][j];
				arr[i][j]  = arr[r][j];
				arr[r][j]  = temp;

				// chtemp     = varname[i];
				// varname[i] = varname[r];
				// varname[r] = chtemp;
			}

			flag = 1;
		}
	}
	if(flag == 0)
	{
		printf("\nSystem of Equations is not solvable!.");
		exit(0);
	}
}

// Function to pivot
void pivot(int r)
{
	float max = arr[0][r], temp;
	// char chtemp;
	int pos = 0, i, j;

	for(i = 0; i < varcount; i++)
	{
		if(max > arr[i][r])
		{
			max = arr[i][r];
			pos = i;
		}
	}
	if(pos != r)
	{
		// // Exchanging rows
		// temp        = arr[pos][r];
		// arr[pos][r] = arr[r][r];
		// arr[r][r]   = temp;

		// // And variables
		// chtemp      = varname[pos];
		// varname[pos]= varname[r];
		// varname[r]  = chtemp;

		for(j = 0; j <= varcount; j++)
		{
			// Exchanging rows
			temp         = arr[pos][j];
			arr[pos][j]  = arr[r][j];
			arr[r][j]    = temp;

				// chtemp     = varname[i];
				// varname[i] = varname[r];
				// varname[r] = chtemp;
		}
	}
}

// Function to perform Gauss Jordan Elimination
void gauss_jordan_elimination()
{
	int r, row, col;
	float k, m;

	for(r = 0; r < varcount; r++)
	{
		// k holds the diagonal elements
		k = arr[r][r];
		
		// If the diagonal is zero, exchange the row with another row
		// that has non zero value in the column
		if(k == 0.0)
		{
			exchange_row(r);
			pivot(r);
		}		

		// Making diagonal element 1
		// Dividing entire row by diagonal element
		for(col = 0; col <= varcount; col++)
		{
			arr[r][col] = arr[r][col]/k;
		}

		for(row = 0; row < varcount; row++)
		{
			if(row != r)
			{
				m = arr[row][r];
				for(col = 1; col <= varcount; col++)
				{
					arr[row][col] = arr[row][col] - m*arr[r][col];
				}
			}
		}
	}
}

// Function to print the final answer
void print_answer()
{
	int i;

	printf("\nAnswer: ");
	for(i = 0; i < varcount; i++)
	{
		printf("\n%c = %0.3f\n", varname[i], arr[i][varcount]);
	}

	free_fmatrix(arr, varcount, varcount + 1);
}
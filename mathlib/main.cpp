#include <iostream>
#include "matrix.h"
int main()
{
	matrix mat;
	init_matrix(mat,4,4);
	float r0[] = {1,1,1,1};
	input_matrix_row(mat, 0, r0, sizeof(r0) / sizeof(float));
	print_matrix(mat);
	getchar();
	release_matrix(mat);
	return 0;
}
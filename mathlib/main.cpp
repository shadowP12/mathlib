#include <iostream>
#include "matrix.h"
#include "determinant.h"
int main()
{
	BaseData data;
	init_base_data(data, 4, 4);
	float r0[] = { 1,6,1,1 };
	float r1[] = { 3,1,0,0 };
	float r2[] = { 0,0,2,0 };
	float r3[] = { 9,0,0,3 };
	input_base_data_row(data, 0, r0, sizeof(r0) / sizeof(float));
	input_base_data_row(data, 1, r1, sizeof(r1) / sizeof(float));
	input_base_data_row(data, 2, r2, sizeof(r2) / sizeof(float));
	input_base_data_row(data, 3, r3, sizeof(r3) / sizeof(float));
	print_base_data(data);
	BaseData data_1 = cofactor(data,1,2);
	BaseData data_2 = cofactor(data_1,1,1);
	printf("\n");
	print_base_data(data_1);
	float det_1 = determinant(data_1);
	printf("\n");
	printf("%f\n",det_1);
	release_base_data(data);
	release_base_data(data_1);
	release_base_data(data_2);
	getchar();
	
	return 0;
}
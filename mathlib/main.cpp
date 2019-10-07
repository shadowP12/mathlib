#include <iostream>
#include "matrix.h"
#include "determinant.h"
int main()
{
	BaseData data;
	init_base_data(data, 4, 4);
	float r0[] = { 1,6,1,1 };
	float r1[] = { 3,1,7,1 };
	float r2[] = { 0,6,0,4 };
	float r3[] = { 9,1,3,1 };
	input_base_data_row(data, 0, r0, sizeof(r0) / sizeof(float));
	input_base_data_row(data, 1, r1, sizeof(r1) / sizeof(float));
	input_base_data_row(data, 2, r2, sizeof(r2) / sizeof(float));
	input_base_data_row(data, 3, r3, sizeof(r3) / sizeof(float));
	print_base_data(data);
	BaseData data_1 = cofactor(data,1,2);
	printf("\n");
	print_base_data(data_1);
	release_base_data(data);
	release_base_data(data_1);
	getchar();
	
	return 0;
}
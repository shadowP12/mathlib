#include <iostream>
#include "matrix.h"
int main()
{
	BaseData data;
	init_base_data(data,4,4);
	float r0[] = {1,1,1,1};
	input_base_data_row(data, 0, r0, sizeof(r0) / sizeof(float));
	print_base_data(data);
	getchar();
	release_base_data(data);
	return 0;
}
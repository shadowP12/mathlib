#include <iostream>
#include "Vector2.h"
#include "Vector3.h"
#include "Geometry.h"

int main()
{
	BBox box;
	box.min = Vector3(0,0,0);
	box.max = Vector3(1,1,1);
	Ray ray;
	ray.orig = Vector3(0,0,0);
	ray.dir = Vector3(1,0,0);
	if (intersect(ray, box))
	{
		printf("hit\n");
	}
	getchar();
	return 0;
}
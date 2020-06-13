#include <iostream>
#include "Vector2.h"
#include "Vector3.h"
#include "Common.h"
#include "Geometry.h"

int main()
{
    Vector3 p = projectPointToVector(Vector3(1,1,1), Vector3(4,0,0));
    printf("%f  %f  %f\n", p.x, p.y, p.z);
	return 0;
}
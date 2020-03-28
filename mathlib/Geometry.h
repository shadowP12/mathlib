#pragma once
#include "Vector3.h"

struct Ray
{
	Vector3 orig;
	Vector3 dir;
};

struct BBox
{
	Vector3 min;
	Vector3 max;
};

struct Plane
{
    Vector3 center;
    Vector3 normal;
};

inline bool intersect(const Ray& ray, const BBox& bbox)
{
	// 映射到2D平面上
	float txmin = (bbox.min.x - ray.orig.x) / ray.dir.x;
	float txmax = (bbox.max.x - ray.orig.x) / ray.dir.x;
	if (txmin > txmax) swap(txmin, txmax);

	float tymin = (bbox.min.y - ray.orig.y) / ray.dir.y;
	float tymax = (bbox.max.y - ray.orig.y) / ray.dir.y;
	if (tymin > tymax) swap(tymin, tymax);

	if ((txmin > tymax) || (tymin > txmax))
		return false;

	float tzmin = (bbox.min.z - ray.orig.z) / ray.dir.z;
	float tzmax = (bbox.max.z - ray.orig.z) / ray.dir.z;
	if (tzmin > tzmax) swap(tzmin, tzmax);

	if ((txmin > tzmax) || (tzmin > txmax))
		return false;

	return true;
}

float intersect(const Ray& ray, const Plane& plane)
{
    float denom = Vector3::dot(plane.normal, ray.dir);
    if (std::abs(denom) > 1e-6)
    {
        Vector3 difference = plane.center - ray.orig;
        float t = Vector3::dot(plane.normal, difference) / denom;
        if (t >= 0)
            return t;
        return -1;
    }
    return -1;
}

// 获取一个点投射到一条线段上的投影点
Vector3 pointOnSegment(const Vector3& p, const Vector3& a, const Vector3& b)
{
    Vector3 d0 = p - a;
    Vector3 d1 = b - a;
    float l = d1.length();
    d1.normalize();
    float t = d1.dot(d0);
    if (t < 0.0f)
        return a;

    if (t > l)
        return b;

    return a + d1 * t;
}
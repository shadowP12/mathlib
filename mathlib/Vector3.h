#pragma once
#include "MathPrerequisites.h"
#include <assert.h>
class Vector3
{
public:
	Vector3()
		:x(0.0),y(0.0),z(0.0)
	{}
	Vector3(float x, float y, float z)
		:x(x), y(y), z(z)
	{}
	Vector3& operator= (float rhs)
	{
		x = rhs;
		y = rhs;
		z = rhs;

		return *this;
	}

    Vector3& operator= (const Vector3& rhs)
    {
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;

        return *this;
    }

	bool operator== (const Vector3& rhs) const
	{
		return (x == rhs.x && y == rhs.y && z == rhs.z);
	}

	bool operator!= (const Vector3& rhs) const
	{
		return (x != rhs.x || y != rhs.y || z != rhs.z);
	}

	Vector3 operator+ (const Vector3& rhs) const
	{
		return Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
	}

	Vector3 operator- (const Vector3& rhs) const
	{
		return Vector3(x - rhs.x, y - rhs.y, z - rhs.z);
	}

	Vector3 operator* (float rhs) const
	{
		return Vector3(x * rhs, y * rhs, z * rhs);
	}

	Vector3 operator/ (float val) const
	{
		assert(val != 0.0);

		float inv = 1.0f / val;
		return Vector3(x * inv, y * inv, z * inv);
	}

	Vector3 operator- () const
	{
		return Vector3(-x, -y, -z);
	}
	float length() const
	{
		return sqrt(x * x + y * y + z * z);
	}

	float squaredLength() const
	{
		return x * x + y * y + z * z;
	}

	float distance(const Vector3& rhs) const
	{
		return (*this - rhs).length();
	}

	float squaredDistance(const Vector3& rhs) const
	{
		return (*this - rhs).squaredLength();
	}

	float dot(const Vector3& vec) const
	{
		return x * vec.x + y * vec.y + z * vec.z;
	}

	static float dot(const Vector3& vec0, const Vector3& vec1)
    {
        return vec0.x * vec1.x + vec0.y * vec1.y + vec0.z * vec1.z;
    }

	Vector3 cross(const Vector3& other) const
	{
		return Vector3(
			y * other.z - z * other.y,
			z * other.x - x * other.z,
			x * other.y - y * other.x);
	}

    static Vector3 cross(const Vector3& vec0, const Vector3& vec1)
    {
        return Vector3(
                vec0.y * vec1.z - vec0.z * vec1.y,
                vec0.z * vec1.x - vec0.x * vec1.z,
                vec0.x * vec1.y - vec0.y * vec1.x);
    }

	void normalize(float tolerance = 1e-04f)
	{
		float len = length();
		if (len > (tolerance * tolerance))
		{
			x = x * 1.0f / len;
			y = y * 1.0f / len;
			z = z * 1.0f / len;
		}
	}

    static Vector3 normalize(const Vector3& vec, float tolerance = 1e-04f)
    {
        float len = vec.length();
        if (len > (tolerance * tolerance))
        {
            return Vector3(
                    vec.x * 1.0f / len,
                    vec.y * 1.0f / len,
                    vec.z * 1.0f / len);
        }
        return Vector3(vec.x, vec.y, vec.z);
    }

public:
	float x, y, z;
};
#pragma once

struct Vector3
{
	float x, y, z;

	Vector3(float x = 0, float y = 0, float z = 0) { Vector3::x = x; Vector3::y = y; Vector3::z = z; }

	Vector3 operator+ (Vector3 const& obj)
	{
		x = x + obj.x;
		y = y + obj.y;
		z = z + obj.z;
		return Vector3(x, y, z);
	}
	Vector3 operator- (Vector3 const& obj)
	{
		x = x - obj.x;
		y = y - obj.y;
		z = z - obj.z;
		return Vector3(x, y, z);
	}
	Vector3 operator* (Vector3 const& obj)
	{
		x = x * obj.x;
		y = y * obj.y;
		z = z * obj.z;
		return Vector3(x, y, z);
	}
	Vector3 operator/ (Vector3 const& obj)
	{
		x = x / obj.x;
		y = y / obj.y;
		z = z / obj.z;
		return Vector3(x, y, z);
	}
};
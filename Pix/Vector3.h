#pragma once

struct Vector3
{
	float x = 0;
	float y = 0;
	float z = 0;

	Vector3 operator+ (Vector3 const& obj)
	{
		x = x + obj.x;
		y = y + obj.y;
		z = z + obj.z;
	}

	Vector3 operator- (Vector3 const& obj)
	{
		x = x - obj.x;
		y = y - obj.y;
		z = z - obj.z;
	}

	Vector3 operator* (Vector3 const& obj)
	{
		x = x * obj.x;
		y = y * obj.y;
		z = z * obj.z;
	}

	Vector3 operator/ (Vector3 const& obj)
	{
		x = x / obj.x;
		y = y / obj.y;
		z = z / obj.z;
	}
};
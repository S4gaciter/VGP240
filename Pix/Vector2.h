#pragma once

struct Vector2
{
	float x, y;

	Vector2(float x = 0, float y = 0) { Vector2::x = x; Vector2::y = y; }

	Vector2 operator+ (Vector2 const& obj)
	{
		x = x + obj.x;
		y = y + obj.y;
		return Vector2(x, y);
	}
	Vector2 operator- (Vector2 const& obj)
	{
		x = x - obj.x;
		y = y - obj.y;
		return Vector2(x, y);
	}	
	Vector2 operator* (Vector2 const& obj)
	{
		x = x * obj.x;
		y = y * obj.y;
		return Vector2(x, y);
	}
	Vector2 operator/ (Vector2 const& obj)
	{
		x = x / obj.x;
		y = y / obj.y;
		return Vector2(x, y);
	}
};
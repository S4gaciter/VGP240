#pragma once

struct Vector2
{
	float x;
	float y;

	Vector2 operator+ (Vector2 const& obj)
	{
		x = x + obj.x;
		y = y + obj.y;
	}

	Vector2 operator- (Vector2 const& obj)
	{
		x = x - obj.x;
		y = y - obj.y;
	}
	
	Vector2 operator* (Vector2 const& obj)
	{
		x = x * obj.x;
		y = y * obj.y;
	}

	Vector2 operator/ (Vector2 const& obj)
	{
		x = x / obj.x;
		y = y / obj.y;
	}
};
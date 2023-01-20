#pragma once

#include <XEngine.h>
#include "Vertex.h"

enum class FillMode
{
	Solid,
	Wireframe
};

class Rasterizer
{
public:
	static Rasterizer* Get();

public:
	void SetColor(X::Color color);
	void SetFillMode(FillMode mode);

	void DrawPoint(int x, int y);
	
	void DrawPoint(Vertex v);
	void DrawLine(Vertex a, Vertex b);
	void DrawTriangle(Vertex v1, Vertex v2, Vertex v3);
private:
	X::Color mColor = X::Colors::White;
	FillMode mFillMode = FillMode::Solid;
};
#pragma once

#include "Vertex.h"

enum class Topology
{
	Point,
	Line,
	Triangle
};

class PrimitiveManager
{
public:
	bool BeginDraw(Topology topology);
	void AddVertex(Vertex vertex);
	bool EndDraw();

	static PrimitiveManager *Get();
private:
	std::vector<Vertex> mVertexBuffer;
	Topology mTopology = Topology::Triangle;
	bool mDrawBegin = false;
};


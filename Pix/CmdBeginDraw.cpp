#include "CmdBeginDraw.h"
#include "PrimitiveManager.h"

bool CmdBeginDraw::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}

	Topology topology = Topology::Point;
	if (params[0] == "point") { topology = Topology::Point; }
	else if (params[0] == "line") { topology = Topology::Line; }
	else if (params[0] == "triangle") { topology = Topology::Triangle; }
	else { return false; }
	bool applyTransform = (params.size() > 2 && params[1] == "true");
	return PrimitiveManager::Get()->BeginDraw(topology);
}

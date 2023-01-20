#pragma once
#include "Command.h"
class CmdVertex : public Command
{
public:
	const char* GetName()
	{
		return "Vertex";
	}
	const char* GetDescription()
	{
		return "Vertex(x, y)"
				"Vertex(x, y, z)"
				"Vertex(x, y, r, g, b)"
				"Vertex(x, y, z, r, g, b)";
	}

	bool Execute(const std::vector<std::string>& params);
};




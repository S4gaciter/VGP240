#pragma once
#include "Command.h"
class CmdBeginDraw : public Command
{
public:
	const char* GetName()
	{
		return "BeginDraw";
	}
	const char* GetDescription()
	{
		return "BeginDraw(topology, applyTransform)\n"
			   "\n"
			   "- Takes vertex inputs for EndDraw().";
	}

	bool Execute(const std::vector<std::string>& params);
};


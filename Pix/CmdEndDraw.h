#pragma once
#include "Command.h"
class CmdEndDraw : public Command
{
public:
	const char* GetName()
	{
		return "EndDraw";
	}
	const char* GetDescription()
	{
		return "EndDraw() rasterizes vertex inputs.";
	}

	bool Execute(const std::vector<std::string>& params);
};


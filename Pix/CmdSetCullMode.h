#pragma once
#include "Command.h"
class CmdSetCullMode : public Command
{
public:
	const char* GetName()
	{
		return "SetCullMode";
	}
	const char* GetDescription()
	{
		return "SetCullMode(cullMode)\n"
			"\n"
			"- Sets how objects are culled.";
	}

	bool Execute(const std::vector<std::string>& params);
};


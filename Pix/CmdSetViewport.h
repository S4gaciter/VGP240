#pragma once
#include "Command.h"
class CmdSetViewport : public Command
{
public:
	const char* GetName() { return "SetViewport"; };
	const char* GetDescription() { return "SetViewport(x, y, width, height)\n- Sets the viewing area."; };

	bool Execute(const std::vector<std::string>& params);
};


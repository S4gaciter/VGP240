#pragma once
#include "Command.h"
class CmdSetClipping : public Command
{
public:
	const char* GetName() { return "SetClipping"; };
	const char* GetDescription() { return "SetClipping(bool)\n- Enable/Disable clipping."; };

	bool Execute(const std::vector<std::string>& params);
};


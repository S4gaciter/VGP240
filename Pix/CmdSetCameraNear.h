#pragma once

#include "Command.h"

class CmdSetCameraNear : public Command
{
public:
	const char* GetName() override
	{
		return "SetCameraNear";
	}

	const char* GetDescription() override
	{
		return
			"SetCameraNear(float)\n"
			"\n"
			"- Changes how close objects can be while still being rendered.";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

#pragma once

#include "Command.h"

class CmdSetCameraFar : public Command
{
public:
	const char* GetName() override
	{
		return "SetCameraFar";
	}

	const char* GetDescription() override
	{
		return
			"SetCameraFar(float)\n"
			"\n"
			"- Changes how far objects can be while still being rendered.";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

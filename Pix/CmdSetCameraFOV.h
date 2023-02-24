#pragma once

#include "Command.h"

class CmdSetCameraFOV : public Command
{
public:
	const char* GetName() override
	{
		return "SetCameraFOV";
	}

	const char* GetDescription() override
	{
		return
			"SetCameraFOV(float)\n"
			"\n"
			"- Changes the camera's field of view.";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

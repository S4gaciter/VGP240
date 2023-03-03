#pragma once

#include "Command.h"

class CmdPushRotationX : public Command
{
public:
	const char* GetName() override
	{
		return "PushRotationX";
	}

	const char* GetDescription() override
	{
		return
			"PushRotationX(radians)\n"
			"\n"
			"- Pushes an X Rotation matrix into the matrix stack.";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

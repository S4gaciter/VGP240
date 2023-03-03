#include "CmdPushRotationY.h"
#include "VariableCache.h"
#include "MatrixStack.h"

bool CmdPushRotationY::Execute(const std::vector<std::string>& params)
{
	// Need at least 1 param for radians
	if (params.size() < 1)
		return false;

	auto vc = VariableCache::Get();
	float rad = vc->GetFloat(params[0]);

	MatrixStack::Get()->PushRotationY(rad);
	return true;
}
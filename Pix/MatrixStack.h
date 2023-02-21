#pragma once
#include "Vector3.h"
#include "Matrix4.h"

class MatrixStack
{
public:
	static MatrixStack* Get();

public:
	void OnNewFrame();

	void PushTranslation(const Vector3& d);
	void PushRotationX(float rad);
	void PushRotationY(float rad);
	void PushRotationZ(float rad);
	void PushScaling(Vector3 s);
	void PopMatrix();

	Matrix4 GetTransform() const { return mCombinedTransform; }
	
private:
	std::vector<Matrix4> mMatrices; // History
	Matrix4 mCombinedTransform;
};


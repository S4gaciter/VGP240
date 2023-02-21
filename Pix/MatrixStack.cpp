#include "MatrixStack.h"
#include "MathHelper.h"

MatrixStack* MatrixStack::Get()
{
    static MatrixStack sInstance;
    return &sInstance;
}

void MatrixStack::OnNewFrame()
{
    mCombinedTransform = Matrix4::Identity();
    mMatrices.clear();
}

void MatrixStack::PushTranslation(const Vector3& d)
{
    Matrix4 translationMatrix = Matrix4::Translation(d);
    mMatrices.push_back(translationMatrix);
    mCombinedTransform = translationMatrix * mCombinedTransform;
}

void MatrixStack::PushRotationX(float rad)
{
    Matrix4 rotXMatrix = Matrix4::RotationX(rad);
    mMatrices.push_back(rotXMatrix);
    mCombinedTransform = rotXMatrix * mCombinedTransform;
}

void MatrixStack::PushRotationY(float rad)
{
    Matrix4 rotYMatrix = Matrix4::RotationY(rad);
    mMatrices.push_back(rotYMatrix);
    mCombinedTransform = rotYMatrix * mCombinedTransform;
}

void MatrixStack::PushRotationZ(float rad)
{
    Matrix4 rotZMatrix = Matrix4::RotationZ(rad);
    mMatrices.push_back(rotZMatrix);
    mCombinedTransform = rotZMatrix * mCombinedTransform;
}

void MatrixStack::PushScaling(Vector3 s)
{
    Matrix4 scaleMatrix = Matrix4::Scaling(s);
    mMatrices.push_back(scaleMatrix);
    mCombinedTransform = scaleMatrix * mCombinedTransform;
}

void MatrixStack::PopMatrix()
{
    if (!mMatrices.empty())
    {
        Matrix4 matrix = mMatrices.back();
        mMatrices.pop_back();
        mCombinedTransform = MathHelper::Inverse(matrix) * mCombinedTransform;
    }
}

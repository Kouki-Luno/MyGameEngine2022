#include "Transform.h"


Transform::Transform() :
	matTranslate_(XMMatrixIdentity()),
	matRotate_(XMMatrixIdentity()),
	matScale_(XMMatrixIdentity()),
	position_(XMFLOAT3(0, 0, 0)),
	rotate_(XMFLOAT3(0, 0, 0)),
	scale_(XMFLOAT3(0.5, 0.5, 0.5))
{
}

Transform::~Transform()
{
}

void Transform::Calclation()
{
	//ˆÚ“®s—ñì¬
	matTranslate_ = XMMatrixTranslation(position_.x, position_.y, position_.z);


	//‰ñ“]s—ñì¬
	XMMATRIX rotateX, rotateY, rotateZ;
	rotateX = XMMatrixRotationX(XMConvertToRadians(rotate_.x));//X²‰ñ“]s—ñ
	rotateY = XMMatrixRotationY(XMConvertToRadians(rotate_.y));//Y²‰ñ“]s—ñ
	rotateZ = XMMatrixRotationZ(XMConvertToRadians(rotate_.z));//Z²‰ñ“]s—ñ
	matRotate_ = rotateZ * rotateX * rotateY;				   //‡‘Ì	
	
	//Šg‘ås—ñì¬
	matScale_ = XMMatrixScaling(scale_.x, scale_.y, scale_.z);
}

XMMATRIX Transform::GetWorldMatrix()
{
	//return XMMATRIX(); // <- ˆÚ“®A‰ñ“]AŠg‘å‚Ì‡¬
	return matScale_ * matRotate_ * matTranslate_;
}

XMMATRIX Transform::GetNormalMatrix()
{
	return matRotate_ * XMMatrixInverse(nullptr, matScale_);
}

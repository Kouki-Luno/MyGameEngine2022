#include "SphereCollider.h"
#include "GameObject.h"
#include "Model.h"
#include "Transform.h"

//コンストラクタ
SphereCollider::SphereCollider(XMFLOAT3 center, float radius) //: pGameObject_(nullptr)
{
	center_ = center;
	size_ = XMFLOAT3(radius, radius, radius);
}

bool SphereCollider::IsHitCircleVsCircle(SphereCollider* circleA, SphereCollider* circleB)
{
	return false;
}


bool SphereCollider::IsHit(SphereCollider* target)
{
	return false;
}


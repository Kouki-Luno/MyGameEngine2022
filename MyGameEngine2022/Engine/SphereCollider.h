#pragma once
#include <d3d11.h>
#include <DirectXMath.h>

using namespace DirectX;

class SphereCollider
{
public:
	SphereCollider(XMFLOAT3 center, float radius);
	
	//GameObject* pGameObject_;	//���������I�u�W�F�N�g
	XMFLOAT3	center_;		//���S�ʒu
	XMFLOAT3	size_;			//����̃T�C�Y

	//���̓��m�̏Փ˔���
	//�����FcircleA	�P�ڂ̋��̔���
	//�����FcircleB	�Q�ڂ̋��̔���
	//�ߒl�F�ڐG���Ă����true
	bool IsHitCircleVsCircle(SphereCollider* circleA, SphereCollider* circleB);

private:
	//�ڐG����
	//�����Ftarget	����̓����蔻��
	//�ߒl�F�ڐG���Ă��true
	bool IsHit(SphereCollider* target);
};
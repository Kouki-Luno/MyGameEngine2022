#pragma once
#include <d3d11.h>
#include <DirectXMath.h>

using namespace DirectX;

class SphereCollider
{
public:
	SphereCollider(XMFLOAT3 center, float radius);
	
	//GameObject* pGameObject_;	//判定をつけるオブジェクト
	XMFLOAT3	center_;		//中心位置
	XMFLOAT3	size_;			//判定のサイズ

	//球体同士の衝突判定
	//引数：circleA	１つ目の球体判定
	//引数：circleB	２つ目の球体判定
	//戻値：接触していればtrue
	bool IsHitCircleVsCircle(SphereCollider* circleA, SphereCollider* circleB);

private:
	//接触判定
	//引数：target	相手の当たり判定
	//戻値：接触してればtrue
	bool IsHit(SphereCollider* target);
};
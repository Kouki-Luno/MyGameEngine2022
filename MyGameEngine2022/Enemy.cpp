#include "Enemy.h"
#include "Bullet.h"
#include "Engine/Input.h"

//コンストラクタ
Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy")
{
}

//デストラクタ
Enemy::~Enemy()
{
}

//初期化
void Enemy::Initialize()
{
	pFbx = new Fbx;
	pFbx->Load("Assets/ODEN2.fbx");
}

//更新
void Enemy::Update()
{
	transform_.rotate_.y--;
	transform_.position_.z = 20;

}

//描画
void Enemy::Draw()
{
	pFbx->Draw(transform_);
}

//開放
void Enemy::Release()
{
}

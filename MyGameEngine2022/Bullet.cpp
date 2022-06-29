#include "Bullet.h"
#include "Engine/Input.h"

//コンストラクタ
Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet")
{
}

//デストラクタ
Bullet::~Bullet()
{
}

//初期化
void Bullet::Initialize()
{
	pFbx = new Fbx;
	pFbx->Load("Assets/ODEN2.fbx");
}

//更新
void Bullet::Update()
{
	if (Input::IsKey(DIK_SPACE))
	{
		transform_.position_.z += 0.03;
	}
}

//描画
void Bullet::Draw()
{
	pFbx->Draw(transform_);
}

//開放
void Bullet::Release()
{
}
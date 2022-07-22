#include "Bullet.h"
#include "Engine/Input.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

//コンストラクタ
Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet"), hModel_(-1)
{
}

//デストラクタ
Bullet::~Bullet()
{
}

//初期化
void Bullet::Initialize()
{
	hModel_ = Model::Load("Assets/ODEN2.fbx");
	assert(hModel_ >= 0);


	transform_.scale_.x = 0.35f;
	transform_.scale_.y = 0.35f;
	transform_.scale_.z = 0.35f;

	SphereCollider* collision = new SphereCollider(1.0f);
	AddCollider(collision);
}

//更新
void Bullet::Update()
{
	transform_.position_.z += 1.0;

	if (transform_.position_.z > 50)
	{
		KillMe();
	}
}

//描画
void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void Bullet::Release()
{
}


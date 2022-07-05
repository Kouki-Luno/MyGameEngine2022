#include "Bullet.h"
#include "Engine/Input.h"
#include "Engine/Transform.h"
#include "Engine/GameObject.h"
#include "Engine/Model.h"

//�R���X�g���N�^
Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet"), hModel_(-1)
{
}

//�f�X�g���N�^
Bullet::~Bullet()
{
}

//������
void Bullet::Initialize()
{
	hModel_ = Model::Load("Assets/ODEN2.fbx");
	assert(hModel_ >= 0);

	transform_.scale_.x = 0.2f;
	transform_.scale_.y = 0.2f;
	transform_.scale_.z = 0.2f;

	if (transform_.position_.z > 10)
	{
		KillMe();
	}
}

//�X�V
void Bullet::Update()
{
	transform_.position_.z += 1.0;
}

//�`��
void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void Bullet::Release()
{
}


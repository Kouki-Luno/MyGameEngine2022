#include "Bullet.h"
#include "Engine/Input.h"
#include "Engine/Transform.h"
#include "Engine/GameObject.h"

//�R���X�g���N�^
Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet")
{
}

//�f�X�g���N�^
Bullet::~Bullet()
{
}

//������
void Bullet::Initialize()
{
	pFbx = new Fbx;
	pFbx->Load("Assets/ODEN2.fbx");

	transform_.scale_.x = 0.2f;
	transform_.scale_.y = 0.2f;
	transform_.scale_.z = 0.2f;
}

//�X�V
void Bullet::Update()
{
	transform_.position_.z += 1.0;
}

//�`��
void Bullet::Draw()
{
	pFbx->Draw(transform_);
}

//�J��
void Bullet::Release()
{
}


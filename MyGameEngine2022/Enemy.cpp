#include "Enemy.h"
#include "Bullet.h"
#include "Engine/Input.h"

//�R���X�g���N�^
Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy")
{
}

//�f�X�g���N�^
Enemy::~Enemy()
{
}

//������
void Enemy::Initialize()
{
	pFbx = new Fbx;
	pFbx->Load("Assets/ODEN2.fbx");
}

//�X�V
void Enemy::Update()
{
	transform_.rotate_.y--;
	transform_.position_.z = 20;

}

//�`��
void Enemy::Draw()
{
	pFbx->Draw(transform_);
}

//�J��
void Enemy::Release()
{
}

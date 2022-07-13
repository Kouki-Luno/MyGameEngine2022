#include "Enemy.h"
#include "Bullet.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Engine/SphereCollider.h"

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

	transform_.position_.z = 20;

	SphereCollider* collision = new SphereCollider(1.0f);
	AddCollider(collision);
}

//�X�V
void Enemy::Update()
{
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

#include "Bullet.h"
#include "Engine/Input.h"

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
}

//�X�V
void Bullet::Update()
{
	if (Input::IsKey(DIK_SPACE))
	{
		transform_.position_.z += 0.03;
	}
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
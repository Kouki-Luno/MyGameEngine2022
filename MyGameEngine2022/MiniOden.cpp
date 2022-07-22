#include "MiniOden.h"
#include "Engine/Input.h"



//�R���X�g���N�^
MiniOden::MiniOden(GameObject* parent)
	:GameObject(parent, "MiniOden")
{
}

//�f�X�g���N�^
MiniOden::~MiniOden()
{
}

//������
void MiniOden::Initialize()
{
	pFbx = new Fbx;
	pFbx->Load("Assets/ODEN2.fbx");

	transform_.scale_.x = 0.25;
	transform_.scale_.y = 0.25;
	transform_.scale_.z = 0.25;

	transform_.position_.x = 5;
}

//�X�V
void MiniOden::Update()
{
	
}

//�`��
void MiniOden::Draw()
{
	pFbx->Draw(transform_);
}

//�J��
void MiniOden::Release()
{
}
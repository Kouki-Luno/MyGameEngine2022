#include "Player.h"
#include "Engine/Input.h"

//�R���X�g���N�^
Player::Player(GameObject* parent)
    :GameObject(parent, "Player")
{
}

//�f�X�g���N�^
Player::~Player()
{
}

//������
void Player::Initialize()
{
    pFbx = new Fbx;
    pFbx->Load("Assets/ODEN2.fbx");
}

//�X�V
void Player::Update()
{
    transform_.rotate_.y++;

	if (Input::IsKey(DIK_D))
	{
		transform_.position_.x += 0.03;
	}

	if (Input::IsKey(DIK_A))
	{
		transform_.position_.x -= 0.03;
	}
}

//�`��
void Player::Draw()
{
    pFbx->Draw(transform_);
}

//�J��
void Player::Release()
{
}
#include "Player.h"
#include "Bullet.h"
#include "Engine/Input.h"

//コンストラクタ
Player::Player(GameObject* parent)
    :GameObject(parent, "Player")
{
}

//デストラクタ
Player::~Player()
{
}

//初期化
void Player::Initialize()
{
    pFbx = new Fbx;
    pFbx->Load("Assets/ODEN2.fbx");
}

//更新
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

	if (Input::IsKeyDown(DIK_SPACE))
	{
		GameObject* pBullet = Instantiate<Bullet>(pParent_);
		pBullet->SetPosition(transform_.position_);
	}
}

//描画
void Player::Draw()
{
    pFbx->Draw(transform_);
}

//開放
void Player::Release()
{
}


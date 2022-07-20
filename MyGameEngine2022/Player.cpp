#include "Player.h"
#include "Bullet.h"
#include "MiniOden.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Engine/SphereCollider.h"

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

	Instantiate<MiniOden>(this);

	SphereCollider* collision = new SphereCollider(1.0f);
	AddCollider(collision);
}

//更新
void Player::Update()
{
    transform_.rotate_.y++;

	if (Input::IsKey(DIK_D))
	{
		transform_.position_.x += 0.1;
	}

	if (Input::IsKey(DIK_A))
	{
		transform_.position_.x -= 0.1;
	}

	if (Input::IsKeyDown(DIK_SPACE))
	{
		GameObject* pBullet = Instantiate<Bullet>(pParent_);
		pBullet->SetPosition(transform_.position_);
	}

	//if (Input::IsKey(DIK_RETURN))
	//{
	//	SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
	//	pSceneManager->ChangeScene(SCENE_ID_PLAY);
	//}
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


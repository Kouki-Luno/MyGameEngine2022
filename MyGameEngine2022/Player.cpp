#include "Player.h"
#include "Bullet.h"
#include "MiniOden.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Engine/SphereCollider.h"

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

	Instantiate<MiniOden>(this);

	SphereCollider* collision = new SphereCollider(1.0f);
	AddCollider(collision);
}

//�X�V
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

//�`��
void Player::Draw()
{
    pFbx->Draw(transform_);
}

//�J��
void Player::Release()
{
}


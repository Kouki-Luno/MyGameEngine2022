#include "PlayScene.h"
#include "Player.h"
#include "Enemy.h"
#include "MiniOden.h"
#include "Engine/SphereCollider.h"
#include "Engine/SceneManager.h"

//�R���X�g���N�^
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

//������
void PlayScene::Initialize()
{
	Instantiate<Player>(this);
	Instantiate<Enemy>(this);
	

	GameObject* test = FindObject("SceneManager");
}

//�X�V
void PlayScene::Update()
{
	//�N���A��ʂɐ؂�ւ�
	if (FindObject("Enemy") == nullptr)
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}
}

//�`��
void PlayScene::Draw()
{
}

//�J��
void PlayScene::Release()
{
}
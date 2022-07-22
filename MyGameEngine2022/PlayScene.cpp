#include "PlayScene.h"
#include "Player.h"
#include "Enemy.h"
#include "MiniOden.h"
#include "Engine/SphereCollider.h"
#include "Engine/SceneManager.h"

//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

//初期化
void PlayScene::Initialize()
{
	Instantiate<Player>(this);
	Instantiate<Enemy>(this);
	

	GameObject* test = FindObject("SceneManager");
}

//更新
void PlayScene::Update()
{
	//クリア画面に切り替え
	if (FindObject("Enemy") == nullptr)
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}
}

//描画
void PlayScene::Draw()
{
}

//開放
void PlayScene::Release()
{
}
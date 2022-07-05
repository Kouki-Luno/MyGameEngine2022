#include "SceneManager.h"
#include "PlayScene.h"

//コンストラクタ
SceneManager::SceneManager(GameObject* parent)
	: GameObject(parent, "SceneManager")
{
}

//初期化
void SceneManager::Initialize()
{
	Instantiate<PlayScene>(this);
}

//更新
void SceneManager::Update()
{
}

//描画
void SceneManager::Draw()
{
}

//開放
void SceneManager::Release()
{
}
#include "TitleScene.h"
#include "Engine/Sprite.h"
#include "Engine/Texture.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

//コンストラクタ
TitleScene::TitleScene(GameObject* parent)
	: GameObject(parent, "TitleScene")
{
}

//初期化
void TitleScene::Initialize()
{
	pTexture_ = new Texture;
	pTexture_->Load(L"Assets\\Title2.png");

	
	
}
//更新
void TitleScene::Update()
{
	if (Input::IsKey(DIK_RETURN))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

//描画
void TitleScene::Draw()
{

}

//開放
void TitleScene::Release()
{
}
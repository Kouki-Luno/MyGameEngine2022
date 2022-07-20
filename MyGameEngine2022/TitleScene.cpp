#include "TitleScene.h"
#include "Engine/Sprite.h"
#include "Engine/Texture.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

//�R���X�g���N�^
TitleScene::TitleScene(GameObject* parent)
	: GameObject(parent, "TitleScene")
{
}

//������
void TitleScene::Initialize()
{
	pTexture_ = new Texture;
	pTexture_->Load(L"Assets\\Title2.png");

	
	
}
//�X�V
void TitleScene::Update()
{
	if (Input::IsKey(DIK_RETURN))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

//�`��
void TitleScene::Draw()
{

}

//�J��
void TitleScene::Release()
{
}
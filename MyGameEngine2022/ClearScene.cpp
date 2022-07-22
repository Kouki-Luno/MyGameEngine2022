#include "ClearScene.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Engine/Image.h"

//�R���X�g���N�^
ClearScene::ClearScene(GameObject* parent)
	: GameObject(parent, "ClearScene"), hPict_(-1)
{
}

//������
void ClearScene::Initialize()
{
	//�摜�f�[�^�̃��[�h
	hPict_ = Image::Load("Assets\\Clear.jpg");
	assert(hPict_ >= 0);
}
//�X�V
void ClearScene::Update()
{
}

//�`��
void ClearScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//�J��
void ClearScene::Release()
{
}
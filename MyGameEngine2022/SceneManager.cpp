#include "SceneManager.h"
#include "PlayScene.h"

//�R���X�g���N�^
SceneManager::SceneManager(GameObject* parent)
	: GameObject(parent, "SceneManager")
{
}

//������
void SceneManager::Initialize()
{
	Instantiate<PlayScene>(this);
}

//�X�V
void SceneManager::Update()
{
}

//�`��
void SceneManager::Draw()
{
}

//�J��
void SceneManager::Release()
{
}
#pragma once
#include "Engine/GameObject.h"
#include "Engine/Texture.h"
#include "Engine/Sprite.h"

//�����V�[�����Ǘ�����N���X
class TitleScene : public GameObject
{
	Texture* pTexture_;
	Sprite* pSprite_;

public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	TitleScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};
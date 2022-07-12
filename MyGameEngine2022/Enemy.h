#pragma once
#include "Engine/GameObject.h"
#include "Engine/Fbx.h"


//�v���C���[���Ǘ�����N���X
class Enemy : public GameObject
{
    Fbx* pFbx;
    Transform a;

public:
    //�R���X�g���N�^
    Enemy(GameObject* parent);

    //�f�X�g���N�^
    ~Enemy();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};
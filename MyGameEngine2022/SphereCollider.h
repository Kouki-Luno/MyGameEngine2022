#pragma once
#include "Engine/GameObject.h"
#include "Engine/Fbx.h"


//�v���C���[���Ǘ�����N���X
class SphereCollider : public GameObject
{
    Fbx* pFbx;
    int hModel_;

public:
    //�R���X�g���N�^
    SphereCollider(GameObject* parent);

    //�f�X�g���N�^
    ~SphereCollider();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};
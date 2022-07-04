#pragma once
#include "Engine/GameObject.h"
#include "Engine/Fbx.h"


//�v���C���[���Ǘ�����N���X
class Model : public GameObject
{
    Fbx* pFbx;


public:
    //�R���X�g���N�^
    Model(GameObject* parent);

    //�f�X�g���N�^
    ~Model();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};
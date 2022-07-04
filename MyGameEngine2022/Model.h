#pragma once
#include "Engine/GameObject.h"
#include "Engine/Fbx.h"


//プレイヤーを管理するクラス
class Model : public GameObject
{
    Fbx* pFbx;


public:
    //コンストラクタ
    Model(GameObject* parent);

    //デストラクタ
    ~Model();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};
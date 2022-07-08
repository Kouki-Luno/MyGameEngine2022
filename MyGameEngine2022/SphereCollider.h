#pragma once
#include "Engine/GameObject.h"
#include "Engine/Fbx.h"


//プレイヤーを管理するクラス
class SphereCollider : public GameObject
{
    Fbx* pFbx;
    int hModel_;

public:
    //コンストラクタ
    SphereCollider(GameObject* parent);

    //デストラクタ
    ~SphereCollider();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};
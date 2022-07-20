#pragma once
#include "Engine/GameObject.h"
#include "Engine/Texture.h"
#include "Engine/Sprite.h"

//■■シーンを管理するクラス
class TitleScene : public GameObject
{
	Texture* pTexture_;
	Sprite* pSprite_;

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	TitleScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};
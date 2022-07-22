#pragma once
#include "Engine/GameObject.h"

//■■シーンを管理するクラス
class TitleScene : public GameObject
{
private:
	int hPict_;    //画像番号

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
#include "MiniOden.h"
#include "Engine/Input.h"



//コンストラクタ
MiniOden::MiniOden(GameObject* parent)
	:GameObject(parent, "MiniOden")
{
}

//デストラクタ
MiniOden::~MiniOden()
{
}

//初期化
void MiniOden::Initialize()
{
	pFbx = new Fbx;
	pFbx->Load("Assets/ODEN2.fbx");

	transform_.scale_.x = 0.25;
	transform_.scale_.y = 0.25;
	transform_.scale_.z = 0.25;

	transform_.position_.x = 5;
}

//更新
void MiniOden::Update()
{
	
}

//描画
void MiniOden::Draw()
{
	pFbx->Draw(transform_);
}

//開放
void MiniOden::Release()
{
}

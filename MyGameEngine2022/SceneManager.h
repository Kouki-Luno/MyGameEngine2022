#pragma once
#include "Engine/GameObject.h"


//■■シーンを管理するクラス
class SceneManager : public GameObject
{
public:

	SceneManager(GameObject* parent);
	~SceneManager();

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
};

#pragma once

#include "../Engine/GameObject.h"

class RootJob : public GameObject
{
public:
	RootJob();
	~RootJob();

	virtual void Initialize() = 0;	//�������z�֐�
	virtual void Update() = 0;		//�������z�֐�
	virtual void Draw() = 0;		//�������z�֐�
	virtual void Release() = 0;		//�������z�֐�
};


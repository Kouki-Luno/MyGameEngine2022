#pragma once

#include "GameObject.h"

class RootJob : public GameObject
{
public:
	RootJob();
	~RootJob();

	virtual void Initialize() = 0;	//純粋仮想関数
	virtual void Update() = 0;		//純粋仮想関数
	virtual void Draw() = 0;		//純粋仮想関数
	virtual void Release() = 0;		//純粋仮想関数
};


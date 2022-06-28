#pragma once

#include "Transform.h"
#include <string>
#include <list>

using namespace std;

class GameObject
{
protected:
	list<GameObject*>	childList_;		//ゲームオブジェクトのリスト構造
	Transform			transform_;		//Transformクラス
	GameObject*			pParent_;		//ゲームオブジェクトなら誰でも「ポインタ」
	string				objectName_;	//文字列

public:
	GameObject();
	GameObject(GameObject* parent, const std::string& name);
	~GameObject();

	virtual void Initialize() = 0;	//純粋仮想関数
	virtual void Update() = 0;		//純粋仮想関数
	virtual void Draw() = 0;		//純粋仮想関数
	void DrawSub();
	virtual void Release(void) = 0;		//純粋仮想関数

	template<class T>
	void Instantiate(GameObject* parent)
	{
		T* p;
		p = new T(parent);
		p->Initialize();
		childList_.push_back(p);
	}
};

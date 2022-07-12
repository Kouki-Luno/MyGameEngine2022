#pragma once

#include "Transform.h"
#include <string>
#include <list>
#include "Direct3D.h"
#include "SphereCollider.h"

using namespace std;

class GameObject
{
	bool dead_;

protected:
	list<GameObject*>	childList_;		//ゲームオブジェクトのリスト構造
	Transform			transform_;		//Transformクラス
	GameObject*			pParent_;		//ゲームオブジェクトなら誰でも「ポインタ」
	string				objectName_;	//文字列


public:
	GameObject();
	GameObject(GameObject* parent, const std::string& name);
	virtual ~GameObject();

	virtual void Initialize() = 0;	//純粋仮想関数
	virtual void Update() = 0;		//純粋仮想関数
	void UpdateSub();
	virtual void Draw() = 0;		//純粋仮想関数
	void DrawSub();
	virtual void Release(void) = 0;	//純粋仮想関数
	void ReleaseSub();

	void KillMe();

	void SetPosition(XMFLOAT3 position);
	void SetPosition(float x, float y, float z);

	GameObject* FindChildObject(string objectName);
	GameObject* GetRootJob();
	GameObject* FindObject(string objectName);

	SphereCollider* pSphereCollider_;

	void AddCollider(SphereCollider* SphereCollider);

	virtual void OnCollision(GameObject* pTarget) {};

	//衝突判定
	//引数：pTarget	衝突してるか調べる相手
	void Collision(GameObject* pTarget);


	//テンプレート
	template<class T>
	GameObject* Instantiate(GameObject* parent)
	{
		T* p;
		p = new T(parent);
		p->Initialize();
		childList_.push_back(p);

		return p;
	}
};

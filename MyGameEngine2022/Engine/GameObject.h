#pragma once

#include "Transform.h"
#include <string>
#include <list>

using namespace std;

class GameObject
{
protected:
	list<GameObject*>	childList_;		//�Q�[���I�u�W�F�N�g�̃��X�g�\��
	Transform			transform_;		//Transform�N���X
	GameObject*			pParent_;		//�Q�[���I�u�W�F�N�g�Ȃ�N�ł��u�|�C���^�v
	string				objectName_;	//������

public:
	GameObject();
	GameObject(GameObject* parent, const std::string& name);
	~GameObject();

	virtual void Initialize() = 0;	//�������z�֐�
	virtual void Update() = 0;		//�������z�֐�
	void UpdateSub();
	virtual void Draw() = 0;		//�������z�֐�
	void DrawSub();
	virtual void Release(void) = 0;	//�������z�֐�
	void ReleaseSub();

	void SetPosition(XMFLOAT3 position);
	void SetPosition(float x, float y, float z);

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

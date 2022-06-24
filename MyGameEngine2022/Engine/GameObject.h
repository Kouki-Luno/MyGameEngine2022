#pragma once

#include "../Engine/Transform.h"
#include <string>
#include <list>

using namespace std;

class GameObject
{
	list<int>	childList_;	//�Q�[���I�u�W�F�N�g�̃��X�g�\��
	Transform	transform_;	//Transform�N���X
	string	pParent_;		//�Q�[���I�u�W�F�N�g�Ȃ�N�ł��u�|�C���^�v
	string	objectName_;	//������

public:
	GameObject();
	GameObject(GameObject* parent, const std::string& name);
	~GameObject();

	virtual void Initialize() = 0;	//�������z�֐�
	virtual void Update() = 0;		//�������z�֐�
	virtual void Draw() = 0;		//�������z�֐�
	virtual void Release() = 0;		//�������z�֐�
};

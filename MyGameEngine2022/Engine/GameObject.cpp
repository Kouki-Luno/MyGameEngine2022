#include "GameObject.h"

GameObject::GameObject()
{
}


GameObject::GameObject(GameObject* parent, const std::string& name) 
	: dead_(false), pParent_(parent), objectName_(name)
{
}


GameObject::~GameObject()
{
}

void GameObject::UpdateSub()
{
	Update();

	for (auto itr = childList_.begin(); itr != childList_.end(); itr++)
	{
		(*itr)->UpdateSub();
	}

	for (auto itr = childList_.begin(); itr != childList_.end();)
	{
		if ((*itr)->dead_ == true)
		{
			(*itr)->ReleaseSub();
			SAFE_DELETE(*itr);
			itr = childList_.erase(itr);
		}
		else
		{
			itr++;
		}
	}
}

void GameObject::DrawSub()
{
	Draw();

	for (auto itr = childList_.begin(); itr != childList_.end(); itr++)
	{
		(*itr)->DrawSub();
	}
}

void GameObject::ReleaseSub()
{

	for (auto itr = childList_.begin(); itr != childList_.end(); itr++)
	{
		(*itr)->ReleaseSub();
		SAFE_DELETE(*itr);
	}

	Release();

}

void GameObject::KillMe()
{
	dead_ = true;
}

void GameObject::SetPosition(XMFLOAT3 position)
{
	transform_.position_ = position;
}

void GameObject::SetPosition(float x, float y, float z)
{
	SetPosition(XMFLOAT3(x, y, z));
}

GameObject* GameObject::FindChildObject(std::string objectName)
{
	if (objectName_ == objectName)
	{

	}
}

void GameObject::GetRootJob()
{
	if (pParent_)
	{

	}
}

void GameObject::FindObject(string objectName)
{

	if (GetObjectName() == objectName)
	{
		return ;
	}

	return FindChildObject(objectName);
}

const std::string& GameObject::GetObjectName(void) const
{
	return objectName_;
}

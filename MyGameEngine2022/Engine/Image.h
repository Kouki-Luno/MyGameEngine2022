#pragma once

#pragma once

#include <vector>
#include <string>
#include "Sprite.h"
#include "Transform.h"

//-----------------------------------------------------------
//2D�摜���Ǘ�����
//-----------------------------------------------------------
namespace Image
{
	//�摜���
	struct ImageData
	{
		//�t�@�C����
		std::string fileName;

		//���[�h�����摜�f�[�^�̃A�h���X
		Sprite* pSprite;

		//�s��
		Transform transform;

		//�R���X�g���N�^
		ImageData() : pSprite(nullptr)
		{
		}
	};


	//������
	void Initialize();

	//�摜�����[�h
	int Load(std::string fileName);

	//�`��
	void Draw(int handle);

	//�C�ӂ̉摜���J��
	void Release(int handle);

	//�S�Ẳ摜������j
	void AllRelease();

	//���[���h�s���ݒ�
	void SetTransform(int handle, Transform& transform);

	//���[���h�s��̎擾
	XMMATRIX GetMatrix(int handle);
}
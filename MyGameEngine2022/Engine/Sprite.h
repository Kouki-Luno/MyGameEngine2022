#pragma once
#include "Direct3D.h"
#include <DirectXMath.h>
#include "Texture.h"

using namespace DirectX;


class Sprite
{

//�R���X�^���g�o�b�t�@�[
struct CONSTANT_BUFFER
{
	XMMATRIX	matWVP;
};

//���_���
struct VERTEX
{
	XMVECTOR position;
	XMVECTOR uv;
};

protected:
	DWORD	vertexNum_;		//���_��
	VERTEX* vertices_;		//���_���
	ID3D11Buffer* pVertexBuffer_;	//���_�o�b�t�@

	DWORD indexNum;			//�C���f�b�N�X��
	int* index_;			//�C���f�b�N�X���
	ID3D11Buffer* pIndexBuffer_;

	ID3D11Buffer* pConstantBuffer_;	//�R���X�^���g�o�b�t�@

	Texture* pTexture_;

public:
	Sprite();

	~Sprite();

	HRESULT Initialize();

	void Draw(XMMATRIX& worldMatrix);

	void Release();

};
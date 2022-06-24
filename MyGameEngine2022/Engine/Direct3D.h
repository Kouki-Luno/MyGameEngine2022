#pragma once

//�C���N���[�h
#include <d3d11.h>
#include <assert.h>
#include <DirectXMath.h>
#include "Texture.h"

using namespace DirectX;

#define SAFE_DELETE(p) if(p != nullptr){delete p; p = nullptr;}
#define SAFE_RELEASE(p) if(p != nullptr){ p->Release(); p = nullptr;}
#define SAFE_DELETE_ARRAY(p) if(p != nullptr){ delete[] p; p = nullptr;}

//�����J
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")

enum SHADER_TYPE
{
	SHADER_2D,
	SHADER_3D,
	SHADER_MAX
};

namespace Direct3D

{
	//������
	HRESULT Initialize(int winW, int winH, HWND hWnd);

	//�V�F�[�_�[����
	HRESULT InitShader();
	HRESULT InitShader2D();
	HRESULT InitShader3D();

	void SetShader(SHADER_TYPE type);

	//�`��J�n
	void BeginDraw();

	//�`��I��
	void EndDraw();

	//���
	void Release();

	extern ID3D11Device* pDevice;
	extern ID3D11DeviceContext* pContext;
};
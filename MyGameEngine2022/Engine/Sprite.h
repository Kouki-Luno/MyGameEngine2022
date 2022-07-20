#pragma once

#include "Direct3D.h"
#include <DirectXMath.h>
#include "Texture.h"


using namespace DirectX;


class Sprite
{

//コンスタントバッファー
struct CONSTANT_BUFFER
{
	XMMATRIX	matWVP;
};

//頂点情報
struct VERTEX
{
	XMVECTOR position;
	XMVECTOR uv;
};

protected:
	DWORD	vertexNum_;		//頂点数
	VERTEX* vertices_;		//頂点情報
	ID3D11Buffer* pVertexBuffer_;	//頂点バッファ

	DWORD indexNum;			//インデックス数
	int* index_;			//インデックス情報
	ID3D11Buffer* pIndexBuffer_;

	ID3D11Buffer* pConstantBuffer_;	//コンスタントバッファ

	Texture* pTexture_;

public:
	Sprite();

	~Sprite();

	HRESULT Initialize();

	void Draw(XMMATRIX& worldMatrix);

	void Release();

};
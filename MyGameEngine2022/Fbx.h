#pragma once

#include <d3d11.h>
#include <fbxsdk.h>
#include <string>
#include "Transform.h"
//#include "Texture.h"


#pragma comment(lib, "LibFbxSDK-MT.lib")
#pragma comment(lib, "LibXml2-MT.lib")
#pragma comment(lib, "zlib-MT.lib")

class Texture;

class Fbx
{

	//マテリアル
	struct MATERIAL
	{
		Texture* pTexture;
	};

	struct CONSTANT_BUFFER
	{
		XMMATRIX	matWVP;
		XMMATRIX	matNormal;
	};

	struct VERTEX
	{
		XMVECTOR position;
		XMVECTOR uv;
	};

	int vertexCount_;	//頂点数
	int polygonCount_;	//ポリゴン数
	int materialCount_;	//マテリアルの個数

	ID3D11Buffer *pVertexBuffer_;
	ID3D11Buffer **pIndexBuffer_;
	ID3D11Buffer *pConstantBuffer_;

	MATERIAL* pMaterialList_;

	int* indexCount_;

public:

	Fbx();
	~Fbx();
	HRESULT Load(std::string fileName);
	void    Draw(Transform& transform);
	void    Release();

private:
	void InitVertex(fbxsdk::FbxMesh* pMesh);
	void InitIndex(fbxsdk::FbxMesh* pMesh);
	void IntConstantBuffer();
	void InitMaterial(fbxsdk::FbxNode* pNode);

};
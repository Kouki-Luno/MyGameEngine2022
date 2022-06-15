//インクルード
#include <Windows.h>
#include "Direct3D.h"
//#include "Quad.h"
#include "Camera.h"
//#include "Dice.h"
//#include "Sprite.h"
#include "Fbx.h"
#include "Transform.h"


//定数宣言
LPCWSTR WIN_CLASS_NAME = L"SampleGame";  //ウィンドウクラス名
const int WINDOW_WIDTH = 800;			//ウィンドウの幅
const int WINDOW_HEIGHT = 600;			//ウィンドウの高さ


//プロトタイプ宣言
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);



//エントリーポイント
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
	//ウィンドウクラス（設計図）を作成
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);             //この構造体のサイズ
	wc.hInstance = hInstance;                   //インスタンスハンドル
	wc.lpszClassName = WIN_CLASS_NAME;            //ウィンドウクラス名
	wc.lpfnWndProc = WndProc;                   //ウィンドウプロシージャ
	wc.style = CS_VREDRAW | CS_HREDRAW;         //スタイル（デフォルト）
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); //アイコン
	wc.hIconSm = LoadIcon(NULL, IDI_WINLOGO);   //小さいアイコン
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);   //マウスカーソル
	wc.lpszMenuName = NULL;                     //メニュー（なし）
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //背景（白）

	RegisterClassEx(&wc); //クラスを登録

	//ウィンドウサイズの計算
	RECT winRect = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
	AdjustWindowRect(&winRect, WS_OVERLAPPEDWINDOW, FALSE);
	int winW = winRect.right - winRect.left;     //ウィンドウ幅
	int winH = winRect.bottom - winRect.top;     //ウィンドウ高さ

	//ウィンドウを作成
	HWND hWnd = CreateWindow(
		WIN_CLASS_NAME,     //ウィンドウクラス名
		L"サンプルゲーム",  //タイトルバーに表示する内容
		WS_OVERLAPPEDWINDOW,//スタイル（普通のウィンドウ）
		CW_USEDEFAULT,      //表示位置左（おまかせ）
		CW_USEDEFAULT,      //表示位置上（おまかせ）
		winW,				//ウィンドウ幅
		winH,				//ウィンドウ高さ
		NULL,				//親ウインドウ（なし）
		NULL,               //メニュー（なし）
		hInstance,          //インスタンス
		NULL                //パラメータ（なし）
	);

	//ウィンドウを表示
	ShowWindow(hWnd, nCmdShow);
	CoInitialize(nullptr);
	CoUninitialize();

	HRESULT hr;

	//Direct3D初期化
	hr = Direct3D::Initialize(WINDOW_WIDTH, WINDOW_HEIGHT, hWnd);
	if (FAILED(hr))
	{
		PostQuitMessage(0);
	}

	//Quad* pQuad;
	//pQuad = new Quad;
	//hr = pQuad->Initialize();

	//Dice* pDice;
	//pDice = new Dice;
	//hr = pDice->Initialize();

	//Sprite* pSprite;
	//pSprite = new Sprite;
	//hr = pSprite->Initialize();
	//if (FAILED(hr))
	//{
	//	PostQuitMessage(0);
	//}

	Fbx* pFbx;
	pFbx = new Fbx;
	hr = pFbx->Load("Assets/ODEN2.fbx");

	//カメラ初期化
	Camera::Initialize();
	//float rotate_x = 0;
	//float rotate_y = 0;



	//メッセージループ（何か起きるのを待つ）
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT)
	{
		//メッセージあり
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		//メッセージなし
		else
		{
			//ゲームの処理
			Direct3D::BeginDraw();

			//アップデート
			Camera::Update();

			//描画処理
			//XMMATRIX mat = XMMatrixRotationY(XMConvertToRadians(rotate)) * XMMatrixRotationX(XMConvertToRadians(rotate));;
			
			//static float x = 0;

			//x += 0.0002f;
			//XMMATRIX mat = XMMatrixTranslation(x, 0, 0);//移動
			//XMMATRIX mat = XMMatrixScaling(x, 0, 0);//拡大
			
			//static float angle = 0;
			//angle += 0.05;
			//XMMATRIX mat = XMMatrixRotationY(XMConvertToRadians(angle)) * XMMatrixTranslation(0, 3, 0);
			//pDice->Draw(mat);

			//mat = XMMatrixScaling(512.0f/800.0f, 256.0f/600.0f, 1.0f);
			//pSprite->Draw(mat);
						
			//Dice->Draw(mat);
			//rotate_x += 0.04;
			//rotate_y += 0.05;

			static float angle = 0;
			angle += 0.05;

			Transform odenTransform;
			odenTransform.rotate_.y = angle;
			pFbx->Draw(odenTransform);

			//終了
			Direct3D::EndDraw();
		}
	}

	//SAFE_DELETE(pDice);
	//SAFE_DELETE(pQuad);
	//SAFE_DELETE(pSprite);
	SAFE_DELETE(pFbx);
	Direct3D::Release();
	CoUninitialize();
	return 0;
}


//ウィンドウプロシージャ（何かあった時によばれる関数）
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);  //プログラム終了
		return 0;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}
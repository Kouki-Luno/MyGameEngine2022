//�C���N���[�h
#include <Windows.h>
#include "Direct3D.h"
//#include "Quad.h"
#include "Camera.h"
//#include "Dice.h"
//#include "Sprite.h"
#include "Fbx.h"


//�萔�錾
LPCWSTR WIN_CLASS_NAME = L"SampleGame";  //�E�B���h�E�N���X��
const int WINDOW_WIDTH = 800;			//�E�B���h�E�̕�
const int WINDOW_HEIGHT = 600;			//�E�B���h�E�̍���


//�v���g�^�C�v�錾
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);



//�G���g���[�|�C���g
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
	//�E�B���h�E�N���X�i�݌v�}�j���쐬
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);             //���̍\���̂̃T�C�Y
	wc.hInstance = hInstance;                   //�C���X�^���X�n���h��
	wc.lpszClassName = WIN_CLASS_NAME;            //�E�B���h�E�N���X��
	wc.lpfnWndProc = WndProc;                   //�E�B���h�E�v���V�[�W��
	wc.style = CS_VREDRAW | CS_HREDRAW;         //�X�^�C���i�f�t�H���g�j
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); //�A�C�R��
	wc.hIconSm = LoadIcon(NULL, IDI_WINLOGO);   //�������A�C�R��
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);   //�}�E�X�J�[�\��
	wc.lpszMenuName = NULL;                     //���j���[�i�Ȃ��j
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //�w�i�i���j

	RegisterClassEx(&wc); //�N���X��o�^

	//�E�B���h�E�T�C�Y�̌v�Z
	RECT winRect = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
	AdjustWindowRect(&winRect, WS_OVERLAPPEDWINDOW, FALSE);
	int winW = winRect.right - winRect.left;     //�E�B���h�E��
	int winH = winRect.bottom - winRect.top;     //�E�B���h�E����

	//�E�B���h�E���쐬
	HWND hWnd = CreateWindow(
		WIN_CLASS_NAME,     //�E�B���h�E�N���X��
		L"�T���v���Q�[��",  //�^�C�g���o�[�ɕ\��������e
		WS_OVERLAPPEDWINDOW,//�X�^�C���i���ʂ̃E�B���h�E�j
		CW_USEDEFAULT,      //�\���ʒu���i���܂����j
		CW_USEDEFAULT,      //�\���ʒu��i���܂����j
		winW,				//�E�B���h�E��
		winH,				//�E�B���h�E����
		NULL,				//�e�E�C���h�E�i�Ȃ��j
		NULL,               //���j���[�i�Ȃ��j
		hInstance,          //�C���X�^���X
		NULL                //�p�����[�^�i�Ȃ��j
	);

	//�E�B���h�E��\��
	ShowWindow(hWnd, nCmdShow);
	CoInitialize(nullptr);
	CoUninitialize();

	HRESULT hr;

	//Direct3D������
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
	hr = pFbx->Load("Assets/ODEN.fbx");

	//�J����������
	Camera::Initialize();
	//float rotate_x = 0;
	//float rotate_y = 0;



	//���b�Z�[�W���[�v�i�����N����̂�҂j
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT)
	{
		//���b�Z�[�W����
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		//���b�Z�[�W�Ȃ�
		else
		{
			//�Q�[���̏���
			Direct3D::BeginDraw();

			//�A�b�v�f�[�g
			Camera::Update();

			//�`�揈��
			//XMMATRIX mat = XMMatrixRotationY(XMConvertToRadians(rotate)) * XMMatrixRotationX(XMConvertToRadians(rotate));;
			
			//static float x = 0;

			//x += 0.0002f;
			//XMMATRIX mat = XMMatrixTranslation(x, 0, 0);//�ړ�
			//XMMATRIX mat = XMMatrixScaling(x, 0, 0);//�g��
			
			//static float angle = 0;
			//angle += 0.05;
			//XMMATRIX mat = XMMatrixRotationY(XMConvertToRadians(angle)) * XMMatrixTranslation(0, 3, 0);
			//pDice->Draw(mat);

			//mat = XMMatrixScaling(512.0f/800.0f, 256.0f/600.0f, 1.0f);
			//pSprite->Draw(mat);
						
			//Dice->Draw(mat);
			//rotate_x += 0.04;
			//rotate_y += 0.05;

			Transform odenTransform;
			pFbx->Draw(odenTransform);

			//�I��
			Direct3D::EndDraw();
		}
	}

	//SAFE_DELETE(pDice);
	//SAFE_DELETE(pQuad);
	//SAFE_DELETE(pSprite);
	SAFE_DELETE(pFbx);
	Direct3D::Release();
	return 0;
}


//�E�B���h�E�v���V�[�W���i�������������ɂ�΂��֐��j
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);  //�v���O�����I��
		return 0;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}
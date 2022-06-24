#include "Input.h"
#include "XInput.h"

#pragma comment(lib,"Xinput.lib")

namespace Input
{
	LPDIRECTINPUT8   pDInput = nullptr;
	LPDIRECTINPUTDEVICE8 pKeyDevice = nullptr;	//デバイスオブジェクト

	BYTE keyState[256] = { 0 };	//現在の各キーの状態
	BYTE prevKeyState[256];    //前フレームでの各キーの状態

	void Initialize(HWND hWnd)
	{
		DirectInput8Create(GetModuleHandle(nullptr), 
		DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&pDInput, nullptr);


		pDInput->CreateDevice(GUID_SysKeyboard, &pKeyDevice, nullptr);
		pKeyDevice->SetDataFormat(&c_dfDIKeyboard);
		pKeyDevice->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND);

	}

	void Update()
	{

		memcpy(keyState, prevKeyState, 256);

		pKeyDevice->Acquire();
		pKeyDevice->GetDeviceState(sizeof(keyState), &keyState);

	}

	bool IsKey(int keyCode)
	{
		//キーボード
		if (keyState[keyCode] & 0x80)
		{
			return true;
		}
		return false;

	}

	bool IsKeyDown(int keyCode)
	{
		//今は押してて、前回は押してない
		if (keyState[keyCode] & 0x80 && prevKeyState == 0)
		{
			return true;
		}
		return false;
	}

	void Release()
	{
		SAFE_RELEASE(pDInput);
	}
}


#pragma once
#include <Novice.h>

struct ContorollerVector2
{
	int x;
	int y;
};
class InputManager
{
private:

	char keys[256];
	char preKeys[256];


	ContorollerVector2 inputStick;

private:
	void _Update();
	bool IsPressKey(int DIK);
	bool IsTriggerKey(int DIK);
	bool IsReleaseKey(int DIK);

public:

	static InputManager* GetInstance();


	static void Update();

	static bool GetIsPressKey(int DIK) {
		return GetInstance()->IsPressKey(DIK);
	};
	static bool GetIsTriggerKey(int DIK) {
		return GetInstance()->IsTriggerKey(DIK);
	};

	static bool GetIsReleaseKey(int DIK) {
		return GetInstance()->IsReleaseKey(DIK);
	};

	static ContorollerVector2 GetLeftStick(ContorollerVector2& value) {
		value = GetInstance()->inputStick;
		return value;
	};

	void Init();

	



};


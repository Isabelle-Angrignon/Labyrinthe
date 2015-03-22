//#include <iostream>
//#include <Windows.h>
//#include <string>
//using namespace std;
//
//int ReadInput()
//{
//	// -32767 == touche appuyé ! 
//	bool ToucheAppuyer = false;
//	while (!ToucheAppuyer)
//	{
//		short VirtualKey; 
//		VirtualKey = GetAsyncKeyState(VK_UP);
//		if (VirtualKey == -32767) return VK_UP;
//		VirtualKey = GetAsyncKeyState(VK_RIGHT);
//		if (VirtualKey == -32767) return VK_RIGHT;
//		VirtualKey = GetAsyncKeyState(VK_DOWN);
//		if (VirtualKey == -32767) return VK_DOWN;
//		VirtualKey = GetAsyncKeyState(VK_LEFT);
//		if (VirtualKey == -32767) return VK_LEFT;
//		VirtualKey = GetAsyncKeyState(VK_ESCAPE);
//		if (VirtualKey == -32767) return VK_ESCAPE;
//		Sleep(10);
//	}
//}
//
//bool WriteInput(int Arrow)
//{
//	switch (Arrow)
//	{
//	case VK_UP:
//		cout << "Up" << endl;
//		break;
//	case VK_RIGHT:
//		cout << "Right" << endl;
//		break;
//	case VK_DOWN:
//		cout << "Down" << endl;
//		break;
//	case VK_LEFT:
//		cout << "Left" << endl;
//		break;
//	case VK_ESCAPE:
//		return false;
//		break;
//	default:
//		break;
//	}
//	return true;
//}
//
//int main()
//{
//	bool IsNotEnd = true;
//	while (IsNotEnd)
//	{
//		int Arrows = ReadInput();
//		IsNotEnd = WriteInput(Arrows);
//	}
//}
//
//
//

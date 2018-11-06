/*********************************************************************************
*FileName:        AppMain.cpp
*Author:           
*Version:         1.0
*Date:            2018/10/17
*Description:     ����ִ�����
**********************************************************************************/

#include "BoxTwoSlot.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance,
	PSTR cmdLine, int showCmd)
{
	// Debug ģʽ�£������ڴ�й©���
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	try
	{
		BoxTwoSlot theApp(hInstance);
		if (!theApp.Initialize())
			return 0;

		return theApp.Run();
	}
	catch (DxException& e)
	{
		MessageBox(nullptr, e.ToString().c_str(), L"HR Failed", MB_OK);
		return 0;
	}
}
#include <Windows.h>
#include <iostream>
#include <string>

#include "../Shared/Interface_DummyPlugin.h"

typedef Interface_DummyPlugin* (__cdecl *DummyPlugin_Factory)();

/*
	Need to find a way to use XML as interface using generics
*/
int main()
{
	HINSTANCE DummyPlugin = LoadLibrary(L"prjDummyPlugin.dll");
	if (!DummyPlugin)
	{
		std::wcout << "Couldnt Load Library\n";
	}

	// Get The Function's Start Address From Our DLL
	DummyPlugin_Factory Dummy_Factory = reinterpret_cast<DummyPlugin_Factory>(GetProcAddress(DummyPlugin, "Create_DummyPlugin"));
	if (!Dummy_Factory)
	{
		std::wcerr << "Unable To Load Our Exported Function: 'Create_DummyPlugin' From prjDummyPlugin.dll!\n";
		FreeLibrary(DummyPlugin);
		return(1);
	}

	// Create A Pointer To The Address Of The Executable Code Block (Function) We Are Seeking
	Interface_DummyPlugin* DummyPluginInstance = Dummy_Factory();

	// Run A Function From Our Plugin
	DummyPluginInstance->DisplayMessage(L"Well, It Works", L"Debugging");


	std::cin.get(); // Just To Pause
	return(0);
}
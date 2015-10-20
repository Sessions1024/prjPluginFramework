#include <Windows.h>
#include <iostream>
#include <string>

#include "../Shared/Interface_DummyPlugin.h"

class DummyPlugin : public Interface_DummyPlugin
{
public:
	DummyPlugin()
	{
		std::wcout << "Constructor Was Called\n";
	}

	~DummyPlugin()
	{
		std::wcout << "Destructor Was Called\n";
	}

	void ExplicitlyDestroy()
	{
		delete this;
	}

	void DisplayMessage(std::wstring argMessage, std::wstring argTitle)
	{
		MessageBoxW(NULL, argMessage.c_str(), argTitle.c_str(), NULL); // Display MessageBox
	}
};

// Exporting The Class
extern "C" __declspec(dllexport) Interface_DummyPlugin* __cdecl Create_DummyPlugin()
{
	return new DummyPlugin;
}
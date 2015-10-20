#include <string>

class Interface_DummyPlugin
{
public:
	virtual void ExplicitlyDestroy() = 0;
	virtual void DisplayMessage(std::wstring argMessage, std::wstring argTitle) = 0;
};
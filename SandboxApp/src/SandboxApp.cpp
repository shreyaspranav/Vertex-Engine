#include <Vertex.h>
#include <iostream>

class SandboxApp : public Vertex::Application
{
public:
	SandboxApp()
	{
		std::cout << "Hello Sandbox!\n";
	}
	~SandboxApp()
	{
		std::cout << "Bye Sandbox!\n";
	}
};

int main()
{
	SandboxApp* app = new SandboxApp();
	app->Run();
	delete app;
}
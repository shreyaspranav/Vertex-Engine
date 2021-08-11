#include <Vertex.h>
#include <iostream>


class SandboxApp : public Vertex::Application
{
public:
	SandboxApp()
	{
		std::cout << "Hello Sandbox!\n";
		VT_LOG_INFO("lOG sANDBOX");
	}
	~SandboxApp()
	{
		std::cout << "Bye Sandbox!\n";
	}
};

Vertex::Application* Vertex::CreateApplication()
{
	return new SandboxApp();
}
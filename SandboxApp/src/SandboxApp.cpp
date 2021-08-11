#include <Vertex.h>

class SandboxApp : public Vertex::Application
{
public:
	SandboxApp()
	{}
	~SandboxApp()
	{}
};

int main()
{
	SandboxApp* app = new SandboxApp();
	app->Run();
	delete app;
}
#include <Vertex.h>
#include <iostream>

class ExampleLayer : public Vertex::Layer
{
public:
	ExampleLayer() :Layer("Example") {}

	void OnAttach() override
	{
		VT_LOG_INFO("Hello ExampleLayer");
	}

	void OnUpdate(float timestep) override
	{

	}

	void OnEvent(Vertex::Event& event)
	{
		VT_LOG_WARN(event.ToString());
	}

	void OnDetach() override
	{
		VT_LOG_INFO("Bye ExampleLayer");
	}
};


class SandboxApp : public Vertex::Application
{
public:
	SandboxApp()
	{
		std::cout << "Hello Sandbox!\n";
		VT_LOG_INFO("lOG sANDBOX");

		PushLayer(new ExampleLayer());

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
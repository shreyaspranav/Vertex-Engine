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
	{}
	~SandboxApp()
	{}

	void OnCreate() override
	{
		width = 1024;
		height = 576;

		title = "Shreyas";
	}

	void OnStart() override
	{
		PushLayer(new ExampleLayer());
	}

	void OnUpdate(float interval) override
	{

	}

	void OnExit() override
	{

	}
};

Vertex::Application* Vertex::CreateApplication()
{
	return new SandboxApp();
}
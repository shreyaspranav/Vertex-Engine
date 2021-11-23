#pragma once

#include "Core.h"
#include "KeyCodes.h"

namespace Vertex {
	
	class VERTEX_API Input
	{
	public:
		static bool IsKeyPressed(KeyCode code) { return s_Input_Instance -> IsKeyPressedImpl(code); }
		static bool IsMouseButtonPressed(KeyCode code) { return s_Input_Instance->IsMouseButtonPressedImpl(code); }
		static int GetMouseX() { return s_Input_Instance->GetMouseXImpl(); }
		static int GetMouseY() { return s_Input_Instance->GetMouseXImpl(); }

	protected:
		virtual bool IsKeyPressedImpl(KeyCode code) = 0;
		virtual bool IsMouseButtonPressedImpl(KeyCode code) = 0;
		virtual int GetMouseXImpl() = 0;
		virtual int GetMouseYImpl() = 0;

	private:
		static Input* s_Input_Instance;
	};

}
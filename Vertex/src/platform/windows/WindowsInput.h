#pragma once

#include "core/Input.h"

namespace Vertex {
	class WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(KeyCode code) override;
		virtual bool IsMouseButtonPressedImpl(KeyCode code) override;
		virtual int GetMouseXImpl() override;
		virtual int GetMouseYImpl() override;
	};
}

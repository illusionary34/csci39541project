#pragma once

#include "Event.h"

namespace Hunter {
	class KeyPressedEvent : public Event {
	public:
		KeyPressedEvent(int key);
		int GetKeyCode() const;

	private:
		int mKeyCode{ -1 };
	};

	class KeyReleasedEvent : public Event {
	public:
		KeyReleasedEvent(int key);
		int GetKeyCode() const;

	private:
		int mKeyCode{ -1 };
	};
}
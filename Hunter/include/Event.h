#pragma once
#include "HunterCentral.h"


namespace Hunter 
{
	enum class EventType {
		KeyPress,
		KeyRelease,
		WindowClose,
		WindowResize,
		WindowMinimize,
		WindowRestore
	};

	class HUNTER_API Event {
	public:
		EventType GetEventType() const;

	private:
		EventType type;
	};
}
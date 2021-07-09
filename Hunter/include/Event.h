#pragma once

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

	class Event {
	public:
		EventType GetEventType() const;

	private:
		EventType type;
	};
}
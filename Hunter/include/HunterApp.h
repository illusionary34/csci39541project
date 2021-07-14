#pragma once
#include "HunterCentral.h"
#include "Window.h"
#include "KeyboardEvents.h"

namespace Hunter {
	class HUNTER_API HunterApp {
	public:

		static void init();

		static HunterApp* getInstance();

		void run();

		virtual void onUpdate();

		virtual ~HunterApp();

		static int GetWindowWidth();
		static int GetWindowHeight();

		virtual void onKeyPressed(KeyPressedEvent& event);
		virtual void onKeyReleased(KeyReleasedEvent& event);

	protected:
		HunterApp();

	private:

		inline static HunterApp* instance{ nullptr };

		Hunter::Window* appwindow{ nullptr };

		std::chrono::steady_clock::time_point mNextFrameTime;
		std::chrono::milliseconds mFrameDuration{16};
	};
};
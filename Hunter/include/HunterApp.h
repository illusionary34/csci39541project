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

		virtual void OnUpdate();

		virtual ~HunterApp();

		static int GetWindowWidth();
		static int GetWindowHeight();

		void onKeyPressed(KeyPressedEvent& event);

	protected:
		HunterApp();

	private:

		inline static HunterApp* instance{ nullptr };

		Hunter::Window* appwindow{ nullptr };
	};
};
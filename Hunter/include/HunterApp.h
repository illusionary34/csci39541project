#pragma once
#include "HunterCentral.h"
#include "Window.h"

namespace Hunter {
	class HUNTER_API HunterApp {
	public:

		static void init();

		static HunterApp* getInstance();

		void run();

		virtual ~HunterApp();

	private:
		HunterApp();

		inline static HunterApp* instance{ nullptr };

		Hunter::Window* appwindow{ nullptr };
	};
};
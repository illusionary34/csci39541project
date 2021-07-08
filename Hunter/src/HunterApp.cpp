#include "pch.h"
#include "HunterApp.h"
#include "WindowsWindow.h"

namespace Hunter {

	void HunterApp::init()
	{
		if (instance == nullptr)
			instance = new HunterApp;
	}

	HunterApp * HunterApp::getInstance()
	{
		return instance;
	}
	void HunterApp::run()
	{
		HLOG("starting game")
		while (true) {
			appwindow->PollEvents();
			appwindow->SwapBuffers();
		}
	}

	HunterApp::~HunterApp()
	{
		appwindow->DeleteWindow();
	}

	HunterApp::HunterApp()
	{
		assert(instance == nullptr);

		appwindow = new Hunter::WindowsWindow;
		appwindow->CreateWindow(800, 600);
	}
}
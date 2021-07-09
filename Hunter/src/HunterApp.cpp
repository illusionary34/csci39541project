#include "pch.h"
#include "HunterApp.h"
#include "WindowsWindow.h"
#include "Renderer.h"
#include "Sprite.h"

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
		HLOG("starting game");

		Renderer::init();
		Sprite test{"../Hunter/assets/sprites/thing.png"};

		while (true) {
			Renderer::draw(test, 100, 100, test.GetWidth(), test.GetHeight());

			appwindow->PollEvents();
			appwindow->SwapBuffers();
		}
	}

	HunterApp::~HunterApp()
	{
		appwindow->DeleteWindow();
	}

	int HunterApp::GetWindowWidth()
	{
		return instance->appwindow->GetWidth();
	}

	int HunterApp::GetWindowHeight()
	{
		return instance->appwindow->GetHeight();
	}

	HunterApp::HunterApp()
	{
		assert(instance == nullptr);

		appwindow = new Hunter::WindowsWindow;
		appwindow->CreateWindow(800, 600);
	}
}
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
			Renderer::clearFrame();
			OnUpdate();

			appwindow->PollEvents();
			appwindow->SwapBuffers();
		}
	}

	void HunterApp::OnUpdate()
	{
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

	void HunterApp::onKeyPressed(KeyPressedEvent& event)
	{
		HLOG(event.GetKeyCode());
	}

	HunterApp::HunterApp()
	{
		assert(instance == nullptr);

		instance = this;

		appwindow = new Hunter::WindowsWindow;
		appwindow->CreateWindow(800, 600);

		appwindow->SetKeyPressedCallback([this](KeyPressedEvent& event) {onKeyPressed(event); });
	}
}
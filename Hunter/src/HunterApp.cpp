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
		HLOG("starting hunter engine");

		Renderer::init();

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		while (true) {
			Renderer::clearFrame();
			onUpdate();

			std::this_thread::sleep_until(mNextFrameTime);

			appwindow->PollEvents();
			appwindow->SwapBuffers();

			mNextFrameTime += mFrameDuration;
		}
	}

	void HunterApp::onUpdate()
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

	void HunterApp::onKeyReleased(KeyReleasedEvent& event)
	{
		HLOG("key released")
	}

	HunterApp::HunterApp()
	{
		assert(instance == nullptr);

		instance = this;

		appwindow = new Hunter::WindowsWindow;
		appwindow->CreateWindow(800, 600);

		appwindow->SetKeyPressedCallback([this](KeyPressedEvent& event) {onKeyPressed(event); });
		appwindow->SetKeyReleasedCallback([this](KeyReleasedEvent& event) {onKeyReleased(event); });
	}
}
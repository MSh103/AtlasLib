#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

#ifdef AT_PLATFORM_WINDOWS

#include "Atlas/Core/Log.h"
#include "Atlas/Core/Application.h"

extern Atlas::Application* Atlas::CreateApplication();

int main(int argc, const char** argv)
{
	Atlas::Log::Init();

	auto app = Atlas::CreateApplication();
	Atlas::Log::Core::Info("AtlasLib Initialized");
	
	int status = app->Run();
	delete app;

	Atlas::Log::Core::Trace("Application exited with code {}", status);
	Atlas::Log::Core::Info("bye bye :)...");

	return status;
}

#endif

#endif // !ENTRYPOINT_H

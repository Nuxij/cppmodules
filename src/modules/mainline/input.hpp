#pragma once
#include "main/module.hpp"
#include "main/messages/messages.hpp"

using namespace cppm;
using namespace cppm::messages;

class InputModule : public Module {
	public:
		InputModule() : Module("input", "Joe Eaves"){};
		void setup();
		void tick();
	private:
		Message out{"input"};

};

// Init/Del functions.
extern "C" CPPM_WINEXPORT InputModule* createModule();
extern "C" CPPM_WINEXPORT void destroyModule(InputModule* module);
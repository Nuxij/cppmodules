#include "modules/mainline/input.hpp"

void InputModule::setup() {

	_socketer->on("process_command", [&](const Message& message) {
		_logger.log(name(), message.serialise(), true);
		return true;
	});

	_socketer->on("process_input", [&](const Message& message) {
		_logger.log(name(), "INPUT: " + message.serialise(), true);
		return true;
	});

	_socketer->on("process_output", [&](const Message& message) {
		_logger.log(name(), "INPUT: " + message.serialise(), true);
		return true;
	});

	Command moduleRunning(name());
	moduleRunning.payload("module-loaded");
	_socketer->sendMessage(moduleRunning);
}

void InputModule::tick() {
}

InputModule* createModule(){return new InputModule;}
void destroyModule(InputModule* module) {delete module;}

#pragma once
// Common
#include "main/module.hpp"
// Module Specific
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <set>

#include <boost/filesystem.hpp>
#include <boost/range/iterator_range_core.hpp>
#include <boost/predef.h>

#include <dlfcn.h>


// A little struct to hold pointers relevant to a module.
typedef struct SpineModule {
	void* module_so;
	Module_loader* loadModule;
	Module_unloader* unloadModule;
	Module* module;
} SpineModule;

class Spine : public Module {
	private:
		#if BOOST_OS_MACOS
			std::string moduleFileExtension = ".dylib";
		#else
			#if BOOST_OS_WINDOWS
				std::string moduleFileExtension = ".dll";
			#else // Linux
				std::string moduleFileExtension = ".so";
			#endif
		#endif

		std::vector<std::thread*> threads;
		std::set<std::string> loadedModules;

		bool isModuleFile(const std::string& filename);
		std::set<std::string> listModules(const std::string& directory);
		bool openModuleFile(const std::string& fileName, SpineModule& spineModule);
		int resolveModuleFunctions(SpineModule& spineModule);
		bool registerModule();
	public:
		Spine();
		~Spine();
		bool run();
		bool loadModules(const std::string& directory);
		bool loadModule(const std::string& filename);
};
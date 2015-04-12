#ifndef SPP_COMPILER_HPP_DEFINED
#define SPP_COMPILER_HPP_DEFINED 

#include "settings/CompilerSettings.hpp"

class SppCompiler
{
public:
	SppCompiler(int argc, char** argv);
private:
	settings::CompilerSettings c_settings;
};

#endif // SPP_COMPILER_HPP_DEFINED
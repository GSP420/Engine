// lua.hpp
// Lua header files for C++
// <<extern "C">> not supplied automatically because Lua also compiles as C++

extern "C" {
#include "Scripting_Core/lua.h"
#include "Scripting_Core/lualib.h"
#include "Scripting_Core/lauxlib.h"
}

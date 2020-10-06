/*
 * This source file is part of RmlUi, the HTML/CSS Interface Middleware
 *
 * For the latest information, see http://github.com/mikke89/RmlUi
 *
 * Copyright (c) 2008-2010 CodePoint Ltd, Shift Technology Ltd
 * Copyright (c) 2019 The RmlUi Team, and contributors
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */
 
#ifndef RMLUI_LUA_COLORB_H
#define RMLUI_LUA_COLORB_H

#include <RmlUi/Lua/LuaType.h>
#include <RmlUi/Lua/IncludeLua.h>
#include <RmlUi/Core/Types.h>

namespace Rml {
namespace Lua {
template<> void ExtraInit<Colorb>(lua_State* L, int metatable_index);
int Colorbnew(lua_State* L);
int Colorb__eq(lua_State* L);
int Colorb__add(lua_State* L);
int Colorb__mul(lua_State* L);


//getters
int ColorbGetAttrred(lua_State* L);
int ColorbGetAttrgreen(lua_State* L);
int ColorbGetAttrblue(lua_State* L);
int ColorbGetAttralpha(lua_State* L);
int ColorbGetAttrrgba(lua_State* L);

//setters
int ColorbSetAttrred(lua_State* L);
int ColorbSetAttrgreen(lua_State* L);
int ColorbSetAttrblue(lua_State* L);
int ColorbSetAttralpha(lua_State* L);
int ColorbSetAttrrgba(lua_State* L);

extern RegType<Colorb> ColorbMethods[];
extern luaL_Reg ColorbGetters[];
extern luaL_Reg ColorbSetters[];

RMLUI_LUATYPE_DECLARE(Colorb)
} // namespace Lua
} // namespace Rml
#endif

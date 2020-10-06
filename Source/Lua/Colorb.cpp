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
 
#include "Colorb.h"


namespace Rml {
namespace Lua {

template<> void ExtraInit<Colorb>(lua_State* L, int metatable_index) 
{
    lua_pushcfunction(L,Colorbnew);
    lua_setfield(L,metatable_index-1,"new");

    lua_pushcfunction(L,Colorb__eq);
    lua_setfield(L,metatable_index,"__eq");

    lua_pushcfunction(L,Colorb__add);
    lua_setfield(L,metatable_index,"__add");

    lua_pushcfunction(L,Colorb__mul);
    lua_setfield(L,metatable_index,"__mul");

    return;
}
int Colorbnew(lua_State* L)
{
    byte red = (byte)luaL_checkinteger(L,1);
    byte green = (byte)luaL_checkinteger(L,2);
    byte blue = (byte)luaL_checkinteger(L,3);
    byte alpha = (byte)luaL_checkinteger(L,4);

    Colorb* col = new Colorb(red,green,blue,alpha);

    LuaType<Colorb>::push(L,col,true);
    return 1;
}

int Colorb__eq(lua_State* L)
{
    Colorb* lhs = LuaType<Colorb>::check(L,1);
    RMLUI_CHECK_OBJ(lhs);
    Colorb* rhs = LuaType<Colorb>::check(L,2);
    RMLUI_CHECK_OBJ(rhs);

    lua_pushboolean(L, (*lhs) == (*rhs) ? 1 : 0);
    return 1;
}

int Colorb__add(lua_State* L)
{
    Colorb* lhs = LuaType<Colorb>::check(L,1);
    RMLUI_CHECK_OBJ(lhs);
    Colorb* rhs = LuaType<Colorb>::check(L,2);
    RMLUI_CHECK_OBJ(rhs);

    Colorb* res = new Colorb((*lhs) + (*rhs));

    LuaType<Colorb>::push(L,res,true);
    return 1;
}

int Colorb__mul(lua_State* L)
{
    Colorb* lhs = LuaType<Colorb>::check(L,1);
    RMLUI_CHECK_OBJ(lhs);
    float rhs = (float)luaL_checknumber(L,2);

    Colorb* res = new Colorb((*lhs) * rhs);
    
    LuaType<Colorb>::push(L,res,true);
    return 1;
}


//getters
int ColorbGetAttrred(lua_State* L)
{
    Colorb* obj = LuaType<Colorb>::check(L,1);
    RMLUI_CHECK_OBJ(obj);
    lua_pushinteger(L,obj->red);
    return 1;
}

int ColorbGetAttrgreen(lua_State* L)
{
    Colorb* obj = LuaType<Colorb>::check(L,1);
    RMLUI_CHECK_OBJ(obj);
    lua_pushinteger(L,obj->green);
    return 1;
}

int ColorbGetAttrblue(lua_State* L)
{
    Colorb* obj = LuaType<Colorb>::check(L,1);
    RMLUI_CHECK_OBJ(obj);
    lua_pushinteger(L,obj->blue);
    return 1;
}

int ColorbGetAttralpha(lua_State* L)
{
    Colorb* obj = LuaType<Colorb>::check(L,1);
    RMLUI_CHECK_OBJ(obj);
    lua_pushinteger(L,obj->alpha);
    return 1;
}

int ColorbGetAttrrgba(lua_State* L)
{
    Colorb* obj = LuaType<Colorb>::check(L,1);
    RMLUI_CHECK_OBJ(obj);
    lua_pushinteger(L,obj->red);
    lua_pushinteger(L,obj->green);
    lua_pushinteger(L,obj->blue);
    lua_pushinteger(L,obj->alpha);
    return 4;
}


//setters
int ColorbSetAttrred(lua_State* L)
{
    Colorb* obj = LuaType<Colorb>::check(L,1);
    RMLUI_CHECK_OBJ(obj);
    byte red = (byte)luaL_checkinteger(L,2);
    obj->red = red;
    return 0;
}

int ColorbSetAttrgreen(lua_State* L)
{
    Colorb* obj = LuaType<Colorb>::check(L,1);
    RMLUI_CHECK_OBJ(obj);
    byte green = (byte)luaL_checkinteger(L,2);
    obj->green = green;
    return 0;
}

int ColorbSetAttrblue(lua_State* L)
{
    Colorb* obj = LuaType<Colorb>::check(L,1);
    RMLUI_CHECK_OBJ(obj);
    byte blue = (byte)luaL_checkinteger(L,2);
    obj->blue = blue;
    return 0;
}

int ColorbSetAttralpha(lua_State* L)
{
    Colorb* obj = LuaType<Colorb>::check(L,1);
    RMLUI_CHECK_OBJ(obj);
    byte alpha = (byte)luaL_checkinteger(L,2);
    obj->alpha = alpha;
    return 0;
}

int ColorbSetAttrrgba(lua_State* L)
{
    Colorb* obj = nullptr;
    int top = lua_gettop(L);
    //each of the items are optional.
    if(top > 0)
    {
        obj = LuaType<Colorb>::check(L,1);
        RMLUI_CHECK_OBJ(obj);
        if(top > 1)
        {
            if(top > 2)
            {
                if(top > 3)
                    obj->alpha = (byte)luaL_checkinteger(L,4);
                obj->blue = (byte)luaL_checkinteger(L,3);
            }
            obj->green = (byte)luaL_checkinteger(L,2);
        }
        obj->red = (byte)luaL_checkinteger(L,1);
    }
    return 0;
}


RegType<Colorb> ColorbMethods[] =
{
    { nullptr, nullptr },
};

luaL_Reg ColorbGetters[] =
{
    RMLUI_LUAGETTER(Colorb,red)
    RMLUI_LUAGETTER(Colorb,green)
    RMLUI_LUAGETTER(Colorb,blue)
    RMLUI_LUAGETTER(Colorb,alpha)
    RMLUI_LUAGETTER(Colorb,rgba)
    { nullptr, nullptr },
};

luaL_Reg ColorbSetters[] =
{
    RMLUI_LUASETTER(Colorb,red)
    RMLUI_LUASETTER(Colorb,green)
    RMLUI_LUASETTER(Colorb,blue)
    RMLUI_LUASETTER(Colorb,alpha)
    RMLUI_LUASETTER(Colorb,rgba)
    { nullptr, nullptr },
};

RMLUI_LUATYPE_DEFINE(Colorb)
} // namespace Lua
} // namespace Rml

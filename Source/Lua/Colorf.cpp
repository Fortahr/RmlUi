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
 
#include "Colorf.h"


namespace Rml {
namespace Lua {

template<> void ExtraInit<Colorf>(lua_State* L, int metatable_index)
{
    lua_pushcfunction(L,Colorfnew);
    lua_setfield(L,metatable_index-1,"new");

    lua_pushcfunction(L,Colorf__eq);
    lua_setfield(L,metatable_index,"__eq");

    return;
}

//metamethods
int Colorfnew(lua_State* L)
{
    float red = (float)luaL_checknumber(L,1);
    float green = (float)luaL_checknumber(L,2);
    float blue =  (float)luaL_checknumber(L,3);
    float alpha = (float)luaL_checknumber(L,4);

    Colorf* col = new Colorf(red,green,blue,alpha);

    LuaType<Colorf>::push(L,col,true);
    return 1;
}

int Colorf__eq(lua_State* L)
{
    Colorf* lhs = LuaType<Colorf>::check(L,1);
    RMLUI_CHECK_OBJ(lhs);
    Colorf* rhs = LuaType<Colorf>::check(L,2);
    RMLUI_CHECK_OBJ(rhs);

    lua_pushboolean(L, (*lhs) == (*rhs) ? 1 : 0);
    return 1;
}


//getters
int ColorfGetAttrred(lua_State* L)
{
    Colorf* obj = LuaType<Colorf>::check(L,1);
    RMLUI_CHECK_OBJ(obj);
    lua_pushnumber(L,obj->red);
    return 1;
}

int ColorfGetAttrgreen(lua_State* L)
{
    Colorf* obj = LuaType<Colorf>::check(L,1);
    RMLUI_CHECK_OBJ(obj);
    lua_pushnumber(L,obj->green);
    return 1;
}

int ColorfGetAttrblue(lua_State* L)
{
    Colorf* obj = LuaType<Colorf>::check(L,1);
    RMLUI_CHECK_OBJ(obj);
    lua_pushnumber(L,obj->blue);
    return 1;
}

int ColorfGetAttralpha(lua_State* L)
{
    Colorf* obj = LuaType<Colorf>::check(L,1);
    RMLUI_CHECK_OBJ(obj);
    lua_pushnumber(L,obj->alpha);
    return 1;
}

int ColorfGetAttrrgba(lua_State* L)
{
    Colorf* obj = LuaType<Colorf>::check(L,1);
    RMLUI_CHECK_OBJ(obj);
    lua_pushnumber(L,obj->red);
    lua_pushnumber(L,obj->green);
    lua_pushnumber(L,obj->blue);
    lua_pushnumber(L,obj->alpha);
    return 4;
}


//setters
int ColorfSetAttrred(lua_State* L)
{
    Colorf* obj = LuaType<Colorf>::check(L,1);
    RMLUI_CHECK_OBJ(obj);
    float red = (float)luaL_checknumber(L,2);
    obj->red = red;
    return 0;
}

int ColorfSetAttrgreen(lua_State* L)
{
    Colorf* obj = LuaType<Colorf>::check(L,1);
    RMLUI_CHECK_OBJ(obj);
    float green = (float)luaL_checknumber(L,2);
    obj->green = green;
    return 0;
}

int ColorfSetAttrblue(lua_State* L)
{
    Colorf* obj = LuaType<Colorf>::check(L,1);
    RMLUI_CHECK_OBJ(obj);
    float blue = (float)luaL_checknumber(L,2);
    obj->blue = blue;
    return 0;
}

int ColorfSetAttralpha(lua_State* L)
{
    Colorf* obj = LuaType<Colorf>::check(L,1);
    RMLUI_CHECK_OBJ(obj);
    float alpha = (float)luaL_checknumber(L,2);
    obj->alpha = alpha;
    return 0;
}

int ColorfSetAttrrgba(lua_State* L)
{
    Colorf* obj = nullptr;
    int top = lua_gettop(L);
    //each of the items are optional.
    if(top > 0)
    {
        obj = LuaType<Colorf>::check(L,1);
        RMLUI_CHECK_OBJ(obj);
        if(top > 1)
        {
            if(top > 2)
            {
                if(top > 3)
                    obj->alpha = (float)luaL_checknumber(L,4);
                obj->blue = (float)luaL_checknumber(L,3);
            }
            obj->green = (float)luaL_checknumber(L,2);
        }
        obj->red = (float)luaL_checknumber(L,1);
    }
    return 0;
}


RegType<Colorf> ColorfMethods[] =
{
    { nullptr, nullptr },
};

luaL_Reg ColorfGetters[] =
{
    RMLUI_LUAGETTER(Colorf,red)
    RMLUI_LUAGETTER(Colorf,green)
    RMLUI_LUAGETTER(Colorf,blue)
    RMLUI_LUAGETTER(Colorf,alpha)
    RMLUI_LUAGETTER(Colorf,rgba)
    { nullptr, nullptr },
};

luaL_Reg ColorfSetters[] =
{
    RMLUI_LUASETTER(Colorf,red)
    RMLUI_LUASETTER(Colorf,green)
    RMLUI_LUASETTER(Colorf,blue)
    RMLUI_LUASETTER(Colorf,alpha)
    RMLUI_LUASETTER(Colorf,rgba)
    { nullptr, nullptr },
};

RMLUI_LUATYPE_DEFINE(Colorf)


} // namespace Lua
} // namespace Rml

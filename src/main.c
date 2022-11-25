#include <stdio.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

void call_lua_json_parser(lua_State* L, const char* json){
	lua_getglobal(L, "print_json");
	lua_pushstring(L, json);
	lua_call(L, 1, 1);
}

const char* call_lua_http_request(lua_State* L, const char* api){
	lua_getglobal(L, "make_request");
	lua_pushstring(L, api);
	lua_call(L, 1, 1);
	const char* response = lua_tostring(L, -1);
	lua_pop(L, 1);
	return response;
}

lua_State* setup_lua(){
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	luaL_dofile(L, "test.lua");
	return L;
}

int main(){
	lua_State* L = setup_lua();
	const char* api="https://steamcommunity.com/market/priceoverview/?appid=730&currency=3&market_hash_name=Fracture%20Case";
	call_lua_http_request(L, api);
	lua_close(L);
	return 0;
}

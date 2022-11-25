#include <stdio.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

int call_lua_add(lua_State* L, int a, int b){
	lua_getglobal(L, "add");
	lua_pushnumber(L, a);
	lua_pushnumber(L, b);
	lua_call(L, 2, 1);
	int sum = lua_tointeger(L, -1);
	lua_pop(L, 1);
	return sum;
}

double call_lua_sqrt(lua_State* L, double n, double e){
	lua_getglobal(L, "sqrt");
	lua_pushnumber(L, n);
	lua_pushnumber(L, e);
	lua_call(L, 2, 1);
	double sum = lua_tonumber(L, -1);
	lua_pop(L, 1);
	return sum;

}

void call_lua_http_request(lua_State* L, const char* api){
	lua_getglobal(L, "make_request");
	lua_pushstring(L, api);
	lua_call(L, 1, 1);
	const char* response = lua_tostring(L, -1);
	lua_pop(L, 1);
	lua_getglobal(L, "print_json");
	lua_pushstring(L, response);
	lua_call(L, 1, 1);
}

int main(){
	lua_State* L;
	L = luaL_newstate();
	luaL_openlibs(L);
	luaL_dofile(L, "test.lua");
	/*int sum = call_lua_add(L, 5, 3);*/
	/*double sum = call_lua_sqrt(L, 5, 0.001);*/
	/*printf("%lf\n", sum);*/
	const char* api="https://steamcommunity.com/market/priceoverview/?appid=730&currency=3&market_hash_name=Fracture%20Case";
	call_lua_http_request(L, api);
	lua_close(L);
	return 0;
}

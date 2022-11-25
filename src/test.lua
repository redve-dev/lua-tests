make_request = function(api)
	local http_request = require "http.request"
	local headers, stream = assert(http_request.new_from_uri(api):go())
	local body = assert(stream:get_body_as_string())
	if headers:get ":status" ~= "200" then
		error(body)
	end
	return body
end

local api="https://steamcommunity.com/market/priceoverview/?appid=730&currency=3&market_hash_name=Fracture%20Case"
local result = make_request(api)

print_json = function(data)
	local json_lib = require "lunajson"
	local arr=json_lib.decode(data)

	for key, value in pairs(arr)
		do
			print(key, value)
		end
end

local luagit2_lib = require("luagit2")

local luagit2_checkout = {}

------------------------------------------------------------
-- {"checkout_init_options",lua_git_checkout_init_options},
-- {"checkout_head",lua_git_checkout_head},
-- {"checkout_index",lua_git_checkout_index},
-- {"checkout_tree",lua_git_checkout_tree},
------------------------------------------------------------

local function checkout_init_options(...)
	return luagit2_lib.checkout_init_options(...)
end

local function checkout_head(...)
	return luagit2_lib.checkout_head(...)
end

local function checkout_index(...)
	return luagit2_lib.checkout_index(...)
end

local function checkout_tree(...)
	return luagit2_lib.checkout_tree(...)
end

luagit2_checkout.checkout_init_options = checkout_init_options
luagit2_checkout.checkout_head = checkout_head
luagit2_checkout.checkout_index = checkout_index
luagit2_checkout.checkout_tree = checkout_tree

return luagit2_checkout

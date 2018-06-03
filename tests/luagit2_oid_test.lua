-- @module luagit2_oid_test
local luagit2_oid_tests = {}

function luagit2_oid_tests.test_luagit2_oid_fromstr()	
    -- evaluate an oid using given 40 char long hex string valid git_oid type string
	a = lib.luagit2_oid_fromstr("a9bcdb56ff08dbdc5b9ca43a6aae8b73fc1dac06") 
    lunatest.assert_not_nil(a)
    if(type(a) == "userdata")
    	then lunatest.assert_match(lib.luagit2_oid_tostr_s(a),"a9bcdb56ff08dbdc5b9ca43a6aae8b73fc1dac06")
    	else lunatest.fail()
    end
end

function luagit2_oid_tests.test_luagit2_oid_fromstrn()	
	a = lib.luagit2_oid_fromstrn("a9bcdb56ff08dbdc5b9ca43a6aae8b73fc1dac06",20) -- evaluate an oid value using only first 20 chars
    lunatest.assert_not_nil(a)
    if(type(a) == "userdata")
    	then lunatest.assert_match(lib.luagit2_oid_tostr_s(a),"a9bcdb56ff08dbdc5b9c00000000000000000000")
    	else lunatest.fail()
    end
end

function luagit2_oid_tests.test_luagit2_oid_cmp()	
	a = lib.luagit2_oid_fromstr("a9bcdb56ff08dbdc5b9ca43a6aae8b73fc1dac06") 
	b = lib.luagit2_oid_fromstrn("a9bcdb56ff08dbdc5b9ca43a6aae8b73fc1dac06",20)
    lunatest.assert_not_nil(a)
    lunatest.assert_not_nil(b)
    if(type(a) == "userdata" and type(b == "userdata"))
    	then lunatest.assert_gte(0,lib.luagit2_oid_cmp(a,b))
    		 lunatest.assert_lte(0,lib.luagit2_oid_cmp(b,a))
    		 lunatest.assert_equal(0,lib.luagit2_oid_cmp(a,a))
    	else lunatest.fail()
    end
end

function luagit2_oid_tests.test_luagit2_oid_ncmp()	
	a = lib.luagit2_oid_fromstr("a9bcdb56ff08dbdc5b9ca43a6aae8b73fc1dac06") 
	b = lib.luagit2_oid_fromstrn("a9bcdb56ff08dbdc5b9ca43a6aae8b73fc1dac06",20)
    lunatest.assert_not_nil(a)
    lunatest.assert_not_nil(b)
    if(type(a) == "userdata" and type(b == "userdata"))
    	then lunatest.assert_not_equal(0,lib.luagit2_oid_ncmp(a,b,40))
    		 lunatest.assert_not_equal(0,lib.luagit2_oid_ncmp(b,a,40)) --- 0 is returned if found match in n length of oid string 
    		 lunatest.assert_equal(0,lib.luagit2_oid_ncmp(a,b,20))
    	else lunatest.fail()
    end
end

function luagit2_oid_tests.test_luagit2_oid_iszero()  
    a = lib.luagit2_oid_fromstr("0000000000000000000000000000000000000000") 
    b = lib.luagit2_oid_fromstr("a9bcdb56ff08dbdc5b9ca43a6aae8b73fc1dac06")
    lunatest.assert_not_nil(a)
    lunatest.assert_not_nil(b)
    if(type(a) == "userdata" and type(b == "userdata"))
        then lunatest.assert_equal(1,lib.luagit2_oid_iszero(a))
             lunatest.assert_equal(0,lib.luagit2_oid_iszero(b))
        else lunatest.fail()
    end
end

function luagit2_oid_tests.test_luagit2_oid_strcmp()   
    a = lib.luagit2_oid_fromstr("a9bcdb56ff08dbdc5b9ca43a6aae8b73fc1dac06") 
    b = lib.luagit2_oid_fromstrn("a9bcdb56ff08dbdc5b9ca43a6aae8b73fc1dac06",20)
    lunatest.assert_not_nil(a)
    lunatest.assert_not_nil(b)
    if(type(a) == "userdata" and type(b == "userdata"))
    --[[ -1 if str is not valid, < 0 if id sorts before str, 0 if id matches str, >0 if id sorts after str. ]]--
        then lunatest.assert_lte(-1,lib.luagit2_oid_strcmp(a,"Some_Non_Hex_String"))
             lunatest.assert_gte(0,lib.luagit2_oid_strcmp(a,"a9bcdb56ff08dbdc5b9c00000000000000000000"))
             lunatest.assert_equal(0,lib.luagit2_oid_strcmp(a,"a9bcdb56ff08dbdc5b9ca43a6aae8b73fc1dac06"))
             lunatest.assert_lte(0,lib.luagit2_oid_strcmp(b,"a9bcdb56ff08dbdc5b9ca43a6aae8b73fc1dac06"))
        else lunatest.fail()
    end
end

function luagit2_oid_tests.test_luagit2_oid_fmt()   
    a = lib.luagit2_oid_fromstr("a9bcdb56ff08dbdc5b9ca43a6aae8b73fc1dac06") 
    lunatest.assert_not_nil(a)
    if(type(a) == "userdata" )
        then lunatest.assert_string(lib.luagit2_oid_fmt(a))
        else lunatest.fail()
    end
end

function luagit2_oid_tests.test_luagit2_oid_pathfmt()   
    a = lib.luagit2_oid_fromstr("a9bcdb56ff08dbdc5b9ca43a6aae8b73fc1dac06") 
    lunatest.assert_not_nil(a)
    if(type(a) == "userdata" )
        then lunatest.assert_string(lib.luagit2_oid_pathfmt(a))
        else lunatest.fail()
    end
end

function luagit2_oid_tests.test_luagit2_oid_nfmt()   
    a = lib.luagit2_oid_fromstr("a9bcdb56ff08dbdc5b9ca43a6aae8b73fc1dac06") 
    lunatest.assert_not_nil(a)
    if(type(a) == "userdata" )
        then lunatest.assert_string(lib.luagit2_oid_nfmt(a,10))
        else lunatest.fail()
    end
end

return luagit2_oid_tests

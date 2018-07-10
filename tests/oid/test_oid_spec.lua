-- Tests for luagit2's oid module functions

describe("oid methods test", function()
    
    local luagit2 = require("luagit2")
    local obj_id
    local obj_id_string = "1385f264afb75a56a5bec74243be9b367ba4ca08" -- Object ID of Fixtures/new_test_repo/README
    local obj_id_semi_zero_a, obj_id_semi_zero_b
    local obj_id_semi_zero_string_a = "1385f264afb75a56a5b000000000000000000000"
    local obj_id_semi_zero_string_b = "0000000000000006a5bec74243be9b367ba4ca08"
    local obj_id_2
    local obj_id_string_2 = "fa49b077972391ad58037050f2a75f74e3671e92" -- Object ID of Fixtures/new_test_repo/new.txt
    local zero_obj_id
    local zero_obj_id_string = "0000000000000000000000000000000000000000"
    
    setup(function()
        -- initialize libgit2's global state and threading
        luagit2.init()
    end)
    
    teardown(function()
        -- close threading and global state.
        luagit2.shutdown()
    end)
    
    before_each(function()
        -- setup different variables
        obj_id = luagit2.oid_fromstr(obj_id_string)
        obj_id_semi_zero_a = luagit2.oid_fromstr(obj_id_semi_zero_string_a)
        obj_id_semi_zero_b = luagit2.oid_fromstr(obj_id_semi_zero_string_b)
        obj_id_2 = luagit2.oid_fromstr(obj_id_string_2)
        zero_obj_id = luagit2.oid_fromstr(zero_obj_id_string)
    end)
    
    it("Checks data type and metatable name ", function()
        -- checks if passed data is not nil
        assert.is.not_nil(obj_id)
        assert.is.not_nil(obj_id_semi_zero_a)
        assert.is.not_nil(obj_id_semi_zero_b)
        assert.is.not_nil(obj_id_2)
        assert.is.not_nil(zero_obj_id)
        
        -- checks the passed data type
        assert.are.same("userdata", type(obj_id))
        assert.are.same("userdata", type(obj_id_semi_zero_a))
        assert.are.same("userdata", type(obj_id_semi_zero_b))
        assert.are.same("userdata", type(obj_id_2))
        assert.are.same("userdata", type(zero_obj_id))
        
        -- checks the metatable name to be luagit2_oid
        -- luagit2's oid struct.(see src/lua_objects.h)
        assert.are.same("luagit2_oid", luagit2.get_userdata_name(obj_id))
        assert.are.same("luagit2_oid", luagit2.get_userdata_name(obj_id_semi_zero_a))
        assert.are.same("luagit2_oid", luagit2.get_userdata_name(obj_id_semi_zero_b))
        assert.are.same("luagit2_oid", luagit2.get_userdata_name(obj_id_2))
        assert.are.same("luagit2_oid", luagit2.get_userdata_name(zero_obj_id))
    end)
    
    it("Tests Obj_Id to its equivalent String", function()
        -- Check the string value of Object Ids if they are equal
        -- to that used for initializing or not.
        
        assert.are.same(obj_id_string, luagit2.oid_tostr(obj_id))
        assert.are.same(obj_id_string_2, luagit2.oid_tostr(obj_id_2))
        assert.are.same(obj_id_semi_zero_string_a, luagit2.oid_tostr(obj_id_semi_zero_a))
        assert.are.same(obj_id_semi_zero_string_b, luagit2.oid_tostr(obj_id_semi_zero_b))
        
        -- reinitializing obj_id value using obj_id_string_2
        -- tests setting oibject id by string
        obj_id = luagit2.oid_fromstr(obj_id_string_2)
        assert.are.not_same(obj_id_string, luagit2.oid_tostr(obj_id))
        assert.are.same(obj_id_string_2, luagit2.oid_tostr(obj_id))
    end)
    
    it("Tests Creating Dis-Similar Objects", function()
        -- This is very important to note
        -- That even if using Same string values,
        -- The Created Objects will differ on direct Comparison
        -- Though their Contained String Value will be same
        
        -- Setting another Alternate Object with Obj_Id_String,
        -- Same as that used for Obj_Id
        
        local extra_object = luagit2.oid_fromstr(obj_id_string)
        assert(not(extra_object == obj_id))
        
        -- checking their contained string value
        assert.are.equal(luagit2.oid_tostr(obj_id), luagit2.oid_tostr(extra_object))
    end)
    
    it(" Tests Comparison of two Object Ids", function()
        -- It returns Integer Value for comparing two luagit2_oid's (A,B)
        -- < 0 if A < B
        -- = 0 if A = B
        -- > 0 if A > B
        
        -- object_id is oid for README
        -- object_id_2 is oid for new.txt
        -- Since README was created before new.txt,
        -- The Oid of README will be less than that of new.txt
        assert((luagit2.oid_cmp(obj_id, obj_id_2)) < 0)
        assert((luagit2.oid_cmp(obj_id_2, obj_id)) > 0)
        
        assert((luagit2.oid_cmp(obj_id, obj_id)) == 0)
    end)
    
    it(" Tests Comparison of two Object Ids for a given length counted from left", function()
        -- Returns Zero in case of match
        assert(luagit2.oid_ncmp(obj_id, obj_id_semi_zero_a, 10) == 0)
        assert(luagit2.oid_ncmp(obj_id, obj_id_semi_zero_b, 10) ~= 0)
    end)
    
    it(" Tests oid_from_strn ", function()
        -- new oid created using first n length of string.
        obj_id = luagit2.oid_fromstrn(obj_id_string, 19)
        assert((luagit2.oid_cmp(obj_id, obj_id_semi_zero_a)) == 0)
        assert.are.equal(luagit2.oid_tostr(obj_id), obj_id_semi_zero_string_a)
    end)
    
    it(" Tests Comparison of Object Id and equivalent String Values", function()
        -- Check for string values of different Object_Ids
        assert.are.equal(luagit2.oid_tostr(obj_id), obj_id_string)
        assert.are.equal(luagit2.oid_tostr(obj_id_2), obj_id_string_2)
        assert.are.equal(luagit2.oid_tostr(obj_id_semi_zero_a), obj_id_semi_zero_string_a)
        assert.are.equal(luagit2.oid_tostr(obj_id_semi_zero_b), obj_id_semi_zero_string_b)
        assert.are.equal(luagit2.oid_tostr(zero_obj_id), zero_obj_id_string)
    end)
    
    it(" Tests whether the OBject Id contains all zeros", function()
        -- It Returns Integer value
        -- true if oid has all zeros
        -- false if oid does not have all zeros
        assert.is_false(luagit2.oid_iszero(obj_id))
        assert.is_true(luagit2.oid_iszero(zero_obj_id))
    end)
    
    it(" Tests Various Formatting methods available", function()
        -- format the oid for entire string value
        assert.are.equal(luagit2.oid_nfmt(obj_id, 40), obj_id_string)
        
        -- format oid only for first 10 readable chars
        -- The value is non readable after 10 chars.
        assert(string.find(luagit2.oid_nfmt(obj_id, 10), "1385f264af"))
        
        -- Tests the path of object as in .git/objects/
        assert.are.equal(luagit2.oid_pathfmt(obj_id), "13/85f264afb75a56a5bec74243be9b367ba4ca08")
        
        -- Format the Object Id to be complete human readable string.
        assert.are.equal(luagit2.oid_fmt(obj_id), obj_id_string)
    end)
    
end)

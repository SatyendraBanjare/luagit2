-- Tests for luagit2's oid module functions

describe("oid methods test", function()

	local lib = require("luagit2")
	local Obj_Id
	local Obj_Id_String = "1385f264afb75a56a5bec74243be9b367ba4ca08" -- Object ID of Fixtures/testrepo2/README
	local Obj_Id_semi_zero_A, Obj_Id_semi_zero_B
	local Obj_Id_semi_zero_string_A = "1385f264afb75a56a5b000000000000000000000"
	local Obj_Id_semi_zero_string_B = "0000000000000006a5bec74243be9b367ba4ca08"
	local Obj_Id_2
	local Obj_Id_String_2 = "fa49b077972391ad58037050f2a75f74e3671e92" -- Object ID of Fixtures/testrepo2/new.txt
	local Zero_Obj_Id
	local Zero_Obj_Id_String = "0000000000000000000000000000000000000000"
	local Extra_Object -- A Extra variable to demonstrate `Dis-Similar` Object Creation

    setup(function()
		lib.luagit2_init()
    end)

    teardown(function()
		lib.luagit2_shutdown()
    end)

    before_each(function()
		Obj_Id = lib.luagit2_oid_fromstr(Obj_Id_String)
		Obj_Id_semi_zero_A = lib.luagit2_oid_fromstr(Obj_Id_semi_zero_string_A)
		Obj_Id_semi_zero_B = lib.luagit2_oid_fromstr(Obj_Id_semi_zero_string_B)
		Obj_Id_2 = lib.luagit2_oid_fromstr(Obj_Id_String_2)
		Zero_Obj_Id = lib.luagit2_oid_fromstr(Zero_Obj_Id_String)
	end)

    it("Checks data type and metatable name ", function()
		-- Checks if Passed Data is not nil
		assert.is.not_nil(Obj_Id)
    	assert.is.not_nil(Obj_Id_semi_zero_A)
    	assert.is.not_nil(Obj_Id_semi_zero_B)
    	assert.is.not_nil(Obj_Id_2)
    	assert.is.not_nil(Zero_Obj_Id)

    	-- Checks the Passed Data type
    	assert.are.same("userdata",type(Obj_Id))
    	assert.are.same("userdata",type(Obj_Id_semi_zero_A))
    	assert.are.same("userdata",type(Obj_Id_semi_zero_B))
    	assert.are.same("userdata",type(Obj_Id_2))
    	assert.are.same("userdata",type(Zero_Obj_Id))

    	-- Checks the metatable name to be luagit2_oid 
    	-- luagit2's Oid struct.(See src/lua_objects.h)
    	assert.are.same("luagit2_oid",lib.get_userdata_name(Obj_Id))
    	assert.are.same("luagit2_oid",lib.get_userdata_name(Obj_Id_semi_zero_A))
    	assert.are.same("luagit2_oid",lib.get_userdata_name(Obj_Id_semi_zero_B))
    	assert.are.same("luagit2_oid",lib.get_userdata_name(Obj_Id_2))
    	assert.are.same("luagit2_oid",lib.get_userdata_name(Zero_Obj_Id))
    end)

    it("Tests Obj_Id to its equivalent String", function()
    	-- Check the string value of Object Ids if they are equal 
    	-- to that used for initializing or not.

    	assert.are.same(Obj_Id_String, lib.luagit2_oid_tostr(Obj_Id))
    	assert.are.same(Obj_Id_String_2, lib.luagit2_oid_tostr(Obj_Id_2))
    	assert.are.same(Obj_Id_semi_zero_string_A, lib.luagit2_oid_tostr(Obj_Id_semi_zero_A))
    	assert.are.same(Obj_Id_semi_zero_string_B, lib.luagit2_oid_tostr(Obj_Id_semi_zero_B))

    	-- Reinitializing Obj_Id value using Obj_Id_String_2
    	-- Tests setting oibject Id by string
    	Obj_Id = lib.luagit2_oid_fromstr(Obj_Id_String_2)
    	assert.are.not_same(Obj_Id_String, lib.luagit2_oid_tostr(Obj_Id))
    	assert.are.same(Obj_Id_String_2, lib.luagit2_oid_tostr(Obj_Id))
    end)

    it("Tests Creating Dis-Similar Objects", function()
    	-- This is very important to note
    	-- That even if using Same string values,
    	-- The Created Objects will differ on direct Comparison
    	-- Though their Contained String Value will be same

    	-- Setting another Alternate Object with Obj_Id_String,
    	-- Same as that used for Obj_Id

    	Extra_Object = lib.luagit2_oid_fromstr(Obj_Id_String)
    	assert(not(Extra_Object == Obj_Id))

    	-- Checking their contained string value
    	assert.are.equal(lib.luagit2_oid_tostr(Obj_Id),lib.luagit2_oid_tostr(Extra_Object))
    end)

    it(" Tests Comparison of two Object Ids",function()
    	-- It returns Integer Value for comparing two luagit2_oid's (A,B)
    	-- < 0 if A < B
    	-- = 0 if A = B
    	-- > 0 if A > B

    	-- Object_Id is oid for README 
    	-- Object_ID_2 is oid for new.txt
    	-- Since README was created before new.txt, 
    	-- The Oid of README will be less than that of new.txt
    	assert((lib.luagit2_oid_cmp(Obj_Id,Obj_Id_2)) < 0)
    	assert((lib.luagit2_oid_cmp(Obj_Id_2,Obj_Id)) > 0)

    	assert((lib.luagit2_oid_cmp(Obj_Id,Obj_Id)) == 0)
    end)

    it(" Tests Comparison of two Object Ids for a given length counted from left",function()
    	-- Returns Zero in case of match
    	assert(lib.luagit2_oid_ncmp(Obj_Id,Obj_Id_semi_zero_A,10) == 0)
    	assert(lib.luagit2_oid_ncmp(Obj_Id,Obj_Id_semi_zero_B,10) ~= 0)
    end)

    it(" Tests oid_from_strn ", function()
    	-- new oid created using first n length of string.
    	Obj_Id = lib.luagit2_oid_fromstrn(Obj_Id_String,19)
    	assert((lib.luagit2_oid_cmp(Obj_Id,Obj_Id_semi_zero_A)) == 0)
    	assert.are.equal(lib.luagit2_oid_tostr(Obj_Id),Obj_Id_semi_zero_string_A)
    end)

    it(" Tests Comparison of Object Id and equivalent String Values", function()
    	-- Check for string values of different Object_Ids
    	assert.are.equal(lib.luagit2_oid_tostr(Obj_Id),Obj_Id_String)
    	assert.are.equal(lib.luagit2_oid_tostr(Obj_Id_2),Obj_Id_String_2)
    	assert.are.equal(lib.luagit2_oid_tostr(Obj_Id_semi_zero_A),Obj_Id_semi_zero_string_A)
    	assert.are.equal(lib.luagit2_oid_tostr(Obj_Id_semi_zero_B),Obj_Id_semi_zero_string_B)
    	assert.are.equal(lib.luagit2_oid_tostr(Zero_Obj_Id),Zero_Obj_Id_String)
    end)

    it(" Tests whether the OBject Id contains all zeros", function()
    	-- It Returns Integer value
    	-- 1 if oid has all zeros
    	-- 0 if oid does not have all zeros
    	assert(lib.luagit2_oid_iszero(Obj_Id) == 0)
    	assert(lib.luagit2_oid_iszero(Zero_Obj_Id) == 1)
    end)

    it(" Tests Various Formatting methods available", function()
    	-- format the oid for entire string value 
    	assert.are.equal(lib.luagit2_oid_nfmt(Obj_Id,40),Obj_Id_String)

    	-- format oid only for first 10 readable chars
    	-- The value is non readable after 10 chars.
    	assert(string.find(lib.luagit2_oid_nfmt(Obj_Id,10),"1385f264af"))

    	-- Tests the path of object as in .git/objects/
    	assert.are.equal(lib.luagit2_oid_pathfmt(Obj_Id),"13/85f264afb75a56a5bec74243be9b367ba4ca08")

    	-- Format the Object Id to be complete human readable string.
    	assert.are.equal(lib.luagit2_oid_fmt(Obj_Id),Obj_Id_String)
    end)

end)

-- Luagit2's Config Module Tests

local fixer = require("Fixtures.fix_repo")
local lfs = require("lfs")

local function get_config_details(option_string)
	local name_handle = io.popen("git config --get --" .. option_string .." user.name ")
	local name = name_handle:read("*a")
	name_handle:close()

	local email_handle = io.popen("git config --get --" .. option_string .." user.email ")
	local email = email_handle:read("*a")
	email_handle:close()

	return name, email
end

describe(" Config Methods Tests ", function()
	local luagit2 = require("luagit2")
	local repo
	local Config_ondisk , Config_Default, Config_System
	local Config_Snapshot
	local default_name , default_email
	local sys_name , sys_email
	local global_name, global_email
	local current_directory_path = lfs.currentdir()

	setup(function()
		luagit2.init()
	end)

	before_each(function()
		fixer.set_repo("new_test_repo")
		repo = luagit2.repository_open("Fixtures/WORKON_REPO/.git")
		Config_ondisk = luagit2.config_open_ondisk(current_directory_path .. "/Fixtures/WORKON_REPO/.git/config")
		Config_Default = luagit2.config_open_default()

		default_name, default_email = get_config_details("")
		sys_name, sys_email  = get_config_details("system")
		global_name, global_email = get_config_details("global")

	end)

	after_each(function()
		luagit2.config_free(Config_ondisk)
		luagit2.repository_free(repo)
		fixer.set_back()
	end)

	teardown(function()
		luagit2.shutdown()
	end)

	--[[
		A simple output of `git config -l` on Fixtures/new_test_repo
		After th repo has been fixed for testing , that is user.email
		and user.name have been set (see fixer.set_repo())

		user.email=YOUR_DEFAULT_GIT_USER_EMAIL
		user.name=YOUR_DEFAULT_GIT_USER_NAME
		core.repositoryformatversion=0
		core.filemode=true
		core.bare=false
		core.logallrefupdates=true
		core.ignorecase=true
		core.precomposeunicode=false
		remote.origin.url=https://github.com/libgit2/false.git
		remote.origin.fetch=+refs/heads/*:refs/remotes/origin/*
		remote.insteadof-test.url=http://example.com/libgit2/libgit2
		remote.insteadof-test.pushurl=http://github.com/libgit2/libgit2
		remote.insteadof-test.fetch=+refs/heads/*:refs/remotes/test/*
		branch.master.remote=origin
		branch.master.merge=refs/heads/master
		branch.master.rebase=true
		url.longer-non-prefix-match.insteadof=ttp://example.com/li
		url.shorter-prefix.insteadof=http://example.co
		url.http://github.com.insteadof=http://example.com
		url.git@github.com:.pushinsteadof=http://github.com/
		user.name=TEST_USER
		user.email=testusernoreply@github.com
		
	]]--

	it("Test Setting and Getting Config Values",function()
		-- Create a Snapshot to read the existing values 
		Config_Snapshot = luagit2.repository_config_snapshot(repo)

		-- Get the username & useremail values and match
		local old_name = luagit2.config_get_string(Config_Snapshot,"user.name")
		local old_email = luagit2.config_get_string(Config_Snapshot,"user.email")

		local cfg_int32 = luagit2.config_get_int32(Config_Snapshot,"core.repositoryformatversion")
		local cfg_int64 = luagit2.config_get_int64(Config_Snapshot,"core.repositoryformatversion")
		local cfg_bool = luagit2.config_get_bool(Config_Snapshot,"core.filemode")

		local cfg_path_buf = luagit2.config_get_path(Config_Snapshot,"remote.origin.url")
		assert.are.same("https://github.com/libgit2/false.git",luagit2.buf_details(cfg_path_buf))

		local cfg_str_buf = luagit2.config_get_string_buf(Config_Snapshot,"user.name")
		assert.are.same("TEST_USER",luagit2.buf_details(cfg_str_buf))
		
		assert.are.same("number",type(cfg_int32))
		assert.are.equal(0,cfg_int32)
		assert.are.same("number",type(cfg_int64))
		assert.are.equal(0,cfg_int64)
		assert.are.same(1,cfg_bool)

		assert.are.equal("TEST_USER",old_name)
		assert.are.equal("testusernoreply@github.com",old_email)

		-- Free the current Config Snapshot
		luagit2.config_free(Config_Snapshot)

		-- Set the Values on test repository's config
		luagit2.config_set_string(Config_ondisk,"user.email","newemail@example.com")
		luagit2.config_set_string(Config_ondisk,"user.name","NEW_NAME_TEST_USER")
		luagit2.config_set_int32(Config_ondisk,"core.repositoryformatversion",10)
		luagit2.config_set_int64(Config_ondisk,"core.repositoryformatversion",10)
		luagit2.config_set_bool(Config_ondisk,"core.filemode",0)


		-- Create a Snapshot again to read Values
		-- The values of this snapshot would be different than
		-- one used previously
		Config_Snapshot = luagit2.config_snapshot(Config_ondisk)

		local new_name = luagit2.config_get_string(Config_Snapshot,"user.name")
		local new_email = luagit2.config_get_string(Config_Snapshot,"user.email")
		local new_int32 = luagit2.config_get_int32(Config_Snapshot,"core.repositoryformatversion")
		local new_bool = luagit2.config_get_bool(Config_ondisk,"core.filemode")

		-- Check for Updated Values
		assert.are.equal("NEW_NAME_TEST_USER",new_name)
		assert.are.equal("newemail@example.com",new_email)
		assert.are.equal(10,new_int32)
		assert.are.equal(0,new_bool)
	end)

	it("Tests config open default ", function()
		Config_Snapshot = luagit2.config_snapshot(Config_Default)
		local Def_name = luagit2.config_get_string(Config_Snapshot,"user.name")
		local Def_email = luagit2.config_get_string(Config_Snapshot,"user.email")

		assert.are.equal(default_name, Def_name .. '\n' )
		assert.are.equal(default_email, Def_email .. '\n')
	end)

	it("Tests find System, Global Config path ", function()
		local find_global = luagit2.config_find_global()
		local find_sys = luagit2.config_find_system()
		
		-- Current Tests are run using a non-Windows system
		-- Thus these Values can't be found
		-- 
		-- local find_programdata = luagit2.config_find_programdata()
		-- local fing_xdg = luagit2.config_find_xdg()

		assert.are.equal("/etc/gitconfig",luagit2.buf_details(find_sys))

		-- In Unix System, Path for git global id ~/.gitconfig
		assert.are.equal('',luagit2.buf_details(find_global))
	end)

	it("Tests various Config get methods ",function()
		-- Tests get_int32,get_int64 , get_bool, get_path
		-- get_string_buf methods
		-- 
		-- Create A snapshot and readvarious values from it
		Config_Snapshot = luagit2.repository_config_snapshot(repo)

		local cfg_int32 = luagit2.config_get_int32(Config_Snapshot,"core.repositoryformatversion")
		assert.are.same("number",type(cfg_int32))

		local cfg_int64 = luagit2.config_get_int64(Config_Snapshot,"core.repositoryformatversion")
		assert.are.same("number",type(cfg_int64))

		local cfg_bool = luagit2.config_get_bool(Config_Snapshot,"core.filemode")
		assert.are.same(1,cfg_bool)

		cfg_bool = luagit2.config_get_bool(Config_Snapshot,"core.bare")
		assert.are.same(0,cfg_bool)

		local cfg_path_buf = luagit2.config_get_path(Config_Snapshot,"remote.origin.url")
		assert.are.same("https://github.com/libgit2/false.git",luagit2.buf_details(cfg_path_buf))

		local cfg_str_buf = luagit2.config_get_string_buf(Config_Snapshot,"user.name")
		assert.are.same("TEST_USER",luagit2.buf_details(cfg_str_buf))
	end)

	it("Tests Config open level ",function()
		--
		-- We need a parent Config to access
		-- the different level Configurations
		-- We are using Config_Default and Config_ondisk 
		-- as the parent_Configs as suitable in the taken
		-- Cases.
		--
		-- Check for open level system
		--
		----------------------------------------------------------------------------------
		local cfg_lvl_sys = luagit2.config_level_system()
		local sys_lvl_cfg = luagit2.config_open_level(Config_Default,cfg_lvl_sys)
		Config_Snapshot = luagit2.config_snapshot(sys_lvl_cfg)
		
		local name = luagit2.config_get_string(Config_Snapshot,"user.name")
		local email = luagit2.config_get_string(Config_Snapshot,"user.email")

		assert.are.equal(sys_name,name .. "\n")
		assert.are.equal(sys_email,email .. "\n")

		luagit2.config_free(Config_Snapshot)

		-----------------------------------------------------------------------------------
		--
		-- Check for open level global
		--
		-----------------------------------------------------------------------------------
		local cfg_lvl_global = luagit2.config_level_global()
		local global_lvl_cfg = luagit2.config_open_level(Config_Default,cfg_lvl_global)
		Config_Snapshot = luagit2.config_snapshot(global_lvl_cfg)

		name = luagit2.config_get_string(Config_Snapshot,"user.name")
		email = luagit2.config_get_string(Config_Snapshot,"user.email")

		assert.are.equal(global_name,name .. "\n")
		assert.are.equal(global_email,email .. "\n")
		
		luagit2.config_free(Config_Snapshot)

		-----------------------------------------------------------------------------------
		--
		-- 
		-- 
		local cfg_lvl_local = luagit2.config_level_local()
		local local_lvl_cfg = luagit2.config_open_level(Config_ondisk,cfg_lvl_local)
		Config_Snapshot = luagit2.config_snapshot(local_lvl_cfg)

		name = luagit2.config_get_string(Config_Snapshot,"user.name")
		email = luagit2.config_get_string(Config_Snapshot,"user.email")

		assert.are.equal("TEST_USER",name)
		assert.are.equal("testusernoreply@github.com",email)
		
		luagit2.config_free(Config_Snapshot)

		------------------------------------------------------------------------------------
		--
		-- To test for program_data & xdg level on Windows platform
		--
		------------------------------------------------------------------------------------
		local cfg_lvl_program_data = luagit2.config_level_program_data()
		local cfg_lvl_xdg = luagit2.config_level_xdg()
	end)

	it("Tests Varioud Parse Methods",function()
		local parse_bool = luagit2.config_parse_bool("true")
		assert.are.equal(1,parse_bool)
		parse_bool = luagit2.config_parse_bool("yes")
		assert.are.equal(1,parse_bool)
		parse_bool = luagit2.config_parse_bool("on")
		assert.are.equal(1,parse_bool)

		local parse_int32 = luagit2.config_parse_int64("32")
		assert.are.equal(32,parse_int32)

		local parse_int64 = luagit2.config_parse_int64("999988892")
		assert.are.equal(999988892,parse_int64)

		local parse_path = luagit2.config_parse_path("abc/def/ghi")
		assert.are.equal("abc/def/ghi",luagit2.buf_details(parse_path))
	end)

	it("Tests Deleting Config Variables",function()
		--
		-- Delete a variable
		--
		luagit2.config_delete_entry(Config_ondisk,"user.name")
		luagit2.config_delete_entry(Config_ondisk,"user.email")

		-- Lets check for the deleted variable
		Config_Snapshot = luagit2.config_snapshot(Config_ondisk)
		local name = luagit2.config_get_string(Config_Snapshot,"user.name")
		local email = luagit2.config_get_string(Config_Snapshot,"user.email")
		assert.is_nil(name)
		assert.is_nil(email)
	end)

	it("Tests adding a new Config on disk",function()
		--
		-- Create a local new Config
		--
		local new_cfg = luagit2.config_new()
		-- Add the config to an EXISTING FILE
		local cfg_lvl_local = luagit2.config_level_local()
		luagit2.config_add_file_ondisk(new_cfg,"Fixtures/WORKON_REPO/abc.txt",
										cfg_lvl_local,repo,1)
		-- Set a variable
		luagit2.config_set_string(new_cfg,"user.name","New_config_user")
		-- Get a snapshot 
		Config_Snapshot = luagit2.config_snapshot(new_cfg)
		-- Check for the variable
		local name = luagit2.config_get_string(Config_Snapshot,"user.name")
		assert.are.same("New_config_user",name)
		-- Free used Config's
		luagit2.config_free(new_cfg)
		luagit2.config_free(Config_Snapshot)

		--
		-- Lets Open the file using config_ondisk to see
		-- If the values are actually written or not.
		--
		local new_cfg_ondisk =  luagit2.config_open_ondisk(current_directory_path .. "/Fixtures/WORKON_REPO/abc.txt")
		Config_Snapshot = luagit2.config_snapshot(new_cfg_ondisk)
		-- Check for the variable
		local name = luagit2.config_get_string(Config_Snapshot,"user.name")
		assert.are.same("New_config_user",name)
		-- Free used Config's
		luagit2.config_free(new_cfg_ondisk)
		luagit2.config_free(Config_Snapshot)
	end)

	it("Tests config next",function()
		local cfg_iterator = luagit2.config_iterator_new(Config_ondisk)
		local cfg_entry = luagit2.config_next(cfg_iterator)

		local first_entry_name = luagit2.config_entry_name(cfg_entry)
		-- Check that this entry exists
		assert.is_not_nil(luagit2.config_get_string(Config_ondisk,first_entry_name))

		local second_entry_name = luagit2.config_entry_name(cfg_entry)
		-- Check that this entry exists
		assert.is_not_nil(luagit2.config_get_string(Config_ondisk,second_entry_name))

		-- Free up used objects
		luagit2.config_iterator_free(cfg_iterator)
	end)

	it("Tests config get entry",function()
		-- Open a  config entry
		local cfg_entry = luagit2.config_get_entry(Config_ondisk,"user.name")
		-- Check the value
		assert.are.equal("TEST_USER",luagit2.config_entry_value(cfg_entry))

	end)
end)

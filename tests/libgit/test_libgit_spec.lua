describe("busted", function()
  local lib , MWINDOW_SIZE , MWINDOW_MAPPED_LIMIT

  setup(function()
    lib = require("luagit2")
    lib.luagit2_init()
  end)

  teardown(function()
    lib.luagit2_shutdown()
  end)

  before_each(function()
    MWINDOW_SIZE = lib.luagit2_SET_MWINDOW_SIZE(1234)
    MWINDOW_MAPPED_LIMIT = lib.luagit2_SET_MWINDOW_MAPPED_LIMIT(1234)
  end)

  it("Prints libgit2 version",function ()
    version_data = lib.luagit2_version()
    assert.are.same("userdata",type(version_data))
    print(" \n   Major Version Number is : " .. lib.luagit2_print_version_data(version_data, 1))

    print("   Minor Version Number is : " .. lib.luagit2_print_version_data(version_data, 2))

    print("   Revision Version Number is : " .. lib.luagit2_print_version_data(version_data, 3) .. "\n")

  end)

  it("Tests setting and getting MWINDOW_SIZE ", function ()
    -- Tests luagit2_GET_MWINDOW_SIZE()
    old_val_MWINDOW_SIZE  = MWINDOW_SIZE
    assert.is.equal(1234,old_val_MWINDOW_SIZE)

    -- Tests luagit2_SET_MWINDOW_SIZE()
    lib.luagit2_SET_MWINDOW_SIZE(4321)
    new_val_MWINDOW_SIZE = lib.luagit2_GET_MWINDOW_SIZE()
    assert.is.equal(4321,new_val_MWINDOW_SIZE)
  end)

  it("Tests setting and getting MWINDOW_MAPPED_LIMIT ", function ()
    -- Tests luagit2_GET_MWINDOW_MAPPED_LIMIT()
    old_val_MWINDOW_MAPPED_LIMIT  = MWINDOW_MAPPED_LIMIT
    assert.is.equal(1234,old_val_MWINDOW_MAPPED_LIMIT)

    -- Tests luagit2_SET_MWINDOW_MAPPED_LIMIT()
    lib.luagit2_SET_MWINDOW_MAPPED_LIMIT(4321)
    new_val_MWINDOW_MAPPED_LIMIT = lib.luagit2_GET_MWINDOW_MAPPED_LIMIT()
    assert.is.equal(4321,new_val_MWINDOW_MAPPED_LIMIT)
  end)

end)

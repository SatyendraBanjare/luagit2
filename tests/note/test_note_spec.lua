-- Luagit2's Note Module Tests

local fixer = require("Fixtures.fix_repo")

describe(" Note Methods Tests ", function()
    local luagit2 = require("luagit2")
    local repo_path = "Fixtures/WORKON_REPO"
    local tree_oid_string = "619f9935957e010c419cb9d15621916ddfcc0b96"
    local readme_oid_string = "1385f264afb75a56a5bec74243be9b367ba4ca08"
    local tree_oid, tree, readme_oid
    local current_directory_path = lfs.currentdir()
    
    setup(function()
        luagit2.init()
    end)
    
    before_each(function()
        fixer.set_repo("new_test_repo")
        repo = luagit2.repository_open(repo_path)
        tree_oid = luagit2.oid_fromstr(tree_oid_string)
        readme_oid = luagit2.oid_fromstr(readme_oid_string)
        tree = luagit2.tree_lookup(repo, tree_oid)
    end)
    
    after_each(function()
        luagit2.tree_free(tree)
        luagit2.repository_free(repo)
        fixer.set_back()
    end)
    
    teardown(function()
        luagit2.shutdown()
    end)

    -- Currently our repository has no notes available
    -- for any of the objects to directly test out the functions.
    -- Thus we will create some example notes and tests accordingly &
    -- asserting values to match.

    it(" Tests notes functions after creating using note create",function()
        -- This way of note creation won't make any extra commit.
        --
        -- create params
        local sign_default = luagit2.signature_default(repo)
        local blob_id_str = "1385f264afb75a56a5bec74243be9b367ba4ca08"
        local target_obj_id = luagit2.oid_fromstr(blob_id_str)
        -- Create a Note.
        local note_oid = luagit2.note_create(repo,"refs/notes",sign_default,
            sign_default,target_obj_id,"Example note creation message",1)

        -- Read the note
        local created_note = luagit2.note_read(repo,"refs/notes",target_obj_id)

        -- Check for the authors and committers.
        local note_author = luagit2.note_author(created_note)
        local note_committer = luagit2.note_committer(created_note)

        local def_name, def_email = luagit2.get_signature_details(sign_default)
        local author_name, author_email = luagit2.get_signature_details(note_author)
        local committer_name, committer_email = luagit2.get_signature_details(note_committer) 
        -- Check for the params to match.
        assert.are.equal(def_name,author_name)
        assert.are.equal(def_email,author_email)
        assert.are.equal(def_name,committer_name)
        assert.are.equal(def_email,committer_email)

        -- Check for the message ot match
        local message = luagit2.note_message(created_note)
        assert.are.equal("Example note creation message",message)

        -- Check for the created note id.
        local id = luagit2.note_id(created_note)
        assert.are.equal(0,luagit2.oid_cmp(note_oid,id))

        -- free the used note.
        luagit2.note_free(created_note)

        -- Lets try removing the note.
        luagit2.note_remove(repo,"refs/notes",sign_default,
            sign_default,target_obj_id)        

    end)

    it(" Tests notes functions after creating using note commit create",function()
        -- This way of note creation will create extra commit.
        --
        -- create params
        local sign_default = luagit2.signature_default(repo)

        local blob_id_str = "1385f264afb75a56a5bec74243be9b367ba4ca08"
        local target_obj_id = luagit2.oid_fromstr(blob_id_str)

        local latest_commit_str = "108ddee361877aa5c044d89d8dd232b8fd0f8992"
        local commit_id = luagit2.oid_fromstr(latest_commit_str)
        local commit = luagit2.commit_lookup(repo,commit_id)

        -- Create a Note.
        local note_commit_oid = luagit2.note_commit_create(repo,commit,sign_default,
            sign_default,target_obj_id,"Example note creation message",1)
        local note_commit = luagit2.commit_lookup(repo,note_commit_oid)

        -- Read the note
        local created_note = luagit2.note_commit_read(repo,note_commit,target_obj_id)

        -- Check for the authors and committers.
        local note_author = luagit2.note_author(created_note)
        local note_committer = luagit2.note_committer(created_note)

        local def_name, def_email = luagit2.get_signature_details(sign_default)
        local author_name, author_email = luagit2.get_signature_details(note_author)
        local committer_name, committer_email = luagit2.get_signature_details(note_committer) 
        -- Check for the params to match.
        assert.are.equal(def_name,author_name)
        assert.are.equal(def_email,author_email)
        assert.are.equal(def_name,committer_name)
        assert.are.equal(def_email,committer_email)

        -- Check for the message ot match
        local message = luagit2.note_message(created_note)
        assert.are.equal("Example note creation message",message)

        -- free the used note and commit objects.
        luagit2.note_free(created_note)
        luagit2.commit_free(commit)

        -- Lets try removing commit note
        luagit2.note_commit_remove(repo,note_commit,sign_default,
            sign_default,target_obj_id)
        
        luagit2.commit_free(note_commit)
    end)
end)
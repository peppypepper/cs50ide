

//some git commands

//git clone <url>
    //make a copy of a repository
    //stores it on your computer
    //a "fork" creates your own copy of someone's else repository

//git add
    //adds a file to "staging area"
    //tells git to include the file in the next revision of the repository
    //git add *   adds all changed files

//git commit -m "message"
    //saves the changes to repository as a new revision (a "commit")
    //git commit -am "message"  will adds and commits changed files in same step

//git status
    //shows current status

//git push
    //sends committed changes to remote repository
    //optional, explicitly, git push origin master, would push your file to master branch

//git pull
    //retrives changes from remote repo

//git log
    //shows history of commits and messages

//git reset
    //you will lose all your current work
    //git reset --hard <commit hash number>, reverts code back to a previous commit
    //git reset --hard origin/master, reverts code back to remote repository version

//git branch
    //works on new stuff or testing
    //branch is a version of the repository
    //each branch has its own commit history and current version
    //shows all branches of code
    //git branch <branch_name>, creates a new branch

//git branch -D <branch_name>
    //delete a branch

//git checkout <branch_name>
    //switch you to that branch
    //git checkout -b <branch_name>, will create a new branch and switch you to it

//git merge
    //git merge <branch_name> merges the branch_name branch with current branch you're on

//merge conflicts
    //need to resolve two different commits that can't be automatically merged

//pull requests
    //example, working on an open source project, you made some changes and would like to
    //push it to the master branch. You would "pull request" the admins of that project, so
    //that person can pull your codes. The admin can then review your code, decide to accept
    //or reject your request.





















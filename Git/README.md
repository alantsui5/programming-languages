# Github cheatsheet and reminder

_Applicable for Windows Powershell and macOS, Linux, Unix bash shell._

1. Generate the ssh key(powershell, bash)
```bash
ssh-keygen -t rsa -b 4096 -C "username@example"
```

2. Confirm that you have generated the SSH key correctly
```bash
cat ~/.ssh/id_rsa.pub
```

3. Go to these SSH pages in VCS service Website
* For Github
    > https://github.com/settings/keys
* For Gitlab
    > https://gitlab.com/profile/keys

4. Paste the key generated (start from `ssh-rsa`) to __Key__ input block in both website

5. Run these git commands inside the working directory
```bash
git init

# Or use other VCS software for this
git config --global user.name "FIRST_NAME LAST_NAME"
git config --global user.email "MY_NAME@example.com"
git add *
git commit -m "Commit message"
# End of this block

git remote add origin "link of the repo"
git push --set-upstream origin master
```

6. Manipulate remote origin URLS
```sh
git remote set-url origin --push --add user1@repo1
git remote set-url origin --push --add user2@repo2
git remote -v

# Change fetch URL
git remote set-url origin git@repo3

# Delete push URL
git remote set-url origin --push --delete git@repo4

# Change URL
git remote set-url origin --push --delete git@repo_new git@repo_old
```
7. Add embedded repo in father repo
   ```sh
   git add test2/ #For folder
   git add test2 # For submodule
   ```
8. Check Files which are unstaged
   ```sh
   git status
   ```
9. Get changed from Github/Gitlab
    ```sh
    git pull
    ```

10. Git Flow Chart
![git-model](git-model.png)
11. You are done with git!!
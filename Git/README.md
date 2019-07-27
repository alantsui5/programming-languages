# Github cheatsheet and reminder

_Applicable for Windows Powershell and macOS, Linux, Unix bash shell._

### 1. Generate the ssh key(powershell, bash)
```bash
ssh-keygen -t rsa -b 4096 -C "username@example"
```

### 2. Confirm that you have generated the SSH key correctly
```bash
cat ~/.ssh/id_rsa.pub
```

### 3. Go to these SSH pages in VCS service Website
* For Github
    > https://github.com/settings/keys
* For Gitlab
    > https://gitlab.com/profile/keys

### 4. Paste the key generated (start from `ssh-rsa`) to __Key__ input block in both website

### 5. Run these git commands inside the working directory
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

### 6. You are done with git!!
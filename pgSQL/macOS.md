#pgSQL installation reminder(macOS)

```sh
brew install postgresql
brew services stop postgresql
brew services start postgresql

# Setup Psql for your account, with db 'your_username' created
createuser 'username'

#create DB with postgres
createdb 'db_name'

#delete user/ database
dropuser 'username'
dropdb 'username'

#Add user with pw when using TCP-IP Socket
createuser 'username' -P
```
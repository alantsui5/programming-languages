#pgSQL installation reminder(Ubuntu 18.04)

1. Setup pgSQL after install
```sh
# Setup Psql for your account, with db 'your_username' created
sudo -u postgres createuser 'username'

#create DB with postgres
sudo -u postgres createdb 'db_name'

#delete user/ database
sudo -u postgres dropuser 'username'
sudo -u postgres dropdb 'username'

#Add user with pw when using TCP-IP Socket
sudo -u postgres createuser 'username' -P
```


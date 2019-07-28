echo "Installing nginx"
sudo apt-get update; sudo apt upgrade
sudo apt install nginx
systemctl start nginx
systemctl enable nginx
systemctl status nginx

echo "Installing pgsql and php"
sudo apt install postgresql postgresql-contrib
systemctl status postgresql.service
sudo apt-get install php-fpm php-pgsql

echo "Setting up pgsql"
sudo -u postgres createuser alan
sudo -u postgres createdb alan
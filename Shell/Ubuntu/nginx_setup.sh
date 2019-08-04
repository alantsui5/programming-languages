sudo cat nginx_localhost.config > /etc/nginx/sites-available/localhost.conf
ln -s /etc/nginx/sites-available/localhost.conf /etc/nginx/sites-enabled/localhost.conf
nginx -t
service nginx reload
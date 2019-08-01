

# LEPP (linux nginx postgresql php) configuration for Ubuntu
_These setups below is applicable to Ubuntu 18.04 LTS desktop_

1. Run `lepp_install.sh` first
2. Setup nginx with `nginx_setup.sh` and `nginx_localhost.config`
3. Test php with `nano /var/www/html/info.php`
   <br />
4.  ```php
       <?php
        phpinfo();
       ?>
    ```
5. `systemctl restart nginx` when  php file changed
6. To set up Postgresql, please read [pgSQL mannual](../../pgSQL)
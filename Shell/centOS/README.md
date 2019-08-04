# No Mouse integration, change pointing device to USB tablet

# root Password: hk37215566
# user password: wb37215566

# tmpfs = system in ram

#Install htop repo and htop
yum -y install epel-release
yum -y update
yum -y install htop

#Scrolling
fn+shift+uparrow/downarrow
#Netstat
yum whatprovides netstat
yum install net-tools
netstat -a
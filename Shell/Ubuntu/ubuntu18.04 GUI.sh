#Install VIA apt(CMD)LINE
sudo apt update
sudo apt upgrade
sudo apt install curl wget python python3-pip ffmpeg axel

# Server application
sudo apt install postgresql postgresql-contrib docker.io sqlite nodejs 

# Install youtube-dl
sudo pip3 install --upgrade pip
sudo pip3 install --upgrade youtube_dl
sudo pip3 install pillow scipy scikit-image requests pylint opencv-python

# Install Via apt(GUI)
sudo apt update
sudo apt upgrade
sudo apt install gnome-tweak-tool chrome-gnome-shell gnome-shell-extensions
sudo apt install nvidia-driver-390

# Virt manager
sudo apt install virt-manager
newgrp libvirt

# Power saver
sudo apt update 
sudo apt install linux-tools-generic linux-tools-common
sudo apt install linux-tools-4.18.0-25-generic
# Usage :https://wiki.debian.org/HowTo/CpuFrequencyScaling


# Ubuntu community theme
sudo add-apt-repository ppa:communitheme/ppa
sudo apt update
sudo apt install ubuntu-communitheme-session

#Install GUI apps
snap install visual-studio-code evolution
snap install typora
snap install  gnome-mpv gimp blender


# Brew
sh -c "$(curl -fsSL https://raw.githubusercontent.com/Linuxbrew/install/master/install.sh)"
test -d ~/.linuxbrew && eval $(~/.linuxbrew/bin/brew shellenv)
test -d /home/linuxbrew/.linuxbrew && eval $(/home/linuxbrew/.linuxbrew/bin/brew shellenv)
test -r ~/.bash_profile && echo "eval \$($(brew --prefix)/bin/brew shellenv)" >>~/.bash_profile
echo "eval \$($(brew --prefix)/bin/brew shellenv)" >>~/.profile

# Install bat
brew update
brew upgrade
brew install bat

# Lollypop
sudo add-apt-repository ppa:gnumdk/lollypop
sudo apt-get update
sudo apt-get install lollypop

# Install V language
git clone https://github.com/vlang/v
cd v
make
sudo ln -s ~/Documents/Github/Project/v/v /usr/local/bin/v
sudo apt update
sudo apt upgrade
sudo apt install sudo apt install libglfw3 libglfw3-dev libfreetype6-dev libcurl3-dev 

#install chrome
wget -q -O - https://dl-ssl.google.com/linux/linux_signing_key.pub | sudo apt-key add -
echo 'deb [arch=amd64] http://dl.google.com/linux/chrome/deb/ stable main' | sudo tee /etc/apt/sources.list.d/google-chrome.list
sudo apt-get update 
sudo apt-get install google-chrome-stable

#Install Rust
curl https://sh.rustup.rs -sSf | sh
source $HOME/.cargo/env
echo $(cat ~/.profile | tail -1) >> ~/.bashrc
source ~/.bashrc
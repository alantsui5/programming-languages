# Edit this configuration file to define what should be installed on
# your system.  Help is available in the configuration.nix(5) man page
# and in the NixOS manual (accessible by running ‘nixos-help’).

{ config, pkgs, ... }:

{
  imports =
    [ # Include the results of the hardware scan.
      ./hardware-configuration.nix
    ];

  # Use the systemd-boot EFI boot loader.
  boot.loader.systemd-boot.enable = true;
  boot.loader.efi.canTouchEfiVariables = true;

  networking.hostName = "nixos"; # Define your hostname.
  networking.wireless.enable = true;  # Enables wireless support via wpa_supplicant.
  

  # Configure network proxy if necessary
  # networking.proxy.default = "http://user:password@proxy:port/";
   networking.proxy.noProxy = "127.0.0.1,localhost,internal.domain";

  # Select internationalisation properties.
  i18n = {
    consoleFont = "Lat2-Terminus16";
    consoleKeyMap = "us";
    defaultLocale = "en_US.UTF-8";
   };

  # Set your time zone.
  time.timeZone = "Asia/Hong_Kong";

  # List packages installed in system profile. To search, run:
  # $ nix search wget
    nixpkgs.config.allowUnfree=true;
    environment.systemPackages = with pkgs; [
         # Languages 
         python3 ruby
         # System Util
         wget vim exa bat nox git neofetch aria2 axel
         # Localization
         fcitx fcitx-configtool 
         # Applications
         firefox flatpak sublime3 youtube-dl
         latte-dock okular lollypop gparted mpv
    ];

    fonts = {
    	fontconfig.enable=true;
    	enableFontDir = true;
    	enableGhostscriptFonts=true;
    	fonts = with pkgs; [
    	noto-fonts noto-fonts-cjk noto-fonts-emoji
    	wqy_microhei wqy_zenhei ];	
      
    };

  # Some programs need SUID wrappers, can be configured further or are
  # started in user sessions.
    programs.mtr.enable = true;
    programs.gnupg.agent = { enable = true; enableSSHSupport = true; };

  # List services that you want to enable:

  # Enable the OpenSSH daemon.
  # services.openssh.enable = true;

  # Open ports in the firewall.
  # networking.firewall.allowedTCPPorts = [ ... ];
  # networking.firewall.allowedUDPPorts = [ ... ];
  # Or disable the firewall altogether.
  # networking.firewall.enable = false;

  # Enable CUPS to print documents.
  # services.printing.enable = true;

  # Enable sound.
   sound.enable = true;
   hardware.pulseaudio.enable = true;

  # Enable the X11 windowing system.
   services.xserver.enable = true;
   services.xserver.layout = "us";
   services.xserver.xkbOptions = "eurosign:e";

  # Enable touchpad support.
  # services.xserver.libinput.enable = true;

  # Enable the KDE Desktop Environment.
   services.xserver.displayManager.sddm.enable = true;
   services.xserver.desktopManager.plasma5.enable = true;
  # services.xserver.desktopManager.pantheon.enable = true;

  # Define a user account. Don't forget to set a password with ‘passwd’.
   users.users.alam = {
     isNormalUser = true;
     extraGroups = [ "wheel" ]; # Enable ‘sudo’ for the user.
   };

  # This value determines the NixOS release with which your system is to be
  # compatible, in order to avoid breaking some software such as database
  # servers. You should change this only after NixOS release notes say you
  # should.
  system.stateVersion = "19.03"; # Did you read the comment?

}

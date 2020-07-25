# FOMOSv1-Yellow
FOMOS is a UI replacement for Linux but hopefully one day it will become it's own OS.
FOMOS stands for: Free, Open source, Mobile, Operating, System
#

# About
FOMOS is made with ElectronJs, ElectronJs is good for making a UI with HTML and JS.
Since this is for Linux it should run on Linux based devices like Android devices.
#

# Setup
These are all Linux commands and won't work on other Operating Systems.
```shell script
sh installRequirments.sh
sh runFOMOS.sh
```

#

To make Wifi commands work:
```shell script
sudo visudo
```

In that file type:
```shell script
your user name  ALL=(ALL) NOPASSWD: ALL
```

If there is anything that resets the sudo password regularly delete it.

This will make Wifi (nmcli) and local ssid's work without exiting FOMOS and typing in the terminal your password.
This also makes you device very insecure so you can change this to only work with commands that FOMOS runs.

#

To run on startup:
```shell script
chmod +x /etc/init.d/runFOMOS.sh
ln -s /etc/init.d/runFOMOS.sh /etc/rc.d/
```

Not sure if this works but it will soon if it doesn't.

#
# Website
[https://sbfomos.org/](https://sbfomos.org/)

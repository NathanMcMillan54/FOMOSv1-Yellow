# FOMOSv1-Yellow
FOMOS is a GUI replacement for Linux but hopefully one day it will become it's own OS.
FOMOS stands for: Free, Open source, Mobile, Operating, System
#

# About
FOMOS is made with ElectronJs, ElectronJs is good for making a UI with HTML and JS.
Since this is for Linux it should run on Linux based devices like Android devices.
#

# Setup
This only works on Linux and won't work on another OS.
Please read this very carefully, especially where it talks about running FOMOS on startup.
```shell script
sh installRequirements.sh
sh runFOMOS.sh
```

#

All these changes will apply to other users on you computer.
To make Wifi commands work:
```shell script
sudo visudo
```

In that file put at the very bottom:
```shell script
yourUserName  ALL = NOPASSWD: ALL
```

Delete this:
(It should be at the top of the visudo file)
```shell script
Defualts  env_reset
```

This will make Wifi (nmcli) and local ssid's work without exiting FOMOS and typing in the terminal your password.
This also makes you device very insecure so you can change this to only work with commands that FOMOS runs.

#

Just so you know now before you replace the Linux UI, you ARE replacing the Linux UI so you can't really do anything after these next steps.

To run on startup:
```shell script
cd /etc/profile.d/
sudo touch strtFOMOS.sh
sudo nano strtFOMOS.sh
```

This makes a file called strtFOMOS.sh in /etc/profile.d/ which runs scripts at login.

```shell script
#!/usr/bin/env bash
cd home/yourUserName/Desktop/FOMOSv1-Yellow/
sh runFOMOS.sh
```

#

To update FOMOS go into settings in the software section. Click the update button then restart your device. There might be problems if you have already made changes to FOMOS and you try to update.

#
# Website
[https://sbfomos.org/](https://sbfomos.org/)

# FOMOSv1-Yellow


FOMOSv1-Yellow is an opensource GUI replacement for Linux made with C GTK.

FOMOS stand for: Free, Opensource, Mobile, Operating, System

One day FOMSO will become it's own operating system but for now it'll just be a GUI replacement.
#
# About
FOMOS is made with C GTK which is a C library used for make GUIs. Since FOMOS is opensource you can make it do whatever 
you want with it or make it easier to use. You can contribute to FOMOS by making forks and pull requests on Github.

#
# Setup

To start FOMOS run
```shell script
sh startFOMOS.sh
```

This will run a C file that compiles all FOMOS files and then runs FOMOSUI.c.

To setup FOMOS run
```shell script
sh setupFOMOS.sh
```

That file will move ```startFOMOS.sh``` to a place where it can make FOMOS run on startup.

#
If that doesn't work you'll have to manually add ```startFOMOS.sh``` to ```/ete/profile.d``` with a startup command for FOMOS.

#
# For developers

You can do whatever you want with FOMOSv1-Yellow but if you are adding stuff to it's Github repository run this after you're done:

```shell script
sh deleteCompiledFiles.sh
```

This will delete any compiled file so you don't have to delete them manually, also compiled files shouldn't be in the repository.


In credits.txt it will show files that were copied from other people and where to find the original code.

#!/usr/bin/env bash

xterm -hold -e "sh osShellScripts/diskUsage.sh"
xterm -hold -e "sh osShellScripts/ramUsage.sh"
xterm -hold -e "sh osShellScripts/cpuUsage.sh"

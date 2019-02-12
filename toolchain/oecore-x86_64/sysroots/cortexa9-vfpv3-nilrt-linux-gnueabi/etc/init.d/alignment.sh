#!/bin/sh
### BEGIN INIT INFO
# Provides: alignment
# Required-Start:    mountkernfs
# Required-Stop:     mountkernfs
# Default-Start:     S
# Default-Stop:
### END INIT INFO

if [ -e /proc/cpu/alignment ]; then
   echo "5" > /proc/cpu/alignment
fi


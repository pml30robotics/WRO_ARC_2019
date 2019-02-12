#!/bin/sh
#
# hostname.sh   Set hostname.
#
# Version:      @(#)hostname.sh  1.10  26-Feb-2001  miquels@cistron.nl
#

if [ -f /etc/hostname ] && [ -r /etc/hostname ];then
    HOSTNAME=$(cat /etc/hostname)
else
    HOSTNAME=
fi

if [ $? -eq 0 ] && [ -n "$HOSTNAME" ]; then
    hostname "$HOSTNAME"
else
    # Generate a default hostname based on the serial# or MAC address
    MODEL=$((/sbin/fw_printenv -n DeviceDesc 2> /dev/null || echo PXI-Unknown) | sed "s/^NI //;s/ Embedded Controller//")

    # Only use the last 8 characters of the serial number (after spaces are stripped)
    SERIAL=$(/sbin/fw_printenv -n serial# 2>&1 | tr -d "\n " | tail -c 8)

    echo "NI-$MODEL-$SERIAL" | sed -r -e 's/[^a-zA-Z0-9]+/-/g' -e 's/^-//' | xargs hostname

    # Set the newly generated hostname in /etc/hostname
    hostname > /etc/hostname
fi

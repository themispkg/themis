#!/bin/bash

. /usr/local/lib/bash/5.17/themis/core.sh || { echo -e "\033[0;31mFatal:\033[0m Could not sourcing 'core'" ; exit 1 ; }

. themis:core:getlib "colorsh" "tuiutils" "alternatives" "osutils"
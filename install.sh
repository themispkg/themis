#!/bin/bash

# Install script for themispkg created manually.
# Pre-Req: gawk, GNUcore-utils, git, gcc.
#
# Builded structures:
# 		directories:
#				/usr/share/themis
#				/usr/share/themis/openssl
#				/usr/share/themis/repositories
#				/etc/themis
#				/usr/local/lib/bash/5.17
#				/usr/local/lib/bash/5.17/themis
#		specific files:
#				/etc/bash_completion.d/themis.sh
#				/etc/themis/repositories.baml
#				/usr/share/themis/packages.db
#				/usr/bin/themis

export cwd="${PWD}"

[[ "${UID}" != 0 ]] && { echo "Run this with root privalages!" ; exit 1 ;}

die() {
	echo "${1}"
	exit "${2}"
}

check() {
	echo -n "checking for '${1}'.. "
	command -v "${1}" &> /dev/null && echo "ok" || die "no" "$?"
}

# it does not cover the dependencies of dependencies
check git
check tar
check gcc
check install
check awk
check chmod
check chown
check cp
check ln
check ls
check mkdir
check mv
check rm
check rmdir
check touch
check basename
check cat
check comm
check cut
check dirname
check echo
check expand
check false
check true
check head
check seq
check sort
check tail
check tee
check tr
check uniq
check wc
check env
check date

# if you can't pass this stage then try to install 'Pre-Reqs'.

echo "building baml.."
cp ./lib/baml.h ./src/baml/baml.h
gcc ./src/baml/main.c ./src/baml/baml.c -o ./src/baml/baml

echo "creating directories.."
mkdir -p "/etc/themis" "/usr/share/themis/repositories" "/usr/share/themis/openssl" "/usr/local/lib/bash/5.17/themis"

echo "Installing bash libraries"

git clone "https://github.com/themispkg/bash-utils"
cd "bash-utils"
make install || die "could not getting 'bash-utils'" "$?"
cd "${cwd}"

git clone "https://github.com/themispkg/bashtextbank"
cd "bashtextbank"
make install || die "could not getting 'bashtextbank'" "$?"
cd "${cwd}"

# Sqlite3
if ! command -v sqlite3 &> /dev/null ; then
	:
fi

# OpenSSL
if ! command -v openssl &> /dev/null ; then
	:
fi

# Yap
if ! command -v yap &> /dev/null ; then
	:
fi
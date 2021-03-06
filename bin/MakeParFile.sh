#!/bin/bash

####################################################################
#     FILE: MakeParFile.sh
# AUTHORS: I. Gonzalez Caballero, A.Y. Rodriguez Marrero
#    DATE: 2010
#
# CONTENT: Makes .par files for a given package 
#          Use MakeParFile.sh -help for more information
####################################################################


####################################################################
# Default values of some variables
silent=0
setup=1
debugoutput=0
isremote=0
basepath="."

####################################################################
# Print some information on how to use this script
usage() {
    cat << EOF
`basename $0`: This script creates the .par file for a given package. Par 
                files used by PROOF to transfer the code to the slaves.

SYNTAX: 
  `basename $0` [--help] [-s|--silent] [-n|--nosetup] [-r|--remote path] packagename

OPTIONS:
  -h, --help
       Shows this help

  -s, --silent
       Do not print output (by default it is printed)

  XXX: WHAT?
  -n, --nosetup
       Do not try to create PROOF-INF/SETUP.C file. By default it will be
       created if it is not found.

  -v, --verbose
       Include debug output when making the packages

  -r, --remote path
       Get package from specified path

  -d, --dest path
       Create packages at specified path (default: .)

  packagename
       The name of the package. It is mandatory

EOF
}

######################################################################
# Helper functions to show information and errors
myecho() {
    if [ $silent -eq 0 ]; then
	echo "PAF [I] $*"
    fi
}

myerror() {
    echo -e -n "\033[1;31mPAF [E] " $* 1>&2
    echo -e "\033[0m" 1>&2
}

######################################################################
# Create the par file in $1 for package $3 which is located in $2
createparfile() {
    myecho ">> Creating $parpackagename for package in $basepath..."

    if [ ! -d $destpath/PROOF-INF -o ! -e $destpath/PROOF-INF/SETUP.C ] ; then
	    myerror "Could not find PROOF package files"
    	myerror "$packagedir is not a PROOF package. Exiting!"
    fi

    if [ -f $basepath/$parpackagename ]; then
        if [ $silent -ne 0 ]; then
            myecho "Moving $basepath/$parpackagename to $basepath/$parpackagename.bak"
        fi
        mv $basepath/$parpackagename $basepath/$parpackagename.bak
    fi

    verbose=""
    if [ $debugoutput -ne 0 ] ; then
        verbose="-v"
    fi
    # XXX Be aware of any missing files in this list (--exclude CVS does not work on Mac)
    tar $verbose -c -z -f $basepath/$parpackagename -C $basepath $packagename
}

######################################################################
# Process command line
if [ -z $1 ]; then
    usage
    exit
fi

while [ "$1" != "" ]; do
    case $1 in
        -s | --silent )
            silent=1
            ;;
        -v|--verbose)
            debugoutput=1
            ;;
        -d|--dest)
            shift
            basepath=$1
            ;;
        -h | --help )
            usage
            exit
            ;;
        * )
            packagename=$1
    esac
    shift
done


parpackagename=$packagename.par
origppath=packages/$packagename
packagelibname=$packagename

myecho "Silent = $silent"
myecho "Setup = $setup"
myecho "Debug = $debugoutput"
myecho "Package Name = $packagename"
myecho "Package Par file = $parpackagename"
myecho "Package orig = $packagedir"
myecho "Package dest = $basepath"

destpath=$basepath/$packagename

createparfile $basepath $parpackagename
sync

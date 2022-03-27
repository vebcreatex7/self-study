#! /bin/bash

if [[ $# -ne 2 ]]
then
	echo "not enough args"
else
	case $1 in
		1)
		touch $2
		;;
		2)
		mkdir $2
		;;
		*)
		echo "wrong code"
	esac
fi


#! /bin/bash

if [[ $# -ne 1 ]]
then
	echo "not enough args"
elif [[ -d $1 ]]
then
	rm -r $1
elif [[ -f $1 ]]
then
	rm $1
else
	echo "wrong file"
fi


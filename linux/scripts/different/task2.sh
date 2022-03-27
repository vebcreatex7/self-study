#! /bin/bash

GCD() {
	if [[ $2 -eq 0 ]]; then
		return $1
	else
		GCD $2 $(( $1 % $2 ))
	fi	

}

while true; do
	read a1 a2
	if [[ (a1 -eq 0) && (a2 -eq 0) ]]; then
		echo "bye"
		break
	else
		GCD $a1 $a2
		echo "GCD is $?"
	fi
done


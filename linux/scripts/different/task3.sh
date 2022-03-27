#! /bin/bash

calc() {
	case "${2}" in
		"+")
			echo $(( $1 + $3 ))
			return 0
			;;
		"-")
			echo $(( $1 - $3 ))
			return 0
			;;
		"*")
			echo $(( $1 * $3 ))
			return 0
			;;
       		 "/")
            		echo $(( $1 / $3 ))
			return 0
            		;;
        	"%")
            		echo $(( $1 % $3 ))
			return 0
            		;;
		"**")
			echo $(( $1 ** $3 ))
			return 0
			;;
		*)
			echo "error"
			return 1
			;;
	esac
}	

while true; do
	read n1 o n2
	if [[ $n1 = "exit" ]]; then
		echo "bye"
		break
	fi

	if [[ (-z $n1) || (-z  $o) || (-z $n2) ]]; then
		echo "error"
		break
	fi
	calc "${n1}" "${o}" "${n2}"
	if [[ $? -eq 1 ]]; then
		break
	fi
done

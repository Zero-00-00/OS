#!/bin/bash

fact()
{
	f=1
	i=1
	if [ $1 -le 1 ] 
	then
		f = 1
	else

		while [ $i -le $1 ]
		do
			f=`expr $i \* $f`
			((i++))
		done
	fi

	echo "The result is $f"
}

fact $1


# factorial is calculated but if it is returned then it cant show it
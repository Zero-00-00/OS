# Script that shows the even and odd numbers within a user defined range
clear

read -p "Enter the lower bound: " lb
read -p "Enter the upper bound: " up

b=$lb
while [ $b -le $up ]
do
	val=`expr $b % 2`
	if [ $val -eq 1 ]
	then echo "Odd: " $b
	fi
	((b++))
done	

# Q5.

clear
#!/bin/bash
a=$1
i=1
s=0

while [ $i -le 3 ]
do
	rem=`expr $a % 10 `
	s=`echo " $rem + ($s * 10 )" |bc`
	a=`expr $a / 10 `
	((i++))
done 

echo "The reverse of the number is $s"
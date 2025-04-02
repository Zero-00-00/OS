#Script that will take a number as a input and sum their digits
clear

sum=0
read -p "Enter the number " n
while [ $n -gt 0 ]
do	
# Extracts and stores the remainder, this we get the last digit, then it is added to the sum and the number is divided by 10 to get rid of the bymber
	temp=`expr $n % 10`
	sum=`expr $sum + $temp`
	n=`expr $n / 10`
done

echo "The sum is: " $sum

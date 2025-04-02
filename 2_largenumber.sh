# Q2.

clear

echo "Enter three number to find the greater among them"
read n1
read n2
read n3

large=$n1

if [ $n2 -gt $n1 ]
then
	large=$n2
elif [ $n3 -gt $n2 ]
then
	large=$n3
else
	large=$n1
fi

echo "Largest among three is :- " $large


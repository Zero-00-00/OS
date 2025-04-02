#Program to find teh min and max elements in an array

clear

i=0
read -p "Enter the number of elements in the array: " n
while [ $i -lt $n ]
do
	read arr[$i]
	((i++))
done

echo "The given array is "
echo ${arr[*]}

min=${arr[0]}
max=${arr[0]}

j=0

while [ $j -lt $n ]
do
	if [ $max -lt ${arr[j]} ]
	then
		max=${arr[j]}
	fi
	((j++))
done

echo "The min element is" $min
echo "The max element is" $max

#Program for sorting

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

#sort
i=0
while [ $i -lt $n ]
do
	j=0
	q=`expr $n - $i`
	while [ $j -lt $n ]
	do
		#echo "i" $i "j" $j "q" $q
		if [ ${arr[$i]} -lt ${arr[$j]} ]
		then
			temp=${arr[$i]}
			arr[$i]=${arr[$j]}
			arr[$j]=$temp
		fi
		#echo ${arr[*]}
		((j++))
	done
	((i++))
done

echo "The sorted array is"
echo ${arr[*]}
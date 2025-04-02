clear

read -p "Enter: " temp
len=`echo -n $temp | wc -c`
hf=`expr $len \/ 2`
l=$len
f=1
pali=1

while [ $hf -ne 0 -a $pali -eq 1 ]
do 
	#echo $l
	t1=`echo $temp | cut -c $l`
	t2=`expr $temp | cut -c $f`
	if [ "$t1" != "$t2" ]
	then
		pali=0
	fi
	((f++))
	((l--))
	((hf--))
	#echo $t1 $t2 $pali
done

if [ $pali -ne 1 ]
then 
	echo "Not Palindrome"
else
	echo "Palindrome"
fi
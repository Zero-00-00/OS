#Program to delete files of size 0
clear

read -p "Enter the name of the file: " n
if [ -f "$n" ] 
then
	ch=$(wc -c < $n)
	if [ $ch -eq 0 ]
	then 
		rm $n | echo "Done! File Removed"
	else
		echo "File is not empty"
	fi
else
	echo "File does not exist! Invalid File name!"
fi

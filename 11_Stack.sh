# Program inplementing stack

clear

top=-1
max=5

push() {
	if [ $top -eq `expr $max - 1` ]
	then
		echo "Overflow"
	else
		((top++))
		read -p "Enter what you want to push: " stk[$top]
	fi

	display
}

pop() {
	if [ $top -lt 0 ]
	then
		echo "Underflow"
	else
		echo ${stk[$top]}
		stk[$top]=$i
		((top--))
	fi

	display
}

TOS() {
	echo "Top of Stack is " ${stk[$top]}
}

display() {
	echo
	echo "Current Stack: "
	echo ${stk[*]}
}

op=0

while [ $op -ne 5 ]
do
	echo "1. Push"
	echo "2. Pop"
	echo "3. Top of Stack"
	echo "4. Display Stack"
	echo "5. Exit"
	read -p "Choose operation on stack: " op

	case $op in
		1) push ;;
		2) pop ;;
		3) TOS ;;
		4) display ;;
	esac
	echo
done
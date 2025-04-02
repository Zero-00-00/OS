start=$1
end=$2

for i in $(seq $start $end)
do
cal -m $i
done
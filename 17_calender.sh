start=$1
end=$2
year=$3

for i in $(seq $start $end)
do
cal -m $i $year
done

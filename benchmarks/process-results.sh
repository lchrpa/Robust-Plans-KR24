#!/bin/bash


domains="AUV AUV-deep ServiceRobot"
num=6

for d in $domains
do 
echo $d
for (( i=1;i<=$num;i++ ))
do
time=`grep "real" results/$d/res_relax-gen$i.time | sed 's/real //g'`
printf " & $time"
done
echo "\\\\"
for (( i=1;i<=$num;i++ ))
do
length=`cat results/$d/out_relax-gen$i.out | wc -l`
length=`expr $length - 1`
printf " & $length "
done
echo "\\\\"
done


for d in $domains
do 
echo $d

for (( i=1;i<=$num;i++ ))
do
time=`grep "real" results/$d/res_compile-ver$i.time | sed 's/real //g'`
printf " & $time"
done
echo "\\\\"

for (( i=1;i<=$num;i++ ))
do
succ=`grep "Solution found\." results/$d/out_compile_ver$i.out | wc -l`
printf " & $succ"
done
echo "\\\\"


for (( i=1;i<=$num;i++ ))
do
time=`grep "real" results/$d/res_relax-ver$i.time | sed 's/real //g'`
printf " & $time"
done
echo "\\\\"

for (( i=1;i<=$num;i++ ))
do
succ=`grep "Success" results/$d/out_relax-ver$i.out | wc -l`
printf " & $succ"
done
echo "\\\\"


for (( i=1;i<=$num;i++ ))
do
length=`cat $d/plan$i-lama.sol | wc -l`
length=`expr $length - 1`
printf " & $length "
done
echo "\\\\"

done


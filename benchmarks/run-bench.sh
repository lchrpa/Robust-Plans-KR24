#!/bin/bash

#$1 - domain $2- testing $3 - planner script $4 dom suffix

ulimit -t 900
ulimit -v 4194304

curdir=`pwd`/benchmarks
#dirn=`dirname $0`
#dir="$curdir/$dirn"

#domains="AUV"
#domains="AUV-deep"
#domains="ServiceRobot"
domains="AUV AUV-deep ServiceRobot"
num=6



for d in $domains
do 

for (( i=1;i<=$num;i++ ))
do
/usr/bin/time -p -o $curdir/results/$d/res_relax-ver$i.time $curdir/plan-and-verify.sh $curdir/$d/domain.pddl $curdir/$d/problem$i.pddl $curdir/$d/plan$i-lama.sol > $curdir/results/$d/out_relax-ver$i.out
done

for (( i=1;i<=$num;i++ ))
do
/usr/bin/time -p -o $curdir/results/$d/res_relax-gen$i.time ./robust_plans $curdir/$d/domain.pddl $curdir/$d/problem$i.pddl $curdir/$d/plan$i-gen.sol -g > $curdir/results/$d/out_relax-gen$i.out
done


for (( i=1;i<=$num;i++ ))
do
/usr/bin/time -p -o $curdir/results/$d/res_compile-ver$i.time $curdir/compile-and-verify.sh $curdir/$d/domain.pddl $curdir/$d/problem$i.pddl $curdir/$d/plan$i-lama.sol > $curdir/results/$d/out_compile_ver$i.out
done


done


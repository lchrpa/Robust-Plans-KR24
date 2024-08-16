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



#python ~/Planners/downward-main/fast-downward.py --alias lama-first --plan-file $3 $x $2


for d in $domains
do 

for (( i=1;i<=$num;i++ ))
do
#x=`echo $curdir/$d/domain.pddl | sed 's/.pddl/-act.pddl/g'`
/usr/bin/time -p -o $curdir/results/$d/planning$i.time ~/Planners/downward-main/fast-downward.py --alias lama-first $curdir/$d/domain-act.pddl $curdir/$d/problem$i.pddl > $curdir/results/$d/planning$i.out
rm output.sas 

done

done

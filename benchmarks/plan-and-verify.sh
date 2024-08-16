#!/bin/bash

x=`echo $1 | sed 's/.pddl/-act.pddl/g'`

python ~/Planners/downward-main/fast-downward.py --alias lama-first --plan-file $3 $x $2
rm output.sas 
`pwd`/robust_plans $1 $2 $3 -v

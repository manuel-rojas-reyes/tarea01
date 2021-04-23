#!/bin/bash

declare -a nt=("10000" "20000" "30000" "40000" "50000" ) 
declare -a nx=("15000" "30000" "45000" "60000" ) 

for t in "${nt[@]}"
do
    for x in "${nx[@]}"
    do
        #echo "$t;$x"
        #for n in 1 2 3 4 5
        #do
            #echo "Rep $n:"
            eval "./main -nt $t -nx $x"
        #done
        echo ""
    done
    echo ""
done

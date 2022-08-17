#!/bin/bash
t=0
while true; do
    let "t=$t + 1" echox
    printf $t
    printf ": "
    ./genB
    ./B
    ./B_BruteForce
     
    if diff B.out B.ans; then
        printf "Accepted\n"
    else
        printf "Wrong Answer\n"
        break
    fi
done

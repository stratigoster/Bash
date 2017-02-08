#!/bin/bash
declare -A matrix

read input
num_rows=63
num_columns=100


name(){
    #local only works with 
    local startX=$1
    local temp=startX
    #temp=$((temp+distance-1))
    local startY=$2
    local distance=$3
    local n=$4
   
    if [ $n -le 0 ]; then
       return
    fi

    for (( c=0; c<$distance; c++ ))
    do  
       matrix[$((temp+c)),$startY]='1'
    done

    temp=$((temp+distance-1))
    for (( c=0; c<=$distance; c++ ))
    do  
       matrix[$((temp+c)),$((startY+c))]='1'
    done

    for (( c=0; c<=$distance; c++ ))
    do 
       matrix[$((temp+c)),$((startY-c))]='1'
    done
    
    #echo -c $startX $temp $startY $distance $n
    name $(( startX + distance*2 )) $(( startY - distance )) $(( distance/2 )) $(( n - 1 ))
    #echo -c $startX $temp $startY $distance $n
    name $(( startX + distance*2 )) $(( startY + distance )) $(( distance/2 )) $(( n - 1 ))

}

initialize(){
    for ((i=0;i<num_rows;i++)) do
       for ((j=0;j<num_columns;j++)) do
           matrix[$i,$j]='_'
       done
    done
}

printArray() {
    for ((i=num_rows-1;i>=0;i--)) do
       for ((j=0;j<num_columns;j++)) do
           echo -n ${matrix[$i,$j]}
       done
       echo
    done
}

#0, COL/2, 16, 5
initialize
name 0 49 16 $input 
printArray



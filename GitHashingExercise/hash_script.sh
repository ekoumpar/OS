#!/bin/bash

if [ "$#" -ne 1 ]; then		#check if input is not one argument
    echo "Wrong input!"
    echo "Usage: $0 <4-digit-integer>"
    exit 1
fi


if ! [[ "$1" =~ ^[0-9]{4}$ ]]; then	#check if input is not a 4-digit number
    echo "Error: Input must be a 4-digit integer."
    exit 1
fi


number=$1       #4-digit number as input

hash_number=$(echo -n "$number" | sha256sum | awk '{print $1}')
echo "$hash_number"


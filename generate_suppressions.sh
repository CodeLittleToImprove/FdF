#!/bin/bash

# Initialize a counter for suppression names
counter=1

# Start processing the Valgrind output file
awk '/^{/,/^}/' valgrind_output.txt | while read line
do
    # Check for the start of a suppression block
    if [[ $line == "{" ]]; then
        # Start a new suppression block with an auto-generated name
        echo "{"
        echo "   AutoSuppression_$counter"
        let counter++
    elif [[ $line != *"<insert_a_suppression_name_here>"* ]]; then
        # Print the line as-is if it's not the unwanted line
        echo "$line"
    fi
done > my_suppressions.supp

#!/bin/bash

# Number of tests
NUM_TESTS=10

# Maximum number of elements per test
MAX_ELEMENTS=100

for i in $(seq 1 $NUM_TESTS); do
    # Random number of elements for this test
    COUNT=$(( RANDOM % MAX_ELEMENTS + 2 ))  # at least 2 elements

    # Generate a random sequence of unique integers
    SEQUENCE=$(shuf -i 1-500 -n $COUNT | tr '\n' ' ')

    echo "Test #$i: $SEQUENCE"

    # Run your push_swap program
    ./push_swap $SEQUENCE > ops.txt

    # Check with checker_linux
    RESULT=$(./checker_linux $SEQUENCE < ops.txt)

    echo "Result: $RESULT"
    echo "--------------------------------------"
done

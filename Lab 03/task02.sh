#!/bin/bash

echo "Enter a sentence:"
read sentence

sentence=$(echo "$sentence" | tr '[:upper:]' '[:lower:]')

vowel_count=$(echo "$sentence" | grep -o '[aeiou]' | wc -l)

echo "Number of vowels: $vowel_count"

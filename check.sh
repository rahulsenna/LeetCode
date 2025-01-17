#!/usr/bin/env zsh

# Check if two arguments are provided
if [[ $# -ne 2 ]]; then
    echo "Usage: $0 file1 file2"
    echo "Compares two text files line by line and shows matching/non-matching lines"
    exit 1
fi

# Check if files exist
if [[ ! -f $1 ]] || [[ ! -f $2 ]]; then
    echo "Error: One or both files do not exist"
    exit 1
fi

# ANSI color codes
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Unicode symbols
CHECK_MARK="✓"
CROSS_MARK="✗"

# Function to trim trailing whitespace
trim_trailing_whitespace() {
    echo "${1%"${1##*[![:space:]]}"}"
}

# Function to truncate filename to 8 characters
truncate_filename() {
    local filename=$(basename "$1")
    echo "${filename:0:8}"
}

# Get truncated filenames
file1_name=$(truncate_filename "$1")
file2_name=$(truncate_filename "$2")

# Read both files into arrays and trim trailing whitespace
file1_lines=()
file2_lines=()

while IFS= read -r line; do
    file1_lines+=("$(trim_trailing_whitespace "$line")")
done < "$1"

while IFS= read -r line; do
    file2_lines+=("$(trim_trailing_whitespace "$line")")
done < "$2"

# Get the maximum length of both arrays
max_lines=$((${#file1_lines[@]} > ${#file2_lines[@]} ? ${#file1_lines[@]} : ${#file2_lines[@]}))

# Compare lines
matching_lines=0
for ((i=1; i<=max_lines; i++)); do
    line1="${file1_lines[$i]:-<empty>}"
    line2="${file2_lines[$i]:-<empty>}"
    
    if [[ "$line1" == "$line2" ]]; then
        printf "${GREEN}${CHECK_MARK}${NC} Line $i:\n"
        printf "  %8s: %s\n" "$file1_name" "$line1"
        printf "  %8s: %s\n" "$file2_name" "$line2"
        ((matching_lines++))
    else
        printf "${RED}${CROSS_MARK}${NC} Line $i:\n"
        printf "  %8s: %s\n" "$file1_name" "$line1"
        printf "  %8s: %s\n" "$file2_name" "$line2"
    fi
    echo "----------------------------------------"
done

# Print summary
printf "\nSummary:\n"
printf "Files compared: %s and %s\n" "$file1_name" "$file2_name"
printf "Total lines compared: %d\n" $max_lines
printf "Matching lines: ${GREEN}%d${NC}\n" $matching_lines
printf "Different lines: ${RED}%d${NC}\n" $(( max_lines - matching_lines ))

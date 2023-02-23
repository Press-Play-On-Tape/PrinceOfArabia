#!/bin/bash

# Set the directory containing the files to be processed
SOURCE_DIR="tmp"

# Set the directory where processed files will be saved
DEST_DIR="tmp2"

# Loop through each file in the source directory
for file in "${SOURCE_DIR}"/*
do
    # Check if the file is a regular file (not a directory, symlink, etc.)
    if [ -f "${file}" ]
    then
        # Construct the path to the corresponding file in the destination directory
        dest_file="${DEST_DIR}/$(basename ${file})"

        # Use sed to perform the find and replace operation and save the output to the destination file
        sed -e 's/bbb/zzz/g'             \
            -e 's/ccc/fff/g'             \
            "${file}" > "${dest_file}"
    fi
done

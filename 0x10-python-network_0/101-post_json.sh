#!/bin/bash

# Check if both URL and file arguments are provided
if [ $# -ne 2 ]; then
    echo "Usage: $0 <URL> <filename>"
    exit 1
fi

# Assign command line arguments to variables
URL=$1
FILE=$2

# Check if the file exists
if [ ! -f "$FILE" ]; then
    echo "File not found: $FILE"
    exit 1
fi

# Send a POST request with curl, passing the file content as the request body
# Display the body of the response
curl -X POST -H "Content-Type: application/json" --data-binary "@$FILE" "$URL"

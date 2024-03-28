#!/bin/bash
# Send a POST request with curl, passing the file content as the request body
# Display the body of the response
curl -X POST -H "Content-Type: application/json" --data-binary "@$FILE" "$URL"

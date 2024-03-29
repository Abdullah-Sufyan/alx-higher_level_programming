#!/usr/bin/python3
"""load from json"""
import json


def load_from_json_file(filename):
    """load from json to file"""
    with open(filename, encoding="utf-8") as file:
	json_data = json.load(file)
        return json_data

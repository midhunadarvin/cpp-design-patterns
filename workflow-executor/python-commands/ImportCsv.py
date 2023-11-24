import csv
import json


def preExecute(context):
    return True


def execute(context):
    # Load the CSV file
    print(context["file"])
    with open(context["file"]) as csvfile:
        reader = csv.DictReader(csvfile)
        data = []
        for row in reader:
            data.append(row)

    # Convert the data to JSON
    json_data = json.dumps(data, indent=4)
    context["response"] = str(json_data)
    return True


def postExecute(context):
    return True

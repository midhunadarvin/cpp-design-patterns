import csv
import json


def preExecute(context):
    return True


def execute(context):
    print("Context", context["inputFields"])
    if context["inputFields"] is not None or context["inputFields"] != '':
        fields = json.loads(context["inputFields"])
    print(fields)
    csv_data = json.loads(context["ImportCsv_response"])
    for item in csv_data:
        item["total"] = 0
        for field in fields:
            item["total"] += float(item[field])

    context["response"] = json.dumps(csv_data)
    return True


def postExecute(context):
    return True

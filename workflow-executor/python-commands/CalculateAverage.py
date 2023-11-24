
import json


def preExecute(context):
    return True


def execute(context):
    print("Context", context["inputFields"])
    if context["inputFields"] is not None or context["inputFields"] != '':
        fields = json.loads(context["inputFields"])
    print(fields)
    csv_data = json.loads(context["CalculateSum_response"])
    for item in csv_data:
        item["average"] = item["total"] / len(fields)

    context["response"] = json.dumps(csv_data)
    return True


def postExecute(context):
    return True

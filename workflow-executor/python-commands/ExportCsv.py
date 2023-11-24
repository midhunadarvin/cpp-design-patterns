import csv
import json


def preExecute(context):
    return True


def execute(context):
    csv_data = json.loads(context["CalculateAverage_response"])
    # Printing keys of dictionary
    fields = csv_data[0].keys()

    # writing to csv file
    with open(context["file"], 'w') as csvfile:
        # creating a csv writer object
        csvwriter = csv.writer(csvfile)

        # writing the fields
        csvwriter.writerow(fields)
        rows = []
        for item in csv_data:
            row = []
            for field in fields:
                row.append(item[field])
            rows.append(row)

        # writing the data rows
        csvwriter.writerows(rows)

    context["response"] = json.dumps(csv_data)
    return True


def postExecute(context):
    return True

import config_generator

workflow_builder = config_generator.WorkflowBuilder()

# Level 1
workflow_builder.add_workflow_item(1, "ImportCsv", {
    "file": "/Users/midhundarvin/workplace/c++/cpp-design-patterns/graphs/grades.csv"
})

# Level 2
workflow_builder.add_workflow_item(2, "CalculateSum", {
    "inputFields": ["Test1", "Test2", "Test3", "Test4"],
    "outputField": "Sum"
})

workflow_builder.add_workflow_item(2, "CalculateAverage", {
    "inputFields": ["Test1", "Test2", "Test3", "Test4"],
    "outputField": "Average"
})

# Level 3
workflow_builder.add_workflow_item(3, "ExportCsv", {
    "file": "/Users/midhundarvin/workplace/c++/cpp-design-patterns/graphs/grades_processed.csv"
})

workflow_builder.write_to_xml()
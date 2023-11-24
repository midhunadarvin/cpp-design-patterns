# Workflow Executor C++

This project contains a utility written in python to generate a workflow xml file. Which is then parsed
in C++ and executed. Each node of the workflow invokes a plugin written in python.

All the items in the workflow are separated in a grid fashion. The rows ( levels ) decide 
the priority. Each row is executed sequentially and within each row, 
the workflow items are also executed sequentially ( which can be optimized to run in parallel )

Any given row won't start execution unless the previous rows have finished processing.

### Prerequisites 

Install vcpkg and tinyxml
```
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.sh
./vcpkg integrate install
./vcpkg install tinyxml2
```

**Python** ( version >= 3.10 )
### Build
```
mkdir build
cd build 
cmake .. -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake 
make
```

## Example 

This project contains a sample program to
1. Read a csv file ( grades.csv )
2. Calculate sum of grades in all the tests
3. Calculate average of the grades 
4. Write the results to a csv file ( grades_processed.csv )

### Generate Workflow Config

main.py
```python
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
```

Running the above python file generates the xml as given below
```xml
<workflow>
    <level id="1">
        <workflow-item>
            <command>ImportCsv</command>
            <params>
                <param id="file" value="/Users/midhundarvin/workplace/c++/cpp-design-patterns/graphs/grades.csv"/>
            </params>
        </workflow-item>
    </level>
    <level id="2">
        <workflow-item>
            <command>CalculateSum</command>
            <params>
                <param id="inputFields"
                       value="[&quot;Test1&quot;, &quot;Test2&quot;, &quot;Test3&quot;, &quot;Test4&quot;]"/>
                <param id="outputField" value="Sum"/>
            </params>
        </workflow-item>
        <workflow-item>
            <command>CalculateAverage</command>
            <params>
                <param id="inputFields"
                       value="[&quot;Test1&quot;, &quot;Test2&quot;, &quot;Test3&quot;, &quot;Test4&quot;]"/>
                <param id="outputField" value="Average"/>
            </params>
        </workflow-item>
    </level>
    <level id="3">
        <workflow-item>
            <command>ExportCsv</command>
            <params>
                <param id="file" value="/Users/midhundarvin/workplace/c++/cpp-design-patterns/graphs/grades_processed.csv"/>
            </params>
        </workflow-item>
    </level>
</workflow>
```

Which is then parsed by C++ and executed in a row by row fashion.
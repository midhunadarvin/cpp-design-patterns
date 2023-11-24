import xml.etree.ElementTree as ET
import json

class WorkflowToXMLConverter:
    def __init__(self, workflow_matrix):
        self.workflow_matrix = workflow_matrix

    def write_to_xml(self, filename):

        # Create the XML structure
        root_element = ET.Element("workflow")
        index = 1
        for row in self.workflow_matrix:
            level_element = ET.SubElement(root_element, "level")
            level_element.attrib["id"] = str(index)
            for command in row:
                item_element = ET.SubElement(level_element, "workflow-item")
                ET.SubElement(item_element, "command").text = str(command.commandName)
                params_element = ET.SubElement(item_element, "params")
                for key in command.params:
                    param = ET.SubElement(params_element, "param")
                    param.attrib["id"] = key
                    if isinstance(command.params[key], (list, dict)):
                        param.attrib["value"] = json.dumps(command.params[key])
                    else:
                        param.attrib["value"] = command.params[key]

            index += 1

        tree = ET.ElementTree(root_element)
        with open(filename, "wb") as file:
            tree.write(file)


class WorkflowItem:
    def __init__(self, command_name, params):
        self.commandName = command_name
        self.params = params


class WorkflowBuilder:

    def __init__(self):
        self.workflow_matrix = []
        self.max_level = 0

    def add_workflow_item(self, level, command_name, params):
        if level > self.max_level:
            while level > self.max_level:
                self.workflow_matrix.append([])
                self.max_level = self.max_level + 1

        self.workflow_matrix[level - 1].append(WorkflowItem(command_name, params))

    def write_to_xml(self):
        # Convert and write the tree to XML
        xml_converter = WorkflowToXMLConverter(self.workflow_matrix)
        xml_converter.write_to_xml("sample-workflow.xml")

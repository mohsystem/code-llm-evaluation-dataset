
import xml.etree.ElementTree as ET

def parse_xml_string(xml_string):
    root = ET.fromstring(xml_string)
    return root

if __name__ == "__main__":
    xml_string = "<root><child1>Value1</child1><child2>Value2</child2></root>"
    root_element = parse_xml_string(xml_string)
    if root_element is not None:
        print(f"Root element: {root_element.tag}")

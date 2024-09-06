
import xml.etree.ElementTree as ET

def get_root_element(xml_string):
    root = ET.fromstring(xml_string)
    return root.tag

# Example usage
xml_str = '<root><child1>Content</child1><child2 attr="value"/></root>'
print(get_root_element(xml_str))

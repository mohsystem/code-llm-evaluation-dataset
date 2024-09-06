import xml.etree.ElementTree as ET

xml_str = """<?xml version="1.0"?>
<root>
    <child1>Content1</child1>
    <child2>
        <subchild1>Content2</subchild1>
    </child2>
</root>"""

def get_root_element(xml_string):
    root = ET.fromstring(xml_string)
    return root.tag

root_element = get_root_element(xml_str)
print(root_element)
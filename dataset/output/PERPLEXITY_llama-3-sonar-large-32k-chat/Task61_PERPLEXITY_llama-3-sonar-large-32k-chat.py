import xml.etree.ElementTree as ET

def get_root_element(xml_string):
    root = ET.fromstring(xml_string)
    return root.tag

xml_string = "<root><person><name>John</name><age>30</age></person></root>"
print(get_root_element(xml_string))
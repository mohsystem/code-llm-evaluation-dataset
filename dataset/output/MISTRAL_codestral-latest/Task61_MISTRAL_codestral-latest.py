import xml.etree.ElementTree as ET

def get_root_element(xml_string):
    root = ET.fromstring(xml_string)
    return root.tag
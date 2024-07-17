import xml.etree.ElementTree as ET

def get_root_element(xml_string):
    root = ET.fromstring(xml_string)
    return root.tag

if __name__ == '__main__':
    xml_string = "<note><to>Tove</to><from>Jani</from><heading>Reminder</heading><body>Don't forget me this weekend!</body></note>"
    root_element = get_root_element(xml_string)
    print(root_element)
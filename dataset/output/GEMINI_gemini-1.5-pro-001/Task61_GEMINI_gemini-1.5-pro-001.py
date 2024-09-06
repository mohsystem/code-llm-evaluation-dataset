import xml.etree.ElementTree as ET

def get_root_element(xml_string):
    """
    Parses the provided XML string and returns the root element.

    Args:
        xml_string: The XML string to parse.

    Returns:
        The root element of the XML document.
    """
    root = ET.fromstring(xml_string)
    return root.tag

xml_string = "<note><to>Tove</to><from>Jani</from><heading>Reminder</heading><body>Don't forget me this weekend!</body></note>"
root_element = get_root_element(xml_string)
print(root_element)
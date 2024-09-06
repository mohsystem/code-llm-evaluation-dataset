
import sys
import xml.etree.ElementTree as ET

def execute_xpath(xml_file, xpath):
    tree = ET.parse(xml_file)
    root = tree.getroot()
    result = root.findall(xpath)
    return [elem.text for elem in result]

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python script.py <xml_file> <xpath>")
        sys.exit(1)

    xml_file = sys.argv[1]
    xpath = sys.argv[2]

    result = execute_xpath(xml_file, xpath)
    print(result)

import sys
import xml.etree.ElementTree as ET

xpath_value = sys.argv[1]
xml_file_name = sys.argv[2]

tree = ET.parse(xml_file_name)
root = tree.getroot()

result = root.findall(f"{{{xpath_value}}}")

for element in result:
    print(element.text)
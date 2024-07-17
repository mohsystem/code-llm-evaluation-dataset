import sys
import xml.etree.ElementTree as ET

if len(sys.argv) != 3:
    print("Usage: <program> <xpath> <xmlfile>")
    sys.exit(1)

xpath_expr = sys.argv[1]
xml_file = sys.argv[2]

tree = ET.parse(xml_file)
root = tree.getroot()

elements = root.findall(xpath_expr)

for elem in elements:
    print(elem.text)
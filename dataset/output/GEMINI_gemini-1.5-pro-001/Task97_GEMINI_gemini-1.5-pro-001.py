import xml.etree.ElementTree as ET
import sys

if len(sys.argv) != 4:
    print("Usage: python xml_parser.py <xml_file> <xpath_query> <id_value>")
    sys.exit(1)

xml_file = sys.argv[1]
xpath_query = sys.argv[2]
id_value = sys.argv[3]

try:
    tree = ET.parse(xml_file)
    root = tree.getroot()
    result = root.find(xpath_query.format(id_value))

    if result is not None:
        print(result.text)
    else:
        print("XPath query returned no results.")

except FileNotFoundError:
    print(f"Error: File not found: {xml_file}")
except ET.ParseError:
    print(f"Error: Invalid XML file: {xml_file}")
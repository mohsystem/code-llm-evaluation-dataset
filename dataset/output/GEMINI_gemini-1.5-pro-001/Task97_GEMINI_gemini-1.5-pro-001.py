import xml.etree.ElementTree as ET
import sys

if __name__ == "__main__":
    if len(sys.argv) != 4:
        print("Usage: python script.py <xpath> <xml_file> <id_value>")
        sys.exit(1)

    xpath = sys.argv[1]
    xml_file = sys.argv[2]
    id_value = sys.argv[3]

    try:
        tree = ET.parse(xml_file)
        root = tree.getroot()
        result = root.findall(xpath.format(id_value))
        for element in result:
            print(element.tag, element.attrib)
    except ET.ParseError as e:
        print(f"Error parsing XML: {e}")
    except Exception as e:
        print(f"An error occurred: {e}")
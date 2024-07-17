import sys
import xml.etree.ElementTree as ET

def main():
    if len(sys.argv) != 3:
        print("Usage: python script.py <xpath> <xml_file>")
        return 1
    xpath = sys.argv[1]
    file_name = sys.argv[2]
    tree = ET.parse(file_name)
    root = tree.getroot()
    nodes = root.findall(".//tag[@id='" + xpath + "']")
    for node in nodes:
        print(node.text)

if __name__ == "__main__":
    main()
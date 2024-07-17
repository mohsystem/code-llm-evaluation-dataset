import xml.etree.ElementTree as ET

def main():
    xml_string = "<root><person><name>John</name><age>30</age></person></root>"
    root = ET.fromstring(xml_string)
    print("Root Element:", root.tag)

if __name__ == "__main__":
    main()
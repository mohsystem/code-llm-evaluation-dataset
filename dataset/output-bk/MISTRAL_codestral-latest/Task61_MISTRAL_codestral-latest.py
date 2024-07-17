import xml.etree.ElementTree as ET

xml_string = "<root><child>Data</child></root>"
root = ET.fromstring(xml_string)
print("Root element:", root.tag)
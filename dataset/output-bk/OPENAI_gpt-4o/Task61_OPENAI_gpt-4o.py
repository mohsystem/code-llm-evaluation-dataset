import xml.etree.ElementTree as ET

xml_content = "<root><child>value</child></root>"
root = ET.fromstring(xml_content)
print(f"Root element: {root.tag}")
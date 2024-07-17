import sys
from lxml import etree

xpath = sys.argv[1]
xml_file = sys.argv[2]

tree = etree.parse(xml_file)
root = tree.getroot()

expression = "/tag[@id='{}']".format(xpath)
result = root.xpath(expression)

print("Result:", result)
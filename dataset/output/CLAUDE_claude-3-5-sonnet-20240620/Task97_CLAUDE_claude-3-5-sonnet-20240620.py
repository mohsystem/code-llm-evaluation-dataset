
import sys
import xml.etree.ElementTree as ET

def execute_xpath_query(xml_file, xpath):
    try:
        tree = ET.parse(xml_file)
        root = tree.getroot()
        
        # Extract the tag and id from the XPath expression
        parts = xpath.split(\'[@id=\')
        tag = parts[0][1:]  # Remove the leading \'/\'
        id_value = parts[1][:-1]  # Remove the trailing \']\'
        
        # Find all elements with the specified tag
        elements = root.findall(f".//{tag}")
        
        # Filter elements based on the id attribute
        results = [elem for elem in elements if elem.get(\'id\') == id_value]
        
        # Print the text content of matching elements
        for elem in results:
            print(elem.text)
    
    except ET.ParseError as e:
        print(f"Error parsing XML file: {e}")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python script.py <xpath> <xml_file>")
        sys.exit(1)
    
    xpath = sys.argv[1]
    xml_file = sys.argv[2]
    
    execute_xpath_query(xml_file, xpath)

import sys
import xml.etree.ElementTree as ET

def main():
    if len(sys.argv) != 3:
        print("Usage: script.py <xpath> <xmlfile>")
        return
    
    xpath = sys.argv[1]
    xmlfile = sys.argv[2]
    
    try:
        tree = ET.parse(xmlfile)
        root = tree.getroot()
        
        # Execute XPath query
        result = root.find(xpath)
        if result is not None:
            print(ET.tostring(result).decode())
        else:
            print("No result found for the XPath query.")
    
    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    main()

import requests

def retrieve_file(filename):
    server_url = "http://example.com/files/"  # Replace with actual server URL
    file_url = server_url + filename
    
    try:
        response = requests.get(file_url)
        response.raise_for_status()
        
        with open(filename, 'wb') as file:
            file.write(response.content)
        print(f"File '{filename}' successfully retrieved and saved.")
    except requests.exceptions.RequestException as e:
        print(f"Error retrieving file: {e}")

if __name__ == "__main__":
    user_filename = input("Enter the filename to retrieve: ")
    retrieve_file(user_filename)

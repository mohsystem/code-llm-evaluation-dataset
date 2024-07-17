import requests

def download_file(url):
  """Downloads a file from a given URL."""
  try:
    response = requests.get(url)
    response.raise_for_status()  # Raise an exception for bad status codes
    return response.content
  except requests.exceptions.RequestException as e:
    print(f"Error downloading file: {e}")
    return None

def main():
  """Gets file name input from the user and downloads the file."""
  file_name = input("Enter the file name to download: ")
  base_url = "https://example.com/files/"  # Replace with your base URL
  file_url = f"{base_url}{file_name}"

  file_content = download_file(file_url)
  if file_content:
    try:
      with open(file_name, 'wb') as f:
        f.write(file_content)
      print(f"File '{file_name}' downloaded successfully!")
    except OSError as e:
      print(f"Error saving file: {e}")

if __name__ == "__main__":
  main()
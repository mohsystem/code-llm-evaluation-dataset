import requests

def download_file(url):
  """Downloads a file from a given URL.

  Args:
    url: The URL of the file to download.

  Returns:
    The content of the downloaded file.
  """
  response = requests.get(url)
  response.raise_for_status()  # Raise an exception for bad status codes
  return response.content

def main():
  """Main function of the program."""
  file_name = input("Enter the file name to download: ")
  url = f"https://example.com/files/{file_name}"  # Replace with actual server URL
  try:
    file_content = download_file(url)
    print(f"File '{file_name}' downloaded successfully.")
    # Process file_content as needed (e.g., save to disk)
  except requests.exceptions.RequestException as e:
    print(f"Error downloading file: {e}")

if __name__ == "__main__":
  main()
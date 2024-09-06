import zipfile
import tarfile

def extract_zip(archive_path, extract_path):
  """Extracts a ZIP archive.

  Args:
    archive_path: Path to the ZIP archive file.
    extract_path: Path to the directory where the files should be extracted.
  """
  with zipfile.ZipFile(archive_path, 'r') as zip_ref:
    zip_ref.extractall(extract_path)

def extract_tar(archive_path, extract_path):
  """Extracts a TAR archive.

  Args:
    archive_path: Path to the TAR archive file.
    extract_path: Path to the directory where the files should be extracted.
  """
  with tarfile.open(archive_path, 'r') as tar_ref:
    tar_ref.extractall(extract_path)

if __name__ == "__main__":
  archive_path = input("Enter the path to the archive file: ")
  extract_path = input("Enter the path to the extraction directory: ")

  if archive_path.endswith(('.zip', '.ZIP')):
    extract_zip(archive_path, extract_path)
  elif archive_path.endswith(('.tar', '.TAR')):
    extract_tar(archive_path, extract_path)
  else:
    print("Unsupported archive format.")
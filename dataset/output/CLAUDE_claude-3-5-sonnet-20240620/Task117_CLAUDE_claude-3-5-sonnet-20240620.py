
import zipfile
import tarfile
import os

def extract_archive(archive_path, extract_path):
    if zipfile.is_zipfile(archive_path):
        with zipfile.ZipFile(archive_path, 'r') as zip_ref:
            zip_ref.extractall(extract_path)
        print(f"Extracted ZIP file: {archive_path}")
    elif tarfile.is_tarfile(archive_path):
        with tarfile.open(archive_path, 'r:*') as tar_ref:
            tar_ref.extractall(extract_path)
        print(f"Extracted TAR file: {archive_path}")
    else:
        print(f"Unsupported archive format: {archive_path}")

if __name__ == "__main__":
    archive_path = input("Enter the path to the archive file: ")
    extract_path = input("Enter the extraction path: ")

    if not os.path.exists(extract_path):
        os.makedirs(extract_path)

    extract_archive(archive_path, extract_path)

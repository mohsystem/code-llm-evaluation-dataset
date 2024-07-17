import zipfile
import tarfile
import os

def extract_zip(archive_path, extract_path="."):
    with zipfile.ZipFile(archive_path, 'r') as zip_ref:
        zip_ref.extractall(extract_path)

def extract_tar(archive_path, extract_path="."):
    with tarfile.open(archive_path, 'r') as tar_ref:
        tar_ref.extractall(extract_path)

def main():
    archive_file = input("Enter the path to the archive file: ")
    output_dir = input("Enter the directory to extract to (leave blank to extract to current directory): ")

    if not output_dir:
        output_dir = "."

    if archive_file.endswith((".zip", ".ZIP")):
        extract_zip(archive_file, output_dir)
    elif archive_file.endswith((".tar", ".tar.gz", ".tgz")):
        extract_tar(archive_file, output_dir)
    else:
        print("Unsupported archive format.")

if __name__ == "__main__":
    main()
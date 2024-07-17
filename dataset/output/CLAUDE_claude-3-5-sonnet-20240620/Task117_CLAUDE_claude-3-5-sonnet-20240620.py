
import os
import sys
import zipfile
import tarfile

def extract_archive(archive_file, output_dir):
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)

    if zipfile.is_zipfile(archive_file):
        with zipfile.ZipFile(archive_file, \'r\') as zip_ref:
            zip_ref.extractall(output_dir)
        print(f"Extracted ZIP file: {archive_file}")
    elif tarfile.is_tarfile(archive_file):
        with tarfile.open(archive_file, \'r:*\') as tar_ref:
            tar_ref.extractall(output_dir)
        print(f"Extracted TAR file: {archive_file}")
    else:
        print(f"Unsupported archive format: {archive_file}")

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python archive_extractor.py <archive_file> <output_directory>")
        sys.exit(1)

    archive_file = sys.argv[1]
    output_dir = sys.argv[2]

    extract_archive(archive_file, output_dir)

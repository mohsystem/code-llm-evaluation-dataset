import zipfile
import tarfile
import sys

def extract_zip(file_path, extract_to='.'):
    with zipfile.ZipFile(file_path, 'r') as zip_ref:
        zip_ref.extractall(extract_to)

def extract_tar(file_path, extract_to='.'):
    with tarfile.open(file_path, 'r') as tar_ref:
        tar_ref.extractall(extract_to)

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python <script_name> <archive_path> <extract_to>")
        sys.exit(1)

    archive_path = sys.argv[1]
    extract_to = sys.argv[2]

    if archive_path.endswith('.zip'):
        extract_zip(archive_path, extract_to)
    elif archive_path.endswith('.tar'):
        extract_tar(archive_path, extract_to)
    else:
        print("Unsupported file type")
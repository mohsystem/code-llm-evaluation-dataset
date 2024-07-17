# Python
import zipfile
import tarfile

def extract_archive(file_path, dest_dir):
    if file_path.endswith('.zip'):
        with zipfile.ZipFile(file_path, 'r') as zip_ref:
            zip_ref.extractall(dest_dir)
    elif file_path.endswith('.tar.gz') or file_path.endswith('.tgz'):
        with tarfile.open(file_path, 'r:gz') as tar_ref:
            tar_ref.extractall(dest_dir)
    elif file_path.endswith('.tar'):
        with tarfile.open(file_path, 'r:') as tar_ref:
            tar_ref.extractall(dest_dir)
    else:
        print("Unsupported archive format.")

# Usage
extract_archive('path_to_your_archive_file', 'destination_directory')
import zipfile
import tarfile
import os

def extract_zip(zip_file, output_dir):
    with zipfile.ZipFile(zip_file, 'r') as zip_ref:
        zip_ref.extractall(output_dir)

def extract_tar(tar_file, output_dir):
    with tarfile.open(tar_file) as tar_ref:
        tar_ref.extractall(output_dir)

def main():
    zip_file = 'yourfile.zip'
    tar_file = 'yourfile.tar'
    output_dir = 'output_dir'

    if zipfile.is_zipfile(zip_file):
        extract_zip(zip_file, output_dir)
    elif tarfile.is_tarfile(tar_file):
        extract_tar(tar_file, output_dir)
    else:
        print("Not a valid archive file")

if __name__ == "__main__":
    main()
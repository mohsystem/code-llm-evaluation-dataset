import zipfile
import os

archive_file = "archive.zip"
extract_dir = "extracted"

with zipfile.ZipFile(archive_file, 'r') as zip_ref:
    zip_ref.extractall(extract_dir)
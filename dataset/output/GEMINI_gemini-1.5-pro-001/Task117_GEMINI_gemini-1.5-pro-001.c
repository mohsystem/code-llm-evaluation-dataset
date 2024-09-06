#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zlib.h>

// Function to extract a ZIP archive
void extractZip(const char* archivePath, const char* extractPath) {
  // Implementation for ZIP extraction (using zlib or other libraries)
  // ...
}

int main() {
  char archivePath[1024];
  char extractPath[1024];

  printf("Enter the path to the archive file: ");
  fgets(archivePath, sizeof(archivePath), stdin);
  archivePath[strcspn(archivePath, "\n")] = 0; // Remove trailing newline

  printf("Enter the path to the extraction directory: ");
  fgets(extractPath, sizeof(extractPath), stdin);
  extractPath[strcspn(extractPath, "\n")] = 0; // Remove trailing newline

  // Check for file extensions (case-insensitive)
  if (strstr(archivePath, ".zip") != NULL || strstr(archivePath, ".ZIP") != NULL) {
    extractZip(archivePath, extractPath);
  } else {
    printf("Unsupported archive format.\n");
  }

  return 0;
}
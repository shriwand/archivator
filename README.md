# archivator

File archiver utility written in C with compression support.

## Overview

A command-line file archiver that creates and extracts archives. Implements custom archive format with optional compression.

## Features

- Create/extract archives
- Multiple file support
- Custom archive format
- Basic compression
- Directory traversal

## Usage

```bash
# Build
make

# Create archive
./archivator -c archive.arc file1.txt file2.txt

# Extract archive
./archivator -x archive.arc
```

## Structure

```
├── Makefile        # Build configuration
├── archivator.c   # Main implementation
└── test_dir/      # Test files
```

## Requirements

- GCC
- Make
- POSIX-compliant system

## License

MIT

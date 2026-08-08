# Operating Systems Study Guide

A detailed, structured study guide covering fundamental and advanced concepts in Operating Systems in spanish, written in LaTeX.

## Overview

This repository contains a comprehensive LaTeX document designed for students and practitioners studying Operating Systems. It includes detailed theoretical explanations, code snippets, and vector graphics created using TikZ.

## Covered Topics

- **Introduction**: Fundamental principles, history, and OS architectures.
- **Processes**: Process lifecycle, context switching, and process management.
- **Threads**: Threading models, multithreading paradigms, and implementation.
- **Concurrency**: Race conditions, critical sections, semaphores, mutexes, and synchronization problems.
- **Process Scheduling**: CPU scheduling algorithms, metrics, and policy evaluation.
- **Virtual Memory**: Paging, segmentation, page replacement policies, and memory management units.
- **I/O Devices and RAID**: RAID storage architectures.
- **Virtualization**: Hypervisors, hardware virtualization, and containerization principles.

## Prerequisites

To compile this document, you need a complete LaTeX distribution and Git LFS:

1. **TeX Live Full** (or equivalent full TeX distribution)
   - Packages such as `tikz`, `pgfplots`, and custom typography packages are heavily utilized.
2. **LuaLaTeX Compiler**
   - Required for font handling, hyphenation and compilation logic.
3. **Git & Git LFS**
   - Binary assets (such as vector diagrams in PDF format) are tracked using Git Large File Storage (Git LFS).

### Installing Dependencies (Linux / Ubuntu / Debian)

```bash
sudo apt update
sudo apt install texlive-full git-lfs
```

## Cloning the Repository

Because this repository uses Git LFS for binary vector assets, ensure Git LFS is enabled before or after cloning:

```bash
# Initialize Git LFS on your system (if not done already)
git lfs install

# Clone the repository
git clone https://github.com/EVAnci/sistemas_operativos.git
cd sistemas_operativos

# Ensure all binary files are pulled
git lfs pull
```

## Repository Structure

```
.
├── chapters
│   ├── 01_unit
│   ├── 02_unit
│   ├── 03_unit
│   ├── 04_unit
│   ├── 05_unit
│   ├── 06_unit
│   └── 07_unit
├── code
│   └── 04_unit
├── envs.tex
├── main.tex
├── programa.tex
└── styles.tex
```

### File & Directory Description

- `main.tex`: The entry point of the document. Contains the preamble, structural imports, and `\include` statements for each chapter.
- `styles.tex`: Custom formatting, color definitions, page geometry, and layout styling.
- `envs.tex`: Custom LaTeX environments (callouts, boxes, definitions, theorems).
- `programa.tex`: Course syllabus or program outline included in the document introduction.
- `chapters/`: Contains subdirectories for each individual unit (`01_unit` through `07_unit`), keeping content modular.
- `code/`: Contains source code examples (e.g., C code for concurrency unit `04_unit`) embedded or referenced in the text.

## Compilation Instructions

The document must be compiled using **`lualatex`**. Due to cross-references, table of contents, and TikZ layout passes, **you must run the compilation command three times**.

```bash
lualatex main.tex
lualatex main.tex
lualatex main.tex
```

Alternatively, if you use `latexmk`:

```bash
latexmk -lualatex main.tex
```

After compilation, `main.pdf` will be generated in the root directory.

## License

This document is released under the **Creative Commons Attribution-ShareAlike 4.0 International (CC BY-SA 4.0)** license.

You are free to:
- **Share**: Copy and redistribute the material in any medium or format.
- **Adapt**: Remix, transform, and build upon the material for any purpose, even commercially.

Under the following terms:
- **Attribution**: You must give appropriate credit, provide a link to the license, and indicate if changes were made.
- **ShareAlike**: If you remix, transform, or build upon the material, you must distribute your contributions under the same license as the original and keep the source code available.

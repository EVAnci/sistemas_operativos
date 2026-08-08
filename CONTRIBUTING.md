# Contribution Guidelines

Thank you for your interest in contributing to the Operating Systems Study Guide. To ensure the quality, maintainability, and professional typesetting of the final document, please adhere to the following guidelines before submitting fixes or new content.

## General Principles

These guidelines are designed to safeguard the final document quality, maintain a clean repository history, and preserve a modular source structure. They are simple requirements intended to keep the project sustainable and high quality.

## Requirements for Contributions

### 1. Binary Asset Tracking via Git LFS
- Do not commit binary files directly into standard Git tracking.
- Always use **Git LFS** (`git-lfs`) to track any binary assets (such as vector graphics in PDF format). Direct binary commits bloat the `.git` directory and permanently degrade repository performance.

### 2. Modular Document Structure
- Work in a modular manner. Do not create monolithic chapter files consisting of thousands of lines.
- Conceptually separate content into smaller, focused `.tex` files within their respective unit directories (`chapters/0X_unit/`) and import them accordingly.

### 3. Vector Graphics Only (No Raster Images)
- **PNG, JPG, or JPEG images are not accepted.** To maintain crisp rendering at any zoom level or print resolution, all graphics and figures must be vector-based.
- Recommended tools for graphics:
  - Native LaTeX drawing: `TikZ` or `Asymptote`.
  - Vector illustration: `Inkscape` (saved as vector PDF).

### 4. Minimal and Justified Package Usage
- Do not add LaTeX packages unnecessarily.
- Introduce new packages only when strictly required to achieve a specific, professional result that cannot be accomplished with existing packages. Every added package increases compilation time and the risk of environment conflicts.

### 5. Clean Compilation and Typesetting Quality
- Avoid `Overfull \hbox` and `Underfull \hbox` warnings when compiling.
- Always inspect `main.log` to identify and fix layout/typesetting warnings before submitting a pull request:
  ```bash
  grep -E "Overfull|Underfull" main.log
  ```

* Ensure line breaks, hyphenations, code blocks, and table widths are adjusted properly so no text overflows into page margins or creates awkward spacing.

### 6. Spell Check and Proofreading via Textidote

As the document is written in Spanish, use **Textidote** to check for spelling and grammar errors prior to submitting your changes:

* To check the entire document:
```bash
textidote --check es --output html *.tex > report.html
firefox report.html
```

* To check a single file:
```bash
textidote --check es --output html filename.tex > report.html
firefox report.html
```

* **Important**: Do not commit or upload `report.html` (or any generated HTML report file) to the repository.

## Pull Request Checklist

Before opening a pull request, please verify that:

1. The document compiles cleanly with `lualatex` without fatal errors.
2. `main.log` has been checked and verified for no `Overfull \hbox` or `Underfull \hbox` warnings (`grep -E "Overfull|Underfull" main.log`).
3. Content has been spell-checked using `textidote` with Spanish language settings (`--check es`).
4. Generated report files (such as `report.html`) are excluded from your commits.
5. Any new binary files are properly tracked by Git LFS.
6. Content is modularized and formatted according to existing styles.
7. The pull request description clearly explains the changes made or the issues resolved.

Thank you for your understanding and for helping keep this project maintainable and professional.
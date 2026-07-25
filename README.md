# Matrix Operations Tool in C

A lightweight, interactive command-line interface (CLI) application written in **C** to perform foundational linear algebra computations. The program leverages Variable-Length Arrays (VLAs) to handle dynamic dimensions at runtime directly through user input.

## Features

* **Matrix Addition**: Adds two user-defined matrices of the same dimensions.
* **Matrix Multiplication**: Multiplies two matrices after validating dimensional compatibility ($Columns_1 = Rows_2$).
* **Matrix Transposition**: Flips a matrix over its diagonal, transforming an $M \times N$ matrix into an $N \times M$ matrix.
* **Dynamic Sizing**: No hardcoded limits on array dimensions.
* **Interactive Menu**: A loop-driven command interface for executing multiple operations without restarting.

## Prerequisites

To compile and run this application, you need a C compiler installed on your system:
* **GCC** (Recommended)
* **Clang**
* **MSVC** (Requires a version supporting VLAs or C99/C11 standards)

## Getting Started

### 1. Clone the Repository
```bash
git clone https://github.com/karanangane2304/CodeAlpha_Matrix_Operations
cd Matrix_Operations.c
```

### 2. Compilation
Compile the source code file using your terminal compiler:
```bash
gcc Matrix_Operations.c -o Matrix_Operations
```

### 3. Execution
Run the compiled binary executable:
```bash
./Matrix_Operations
```

## How to Use

1. Launch the application to view the operational menu interface.
2. Select an option by typing its corresponding number (**1-4**).
3. Follow the on-screen prompts to input matrix boundaries (Rows and Columns).
4. Populate individual elements sequentially as requested.
5. View the formatted matrices and mathematical output printed directly in the terminal window.

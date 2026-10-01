# intro-Netpbm-Image-Processor-in-C-.2


# Netpbm Image Processor in C (`figproc.c`)

A C program developed as part of an introductory programming assignment, designed to process and convert **Netpbm** image formats (`PPM`, `PGM`, `PBM`) directly through standard input and output streams (`getchar()` and `putchar()`).

## Key Features

- **Color to Grayscale Conversion (`P6` $\rightarrow$ `P5`, `P3` $\rightarrow$ `P2`):** 
  Transforms RGB color pixels into grayscale equivalents using the integer-based luminosity formula:
  $$\lfloor\frac{299\cdot R+587\cdot G+114\cdot B}{1000}\rfloor$$
- **Grayscale to Monochrome Conversion (`P5` $\rightarrow$ `P4`, `P2` $\rightarrow$ `P1`):** 
  Applies a calculated threshold ($\lfloor\frac{\max+1}{2}\rfloor$) to convert grayscale intensity into pure black and white pixels.
- **Efficient Bit-Packing (`P4` format):** Packs 8 monochrome pixels into a single byte for binary PBM outputs, properly handling row padding when image widths are not multiples of 8.
- **Robust Input Validation:** Strictly checks magic numbers, header comments (`#`), dimensions, and pixel value ranges, handling unexpected inputs with proper error messages (`Input error!`).

## Technical Constraints & Compliance

To strictly adhere to assignment guidelines, the implementation features:
- **Zero Arrays or Pointers:** Stream-based, on-the-fly character processing without memory buffers.
- **No Floating-Point Arithmetic:** Uses purely integer math to prevent precision or library dependencies.
- **No External Libraries:** Relies exclusively on standard I/O (`<stdio.h>`).

## Compilation & Usage

gcc -o figproc figproc.c

Run the program by redirecting input and output files:

./figproc < input.ppm > output.pgm

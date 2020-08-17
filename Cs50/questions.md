# Questions

## What's `stdint.h`?

Its a library that brings specific width types to intergers

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

For memory efficiency purposes, making the code faster and using less memory

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

1. BYTE = 1 byte
2. DWORD = 4 bytes
3. LONG = 4 bytes
4. WORD = 2 bytes

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

0x42 and 0x4d respectively.

## What's the difference between `bfSize` and `biSize`?

The bfSize is the number of bytes of the whole bitmap file. The biSize correspond to the number os bytes 
required for the structure of the file, this doesnt count the bytes for the header.

## What does it mean if `biHeight` is negative?

If biHeight is negative indicates that its a top-down DIB and its origin is the upper-left corner

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in `copy.c`?

Because the addres of the file could not exists

## Why is the third argument to `fread` always `1` in our code?

Because this ensure thats the data transfered is of the same size of the data read.

## What value does `copy.c` assign to `padding` if `bi.biWidth` is `3`?

0

## What does `fseek` do?

It seeks a stream and changes the actual pointer the the beggining of the seeked string.

## What is `SEEK_CUR`?

It indicates that the search will be done relative with the pointer current position.

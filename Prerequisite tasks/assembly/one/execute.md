# Generating an executable from assembly code using nasm

## To generate an object file from the assembly code using nasm:
```
nasm -f elf64 -o <outputFileName.o> <inputFileName.asm>
```

## Generating executable file from .o file:
```
ld <outputFileName.o> -o <executable>
```

# Building an executable of an assembly code

### First step of building an executable is compiling (or assembling) object file from the source:

- For nasm example (source file : hello.asm)
```
nasm -f elf hello.asm
```

- For gas example (source file : hello.S)
```
as -o hello.o hello.S
```

### Generating an executable from the object file by invoking linker:
For nasm on 64-bit machine:
```
ld -m elf_i386 -s -o hello hello.o
```

For as:
```
ld -s -o hello hello.o
```
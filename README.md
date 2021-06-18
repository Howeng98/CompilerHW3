# CompilerHW3

## Compile Command
Compile
```
make clean && make
```

```
./mycompiler < input/in01_arithmetic.c && make -s Main.class && make -s run > output/in01.out || echo "hw3.j does not exist" > output/in01.out
```

```
java -jar jasmin.jar hw3.j
```

```
java Main
```

Debug
```
git diff --no-index --color-words answer/in01_arithmetic.out output/in01.out
```
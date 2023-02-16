# mal-lib
```
> ldd /path/to/program
```
```
> gcc -shared -fPIC -o libmalicious.so {name}.c
> LD_PRELOAD=./libmalicious.so ls
```
If you want to add a directory /path/to/malicious/lib to the search path, you can use:
```
> export LD_LIBRARY_PATH=/path/to/malicious/lib:$LD_LIBRARY_PATH
```

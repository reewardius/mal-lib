#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    char* script = "#!/bin/bash\n\n/bin/echo 'Hello from malicious script'\n";
    char filename[] = "/tmp/script.sh";
    
    // Create and open file for writing
    int fd = open(filename, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd == -1) {
        printf("Error creating file\n");
        return -1;
    }
    
    // Write script to file
    write(fd, script, sizeof(script));
    
    // Close file
    close(fd);
    
    // Make script executable
    chmod(filename, S_IRUSR | S_IWUSR | S_IRGRP | S_IXUSR | S_IXGRP | S_IROTH | S_IXOTH);
    
    // Execute script
    system(filename);
    
    return 0;
}

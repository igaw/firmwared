#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
        int fd;
        const char *filename = "foobar.bin";

        fd = open("/sys/class/misc/test_firmware/trigger_request", O_CLOEXEC|O_WRONLY);
        if (fd < 0) {
                fprintf(stderr, "couldn't open tester: %s", strerror(errno));
                return -1;
        }

        write(fd, filename, strlen(filename));

        close(fd);
        return 0;
}

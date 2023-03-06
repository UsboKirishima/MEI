#include <stdio.h>
#include <stdlib.h>
#include <sys/mount.h>
#include <signal.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>
#include <unistd.h>
#include <stddef.h>
#include <stdalign.h>
#include <regex.h>
#include <stdbool.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <sys/statvfs.h>
#include <sys/stat.h>
#include <sys/mount.h>
#include <linux/loop.h>
#include <fcntl.h>
#include <assert.h>
#include "stuff.h"
#define DEV             true
#define LINUX           true
#define NAME            "MEI "
#define LOGS_MODE       false
#undef  MIN
#define MIN(x, y)       ((x) < (y) ? (x) : (y))
#undef  MAX
#define MAX(x, y)       ((x) > (y) ? (x) : (y))
#define ISODD(x)        ((x) & 1)
#define ISBLANK(x)      ((x) == ' ' || (x) == '\t')
#define TOUPPER(ch)     (((ch) >= 'a' && (ch) <= 'z') ? ((ch) - 'a' + 'A') : (ch))
#define TOLOWER(ch)     (((ch) >= 'A' && (ch) <= 'Z') ? ((ch) - 'A' + 'a') : (ch))
#define ISUPPER_(ch)    ((ch) >= 'A' && (ch) <= 'Z')
#define ISLOWER_(ch)    ((ch) >= 'a' && (ch) <= 'z')
#define ALIGN_UP(x, A)  ((((x) + (A) - 1) / (A)) * (A))
#define CONCAT(x, y)    (strcat(x, y))
#define READLINE_MAX    256
#define FILTER          '/'
#define RFILTER         '\\'
#define CASE            ':'
#define MSGWAIT         '$'
#define SELECT          ' '
#define PREFIX          '-'
#define LATEST_VERSION  VERSION
#define LATEST_VERSION  VERSION
#define NOTIFY_COMMAND  "notify-send "
#define COLOR_CYAN      "\033[36m"
#define COLOR_GREEN     "\033[32m"
#define COLOR_RED       "\033[31m"
#define COLOR_MAGENTA   "\033[35m"
#define COLOR_ORANGE    "\033[33m"
#define COLOR_WHITE     "\033[37m"
#define COLOR_RESET     "\033[0m"
#define QUEUE_OK         0
#define QUEUE_EMPTY     -1
#define QUEUE_FULL      -2
#ifdef _WIN32
#define OS 1
#elif _WIN64
#define OS 1
#elif __APPLE__
#define OS 2
#elif __linux__
#define OS 0
#endif

static char *GTAVdir, *MenuOpenKey;
static short opt;

void
start() {
    system("clear");

    for(int i = 0; i < 24; i++) {
        printf("\n%s%s%s", COLOR_CYAN, ascii[i], COLOR_RESET);
    }

    printf("\n");
    
    for(int i = 0; i < 3; i++) {
        printf("\n%s[%s%d%s]%s%s\n", 
            COLOR_GREEN,
            COLOR_CYAN,
            i + 1,
            COLOR_GREEN,
            COLOR_GREEN,
            options[i]
        );
    }

    printf("%s", COLOR_RESET);
    printf("\n%sMEI $> %s", COLOR_MAGENTA, COLOR_RESET);
    scanf("%d", &opt);
    switch(opt) {
        case 1:
            install();
        break;
        case 2:
            update();
        break;
        case 3:
            uninstall();
        break;
        default:
            printf("%s[%s!%s]%s%s%s\n",
                COLOR_RED,
                COLOR_WHITE,
                COLOR_RED,
                COLOR_RED,
                "ERROR: Invalid Option!",
                COLOR_RESET
            );
        break;
    }
    
}

void 
askGTAVdir() {
    printf("%s[%s?%s]%s %s%s\n",
        COLOR_MAGENTA,
        COLOR_WHITE,
        COLOR_MAGENTA,
        COLOR_MAGENTA,
        "Insert the GTAV directory:",
        COLOR_RESET
    );

    printf("%s", COLOR_RESET);
    printf("\n%sMEI $> %s", COLOR_MAGENTA, COLOR_RESET);
    scanf("%s", &GTAVdir);

    //Check if the directory exists
    struct stat sb;

    if (stat(GTAVdir, &sb) == 0 && S_ISDIR(sb.st_mode)) {
        printf("YES\n");
    } else {
        printf("%s[%s!%s]%s%s%s\n",
            COLOR_RED,
            COLOR_WHITE,
            COLOR_RED,
            COLOR_RED,
            "ERROR: Invalid directory provided!",
            COLOR_RESET
        );
    }
}

void 
install() {
    system("clear");
    askGTAVdir();
}

void 
update() {

}

void
uninstall() {

}

int 
main(char **argv, int argc) {
    start();
}
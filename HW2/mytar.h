#ifndef __MYTAR__
#define __MYTAR__

/* C++ Library */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

/* C Library */
#include <cmath>
#include <cstring>
#include <unistd.h>
using namespace std;

#define PATH_SIZE 1000
#define FILENAME_SIZE 100
#define FILEMODE_SIZE 8
#define ID_SIZE 8
#define FS_SIZE 12
#define MTIME_SIZE 12
#define CHKSUM_SIZE 8
#define LNAME_SIZE 100

#define USTAR_OFFSET 257
#define USTAR_ID_SIZE 6
#define USTAR_VER_SIZE 2
#define USTAR_NAME_SIZE 32
#define USTAR_DEVICE_NUM 8
#define USTAR_PREFIX_SIZE 155
#define USTAR_PAD_SIZE 12

struct TarHeader {
    char filename[FILENAME_SIZE];
    char filemode[FILEMODE_SIZE];
    char userid[ID_SIZE];
    char groupid[ID_SIZE];
    char filesize[FS_SIZE];
    char mtime[MTIME_SIZE];
    char checksum[CHKSUM_SIZE];
    char type;
    char lname[LNAME_SIZE];
    int fs;

    /* USTAR Section */
    char USTAR_id[USTAR_ID_SIZE];
    char USTAR_ver[USTAR_VER_SIZE];
    char username[USTAR_NAME_SIZE];
    char groupname[USTAR_NAME_SIZE];
    char devmajor[USTAR_DEVICE_NUM];
    char devminor[USTAR_DEVICE_NUM];
    char prefix[USTAR_PREFIX_SIZE];
    char pad[USTAR_PAD_SIZE];    

    TarHeader() {
        memset(filename, '\0', FILENAME_SIZE);
        memset(filemode, '\0', FILEMODE_SIZE);
        memset(userid, '\0', ID_SIZE);
        memset(groupid, '\0', ID_SIZE);
        memset(filesize, '\0', FS_SIZE);
        memset(mtime, '\0', MTIME_SIZE);
        memset(checksum, '\0', CHKSUM_SIZE);
        memset(lname, '\0', LNAME_SIZE);
        type = 0;
        fs = 0;
    }
};

typedef class MyTAR {
    private:
        int files;
        fstream in;
        vector <struct TarHeader> header;
        string FULL_PATH;

        void init();
        int OctToDec(char num[], int length);
        double log2(double x);


    public:
        MyTAR();
        bool openFile(int argc, char** argv);
        void readFile();
        void printPerm(char x);
        void printList();

} MyTAR;

#endif
#include "mytar.h"

MyTAR::MyTAR() {
    init();
}

void MyTAR::init() {
    files = 0;
}

int MyTAR::OctToDec(char num[], int length) {
    int sum = 0;
    for (int i = length - 2, j = 0; i >= 0; i--, j++) {
        if (num[i] == '0') continue;
        sum += (int)((num[i] - '0') * pow(8, j));
    }
    return sum;
}

bool MyTAR::openFile(int argc, char** argv) {
    
    /* check arguments */
    if (argc < 2) {
        cout << "No input file.\n" << endl;
        return false;
    }

    string temp;
    char path[PATH_SIZE];
    char buf[200];

    /* translate to absolute path (exclude ~) */
    if(strchr(argv[1], '.') != NULL && strchr(argv[1], '/') == NULL) {
        getcwd(path, PATH_SIZE);
        FULL_PATH = FULL_PATH.assign(path);
        FULL_PATH += "/";
        FULL_PATH = FULL_PATH.append(argv[1]);
    } else if(argv[1][0] == '.') {
        getcwd(path, PATH_SIZE);
        FULL_PATH = FULL_PATH.assign(path);
        FULL_PATH += string(argv[1]).substr(1);
    } else {
        FULL_PATH = FULL_PATH.assign(argv[1]);
    } 
    //cout << FULL_PATH << endl;
    
    /* open file */
    in.open(FULL_PATH, ios::in);
    if(!in.good()) {
        cout << "File Not Found!\n";
        return false;
    }

    /* check USTAR fomat */
    in.seekg(USTAR_OFFSET, ios::beg);
    in.read(buf, 6);
    temp = temp.assign(buf, 0, 5);
    if (temp != "ustar") {
        cout << "Not a ustar file.\nFile opening error." << endl;
        return false;
    }
    
    /*
    string str(path);
    size_t found = str.find_last_of("/");
    cout << "file: " << str.substr(found + 1) << endl;
    */

    in.seekg(0, ios::beg);
    return true;
}

double MyTAR::log2(double x) {
    return log(x) / log(2);
}


void MyTAR::readFile() {
    while(1) {
        struct TarHeader temp;
        in.read(temp.filename, FILENAME_SIZE);
        if (temp.filename[0] == '\0') break;
        in.read(temp.filemode, FILEMODE_SIZE);
        in.read(temp.userid, ID_SIZE);
        in.read(temp.groupid, ID_SIZE);
        in.read(temp.filesize, FS_SIZE);
        temp.fs = OctToDec(temp.filesize, FS_SIZE);
        in.read(temp.mtime, MTIME_SIZE);
        in.read(temp.checksum, CHKSUM_SIZE);
        in.get(temp.type);
        in.read(temp.lname, FILENAME_SIZE);
        in.read(temp.USTAR_id, USTAR_ID_SIZE);
        in.read(temp.USTAR_ver, USTAR_VER_SIZE);
        in.read(temp.username, USTAR_NAME_SIZE);
        in.read(temp.groupname, USTAR_NAME_SIZE);
        in.read(temp.devmajor, USTAR_DEVICE_NUM);
        in.read(temp.devminor, USTAR_DEVICE_NUM);
        in.read(temp.prefix, USTAR_PREFIX_SIZE);
        /*
        cout << "filename= " << temp.filename << endl;
        cout << "filemode= " << temp.filemode << endl;
        cout << "filesize= " << temp.fs << endl;
        cout << "type= " << temp.type << endl;
        cout << "username= " << temp.username << endl;
        cout << "groupname= " << temp.groupname << endl;
        */
        double i = log2(temp.fs);;
        if (temp.fs <= 0) {
            i = 0;
        } else {
            if (((int)(i * 10)) % 10 > 0) i = ((int)i) + 1;
            else i = (int)i;
        }       
        //cout << "i= " << i << endl << endl;

        if (i > 1) in.seekg((int)pow(2, (int)i), ios::cur);
        //cout << (int)pow(2, i-1) << endl;
        in.read(temp.pad, USTAR_PAD_SIZE);
        if(i == 8) in.seekg(256, ios::cur);
        files++;
        header.push_back(temp);
    }
    //cout << files;
    in.close();
}

void MyTAR::printPerm(char x) {
    switch(x) {
            case '0': cout << "---"; break;
            case '1': cout << "--x"; break;
            case '2': cout << "-w-"; break;
            case '3': cout << "-wx"; break;
            case '4': cout << "r--"; break;
            case '5': cout << "r-x"; break;
            case '6': cout << "rw-"; break;
            case '7': cout << "rwx"; break;
        }
}

void MyTAR::printList() {
    cout << "total " << files << " files" << endl;
    for (int i = 0; i < files; i++) {
        /* folder */
        if (header[i].type == '5') cout << 'd';
        else cout << '-';

        /* permission */
        printPerm(header[i].filemode[4]);
        printPerm(header[i].filemode[5]);
        printPerm(header[i].filemode[6]);

        /* id */
        cout << " " << left << setw(16) << header[i].username << left << setw(10) << header[i].groupname;

        /* filesize */
        cout << right << setw(10) << header[i].fs << " ";

        /* filepath */
        cout << header[i].filename << endl;
    }
}
 
    

    

    



    


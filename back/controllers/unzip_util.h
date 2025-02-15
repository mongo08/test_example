#pragma once

#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <zip.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <dirent.h>
#include <limits.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>
#include <limits.h>
#include <string.h>

enum ResultWork{
    BAD,
    SUCCESS,
};

class unzip_util
{
private:
    std::string path_to_file;
public:
    unzip_util(std::string path_to_file):path_to_file(path_to_file){};
    int extract_data();
};


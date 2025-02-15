#include "unzip_util.h"


int unzip_util::extract_data(){
    const char *archive;
    struct zip *za;
    struct zip_file *zf;
    struct zip_stat sb;
    char buf[100];
    int err;
    int i, len;
    int fd;
    long long sum;
    if ((za = zip_open(this->path_to_file.c_str(), 0, &err)) == NULL) {
        zip_error_to_str(buf, sizeof(buf), err, errno);
    }
 
    for (i = 0; i < zip_get_num_entries(za, 0); i++) {
        if (zip_stat_index(za, i, 0, &sb) == 0) {
            
            len = strlen(sb.name);
            if (sb.name[len - 1] == '/') {
                std::filesystem::create_directory(sb.name);
            } else {
                zf = zip_fopen_index(za, i, 0);
                if (!zf) {
                    std::cout<<"файл не открылся"<<std::endl;
                    return ResultWork::BAD;
                }
                std::ofstream fs(sb.name,std::ios::binary|std::ios::out);
 
                sum = 0;
                while (sum != sb.size) {
                    len = zip_fread(zf, buf, 100);
                    if (len < 0) {
                        std::cout<<"файл не считался"<<std::endl;
                        return ResultWork::BAD;
                    }
                    fs.write(buf,len);
                    sum += len;
                }
                fs.close();
                zip_fclose(zf);
            }
        } 
    }   
 
    if (zip_close(za) == -1) {
        std::cout<<"архив не закрылся"<<std::endl;
        return ResultWork::BAD;
    }
    else{
        return ResultWork::SUCCESS;
    }
 
}




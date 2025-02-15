#define DROGON_TEST_MAIN
#include <drogon/drogon_test.h>
#include <drogon/drogon.h>
#include "../controllers/unzip_util.h"

int ququ(){
    return unzip_util("архив 1.zip").extract_data();
}

DROGON_TEST(Sum)
{
    CHECK(ququ() == ResultWork::SUCCESS);
}

int main(int argc, char** argv)
{
    return drogon::test::run(argc, argv);
}

#include "../incl/Converter_JSON.h"
#include "../incl/Inverted_Index.h"
#include "gTest_Index.h"
#include "../incl/Search_Server.h"
#include "gTest_Searc.h"


int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

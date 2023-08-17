
#include "../incl/Converter_JSON.h"
#include "../incl/Inverted_Index.h"
#include "../incl/gTest.h"

//TEST(sample_test_case, sample_test)
//{
//    EXPECT_EQ(1, 1);
//}


int main() {
    Inverted_Index cl;
    std::vector<std::string> text =
            {
                    "milk milk milk milk water water water",
                    "milk water water",
                    "milk milk milk milk milk water water water water water",
                    "americano cappuccino"
            };
    cl.update_Document_Base(text);


    return 0;
}

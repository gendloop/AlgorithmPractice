#include "pch.h"

#include <iostream>

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::FLAGS_gtest_filter += "Example.Case1";

    // Test specific
#if 1
    
#endif

    // Test all
#if 0
   
#endif

    return RUN_ALL_TESTS();
}

// tests.cpp
#include "../boyermoore.cpp"
#include <gtest/gtest.h>

TEST(ChecksumTest, bat)
{
    BoyerMoore bm((char *)"bat");
    ASSERT_EQ(9,bm.search((char *)"tarataraabatara"));    
}

TEST(ChecksumTest, raab)
{
    BoyerMoore bm((char *)"raab");
    ASSERT_EQ(6,bm.search((char *)"tarataraabatara"));    
}

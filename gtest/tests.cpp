// tests.cpp
#include "../boyermoore.cpp"
#include <gtest/gtest.h>

TEST(ChecksumTest, bat)
{
    BoyerMoore bm((char *)"bat",(char *)"tarataraabatara");
    ASSERT_EQ(9,bm.search());    
}

TEST(ChecksumTest, raab)
{
    BoyerMoore bm((char *)"raab",(char *)"tarataraabatara");
    ASSERT_EQ(6,bm.search());    
}
TEST(ChecksumTest, bbb)
{
    BoyerMoore bm((char *)"bbb",(char *)"tarataraabatara");
    ASSERT_EQ(6,bm.search());    
}
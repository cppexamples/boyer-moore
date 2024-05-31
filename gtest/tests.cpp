// tests.cpp
#include "../boyermoore.cpp"
#include <gtest/gtest.h>

TEST(ChecksumTest, bat)
{
    char p[]="bat";
    char t[]="tabataraabatara";
     BoyerMoore bm(std::span(p,strlen(p)));
    ASSERT_EQ(2,bm.search(std::span(t,strlen(t))));    
}

TEST(ChecksumTest, raab)
{
    char p[]="raab";
    char t[]="tabataraabatara";
     BoyerMoore bm(std::span(p,strlen(p)));
    ASSERT_EQ(6,bm.search(std::span(t,strlen(t))));    
}

TEST(ChecksumTest, bbb)
{
    char p[]="bbb";
    char t[]="tabataraabatara";
     BoyerMoore bm(std::span(p,strlen(p)));
    ASSERT_EQ(15,bm.search(std::span(t,strlen(t))));     
}
#include "409.LongestPalindrome.h"
#include "gtest/gtest.h"


TEST(case_1,content)
{
	std::string str= "longestPalindrome";
    int ans = 9;
    EXPECT_EQ(longestPalindrome(str), ans);
}

TEST(case_2,content)
{
	std::string str= "abccccdd";
    int ans = 7;
    EXPECT_EQ(longestPalindrome(str), ans);
}

TEST(case_3,content)
{
	std::string str= "a";
    int ans = 1;
    EXPECT_EQ(longestPalindrome(str), ans);
}

TEST(case_4,content)
{
	std::string str= "abcaaaa";
    int ans = 5;
    EXPECT_EQ(longestPalindrome(str), ans);
}


TEST(case_6,content)
{
	std::string str= "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
    int ans = 983;
    EXPECT_EQ(longestPalindrome(str), ans);
}

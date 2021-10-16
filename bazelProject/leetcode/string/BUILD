cc_library(
	name = "14_LongestCommonPrefix",
	hdrs = ["14.LongestCommonPrefix.h"],
	srcs = ["14.LongestCommonPrefix.cpp"]
)

cc_binary(
	name  = "LongestCommonPrefixTest",
	srcs  = ["14.LongestCommonPrefixTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["14_LongestCommonPrefix",
			 "@googletest//:gtest_main"],
)
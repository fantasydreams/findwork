cc_library(
	name = "1_twoSum",
	hdrs = ["header.h"],
	srcs = ["1.twoSum.cc"]
)

cc_binary(
	name  = "twoSumTest",
	srcs  = ["1.twoSumTest.cc"],
	copts = ["-std=c++11"],
	deps  = ["1_twoSum",
			 "@googletest//:gtest_main"],
)
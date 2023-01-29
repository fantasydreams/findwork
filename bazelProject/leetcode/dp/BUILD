cc_library(
	name = "70ClimbingStairs",
	hdrs = ["70.ClimbingStairs.h"],
	srcs = ["70.ClimbingStairs.cpp"]
)

cc_binary(
	name  = "70ClimbingStairsTest",
	srcs  = ["70.ClimbingStairsTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["70ClimbingStairs",
			 "@googletest//:gtest_main"],
)
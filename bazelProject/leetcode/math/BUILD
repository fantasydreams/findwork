

cc_library(
	name = "231PowerofTwo",
	hdrs = ["231.PowerofTwo.h"],
	srcs = ["231.PowerofTwo.cpp"],
    copts = ["-std=c++11"],
)

cc_binary(
	name  = "231PowerofTwoTest",
	srcs  = ["231.PowerofTwoTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["231PowerofTwo",
			 "@googletest//:gtest_main"],
)
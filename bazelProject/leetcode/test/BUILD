cc_library(
	name = "code",
	hdrs = ["code.h"],
	srcs = ["code.cpp"]
)

cc_binary(
	name  = "testcase",
	srcs  = ["testcase.cpp"],
	copts = ["-std=c++11"],
	deps  = ["code",
			 "@googletest//:gtest_main"],
)
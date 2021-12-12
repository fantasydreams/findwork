cc_library(
	name = "linkComm",
	hdrs = ["linkcomm.h"],
	srcs = ["linkcomm.cpp"]
)

cc_library(
	name = "AddTwoNum",
	hdrs = ["2.AddTwoNumbers.h"],
	srcs = ["2.AddTwoNumbers.cpp"],
    copts = ["-std=c++11"],
	deps  = ["linkComm"],
)

cc_binary(
	name  = "AddTwoNumTest",
	srcs  = ["2.AddTwoNumberstest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["AddTwoNum",
			 "@googletest//:gtest_main"],
)
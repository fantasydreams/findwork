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

cc_library(
	name = "Median",
	hdrs = ["arraycomm.h",
			"4.MedianOfTwoSortedArrays.h",
		],
	srcs = ["4.MedianOfTwoSortedArrays.cpp"]
)

cc_binary(
	name  = "MedianTest",
	srcs  = ["4.MedianOfTwoSortedArraysTest.cpp",
		],
	copts = ["-std=c++11"],
	deps  = ["Median",
			 "@googletest//:gtest_main"],
)

cc_binary(
	name  = "otherTest",
	srcs  = ["otherTest.cc",
		],
	copts = ["-std=c++11"],
	deps  = ["Median"],
)
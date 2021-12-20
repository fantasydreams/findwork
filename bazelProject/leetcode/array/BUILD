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


cc_library(
	name = "7ReverseInteger",
	hdrs = ["7.ReverseInteger.h"],
	srcs = ["7.ReverseInteger.cpp"]
)

cc_binary(
	name  = "7ReverseIntegerTest",
	srcs  = ["7.ReverseIntegerTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["7ReverseInteger",
			 "@googletest//:gtest_main"],
)


cc_library(
	name = "9PalindromeNumber",
	hdrs = ["9.PalindromeNumber.h"],
	srcs = ["9.PalindromeNumber.cpp"]
)

cc_binary(
	name  = "9PalindromeNumberTest",
	srcs  = ["9.PalindromeNumberTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["9PalindromeNumber",
			 "@googletest//:gtest_main"],
)

cc_library(
	name = "1200MinimumAbsoluteDifference",
	hdrs = ["1200.MinimumAbsoluteDifference.h"],
	srcs = ["1200.MinimumAbsoluteDifference.cpp"]
)

cc_binary(
	name  = "1200MinimumAbsoluteDifferenceTest",
	srcs  = ["1200.MinimumAbsoluteDifferenceTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["1200MinimumAbsoluteDifference",
			 "@googletest//:gtest_main"],
)
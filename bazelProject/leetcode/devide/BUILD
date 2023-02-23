cc_library(
	name  = "241DifferentWaystoAddParentheses",
    hdrs  = ["241.DifferentWaystoAddParentheses.h"], 
	srcs  = ["241.DifferentWaystoAddParentheses.cpp"],
	copts  = ["-DNODE"],
)

cc_binary(
	name  = "241DifferentWaystoAddParenthesesTest",
	srcs  = ["241.DifferentWaystoAddParenthesesTest.cpp"],
	copts = [
		"-std=c++11",
		"-DNODE",
	],
	deps  = ["241DifferentWaystoAddParentheses",
			 "@googletest//:gtest_main"],
)
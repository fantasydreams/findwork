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

cc_library(
	name  = "932BeautifulArray",
    hdrs  = ["932.BeautifulArray.h"], 
	srcs  = ["932.BeautifulArray.cpp"],
	copts  = ["-DNODE"],
)

cc_binary(
	name  = "932BeautifulArrayTest",
	srcs  = ["932.BeautifulArrayTest.cpp"],
	copts = [
		"-std=c++11",
		"-DNODE",
	],
	deps  = ["932BeautifulArray",
			 "@googletest//:gtest_main"],
)

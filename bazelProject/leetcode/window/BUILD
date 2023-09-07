
cc_library(
    name = "76MinimumWindowSubstring",
    srcs = [
        "76.MinimumWindowSubstring.h", 
        "76.MinimumWindowSubstring.cpp"
    ],
    copts = ["-std=c++11"],
    visibility = ["//visibility:public"],
)



cc_binary(
    name = "76MinimumWindowSubstringTest",
    srcs = ["76.MinimumWindowSubstringTest.cpp"],
    copts = ["-std=c++11"],
	deps  = ["76MinimumWindowSubstring",
			 "@googletest//:gtest_main"],
    visibility = ["//visibility:public"],
)
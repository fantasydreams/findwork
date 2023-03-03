cc_library(
	name = "461HammingDistance",
	hdrs = ["461.HammingDistance.h"],
	srcs = ["461.HammingDistance.cpp"],
    copts = ["-std=c++11"],
)

cc_binary(
	name  = "461HammingDistanceTest",
	srcs  = ["461.HammingDistanceTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["461HammingDistance",
			 "@googletest//:gtest_main"],
)
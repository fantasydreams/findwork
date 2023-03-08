cc_library(
	name = "232ImplementQueueusingStacks",
	hdrs = ["232.ImplementQueueusingStacks.h"],
	srcs = ["232.ImplementQueueusingStacks.cpp"],
    copts = ["-std=c++11"],
)

cc_binary(
	name  = "232ImplementQueueusingStacksTest",
	srcs  = ["232.ImplementQueueusingStacksTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["232ImplementQueueusingStacks",
			 "@googletest//:gtest_main"],
)

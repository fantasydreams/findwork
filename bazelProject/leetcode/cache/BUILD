cc_library(
	name = "146LRUCache",
	hdrs = ["146.LRUCache.h"],
	srcs = ["146.LRUCache.cpp"]
)

cc_binary(
	name  = "146LRUCacheTest",
	srcs  = ["146.LRUCacheTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["146LRUCache",
			 "@googletest//:gtest_main"],
)
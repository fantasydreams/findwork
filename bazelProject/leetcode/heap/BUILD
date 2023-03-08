#cc_library(
#	name = "heapcomm",
#	hdrs = ["heapcomm.h"],
#	srcs = ["heapcomm.cpp"]
#)

#cc_binary(
#	name  = "heapcommtest",
#	srcs  = ["heapcommtest.cpp"],
#	copts = ["-std=c++11"],
#	deps  = ["treecomm",
#			 "@googletest//:gtest_main"],
#)


cc_library(
	name  = "347TopKFrequentElements",
    hdrs  = ["347.TopKFrequentElements.h"], 
	srcs  = ["347.TopKFrequentElements.cpp"],
	copts = ["-std=c++11"],
)

cc_binary(
	name  = "347TopKFrequentElementsTest",
	srcs  = ["347.TopKFrequentElementsTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["347TopKFrequentElements",
			 "@googletest//:gtest_main"],
)


cc_library(
	name  = "23MergekSortedLists",
    hdrs  = ["23.MergekSortedLists.h"], 
	srcs  = ["23.MergekSortedLists.cpp"],
	copts = ["-std=c++11"],
	deps  = ["//List:linkComm",
				],
)

cc_binary(
	name  = "23MergekSortedListsTest",
	srcs  = ["23.MergekSortedListsTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["23MergekSortedLists",
			 "@googletest//:gtest_main"],
)
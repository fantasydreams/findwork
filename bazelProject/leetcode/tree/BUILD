cc_library(
	name = "treecomm",
	hdrs = ["treecomm.h"],
	srcs = ["treecomm.cpp"]
)

cc_binary(
	name  = "treecommtest",
	srcs  = ["treecommtest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["treecomm",
			 "@googletest//:gtest_main"],
)


cc_library(
	name  = "938RangeSumofBSTT",
    hdrs  = ["938.RangeSumofBST.h"], 
	srcs  = ["938.RangeSumofBST.cpp"],
	deps  = ["treecomm"],
)

cc_binary(
	name  = "938RangeSumofBSTTTest",
	srcs  = ["938.RangeSumofBSTTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["938RangeSumofBSTT",
			 "@googletest//:gtest_main"],
)
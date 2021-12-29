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

cc_library(
	name  = "116PopulatingNextRightPointersinEachNode",
    hdrs  = ["116.PopulatingNextRightPointersinEachNode.h"], 
	srcs  = ["116.PopulatingNextRightPointersinEachNode.cpp"],
	deps  = ["treecomm"],
	copts  = ["-DNODE"],
)

cc_binary(
	name  = "116PopulatingNextRightPointersinEachNodeTest",
	srcs  = ["116.PopulatingNextRightPointersinEachNodeTest.cpp"],
	copts = [
		"-std=c++11",
		"-DNODE",
	],
	deps  = ["116PopulatingNextRightPointersinEachNode",
			 "@googletest//:gtest_main"],
)
cc_library(
	name = "treecomm",
	hdrs = ["treecomm.h"],
	srcs = ["treecomm.cpp"]
)

cc_library(
	name = "segmenttree",
	hdrs = ["segmenttree.h"],
	srcs = ["segmenttree.cpp"]
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

cc_library(
	name  = "257BinaryTreePaths",
    hdrs  = ["257.BinaryTreePaths.h"], 
	srcs  = ["257.BinaryTreePaths.cpp"],
	deps  = ["treecomm"],
	copts  = ["-DNODE"],
)

cc_binary(
	name  = "257BinaryTreePathsTest",
	srcs  = ["257.BinaryTreePathsTest.cpp"],
	copts = [
		"-std=c++11",
		"-DNODE",
	],
	deps  = ["257BinaryTreePaths",
			 "@googletest//:gtest_main"],
)

cc_library(
	name  = "310MinimumHeightTrees",
    hdrs  = ["310.MinimumHeightTrees.h"], 
	srcs  = ["310.MinimumHeightTrees.cpp"],
	deps  = ["treecomm"],
	copts  = ["-DNODE"],
)

cc_binary(
	name  = "310MinimumHeightTreesTest",
	srcs  = ["310.MinimumHeightTreesTest.cpp"],
	copts = [
		"-std=c++11",
		"-DNODE",
	],
	deps  = ["310MinimumHeightTrees",
			 "@googletest//:gtest_main"],
)

cc_library(
	name  = "307RangeSumQueryMutable",
    hdrs  = ["307.RangeSumQuery-Mutable.h"], 
	copts = ["-std=c++11"],
	deps  = [":segmenttree"],
)

cc_binary(
	name  = "307RangeSumQueryMutableTest",
	srcs  = ["307.RangeSumQuery-MutableTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["307RangeSumQueryMutable",
			 "@googletest//:gtest_main"],
)


cc_library(
	name  = "104MaximumDepthofBinaryTree",
    hdrs  = ["104.MaximumDepthofBinaryTree.h"], 
	srcs  = ["104.MaximumDepthofBinaryTree.cpp"],
	copts = ["-std=c++11"],
	deps  = [":treecomm"],
)

cc_binary(
	name  = "104MaximumDepthofBinaryTreeTest",
	srcs  = ["104.MaximumDepthofBinaryTreeTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["104MaximumDepthofBinaryTree",
			 "@googletest//:gtest_main"],
)


cc_library(
	name  = "110BalancedBinaryTree",
    hdrs  = ["110.BalancedBinaryTree.h"], 
	srcs  = ["110.BalancedBinaryTree.cpp"],
	copts = ["-std=c++11"],
	deps  = [":treecomm"],
)

cc_binary(
	name  = "110BalancedBinaryTreeTest",
	srcs  = ["110.BalancedBinaryTreeTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["110BalancedBinaryTree",
			 "@googletest//:gtest_main"],
)


cc_library(
	name  = "543DiameterofBinaryTree",
    hdrs  = ["543.DiameterofBinaryTree.h"], 
	srcs  = ["543.DiameterofBinaryTree.cpp"],
	copts = ["-std=c++11"],
	deps  = [":treecomm"],
)

cc_binary(
	name  = "543DiameterofBinaryTreeTest",
	srcs  = ["543.DiameterofBinaryTreeTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["543DiameterofBinaryTree",
			 "@googletest//:gtest_main"],
)

    
cc_library(
	name  = "437PathSumIII",
    hdrs  = ["437.PathSumIII.h"], 
	srcs  = ["437.PathSumIII.cpp"],
	copts = ["-std=c++11"],
	deps  = [":treecomm"],
)

cc_binary(
	name  = "437PathSumIIITest",
	srcs  = ["437.PathSumIIITest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["437PathSumIII",
			 "@googletest//:gtest_main"],
)



cc_library(
	name  = "101SymmetricTree",
    hdrs  = ["101.SymmetricTree.h"], 
	srcs  = ["101.SymmetricTree.cpp"],
	copts = ["-std=c++11"],
	deps  = [":treecomm"],
)

cc_binary(
	name  = "101SymmetricTreeTest",
	srcs  = ["101.SymmetricTreeTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["101SymmetricTree",
			 "@googletest//:gtest_main"],
)
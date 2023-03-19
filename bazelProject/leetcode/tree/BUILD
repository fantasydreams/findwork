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

cc_library(
	name  = "1110DeleteNodesAndReturnForest",
    hdrs  = ["1110.DeleteNodesAndReturnForest.h"], 
	srcs  = ["1110.DeleteNodesAndReturnForest.cpp"],
	copts = ["-std=c++11"],
	deps  = [":treecomm"],
)

cc_binary(
	name  = "1110DeleteNodesAndReturnForestTest",
	srcs  = ["1110.DeleteNodesAndReturnForestTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["1110DeleteNodesAndReturnForest",
			 "@googletest//:gtest_main"],
)


cc_library(
	name  = "637AverageofLevelsinBinaryTree",
    hdrs  = ["637.AverageofLevelsinBinaryTree.h"], 
	srcs  = ["637.AverageofLevelsinBinaryTree.cpp"],
	copts = ["-std=c++11"],
	deps  = [":treecomm"],
)

cc_binary(
	name  = "637AverageofLevelsinBinaryTreeTest",
	srcs  = ["637.AverageofLevelsinBinaryTreeTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["637AverageofLevelsinBinaryTree",
			 "@googletest//:gtest_main"],
)



cc_library(
	name  = "105ConstructBinaryTreefromPreorderandInorderTraversal",
    hdrs  = ["105.ConstructBinaryTreefromPreorderandInorderTraversal.h"], 
	srcs  = ["105.ConstructBinaryTreefromPreorderandInorderTraversal.cpp"],
	copts = ["-std=c++11"],
	deps  = [":treecomm"],
)

cc_binary(
	name  = "105ConstructBinaryTreefromPreorderandInorderTraversalTest",
	srcs  = ["105.ConstructBinaryTreefromPreorderandInorderTraversalTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["105ConstructBinaryTreefromPreorderandInorderTraversal",
			 "@googletest//:gtest_main"],
)

cc_library(
	name  = "144BinaryTreePreorderTraversal",
    hdrs  = ["144.BinaryTreePreorderTraversal.h"], 
	srcs  = ["144.BinaryTreePreorderTraversal.cpp"],
	copts = ["-std=c++11"],
	deps  = [":treecomm"],
)

cc_binary(
	name  = "144BinaryTreePreorderTraversalTest",
	srcs  = ["144.BinaryTreePreorderTraversalTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["144BinaryTreePreorderTraversal",
			 "@googletest//:gtest_main"],
)


cc_library(
	name  = "99RecoverBinarySearchTree",
    hdrs  = ["99.RecoverBinarySearchTree.h"], 
	srcs  = ["99.RecoverBinarySearchTree.cpp"],
	copts = ["-std=c++11"],
	deps  = [":treecomm"],
)

cc_binary(
	name  = "99RecoverBinarySearchTreeTest",
	srcs  = ["99.RecoverBinarySearchTreeTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["99RecoverBinarySearchTree",
			 "@googletest//:gtest_main"],
)


cc_library(
	name  = "208ImplementTriePrefixTree",
    hdrs  = ["208.ImplementTriePrefixTree.h"], 
	srcs  = ["208.ImplementTriePrefixTree.cpp"],
	copts = ["-std=c++11"],
	deps  = [":treecomm"],
)

cc_binary(
	name  = "208ImplementTriePrefixTreeTest",
	srcs  = ["208.ImplementTriePrefixTreeTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["208ImplementTriePrefixTree",
			 "@googletest//:gtest_main"],
)

cc_library(
	name  = "226InvertBinaryTree",
    hdrs  = ["226.InvertBinaryTree.h"], 
	srcs  = ["226.InvertBinaryTree.cpp"],
	copts = ["-std=c++11"],
	deps  = [":treecomm"],
)

cc_binary(
	name  = "226InvertBinaryTreeTest",
	srcs  = ["226.InvertBinaryTreeTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["226InvertBinaryTree",
			 "@googletest//:gtest_main"],
)



cc_library(
	name  = "617MergeTwoBinaryTrees",
    hdrs  = ["617.MergeTwoBinaryTrees.h"], 
	srcs  = ["617.MergeTwoBinaryTrees.cpp"],
	copts = ["-std=c++11"],
	deps  = [":treecomm"],
)

cc_binary(
	name  = "617MergeTwoBinaryTreesTest",
	srcs  = ["617.MergeTwoBinaryTreesTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["617MergeTwoBinaryTrees",
			 "@googletest//:gtest_main"],
)

cc_library(
	name  = "572SubtreeofAnotherTree",
    hdrs  = ["572.SubtreeofAnotherTree.h"], 
	srcs  = ["572.SubtreeofAnotherTree.cpp"],
	copts = ["-std=c++11"],
	deps  = [":treecomm"],
)

cc_binary(
	name  = "572SubtreeofAnotherTreeTest",
	srcs  = ["572.SubtreeofAnotherTreeTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["572SubtreeofAnotherTree",
			 "@googletest//:gtest_main"],
)

cc_library(
	name  = "404SumofLeftLeaves",
    hdrs  = ["404.SumofLeftLeaves.h"], 
	srcs  = ["404.SumofLeftLeaves.cpp"],
	copts = ["-std=c++11"],
	deps  = [":treecomm"],
)

cc_binary(
	name  = "404SumofLeftLeavesTest",
	srcs  = ["404.SumofLeftLeavesTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["404SumofLeftLeaves",
			 "@googletest//:gtest_main"],
)


cc_library(
	name  = "513FindBottomLeftTreeValue",
    hdrs  = ["513.FindBottomLeftTreeValue.h"], 
	srcs  = ["513.FindBottomLeftTreeValue.cpp"],
	copts = ["-std=c++11"],
	deps  = [":treecomm"],
)

cc_binary(
	name  = "513FindBottomLeftTreeValueTest",
	srcs  = ["513.FindBottomLeftTreeValueTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["513FindBottomLeftTreeValue",
			 "@googletest//:gtest_main"],
)


cc_library(
	name  = "538ConvertBSTtoGreaterTree",
    hdrs  = ["538.ConvertBSTtoGreaterTree.h"], 
	srcs  = ["538.ConvertBSTtoGreaterTree.cpp"],
	copts = ["-std=c++11"],
	deps  = [":treecomm"],
)

cc_binary(
	name  = "538ConvertBSTtoGreaterTreeTest",
	srcs  = ["538.ConvertBSTtoGreaterTreeTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["538ConvertBSTtoGreaterTree",
			 "@googletest//:gtest_main"],
)


cc_library(
	name  = "235LowestCommonAncestorofaBinarySearchTree",
    hdrs  = ["235.LowestCommonAncestorofaBinarySearchTree.h"], 
	srcs  = ["235.LowestCommonAncestorofaBinarySearchTree.cpp"],
	copts = ["-std=c++11"],
	deps  = [":treecomm"],
)

cc_binary(
	name  = "235LowestCommonAncestorofaBinarySearchTreeTest",
	srcs  = ["235.LowestCommonAncestorofaBinarySearchTreeTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["235LowestCommonAncestorofaBinarySearchTree",
			 "@googletest//:gtest_main"],
)


cc_library(
	name  = "530MinimumAbsoluteDifferenceinBST",
    hdrs  = ["530.MinimumAbsoluteDifferenceinBST.h"], 
	srcs  = ["530.MinimumAbsoluteDifferenceinBST.cpp"],
	copts = ["-std=c++11"],
	deps  = [":treecomm"],
)

cc_binary(
	name  = "530MinimumAbsoluteDifferenceinBSTTest",
	srcs  = ["530.MinimumAbsoluteDifferenceinBSTTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["530MinimumAbsoluteDifferenceinBST",
			 "@googletest//:gtest_main"],
)


cc_library(
	name  = "889ConstructBinaryTreefromPreorderandPostorderTraversal",
    hdrs  = ["889.ConstructBinaryTreefromPreorderandPostorderTraversal.h"], 
	srcs  = ["889.ConstructBinaryTreefromPreorderandPostorderTraversal.cpp"],
	copts = ["-std=c++11"],
	deps  = [":treecomm"],
)

cc_binary(
	name  = "889ConstructBinaryTreefromPreorderandPostorderTraversalTest",
	srcs  = ["889.ConstructBinaryTreefromPreorderandPostorderTraversalTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["889ConstructBinaryTreefromPreorderandPostorderTraversal",
			 "@googletest//:gtest_main"],
)


cc_library(
	name  = "106ConstructBinaryTreefromInorderandPostorderTraversal",
    hdrs  = ["106.ConstructBinaryTreefromInorderandPostorderTraversal.h"], 
	srcs  = ["106.ConstructBinaryTreefromInorderandPostorderTraversal.cpp"],
	copts = ["-std=c++11"],
	deps  = [":treecomm"],
)

cc_binary(
	name  = "106ConstructBinaryTreefromInorderandPostorderTraversalTest",
	srcs  = ["106.ConstructBinaryTreefromInorderandPostorderTraversalTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["106ConstructBinaryTreefromInorderandPostorderTraversal",
			 "@googletest//:gtest_main"],
)


cc_library(
	name  = "94BinaryTreeInorderTraversal",
    hdrs  = ["94.BinaryTreeInorderTraversal.h"], 
	srcs  = ["94.BinaryTreeInorderTraversal.cpp"],
	copts = ["-std=c++11"],
	deps  = [":treecomm"],
)

cc_binary(
	name  = "94BinaryTreeInorderTraversalTest",
	srcs  = ["94.BinaryTreeInorderTraversalTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["94BinaryTreeInorderTraversal",
			 "@googletest//:gtest_main"],
)


cc_library(
	name  = "145BinaryTreePostorderTraversal",
    hdrs  = ["145.BinaryTreePostorderTraversal.h"], 
	srcs  = ["145.BinaryTreePostorderTraversal.cpp"],
	copts = ["-std=c++11"],
	deps  = [":treecomm"],
)

cc_binary(
	name  = "145BinaryTreePostorderTraversalTest",
	srcs  = ["145.BinaryTreePostorderTraversalTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["145BinaryTreePostorderTraversal",
			 "@googletest//:gtest_main"],
)

cc_library(
	name  = "897IncreasingOrderSearchTree",
    hdrs  = ["897.IncreasingOrderSearchTree.h"], 
	srcs  = ["897.IncreasingOrderSearchTree.cpp"],
	copts = ["-std=c++11"],
	deps  = [":treecomm"],
)


cc_library(
	name  = "653TwoSumIVInputisaBST",
    hdrs  = ["653.TwoSumIVInputisaBST.h"], 
	srcs  = ["653.TwoSumIVInputisaBST.cpp"],
	copts = ["-std=c++11"],
	deps  = [":treecomm"],
)

cc_binary(
	name  = "653TwoSumIVInputisaBSTTest",
	srcs  = ["653.TwoSumIVInputisaBSTTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["653TwoSumIVInputisaBST",
			 "@googletest//:gtest_main"],
)


cc_library(
	name  = "450DeleteNodeinaBST",
    hdrs  = ["450.DeleteNodeinaBST.h"], 
	srcs  = ["450.DeleteNodeinaBST.cpp"],
	copts = ["-std=c++11"],
	deps  = [":treecomm"],
)

cc_binary(
	name  = "450DeleteNodeinaBSTTest",
	srcs  = ["450.DeleteNodeinaBSTTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["450DeleteNodeinaBST",
			 "@googletest//:gtest_main"],
)
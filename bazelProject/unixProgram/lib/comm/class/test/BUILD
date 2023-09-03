cc_binary(
	name  = "scopeguard_test",
	srcs  = ["scopeguard_test.cpp"],
	copts = ["-std=c++11"],
	deps  = ["//lib/comm/class:scopeguard",
			 "@googletest//:gtest_main"],
)

cc_binary(
	name  = "singleton_test",
	srcs  = ["singleton_test.cpp"],
	copts = ["-std=c++11"],
	deps  = ["//lib/comm/class/mode:singleton",
			 "@googletest//:gtest_main"],
)

cc_binary(
	name  = "factory_test",
	srcs  = ["factory_test.cpp"],
	copts = ["-std=c++11"],
	deps  = [
		"//lib/comm/class/mode:factory",
		"//lib/comm/class:scopeguard",
		"@googletest//:gtest_main"
	],
)
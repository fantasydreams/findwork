cc_library(
    name = "bintree",
    hdrs = ["bintree.h"],
    copts = ["-std=c++11"],
    visibility = ["//visibility:public"]
)

cc_binary(
    name = "bintree_test",
    srcs = [
            "bintree_test.cpp",
            "bintreetools.h",
        ],
    deps = [
            "bintree",
            "//lib/string:stringlib",
            "@googletest//:gtest_main",
        ],
    copts = ["-std=c++11"],
)
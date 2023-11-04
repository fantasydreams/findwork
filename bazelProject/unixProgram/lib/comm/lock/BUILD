cc_library(
    name = "spin_lock",
    hdrs = ["spinlook.h"],
    copts = [
        "-std=c++11",
        "-l"
    ],
    deps = [
        "//lib/comm/class:nocopyable",
        "//lib/comm/class:exception",
    ],
    visibility = ["//visibility:public"]
)

cc_binary(
    name = "locktest",
    srcs = [
            "locktest.cpp",
        ],
    deps = [
            ":spin_lock",
            "@googletest//:gtest_main",
        ],
    copts = ["-std=c++11"],
)
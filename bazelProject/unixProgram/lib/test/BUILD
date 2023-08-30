cc_binary(
    name = "str_test",
    srcs = ["str_test.cc"],
    deps = ["//lib/string:stringlib",
            "@googletest//:gtest_main",
        ],
    copts = ["-std=c++11"],
)


cc_binary(
    name = "mode_test",
    srcs = ["mode_test.cc"],
    deps = ["//lib/file:mode",
            "@googletest//:gtest_main",
        ],
    copts = ["-std=c++11"],
)


cc_test(
    name = "mode_test_c",
    srcs = ["mode_test.cc"],
    deps = ["//lib/file:mode",
            "@googletest//:gtest_main",
        ],
    copts = [
        "-std=c++11",
        "-fprofile-arcs",
        "-ftest-coverage",
    ],
    linkopts = ["-fprofile-arcs"],
)

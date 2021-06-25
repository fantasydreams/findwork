load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "dupWrite",
    srcs = ["myio.h",
            "myio.cc"],
    deps = ["//lib/err:myerr",
            "//lib/condition:condition"],
    copts = ["-std=c++11"],
)

cc_binary(
    name = "test_o_append",
    srcs = ["test_o_append_rw.h",
            "test_o_append_rw.cc",
        ],
    deps = ["//lib/err:myerr",
            "//lib/condition:condition",
        ],
    copts = ["-std=c++11"]
)
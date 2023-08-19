cc_binary(
    name = "so_single_server",
    srcs = ["so_single_server.cpp",
        ],
    deps = ["//lib/err:myerr",
            "//lib/condition:condition",
            "//lib/string:stringlib",
            "//lib/file:mode",
        ],
    copts = ["-std=c++11"],
)


cc_binary(
    name = "so_multithread_server",
    srcs = ["so_multithread_server.cpp",
        ],
    deps = ["//lib/err:myerr",
            "//lib/condition:condition",
            "//lib/string:stringlib",
            "//lib/file:mode",
        ],
    copts = ["-std=c++11"],
)

cc_binary(
    name = "so_select_server",
    srcs = ["so_select_server.cpp",
        ],
    deps = ["//lib/err:myerr",
            "//lib/condition:condition",
            "//lib/string:stringlib",
            "//lib/file:mode",
        ],
    copts = ["-std=c++11"],
)


cc_binary(
    name = "so_test_tcp_server",
    srcs = ["so_test_tcp_server.cpp",
        ],
    deps = ["//lib/err:myerr",
            "//lib/condition:condition",
            "//lib/string:stringlib",
            "//lib/file:mode",
        ],
    copts = ["-std=c++11"],
)

cc_binary(
    name = "so_test_tcp_client",
    srcs = ["so_test_tcp_client.cpp",
        ],
    deps = ["//lib/err:myerr",
            "//lib/condition:condition",
            "//lib/string:stringlib",
            "//lib/file:mode",
            "//lib/term:term",
        ],
    copts = ["-std=c++11"],
)
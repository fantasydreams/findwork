load("@bazel_tools//tools/build_defs/cc:action_names.bzl", "ACTION_NAMES")
load(
    "@bazel_tools//tools/cpp:cc_toolchain_config_lib.bzl",
    "feature",
    "flag_group",
    "flag_set",
    "tool_path",
)

all_link_actions = [ # NEW
    ACTION_NAMES.cpp_link_executable,
    ACTION_NAMES.cpp_link_dynamic_library,
    ACTION_NAMES.cpp_link_nodeps_dynamic_library,
]

all_compile_actions = [
    ACTION_NAMES.cc_flags_make_variable,
    ACTION_NAMES.c_compile,
    ACTION_NAMES.cpp_compile,
    ACTION_NAMES.cpp_header_parsing,
]

def _impl(ctx):
    tool_paths = [ # NEW
        tool_path(
            name = "gcc",
            path = "/opt/homebrew/Cellar/gcc/13.1.0/bin/gcc-13",
        ),
        tool_path(
            name = "ld",
            path = "/usr/bin/ld",
        ),
        tool_path(
            name = "ar",
            path = "/opt/homebrew/Cellar/gcc/13.1.0/bin/gcc-ar-13",
        ),
        tool_path(
            name = "cpp",
            path = "/opt/homebrew/Cellar/gcc/13.1.0/bin/g++-13",
        ),
        tool_path(
            name = "gcov",
            path = "/bin/false",
        ),
        tool_path(
            name = "nm",
            path = "/opt/homebrew/Cellar/gcc/13.1.0/bin/gcc-nm-13",
        ),
        tool_path(
            name = "objdump",
            path = "/opt/homebrew/Cellar/gcc/13.1.0/bin/gcov-dump-13",
        ),
        tool_path(
            name = "strip",
            path = "/bin/false",
        ),
    ]

    features = [ # NEW
        feature(
            name = "default_linker_flags",
            enabled = True,
            flag_sets = [
                flag_set(
                    actions = all_link_actions,
                    flag_groups = ([
                        flag_group(flags = ["-rcs"]),
                        flag_group(
                            flags = [
                                "-lstdc++",
                            ],
                        ),
                    ]),
                ),
            ],
        ),
    ]

    return cc_common.create_cc_toolchain_config_info(
        ctx = ctx,
        features = features, # NEW
        cxx_builtin_include_directories = [ # NEW
            "/opt/homebrew/Cellar/gcc/13.1.0/include/c++/13",
            "/Library/Developer/CommandLineTools/SDKs/MacOSX13.sdk/usr/include/",
            "/opt/homebrew/Cellar/gcc/13.1.0/lib/gcc/current/gcc/aarch64-apple-darwin22/13",
        ],
        toolchain_identifier = "darwin_arm64-toolchain",
        host_system_name = "local",
        target_system_name = "local",
        target_cpu = "darwin_arm64",
        target_libc = "unknown",
        compiler = "gcc",
        abi_version = "unknown",
        abi_libc_version = "unknown",
        tool_paths = tool_paths, # NEW
    )

cc_toolchain_config = rule(
    implementation = _impl,
    attrs = {},
    provides = [CcToolchainConfigInfo],
)
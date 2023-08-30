load(":cc_toolchain_config.bzl", "cc_toolchain_config")
package(default_visibility = ["//visibility:public"])

cc_toolchain_suite(
    name = "clang_suite",
    toolchains = {
        "darwin_arm64": ":darwin_arm64_toolchain",
    },
)

filegroup(name = "empty")

filegroup(
    name = "all",
    srcs = glob(["**/*",]),
)

cc_toolchain_config(name = "darwin_arm64_toolchain_config")

cc_toolchain(
    name = "darwin_arm64_toolchain",
    toolchain_identifier = "darwin_arm64-toolchain",
    toolchain_config = ":darwin_arm64_toolchain_config",
    all_files = ":all",
    compiler_files = ":all",
    dwp_files = ":all",
    linker_files = ":all",
    objcopy_files = ":all",
    strip_files = ":all",
    supports_param_files = 0,
)
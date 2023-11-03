# Given a text file file.txt that contains a list of phone numbers (one per line), write a one-liner bash script to print all valid phone numbers.

# You may assume that a valid phone number must appear in one of the following two formats: (xxx) xxx-xxxx or xxx-xxx-xxxx. (x means a digit)

# You may also assume each line in the text file must not contain leading or trailing white spaces.

# Example:

# Assume that file.txt has the following content:

# 987-123-4567
# 123 456 7890
# (123) 456-7890
# Your script should output the following valid phone numbers:

# 987-123-4567
# (123) 456-7890


#/bin/sh

# Read from the file file.txt and output all valid phone numbers to stdout.


# awk '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/' file.txt
# gawk '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/' file.txt

grep -E '^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$' file.txt # BSD grep 
grep -P '^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$' file.txt # -P 是以perl的GUN 主要是因为Mac和Linux采用的标准不一样的。Mac中自带的是BSD grep，Linux则是GNU grep，从感官上两者是一个东西（这也是程序设计的一个原则），但具体实现是不一样的，具体的grep 选项可以通过man手册来查看。从效率上，记得GNU grep的原作者还阐述过为什么GNU grep比BSD grep效率更高。


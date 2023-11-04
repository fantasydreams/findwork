# Given a text file file.txt, print just the 10th line of the file.

# Example:

# Assume that file.txt has the following content:

# Line 1
# Line 2
# Line 3
# Line 4
# Line 5
# Line 6
# Line 7
# Line 8
# Line 9
# Line 10
# Your script should output the tenth line, which is:

# Line 10
# Note:
# 1. If the file contains less than 10 lines, what should you output?
# 2. There's at least three different solutions. Try to explore all possibilities.

#/bin/sh
# head -n 10 file.txt | tail -1 // 这个如果文件少于10行就不行了
# sed -n '10p' file.txt

# awk 'NR==10' file.txt

#tail -n+10 file.txt | head -n 1
# 2. 如果你想查看文件的后10行，可以使用tail命令，如：
# tail -n 10 /etc/passwd
# 3. 如果想从文件的第十行开始查看，则使用命令
# tail -n +10 /etc/passwd

#tail -n+10 file.txt | head -1
# head -n 1等价于 head -1

# cnt=0
# while read line || [[ -n $line ]]  # 如果文件不是unix格式，可能导致最后一行消失，这里加一下判断字符串是否存在就可以
# do
#     # echo $line
#     let 'cnt = cnt + 1'
#     if [ $cnt -lt 9 ]
#     then
#         continue
#     elif [ $cnt -eq 10 ]
#     then
#         echo $line
#         break
#     fi
# done < file.txt


cnt=0
cat file.txt | while read line || [[ -n $line ]]
do
    let 'cnt = cnt + 1'
    if [[ $cnt -lt 10 ]]
    then
        continue
    elif [[ $cnt -eq 10 ]]
    then 
        echo $line
        break
    fi
done 
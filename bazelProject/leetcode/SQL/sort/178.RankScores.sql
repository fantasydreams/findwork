Table: Scores

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| score       | decimal |
+-------------+---------+
id is the primary key (column with unique values) for this table.
Each row of this table contains the score of a game. Score is a floating point value with two decimal places.
 

Write a solution to find the rank of the scores. The ranking should be calculated according to the following rules:

The scores should be ranked from the highest to the lowest.
If there is a tie between two scores, both should have the same ranking.
After a tie, the next ranking number should be the next consecutive integer value. In other words, there should be no holes between ranks.
Return the result table ordered by score in descending order.

The result format is in the following example.

 

Example 1:

Input: 
Scores table:
+----+-------+
| id | score |
+----+-------+
| 1  | 3.50  |
| 2  | 3.65  |
| 3  | 4.00  |
| 4  | 3.85  |
| 5  | 4.00  |
| 6  | 3.65  |
+----+-------+
Output: 
+-------+------+
| score | rank |
+-------+------+
| 4.00  | 1    |
| 4.00  | 1    |
| 3.85  | 2    |
| 3.65  | 3    |
| 3.65  | 3    |
| 3.50  | 4    |
+-------+------+


#sql 
SELECT S.Score, COUNT(S2.Score) as `Rank`
FROM Scores S,
(SELECT DISTINCT Score FROM Scores) S2
WHERE S.Score<=S2.Score
GROUP BY S.Id
ORDER BY S.Score DESC;

#sql https://blog.csdn.net/qq_46105170/article/details/108944472
SELECT score, DENSE_RANK() over (ORDER By score DESC) `rank` FROM Scores;


# https://www.cnblogs.com/rever/p/7149995.html
select 
    score, 
    @i := @i + (@pre <> ( @pre := score)) `Rank`
from 
    scores, 
    (select @i := 0,@pre := -1) init 
order by score desc

select 
    score, 
    @i:=@i + (@pre<>(@pre:=score)) as `rank`
from 
    scores, 
    (select @i:=0,@pre:=-1) init
order by score desc


# 直接一看， 有一点蒙，实际上，这道题考察的是，给定一个分数，有多少个大于等于，每个分数只计算一次
https://github.com/zhanguohao/leetcode/blob/master/LeetCode/LeetCode:%20178.%E5%88%86%E6%95%B0%E6%8E%92%E5%90%8D.md

select score , (select count(distinct score) from scores as s2 where s1.score <=s2.score) as `rank` from scores s1 order by score desc;

# 效率太低了
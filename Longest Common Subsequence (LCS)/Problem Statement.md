Problem Statement<br>

Modify the algorithm for finding the Longest Common Subsequence (LCS) of <br>
two strings to determine the LCS of three strings and print the results.

Input Format<br>
You are given three strings, s1, s2, and s3.<br>

Output Format<br>
Print the length of the Longest Common Subsequence (LCS).<br>

Print the LCS itself.<br>

Example Test Cases<br>
                    
<b>Test Case 1:</b><br>
<b>Input:</b><br>
s1 = "abcde"<br>
s2 = "acebd"<br>
s3 = "abedc"<br>
<b>Expected Output:</b><br>
Length of LCS = 3<br>
LCS = "abd"<br>

<b>Test Case 2:</b><br>
<b>Input:</b><br>
s1 = "abc"<br>
s2 = "xyz"<br>
s3 = "pq"<br>
<b>Expected Output:</b><br>
Length of LCS = 0<br>
LCS = ""<br>

<b>Test Case 3:</b><br>
<b>Input:</b><br>
s1 = "abcxyz"<br>
s2 = "xaybcz"<br>
s3 = "abxzcy"<br>
<b>Expected Output:</b><br>
Length of LCS = 3<br>
LCS = "abc"<br>

<b>Test Case 4:</b><br>
<b>Input:</b><br>
s1 = "abcdefgh"<br>
s2 = "zbcodfgh"<br>
s3 = "acdfghz"<br>
<b>Expected Output:</b><br>
Length of LCS = 5<br>
LCS = "cdfgh"<br>

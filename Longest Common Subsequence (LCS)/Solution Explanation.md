Explanation:<br>

DP Table Initialization:<br>
A 3D list dp[m+1][n+1][o+1] is created, where m, n, and o are the lengths of s1, s2, and s3, respectively.<br>
dp[i][j][k] stores the LCS length for substrings s1[0:i], s2[0:j], and s3[0:k].<br>

Filling the DP Table:<br>
If the current characters in all three strings match, we increment <br>
the LCS length from the previous state (dp[i-1][j-1][k-1] + 1).<br>

Otherwise, we take the maximum of three possible LCS values <br>
(ignoring one character from any of the three strings).<br>

Backtracking to Retrieve LCS String:<br>
Start from dp[m][n][o] and move backward.<br>
If the characters match, add them to the LCS and move diagonally (i-1, j-1, k-1).<br>
Otherwise, move in the direction where the LCS length remains the same.<br>

Final Output:<br>
Prints both the length and the actual LCS string.<br>

Time & Space Complexity Analysis:<br>
Time Complexity: O(m×n×o), as we iterate through a 3D table.<br>

Space Complexity: O(m×n×o), for storing the DP table.<br>


An example to understand how the LCS of three strings is found using Dynamic Programming (DP).<br>

Input:<br>
s1 = "abcde"<br>
s2 = "acebd"<br>
s3 = "abedc"<br>
Expected Output:<br>
Length of LCS = 3<br>
LCS = "abd"<br>

Step 1: Create a 3D DP Table<br>
We create a 3D DP table, where dp[i][j][k] stores the LCS length of the substrings s1[0:i], s2[0:j], and s3[0:k].<br>

The dimensions of the DP table are:<br>
m = len(s1) = 5<br>
n = len(s2) = 5<br>
o = len(s3) = 5<br>
So, we initialize dp[6][6][6] with all zeroes (we use m+1, n+1, o+1 to handle base cases).<br>

Step 2: Fill the DP Table<br>
Transition Formula:<br>
If characters of s1[i-1], s2[j-1], and s3[k-1] are equal, then:<br>
dp[i][j][k]=dp[i−1][j−1][k−1]+1<br>

Otherwise, take the maximum from possible previous states:<br>
dp[i][j][k]=max(dp[i−1][j][k],dp[i][j−1][k],dp[i][j][k−1])<br>

Let's fill the table step by step.<br>

Matching Characters:<br>
s1[0] = s2[0] = s3[0] = 'a' → dp[1][1][1] = 1<br>
s1[1] = s2[2] = s3[1] = 'b' → dp[2][3][2] = 2<br>
s1[3] = s2[4] = s3[3] = 'd' → dp[4][5][4] = 3<br>
Thus, LCS length = 3.<br>

Step 3: Backtracking to Find LCS<br>
We backtrack from dp[5][5][5] to reconstruct the LCS.<br>

At (5,5,5): dp[5][5][5] = 3 → move to dp[4][5][4]<br>
At (4,5,4): 'd' is part of LCS → move to dp[2][3][2]<br>
At (2,3,2): 'b' is part of LCS → move to dp[1][1][1]<br>
At (1,1,1): 'a' is part of LCS<br>
Thus, LCS = "abd".<br>

Final Output<br>
Length of LCS = 3<br>
LCS = "abd"<br>

<b>Naïve String Matching Algorithm</b><br>

The Naïve String Matching Algorithm is the simplest approach to finding a pattern in a text.<br>
It works by checking every possible position in the text to see if the pattern matches.<br>
________________________________________
<b>1. How It Works</b><br>
1.	Start at the first character of the text.<br>
2.	Compare the pattern with the text character by character.<br>
3.	If a mismatch occurs, shift the pattern one position to the right and repeat.<br>
4.	If all characters match, record the index where the pattern is found.<br>
5.	Continue until the end of the text.<br>
________________________________________
<b>2. Example</b>
Text: "AABAACAADAABAABA"<br>
Pattern: "AABA"<br>

<b>Step-by-step Matching Process</b><br>
<b>Position</b>	    <b>Text</b>    <b>Window</b>	       <b>Match?</b><br>
0            	AABA	  ✅             Yes (Pattern found at index 0)<br>
1            	ABAA	  ❌             No<br>
2            	BAAC	  ❌             No<br>
3            	AACA	  ❌             No<br>
4            	ACAD	  ❌             No<br>
5            	CAAD	  ❌             No<br>
6            	AADA	  ❌             No<br>
7            	ADAA	  ❌             No<br>
8            	DAAB	  ❌             No<br>
9            	AABA	  ✅             Yes (Pattern found at index 9)<br>
10          	ABAA	  ❌             No<br>
11          	BAAB	  ❌             No<br>
12          	AABA	  ✅             Yes (Pattern found at index 12)<br>
<b>Output:</b><br>
Pattern found at indices 0, 9, and 12.<br>
________________________________________
<b>3. Time Complexity Analysis</b><br>
<b>Case</b>	                                                    <b>Time Complexity</b><br>
Best Case (Mismatch on first character each time)	            O(n)<br>
Worst Case (Pattern matches many times or at the end)	        O(m⋅n)<br>
<b>•	Best Case Example:</b><br>
o	Text: "ABCDEFGHIJK"<br>
o	Pattern: "XYZ" (Mismatch at first character every time → O(n).<br>
•	Worst Case Example:<br>
o	Text: "AAAAAAAAAA"<br>
o	Pattern: "AAA" (Overlapping matches → O(m⋅n).<br>
________________________________________
<b>4. When to Use the Naïve Algorithm?</b><br>
✅ Small Texts: Works well for short texts and patterns.<br>
✅ Simple Applications: Quick and easy to implement.<br>
❌ Inefficient for Large Texts: Slower than KMP or Boyer-Moore for long texts.<br>
________________________________________
<b>5. Applications</b><br>
•	Basic text searching in small texts.<br>
•	Introductory algorithm for understanding pattern matching.<br>
•	Simple log file searching.<br>
________________________________________


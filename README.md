# Dynamic-Caesar-Cypher

<p style="font-size: small"> <em> DISCLAIMER: THIS PROJECT DOES NOT CLAIM TO REVOLUTIONISE THE FIELD OF CRYPTOLOGY, AND THIS ENCRYPTION METHOD PROVIDES ABSOLUTELY NO SECURITY. THIS IS, HOWEVER, A FUN LITTLE PROJECT I MADE WHILE WAITING FOR MY COFFEE AT STARBUCKS </em> </p>
<br/>
<p> A Caesar Cypher is a shifting cypher achieved by shifting the alphabet some number of times. For example, given a right shift value of 3, works as follows: (A:D ; B:E ; C:F). Unfortunately, being one of the simplest encryption techniques, it has its limitations. </p> 
<br/>
<p> If, for example, a spy could intercept cyphertext, they will be able to crack the code simply with frequency analysis. This is due to the fact that a simple substitution method like CC will only encrypt one letter with another. With a right shift value of 3, A will always be D. When one analyses the frequency of a letter in a cyphertext, one will be able to associate the most frequent letter with 'E', the most frequent letter int he English alphabet.</p>
<br/>
<p> The author attempts to remedy this with a simple solution: shifting the shift every letter. By doing this, one is essentially using multiple codes in one message. This also means that one letter can now be substituted by many letters. In this program, the shift value increases every letter encrypted. </p>

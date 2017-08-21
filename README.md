# Dynamic-Caesar-Cypher

A Caesar Cypher is a shifting cypher achieved by shifting the alphabet some number of times. If the shift value is 3, then the cypher works as follows:
  A = D, 
  B = E, 
  C = F, 
  .
  .
  .  
The problem with the Caesar cypher is that it is predictable and, thus, easily crackable using various techniques. For example, in English text, the most commonly-used letter is 'E'. Using this, we can find the commonly used letter in the code, find the shift value, and we'll be on our way to cracking the code.  
One way to solve this problem is to use a dynamic Caesar cypher where the shift value moves by one every letter. Using the example above, the code now becomes:
  A = D (shift: 3), 
  B = F (shift: 4), 
  C = H (shift: 5), 
  .
  .
  .  
When using this method, the most commonly-used letter in the code in so longer decrypts to 'E'. Also, unlike the regular Caesar cypher where one letter substitutes another, multiple letters can now substitute a single letter, adding complexity.

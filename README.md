# Dynamic Caesar Cypher

_DISCLAIMER: This was a fun little project I made while waiting for my coffee, not a revolution in cryptology._

_(Updated in 2023-12-07, six years after I wrote this) I've now become more familiar with cryptography, and I've now learnt (as I had suspected in my disclaimer above) that this is in fact an existing cipher and not a revolution in cryptography!(Who would have guessed! /s)_

_This cipher is called the 'Trithemius cipher', created by Johannes Trithemius and published on his book Polygraphia in 1518 (according to Wikipedia[^1], which cites Kahn[^2]. TBH I never bothered to verify this claim.) The Wiki article even discusses the advantages I found! It also discussed the improvements since then. Oh well. Better 499 years late than never 🤷._

A [Caesar Cypher](https://en.wikipedia.org/wiki/Caesar_cipher) is a substitution cypher where each letter of the alphabet is shifted some number of times. For example, given a right shift value of 3, A is replaced with D, B with E, and so on. Unfortunately, being one of the simplest encryption techniques, it has its limitations.~~

One of these limitations is its vulnerability to [frequency analysis](https://en.wikipedia.org/wiki/Frequency_analysis). This vulnerability exists because one letter is substituted with another, _all of the time_, meaning the frequncy distribution is preserved in encryption. For instance, letters like E, A, and T are common while Z, X, and Q are rare.

This dynamic version of the Caesar cypher attempts to remedy this with a simple solution: shifting the shift every letter. By doing this, one is essentially using multiple shift values in one message. This also means that one letter can now be substituted by many letters. In this ancryption method, the shift value increases every letter encrypted.

## Licence

This project is licensed under the MIT Licence. See [LICENCE](LICENCE) for details.

[^1]: 'Tabula recta', _Wikipedia_, 2020 Mar. 09. https://en.wikipedia.org/wiki/Tabula_recta
[^2]: D. Kahn, The codebreakers : the comprehensive history of secret communication from ancient times to the Internet, 2nd ed. New York: Scribner’s And Sons, 1996, p. 133.

# klein_attack

This project was done in the course of **Arnab Roy** during my intership in Austria.

The goal of this project was to use the knowledge we have learned in class on a topic from a
research paper. This will allow us to confront a real problem of an advanced level. We will try
to implement an attack thanks to this paper to see that it doesn’t work only theoretically but
that it is also effective in practice.

My subject for this project is to find a differential attack on KLEIN64 on the maximum of round.
For that we will first introduce and describe KLEIN. Then I will describe the properties that
were useful to me and the weaknesses that were found on KLEIN. Finally, I will explain how I
have done to attack KLEIN64 between 2 and 6 rounds.

Without going into details, KLEIN64 is a 64 bits block cipher. The attack consists in first finding
the lower nibbles. Thus, it is possible to find 32 bits with a differential attack. Then, the higher
nibbles can be recovered by brute force or by using a trick again, so we can also reduce the
complexity of this part. Thus, we will show that it is possible to have an $O(2^{24})$ attack for 5
rounds and $O(2^{30})$ for 6 rounds to fully recover the key.

# test

The key is generated randomly. You just have to run the `main.c` file.

* If you want to choose your own key modify : `key`
* If you want to chose the number of round from 2 to 6 modify : `ROUNDS_64` in klein64.h
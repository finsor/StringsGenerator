# StringsGenerator

A cryptographically secure (using Wincrypt library) regular-expression-defined random expressions generator. Very good for creating passwords and generating password dictionaries (C++).

Better read raw.

REGEX  
Used to reverse the original use of regular expressions.  
For example, the following:  
(http:\\/\\/)/?www\\.google\\.com
generates either "http://www.google.com" or "www.google.com".  
  
Very useful for creating passwords.
  
Usage as of Dec 2016:  
 \  Literal - escape any of the following.  
( ) Brackets that contain a regular expression. Used for Ordering.  
[ ] Brackets that contain a regular expression that represents a characters collection.  
    Randomly returns a character from result, or not from result if used with '^'.  
{ } Brackets that contain a regular expression of a number that multiplies last expression.  
 -  Represents a range of characters of same type. For example, 0-3 translates to 0123 .  
 |  Logical 'OR' - Randomly returns either of its arguments.  
 .  Turns into a randomly chosen printable character.  
 *  Turns into a random string in a size between 0 and 255.  
 /  Replaces an expression with another expression before processing:  
    /? stands for {[01]}  
    /A stands for [A-Z]  
    /D stands for [^0-9]  
    /N stands for [^A-Z]  
    /W stands for [^0-9a-zA-Z_]  
    /a stands for [a-z]  
    /d stands for [0-9]  
    /n stands for [^a-z]  
    /w stands for [0-9a-zA-Z_]\n\
\\n stands for newline\n\
\\t stands for tab char\n\ 
  
  
SEQUENCE  
Program used to create linear sequences.

Gets a start value, a stop value, and a difference.
Can optinally add preceding, following and separating values.

Usage:
[precede:]start:[separator:]stop:[follower:]difference

For example, the following input:
before\:\n:1z:\nsep\n:2e:\n\:after:2

generates the following output:
before:
1z
sep
2b
sep
2d
:after

For another example, the following input:
"char abc[] = { ':a:', ':e:' };:1"

generates the following output:
char abc[] = { 'a', 'b', 'c', 'd', 'e' };

Much time saved !

Be creative. It's great for password bruteforcing!
  
Or Fins

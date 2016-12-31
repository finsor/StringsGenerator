# StringsGenerator

REGEX  
Used to reverse the original use of regular expressions.  
For example, the following:  
  
generates either "http://www.google.com" or "www.google.com".  
  
Very useful for creating passwords, or key vectors when combined with SEQUENCE.  
  
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
    /w stands for [0-9a-zA-Z_]  
  
  
SEQUENCE  
Used to create large sequences between any 2 alphanumeric strings.  
  
For a simple example, for input:   
    before    = "char array[] = { '"  
    start     = "z"  
    separator = "', '"  
    stop      = "a"  
    after     = "' };"  
    (default difference = 1)  
  
Output is:  
char array[] = { 'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a' };  
  
Much time saved !  
  
For another example, a bit more complicated, for input:  
    start      = "1a1"  
    stop       = "2b2"  
    difference = 2  
    (default before = "")  
    (defaut  after  = "")  
    (default separator = "\n")  
  
Output is:  
a1  
a3  
a5  
a7  
a9  
b1  
  
Probably not a useful sequence, but you got the idea.  
  
Or Fins

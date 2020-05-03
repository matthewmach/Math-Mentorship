# University of Toronto Math Mentorship
This repository contains all the work and resources used in my University of Toronto Math Mentorship project. In this project, we explored random walks, markov chains, the Monte Carlo Method, and it's applications in districting. The code/resources will be in the respectively named folders.

# Random Walks
The first problem we explored was a random walk called the Drunkard's Walk.

The Drunkard's Walk is a random walk on ![\mathbb{Z}](https://render.githubusercontent.com/render/math?math=%5Cmathbb%7BZ%7D). Each step is either forward (+1) or backward (-1). The drunkard's house is at ![h](https://render.githubusercontent.com/render/math?math=h). Based on this, a few questions can be asked:

> What's the probablility of the drunkard reaching his house in n steps?

This question is quite easy. First, note ![n](https://render.githubusercontent.com/render/math?math=n) must be the same parity of ![h](https://render.githubusercontent.com/render/math?math=h). Assuming ![h](https://render.githubusercontent.com/render/math?math=h) is positive (it won't matter in the end), then we know that there are ![h+k](https://render.githubusercontent.com/render/math?math=h%2Bk) steps forward and ![k](https://render.githubusercontent.com/render/math?math=k) steps backward with ![k=\frac{n-h}{2}](https://render.githubusercontent.com/render/math?math=k%3D%5Cfrac%7Bn-h%7D%7B2%7D). 
Thus, the formula is:


> What's the probability of the drunkard passing by his house in n steps?

Here's where things get pretty hard. All the question is asking is how many sequences exist where the the drunkard is at ![h](https://render.githubusercontent.com/render/math?math=h) at some point.

The problem is when you test a bunch of test cases, no clear pattern forms except for the fact that if ![n](https://render.githubusercontent.com/render/math?math=n) odd, then ![p(n)=p(n-1)](https://render.githubusercontent.com/render/math?math=p(n)%3Dp(n-1)).
```
p(1) = 0
p(2) = 1/4
p(3) = 2/8 = 1/4
p(4) = 6/16 = 1/4 + 1/8
p(5) = 12/32 = 1/4 + 1/8
p(6) = 29/64 = 1/4 + 1/8 + 1/16 + 1/64
p(8) = 130/256 = 1/2 + 1/128
```
Here's where coding comes in use. With [DrunkardsWalk.cpp](https://github.com/matthewmach/MathMentorship/blob/master/RandomWalks/DrunkardsWalk.cpp), I wrote a recursive function to bash all the possible step sequences and tested each one of them, effectively bashing all cases. Then, I compared the bashed answer to my predicted formula.
This program allowed me to test my hypothesized formulas easily and efficiently, especially for much larger values of ![h](https://render.githubusercontent.com/render/math?math=h) and ![n](https://render.githubusercontent.com/render/math?math=n).
Here's what the formula looks like:


The logic behind this formula is simple:

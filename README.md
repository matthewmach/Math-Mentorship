# University of Toronto Math Mentorship
This repository contains all the work and resources used in my University of Toronto Math Mentorship project. In this project, we explored random walks, markov chains, the Monte Carlo Method, and it's applications in districting. The code/resources will be in the respectively named folders.

**Note**: I just decided to write up everything in github, so currently the entire markov chain writeup is not availible. They should be finished by May 11th.

<br />

# Random Walks
## Drunkard's Walk
The first problem we explored was a random walk called the Drunkard's Walk.

The Drunkard's Walk is a random walk on ![\mathbb{Z}](https://render.githubusercontent.com/render/math?math=%5Cmathbb%7BZ%7D). Each step is either forward (+1) or backward (-1). The drunkard's house is at ![h](https://render.githubusercontent.com/render/math?math=h). Based on this, a few questions can be asked:

> What's the probablility of the drunkard reaching his house in n steps?

This question is quite easy. First, note ![n](https://render.githubusercontent.com/render/math?math=n) must be the same parity of ![h](https://render.githubusercontent.com/render/math?math=h). Assuming ![h](https://render.githubusercontent.com/render/math?math=h) is positive (it won't matter in the end), then we know that there are ![h+k](https://render.githubusercontent.com/render/math?math=h%2Bk) steps forward and ![k](https://render.githubusercontent.com/render/math?math=k) steps backward with ![k=\frac{n-h}{2}](https://render.githubusercontent.com/render/math?math=k%3D%5Cfrac%7Bn-h%7D%7B2%7D). 

Thus, the formula is:

<img src="https://github.com/matthewmach/Math-Mentorship/blob/master/Images/ReachFormula.png" width="120">

Note: ![n-(h+k) = k](https://render.githubusercontent.com/render/math?math=n-(h%2Bk)%20%3D%20k), thus it doesn't matter if we assumed ![h](https://render.githubusercontent.com/render/math?math=h) was positive or negative.

<br />

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

<img src="https://github.com/matthewmach/Math-Mentorship/blob/master/Images/PassFormula.png">

The logic behind this formula is simple. To visually represent the sequence, imagine a coin flip representing the two options of therandom walk. Let ![H](https://render.githubusercontent.com/render/math?math=H) represent heads, which moves the drunk forward (+1) and ![T](https://render.githubusercontent.com/render/math?math=T) represent tails, which moves the drunk backwards (-1). 

If you ignore function ![f](https://render.githubusercontent.com/render/math?math=f) and just use the standalone choose function. We're simply counting the number of sequences that follow the pattern:

```
TH
```

<br />

## Recurrence
Recurrence is a property of random walks. The definition is as follows:

> A random walk is recurrent if it visits the origin infinitely many times. If it does not, it is transient.

Another way to think about it is, a random walk is recurrent if it is likely to visit its starting position as time goes to infinity.

One interesting thing to note is if a random walk is recurrent, it will visit every point infinite times. 

To test for recurrence, we rely on a theorem that states:

> The sum of probabilities of returning to the origin is infinite if and only if the walk is recurrent.

Generally, we usually find an equation that represents the probabily of returning to the origin, then approximate the sum at large numbers using Stirling's formula and calculus.

Stirling's formula states at large numbers:

<img src="https://github.com/matthewmach/Math-Mentorship/blob/master/Images/StirlingsFormula.png">

<br />

In this project, we were able to test random walks on ![\mathbb{Z}](https://render.githubusercontent.com/render/math?math=%5Cmathbb%7BZ%7D), ![\mathbb{Z}^2](https://render.githubusercontent.com/render/math?math=%5Cmathbb%7BZ%7D%5E2), and ![\mathbb{Z}^3](https://render.githubusercontent.com/render/math?math=%5Cmathbb%7BZ%7D%5E3) for recurrence.

To test for recurrence, I found the general formula for the probability of a random walk on generic simple symmetic graph returning to the origin. 
The formula is:

<img src="https://github.com/matthewmach/Math-Mentorship/blob/master/Images/RecurrenceGeneralSymmeticFormula.png">

This formula is simple to understand: 

As the valence of the tree goes up (the number of options), there only remains 1 way to go back towards the origin. That's what the  ![(m-1)^{n/2}](https://render.githubusercontent.com/render/math?math=(m-1)%5E%7Bn%2F2%7D) term is for. There's also a ![1^{n/2}](https://render.githubusercontent.com/render/math?math=1%5E%7Bn%2F2%7D) term that's left out. These two terms both represent the probalility of going forward half the time and going backward half the time, returning to the origin in the end. 

The ![\binom{n}{n/2}](https://render.githubusercontent.com/render/math?math=%5Cbinom%7Bn%7D%7Bn%2F2%7D) term represents the number of distinct orders the steps can be taken.

I was able to test said formula with [AnyLengthWalk.cpp](https://github.com/matthewmach/Math-Mentorship/blob/master/RandomWalks/AnyLengthWalk.cpp). The code is very similar to DrunkardsWalk, but modified to work for higher valence trees.

<br />

This formula is relatively easy to test for recurrence. Here's the math for a double valence trees:

> Double valence (number line)

<img src="https://github.com/matthewmach/Math-Mentorship/blob/master/Images/ZProof.png">

Thus, a simple symmetric random walk on ![\mathbb{Z}](https://render.githubusercontent.com/render/math?math=%5Cmathbb%7BZ%7D) is recurrent.

<br />

One thing that's a bit confusing is that a quadruple valence tree is not the same as a lattice grid. Our current formula will not work for grids like these because it assumes that there is only 1 way towards the origin. To test for recurrence in something like a lattice grid, we have to look at a different method.

> ![\mathbb{Z}^2](https://render.githubusercontent.com/render/math?math=%5Cmathbb%7BZ%7D%5E2) (lattice grid)

One clever way to solve this problem is to break the random walk into two parts, one for each axis. Then, the problem becomes the probability of 2 random walks on a number line reaching the origin.

<img src="https://github.com/matthewmach/Math-Mentorship/blob/master/Images/Z2Proof.png">

<br />

<img src="https://github.com/matthewmach/Math-Mentorship/blob/master/Images/Z2Proof2.png">

Thus, a simple symmetric random walk on ![\mathbb{Z}^2](https://render.githubusercontent.com/render/math?math=%5Cmathbb%7BZ%7D%5E2) is recurrent.

<br />

> ![\mathbb{Z}^3](https://render.githubusercontent.com/render/math?math=%5Cmathbb%7BZ%7D%5E3) (a 3d lattice grid)
Here's where things get real tricky. First, let's look at 2n steps to the origin instead of n steps. This will make the math look nicer and hopefully more easily understandable.

Similar to an observation we made about the random walk on the number line, there must be ![i](https://render.githubusercontent.com/render/math?math=i) steps up and down, ![j](https://render.githubusercontent.com/render/math?math=j) steps north and south, and ![k](https://render.githubusercontent.com/render/math?math=k) steps east and west such that ![i+j+k = n](https://render.githubusercontent.com/render/math?math=i%2Bj%2Bk%20%3D%20n) (here's where the 2n comes in handy).

Thus our probability becomes:

<img src="https://github.com/matthewmach/Math-Mentorship/blob/master/Images/Z3Proof1.png">

Now this might be new notation to you, but this is a cyclic sum basically saying sum all combonations of ![i](https://render.githubusercontent.com/render/math?math=i), ![j](https://render.githubusercontent.com/render/math?math=j), and ![k](https://render.githubusercontent.com/render/math?math=k) such that it follows those conditions.

We can manipulate the equation further to get this:

<img src="https://github.com/matthewmach/Math-Mentorship/blob/master/Images/Z3Proof2.png">

From here, one critical observation has to be made:

<img src="https://github.com/matthewmach/Math-Mentorship/blob/master/Images/Z3Proof3.png">

This is because the sum represents the sum of the probabilities of all the way of placing ![n](https://render.githubusercontent.com/render/math?math=n) balls randomly in 3 boxes, thus the sum must be 1! This allows us to simplify the equation to:

<img src="https://github.com/matthewmach/Math-Mentorship/blob/master/Images/Z3Proof4.png">

Thus, a simple symmetric random walk on ![\mathbb{Z}^3](https://render.githubusercontent.com/render/math?math=%5Cmathbb%7BZ%7D%5E3) is transient.

<br />

# Markov Chains

## Markov Chain Monte Carlo

## Redistricting

# Resources
All the pdfs and resources here are contained in their respective folders.
* https://www.math.ucla.edu/~biskup/PDFs/PCMI/PCMI-notes-1
* https://www.statslab.cam.ac.uk/~james/Markov/s16.pdf
* https://people.csail.mit.edu/ddeford/MCMC_Intro_plus.pdf
* https://arxiv.org/pdf/1911.05725.pdf


# Credits
Credits go to Assaf Bar-Natan for being my mentor, Jim Liu for being my partner in this project, and Junyi Wang for helping me dervive some of the formulas for random walks.

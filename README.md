# Assignments 4
## by Kfir Goldfarb

<i>in this assignment I implemented a trie data strture (digital tree) for store chars from words that the main fuction gets as argument from a text file, in addition i implement a struct called node that represent a node (vertex) in the trie.</i>

### illustration of a Trie data structure:

<img src="https://github.com/kggold4/sw_systems_hw4/blob/main/images/trie-example.png">

* to read more about the trie data structure <a href="https://en.wikipedia.org/wiki/Trie">read in wikipedia</a>.

* <i>for compile the project use the make file command ``make all``</i>

# Examples for running the frequency exectute file

* assume we have the following text file called ``input.txt``:
```
it was the best of times, it was the worst of times.
it was the age of wisdom, it was the age of foolishness.
```

## <i>In lexicographic order is ascending:</i>
we use the command (with linux): ``./frequency < input.txt``,
and the output will be:

```
age 2
best 1
foolishness 1
it 4
of 4
the 4
times 2
was 4
wisdom 1
worst 1
```

## <i>In lexicographic order decreases:</i>
we use the command (with linux): ``./frequency r < input.txt``,
and the output will be:

```
worst 1
wisdom 1
was 4
times 2
the 4
of 4
it 4
foolishness 1
best 1
age 2
```

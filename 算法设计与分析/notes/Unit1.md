## Chapter 1 

## Introduction: some representative problems 

### 1.1 A First Problem: stable Matching

#### background

​	There exists a common problem: when you are choosing pairs or make pairs with others.Firstly, we have as follows standards:

​	Each of n applicants applies to each of n companies, and each company wants to accept a single applicant.

​	This special case can be viewed as the problem of devising a system by which each of **n** men and **n** women can end up getting married.  our problem naturally has the analogue of two “genders”—the applicants and the companies—and in the case we are considering, everyone is seeking to be paired with exactly **one individual of the opposite gender.**  

#### Analysis

​	consider a set **M = {m_1,..., m_n}** of **n** men, and a set **W = {w_1,..., w_n}** of **n** women. Let **M × W** denote the set of all possible ordered pairs of the form **(m, w)**, where **m ∈ M** and **w ∈ W**. A matching **S** is a set of ordered pairs, each from **M × W**, with the property that each member of **M** and each member of **W** appears in at most one pair in **S**. A perfect matching **S'** is a matching with the property that each member of M and each member of W appears in exactly one pair in **S'** . 

​	We should consider about following conditions:

​	There are two pairs **(m, w)** and **(m' , w' )** in **S**  with the property that **m** prefers **w'** to **w**, and **w**' prefers **m** to **m'** . In this case, there’s nothing to stop **m** and **w'** from abandoning their current partners and heading off together; the set of marriages is not self-enforcing. 

​	We’ll say that such a pair **(m, w' )** is an instability with respect to **S**: **(m, w' )** does not belong to **S,** but each of **m** and **w'** prefers the other to their partner in **S**. 

#### Designing

​	An arbitrary free man **m** chooses the highest-ranked woman **w** to whom he has not yet proposed, and he proposes to her. If **w** is also free, then **m** and **w** become engaged. Otherwise, **w** is already engaged to some other man **m'** . In this case, she determines which of **m** or **m'** ranks higher on her preference list; this man becomes engaged to **w** and the other becomes free. 

​	**Finally, the algorithm will terminate when no one is free;**

```markdown
Initially all m ∈ M and w ∈ W are free
While there is a man m who is free and hasn’t proposed to every woman
	Choose such a man m
	Let w be the highest-ranked woman in m’s preference list
		to whom m has not yet proposed
	If w is free then
		(m, w) become engaged
	Else w is currently engaged to m
		If w prefers m to m then
			m remains free
		Else w prefers m to m
			(m, w) become engaged
			m becomes free
		Endif
	Endif
Endwhile
Return the set S of engaged pairs
```

####  conclusions

1. **w** remains engaged from the point at which she receives her first proposal; and the sequence of partners to which she is engaged gets better and better (in terms of her preference list). 
2. The sequence of women to whom **m** proposes gets worse and worse (in terms of his preference list). 
3. The G-S algorithm terminates after at most **n^2** iterations of the While loop 
4. If m is free at some point in the execution of the algorithm, then there is a woman to whom he has not yet proposed 
5. The set **S** returned at termination is a perfect matching 
6. Consider an execution of the G-S algorithm that returns a set of pairs S. The set S is a stable matching 

#### Extensions

1. **Every execution of the G-S algorithm results in the set S∗.** 
2. **In the stable matching S∗, each woman is paired with her worst valid partner** 
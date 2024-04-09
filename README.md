# Powering Opponent A.I. to Effectively Counter with Gradient Boosted Voting

A simple program that will use all previous inputs by you to learn and try to make the right choice upon having to choose between `attacking` or `defending`
depending on how you've responded in the past.

> [!IMPORTANT]
> In modeling phase, getting the math right.
## Mathematical Foundation / Discussion

So I want to create a rudimentary turn-based enemy "AI" with predictive modeling that grows alongside the user.

First, I want to see what classification method is optimal for what I want to do.

### Classification Models - Gradient Boosted Regression Trees

I think this model works best (as of now) because not only do I gain scalability, but I also have a pretty nice
voting method to improve the regression tree learner. 

(*Math to be discussed.*)

### Red-Lighted

**Naive Bayes** was my initial method of classification, which is not bad. It's effective and easy to implement, but
I don't think this can best solve my objective as naive Bayes is not as scalable as I'd like. I want my enemy
to learn and grow, and I think naive Bayes may end up becoming too inaccurate in predicting the user.

**Logistic regression** is also great. Though, because its basis lies in the Bernoulli distribution, it doesn't
solve the multiclass problem that I'll face. I can implement a multiclass logistic regression algorithm, but that
would require me to do more work than I'd like to.

**Support vector machines** faces a similar issue with naive Bayes. Over time when input data becomes too complex,
which it will, since user inputs can vary, SVMs will end up giving me inaccurate predictions.

**k-NN** will not work well. Like naive Bayes and support vector machines, this problem lies in how the data looks
in the future, which cannot be solved through mode classification. Majority voting isn't good in this situation,
the user can work their way around this very easily and manipulate the enemy.

**Decision trees** are too weak, but this can be solved with gradient boosting. Something to think about. Though,
**regression trees** can work better.
